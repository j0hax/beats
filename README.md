# beats
Swatch Internet Time implemented as a C program.

## Usage
```console
$ beats -h
beats - outputs current Swatch Internet Time

OPTIONS:
-a              omit leading @-sign
-f              print full float
-h              print this help screen
-i              omit decimal places
-n              omit newline
-t TIMESTAMP    parse UNIX timestamp
```

## Thanks
Quite a few other implementations exist online, such as [brneor/swatch](https://github.com/brneor/swatch) and [hyphenrf/swatch.beats](https://github.com/hyphenrf/swatch.beats).

This program was written with the UNIX Philosophy in mind: to be small, cleanly-written and flexible.
