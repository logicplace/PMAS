CPU ?= pm
PMAS_VERSION := 1.0
VERSION2 :=
MODIFIER :=
INCLUDES := -Isrc -Icpu/$(CPU)
CFLAGS := -Wall $(INCLUDES) -DVERSION="\"$(PMAS_VERSION)$(VERSION2)$(MODIFIER)\"" -DVERSIONN=$(PMAS_VERSION)
CXXFLAGS := $(INCLUDES)
LD := $(CXX)
LDFLAGS := $(INCLUDES)
COMPARE = diff -q --binary
PMAS = pmas$(MODIFIER)
PMDIS = ./pmdis
ifeq "$(CPU)" "pm"
OUTPUTS := cpu/$(CPU)/pm.s
else
OUTPUTS := $(shell find cpu/$(CPU) -name "*.s")
endif
OUTPUTS += $(PMAS)
OUTPUTS += pmdis
AWK := awk
PY := python

########
# help #
########

.PHONY: help
help:
	@echo "Command goals:"
	@echo "  help          This list."
	@echo "  release       Build release version of pmas."
	@echo "  debug         Build debug version of pmas."
	@echo "  bundle        Bundle a release build into a tar.gz"
	@echo "  releasetest   Run some tests."
	@echo "  debugtest     Run some tests under gdb to find bugs."
	@echo "  clean         Delete intermediate files."
	@echo "  cleanall      Delete output and intermediate files."

####################
# dependency stuff #
####################

NODEPS:=clean cleanall
SOURCES:=$(shell find src/ -name "*.cpp")
DEPFILES:=$(patsubst src/%.cpp,obj/%.d,$(SOURCES))
ifeq (0, $(words $(findstring $(MAKECMDGOALS), $(NODEPS))))
	-include $(DEPFILES)
endif

obj/%.d: obj src/%.cpp cpu/$(CPU)/cpu.h
	$(CXX) $(CXXFLAGS) -MM -MT $(patsubst src/%.cpp,obj/%.o,$(filter %.cpp,$+)) $(filter %.cpp,$+) > $@


########
# misc #
########

obj:
	mkdir obj

out:
	mkdir out

out/cpu:
	mkdir out/cpu

.PHONY: debug
debug: CFLAGS += -g -DDEBUG
debug: $(OUTPUTS)

.PHONY: release
release: CFLAGS += -O3
#-march=i586 -mcpu=i686 -O3 -fomit-frame-pointer
release: LDFLAGS +=							#-Wl,-s
release: $(OUTPUTS)

.PHONY: bundle
bundle: pmas.tar.gz

.PHONY: debugtest
debugtest: PMAS = echo r | gdb -q -x - --args $(PMAS)
debugtest: debug
	$(PMAS) test/test.s test/test.min

.PHONY: releasetest
releasetest: PMAS = ./$(PMAS)
releasetest: release test/readme.min test/test1.min test/test2.min test/test3.min test/test4.min test/opcodes1.min test/opcodes2.min test/opcodes3.min
	$(COMPARE) test/opcodes1.min test/opcodes2.min
	$(COMPARE) test/opcodes1.min test/opcodes3.min
	$(COMPARE) test/test1.min test/test2.min
	$(COMPARE) test/test1.min test/test4.min
	$(PMAS) test/test.s test/test.min

#	$(PMDIS) test/opcodes2.min test/opcodes2.dis.s
#	$(PMAS) test/opcodes2.dis.s test/opcodes2.as.min test/opcodes2.as.sym
#	$(COMPARE) test/opcodes2.min test/opcodes2.as.min

pmas.tar.gz: release out out/cpu $(OUTPUTS)
	-cp $(PMAS)* $(PMDIS)* README out
	-cp cpu/$(CPU)/* out/cpu
	cd out && tar -czf ../$@ *

##############
# pmas/pmdis #
##############

PMAS_SOURCES := src/$(PMAS).cpp src/eval.cpp src/misc.cpp src/symbol.cpp src/stack.cpp src/valuetype.cpp src/macrolist.cpp src/instruction.cpp src/mem.cpp src/tmplabel.cpp
PMAS_OBJECTS := $(patsubst src/%.cpp,obj/%.o,$(PMAS_SOURCES))

$(PMAS): obj $(PMAS_OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $(filter %.o,$+)

pmdis: obj obj/pmdis.o cpu/$(CPU)/cpu.h
	$(LD) $(LDFLAGS) -o $@ $(filter %.o,$+)

cpu/pm/pm.s: cpu/s1c88/pm.s
	$(PY) build_common_pm.py

cpu/pm/cpu.h: cpu/pm cpu/s1c88/cpu.h
	-cp cpu/s1c88/cpu.h cpu/pm/cpu.h

cpu/pm:
	mkdir cpu/pm

#########
# tests #
#########

test/%.min: test/%.s $(PMAS)
	$(PMAS) $< $@ $(@:min=sym)

test/%.min: test/%.S $(PMAS)
	$(CPP) $< | $(PMAS) - $@ $(@:min=sym)

########
# misc #
########

obj/pmdis.o: src/pmdis.cpp cpu/$(CPU)/cpu.h
	$(CXX) $(CFLAGS) -c -o $@ $<

obj/%.o: src/%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	-rm -f obj/*.o obj/*.d test/*.min test/*.sym test/*.dis.s parsemindx parsemindx.exe
	-rmdir obj

.PHONY: cleanall
cleanall: clean
	-rm -f *.tar.gz $(PMAS) $(PMAS).exe pmdis pmdis.exe cpu/pm/*
	-rmdir cpu/pm

