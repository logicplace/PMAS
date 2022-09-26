# Pika Macro ASsembler

A simple 2-pass assembler with a customizable instruction set.

Please note that this is something of a restoration project. PMAS is not really intended to be the future of Pokémon mini homebrew going forward. Please check out the official [Epson utilities][Epson] or [Skiploom][] instead.

[Epson]: https://github.com/pokemon-mini/c88-pokemini
[Skiploom]: https://github.com/asterick/skiploom

## Executables

* `pmas` - Assembler
* `pmdis` - Disassembler

## Further information

* `cpu/minx` - The original MindX-based instruction set, from back when we called the PM code MinX
* `cpu/s1c88` - The official Epson S1C88 instruction set
* `cpu/pm` - A combination of the above two syntaxes
* `cpu/r16` - Some other instruction set DarkFader left here
* `cpu/*/readme.s` - A quick reference of directives and required syntax

## About

PMAS was originally designed by Rafael Vuijk (DarkFader) of darkfader.net but he's essentially disappeared so now it's maintained by the pokemon-mini.net community.

The final official release version was 0.15 (built) and 0.19 (source).

### Original license

Taken from [here](https://www.darkfader.net/info/)

> All my own software productions on this website may be used for non-commercial and educational purposes freely unless noted otherwise. It would be of great value if you notify me of additions/improvements.
> For commercial uses, I generally don't make much of a problem either, but contact me anyway.
> But please do not host my files for whatever reason without permission. (while my website is alive)

## Changelog

Old versions can be accessed [here](https://sourceforge.net/projects/pmas/files/).

### v1.1 - 2022-09-26

* Reorganized source code and Makefile
* pmdis now supports CPU selection at runtime
* minx CPU supports a lot more now (which it should've before!!)


### v1.0 - 2022-09-20

* Add support for S1C88 ops
* Change CPU system a bit to make them selectable (at build time)
* Consistency improvements for minx (original) target
* Get disassembler building again
* Add `make bundle` command to build releases


### v0.19 - 2011-06-06

* Fixed string+number concatenation.


### v0.18 - 2011-06-06

* Fixed some memory freeing problem when error was found.


### v0.17 - 2011-06-05

* Fixed ifdef after undefine.
* Cleanup unused code.
* Added string indexer operator [ ]


### v0.16 - 2011-06-02

* Lines ending in backslash will merge line with the next.
* Line variable fixing.
* version up
* Fixed the compiler warnings.
* Added .elif for shorthand .elsif.
* Default value for .define is 1.
* Added some conditional tests.
* applied patch: This patch will expand memory limit from 1MB to 2MB, allowing to assemble .min roms as big as Pokemon-Mini's memory range.
* Makefile now using dependencies and prefixing some executables with ./
* applied: This patch will fix buffer overflow caused by the current (and 0.15 version) mindx.txt


### v0.15 - 2009-05-29

* macro bugfix: end-of-line detection failed when last parameter was being forced as string.
* parsemindx crashed on non-empty instruction structure (hackish solution).
* Pokemon Mini: both old and new instruction names are supported.
* Makefile tested on OS X
* Pokemon Mini: instruction/register name change.
* Pokemon Mini: instruction/register name change.
* ValueType can be undefined
