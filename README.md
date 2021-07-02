# beats
Swatch Internet Time implemented as a C program.

## Usage
```console
$ beats -h
Usage: beats [-ahn] [-f | -i] [-t timestamp]
Displays the Swatch Internet Time.

-a      omit leading @-sign
-f      print full floating-point value
-h      display this help and exit
-i      integer mode (omit decimals)
-n      omit newline (\n)
-t      parse UNIX timestamp
```

## Compile and Install
`gcc` and `make` are required.

Standard procedure:
1. Run `make` to compile, or
2. `make install` to compile and move the binary file to the `$PREFIX`

## Thanks
Quite a few other implementations exist online, such as [brneor/swatch](https://github.com/brneor/swatch) and [hyphenrf/swatch.beats](https://github.com/hyphenrf/swatch.beats).

This program was written with the UNIX Philosophy in mind: to be small, cleanly-written and flexible.
