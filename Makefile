##############################################################################
####                 On building the Pika Macro ASsembler                 ####
##############################################################################
#### PMAS was originally designed by Rafael Vuijk (DarkFader) of darkfader.net
####
#### This is designed for GNU Make. Compile thru MSYS2 on Windows.
#### Windows (admin PowerShell prompt with Chocolatey installed):
####   choco install python3 msys2
####   msys2
####   pacman -S mingw-w64-gcc make diffutils zip
####   make release
#### Linux (Ubuntu):
####   apt install build-essential diffutils tar
####   make release
####
#### build_common_pm.py works on Python 2.7+ so the version that ships with
#### your linux install should be good enough.
PMAS_VERSION := 1.1

.PHONY: help
help:
	@echo "Command goals:"
	@echo "  help          This list."
	@echo "  release       Build release version of pmas."
	@echo "  debug         Build debug version of pmas."
	@echo "  bundle        Bundle a release build"
	@echo "  releasetest   Run some tests."
	@echo "  debugtest     Run some tests under gdb to find bugs."
	@echo "  clean         Delete all output files (besides release)."

##############################################################################
####                                Config                                ####
##############################################################################
# Command-line configurable options
## Select which CPU to test, folder name from cpu subdir
CPU ?= all

# Tools
COMPARE := diff -q --binary
LD := $(CXX)
PY := python

PMAS = ./$(tPMAS)
PMDIS = ./$(tPMDIS)

