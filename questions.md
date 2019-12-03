# Questions

## What's `stdint.h`?

It is a header file in C standard library that declare sets of integer types having specified widths, and shall define corresponding sets of macros.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

These functions are a cross-platform implementation of a standard data type. uint8_t is an unsigned int of 8 bits, uint32_t is an unsigned long long, int32_t is a signed long long, and a uint16_t is an unsigned 16 bit int

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE: 1
DWORD: 4
LONG: 4
WORD: 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes must be BM, 0x42 in hexadecimal 

## What's the difference between `bfSize` and `biSize`?

bfsize is the size of the bitmap file in bytes
bisize is the size of the BITMAPINFOHEADER in bytes

## What does it mean if `biHeight` is negative?

When biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in `copy.c`?

If the file cannot be found.

## Why is the third argument to `fread` always `1` in our code?

The third argument determines the number of elements fread will read. This argument is always 1 because we are always reading only one file.

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3. RGBTRIPLE = 3 bytes, int padding = (4 - (3 * 3 % 4) % 4; int padding = 3

## What does `fseek` do?

It moves the file position indicator to the value pointed by the offset.

## What is `SEEK_CUR`?

It moves file pointer position to given location
