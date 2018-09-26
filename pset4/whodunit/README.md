# Questions

## What's `stdint.h`?

stdint.h is a header file in the C standard library introduced in the C99 standard library section 7.18 to allow programmers
to write more portable code by providing a set of typedefs that specify exact-width integer types,
together with the defined minimum and maximum allowable values for each type, using macros

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

to specify excatly the number of bits we will manipulate and min , max values to it

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1, 4, 4, 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be?
## Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

BM, 424d

## What's the difference between `bfSize` and `biSize`?

bisize is the size of pixels of photo alone
bfsize is the size of whole size of the photo including the headers

## What does it mean if `biHeight` is negative?

he bitmap is a top-down DIB with the origin at the upper left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

Could not open infile or Could not create outfile

## Why is the third argument to `fread` always `1` in our code?

as we going to save one element to the stuct

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

skips over any padding and looks for the next pixel

## What is `SEEK_CUR`?

This is an integer constant which, when used as the whence argument to the fseek or fseeko function,
specifies that the offset provided is relative to the current file position

## Whodunit?

professor plum