# General
CPUS := minx s1c88 pm r16
EXES = $(tPMAS) $(tPMDIS)
COPYME = $(EXES) $(wildcard *.md) cpu
SOURCES := $(wildcard src/*.cpp)
DEPFILES := $(SOURCES:src/%.cpp=obj/%.d)
NODEPS := clean

# Build flags
INCLUDES := -Isrc
CXXFLAGS := -Wall $(INCLUDES) -DVERSION="\"$(PMAS_VERSION)\""
LDFLAGS := $(INCLUDES)

ifeq ($(OS),Windows_NT)
tPMAS := pmas.exe
tPMDIS := pmdis.exe
tPARSEMINDX := parsemindx.exe
ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
BUNDLE := releases/pmas-windows-x64.zip
else
BUNDLE := releases/pmas-windows-x86.zip
endif
else
tPMAS := pmas
tPMDIS := pmdis
tPARSEMINDX := parsemindx
ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
BUNDLE := releases/pmas-windows-x64.zip
else
BUNDLE := releases/pmas-windows-x86.zip
endif
UNAME_S := $(shell uname -s)
UNAME_P := $(shell uname -p)
ifeq ($(UNAME_S),Darwin)
OS := osx
else
OS := linux
endif
ifeq ($(UNAME_P),x86_64)
BUNDLE := releases/pmas-$(OS)-x64.tar.gz
else
BUNDLE := releases/pmas-$(OS)-x86.tar.gz
endif
endif

# Generate dependecies
## Do g++ -MM exports and make object deps rules
ifeq (,$(filter $(MAKECMDGOALS),$(NODEPS)))
	-include $(DEPFILES)
endif

##############################################################################
####                              Phony rules                             ####
##############################################################################
.PHONY: release
release: CFLAGS += -O3
release: $(EXES)

.PHONY: debug
debug: CFLAGS += -g -DDEBUG
release: $(EXES)

.PHONY: releasetest
releasetest: release test-$(CPU)

.PHONY: debugtest
debugtest: PMAS = echo r | gdb -q -x - --args $(PMAS)
debugtest: debug test-$(CPU)

.PHONY: bundle
bundle: releasetest $(BUNDLE)

##############################################################################
####                              Executables                             ####
##############################################################################
EVAL_O = obj/eval.o obj/stack.o obj/misc.o obj/symbol.o $(TMPLABEL_O) obj/valuetype.o
INSTRUCTION_O = obj/instruction.o $(MEM_O) $(EVAL_O)
MACROLIST_O = obj/macrolist.o obj/misc.o # $(SYMBOL_O)
MEM_O = obj/mem.o obj/misc.o
STACK_O = obj/stack.o obj/misc.o $(VALUETYPE_O)
SYMBOL_O = obj/symbol.o $(MACROLIST_O) $(EVAL_O) # $(VALUETYPE_O)
TMPLABEL_O = obj/tmplabel.o obj/misc.o
VALUETYPE_O = obj/valuetype.o $(EVAL_O)

$(tPMAS): obj/pmas.o $(MACROLIST_O) $(INSTRUCTION_O)
	$(LD) $(LDFLAGS) -o $@ $(filter %.o,$^)

$(tPMDIS): obj/pmdis.o $(INSTRUCTION_O)
	$(LD) $(LDFLAGS) -o $@ $(filter %.o,$^)

# Isn't needed anymore but...
$(tPARSEMINDX): obj/parsemindx.o $(INSTRUCTION_O)
	$(LD) $(LDFLAGS) -o $@ $(filter %.o,$^)

obj/%.d: src/%.cpp
	@mkdir obj 2>/dev/null | true
	$(CXX) $(CXXFLAGS) -MM -MT $(patsubst src/%.cpp,obj/%.o,$(filter %.cpp,$+)) $(filter %.cpp,$+) > $@

obj/%.o: src/%.cpp
	@mkdir obj 2>/dev/null | true
	$(CXX) $(CXXFLAGS) -c -o $@ $<

cpu/pm.s: cpu/s1c88/s1c88.s
	$(PY) build_common_pm.py

##############################################################################
####                        Building release rules                        ####
##############################################################################
releases/pmas-%.zip: build
	cd $< && zip -r ../$@ *

releases/pmas-%.tar.gz: build
	cd $< && tar -czf ../$@ *

build: cpu/pm.s $(COPYME)
	@echo 'If this fails, update the changelog'
	grep $(PMAS_VERSION) README.md
	-mkdir $@
	-cp -r $? $@

##############################################################################
####                              Test rules                              ####
##############################################################################
TESTFILESMINX := test/test-reference.s $(wildcard test/minx/*.s)
TESTFILESS1C88 := test/test-reference.s $(wildcard test/s1c88/*.s)
TESTFILESR16 := $(wildcard test/r16/*.s)

# Test suites
.PHONY: test-all test-pm $(addprefix test-,$(patsubst cpu/%,%,$(wildcard cpu/*)))

test-all: test/test-nested.min test-r16 test-pm

test-pm: CPU = pm
test-pm: cpu/pm.s test-minx test-s1c88

test-minx: $(tPMAS) $(TESTFILESMINX:.s=.min)
	$(COMPARE) test/minx/opcodes1.min test/minx/opcodes2.min
	$(COMPARE) test/minx/opcodes1.min test/minx/opcodes3.min
	$(COMPARE) test/test-reference.min test/minx/test.min

test-s1c88: $(tPMAS) $(TESTFILESS1C88:.s=.min)
	$(COMPARE) test/test-reference.min test/s1c88/test.min

test-r16: $(tPMAS) $(TESTFILESR16:.s=.min)
# TODO:	$(COMPARE) test/r16/reference.min test/r16/test.min 

# Build test files
test/%.min: test/%.s $(tPMAS)
	$(PMAS) $< $@ $(@:.min=.sym)

define test_template = 
test/$(1)/%.min: test/$(1)/%.s $$(tPMAS) cpu/$(1)/$(1).s
	$$(PMAS) -c $$(CPU:all=$(1)) $$< $$@ $$(@:.min=.sym)
endef

$(foreach cpu,$(CPUS),$(eval $(call test_template,$(cpu))))


##############################################################################
####                               Clean-up                               ####
##############################################################################
.PHONY: clean
clean:
	-rm -f obj/*.o obj/*.d test/*.min test/*.sym test/*.dis.s \
		test/*/*.min test/*/*.sym test/*/*.dis.s \
		pmas pmas.exe pmdis pmdis.exe parsemindx parsemindx.exe
	-rm -rf build
	-rmdir obj
