/* 
 * CS:APP Data Lab 
 * 
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

/*
 * STEP 2: Modify the following functions according the coding rules.
 */


#endif
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* 
 * specialBits - return bit pattern 0xffca3fff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 3
 *   Rating: 1
 */
int specialBits(void) {
  /* Start with 8 bits 1101 0111
     Shift left 14 and invert to get correct pattern
  */ 
  return ~(215 << 14);
}

/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  /* Uses the fact that Tmax + 1 == Tmin which is unique to Tmax */
  int add1 = x + 1;
  int a = x + add1;
  add1 = !add1;
  a = ~a;
  a = a | add1;
  return !a;
}

/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {
  /* Creates a mask of 0101....0101. Then mask & x leaves even bits in place
     so you can check for non-zero bits*/
  int m = 85;
  int mask = 85;
  mask = mask << 8;
  mask += m;
  mask = mask << 8;
  mask += m;
  mask = mask << 8;
  mask += m;
  x = x & mask;
  return !!x;
}

/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
  /* create mask and shift by n * 8 to get bits in correct position*/
  int mask = c;
  mask = mask << (n << 3);
  /* use | operation on x and the correct bit shift, use x ^ mask to input correct bits, then remove
   extras using ^ operator again*/
  x = x | (255 <<(n << 3));
  x = x ^ mask;
  x = x ^ (255 <<(n << 3));
  return x;
}

/* 
 * signMag2TwosComp - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: signMag2TwosComp(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int signMag2TwosComp(int x) {
  /* sign mag = ~x + 1. Get correct sign and use mask to change correct bits from 1's to zero's
   in the inverted bit pattern. */
  int min = 1 << 31;
  int sign = x & min;
  int spread = min >> 31;
  int mask = spread + !sign;
  return ((mask & ((min) ^ (1 + (~x)))) | (x & ~mask));
}

/* 
 * twosComp2SignMag - Convert from two's complement to sign-magnitude 
 *   where the MSB is the sign bit
 *   You can assume that x > TMin
 *   Example: twosComp2SignMag(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int twosComp2SignMag(int x) {
  /* find the sign to create all 0's or all 1's. Then set the msb by shifting back
   use x ^ mask to change the sign if needed. Reset the lsb, get the magnitude and use | to merge 
  the sign and magnitude*/
  int mask = x >> 31;
  int signmsb = mask << 31;
  int re_sign = x ^ mask;
  int lsb = mask & 1;
  int mag = lsb + re_sign;
  return signmsb | mag;
}

/*
 * intLog2 - return floor(log base 2 of x), where x > 0
 *   Example: intLog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int intLog2(int x) {
  int a, b, c, d, e;
  /* This function returns the floor of the log base 2... meaning that the only significant bit
   is the leftmost 1. We can use this to return the number of bit shifts over the most
  significant 1 bit is from the right. */
  x = x | (x >> 1);
  x = x | (x >> 2);
  x = x | (x >> 4);
  x = x | (x >> 8);
  x = x | (x >> 16);

  // a : 10101010
  a = 85 | (85 << 8); 
  a = a | (a << 16);
  // b : 00110011 
  b = 51 | (51 << 8);
  b = b | (b << 16);
  // c : 00001111 
  c = 15 | (15 << 8);
  c = c | (c << 16);
  // d : 11111111 
  d = 255 | (255 << 16);
  // e : 11111111
  e = 255 | (255 << 8);
  x = (a & x) + (a & (x >> 1));
  x = (b & x) + (b & (x >> 2));
  x = (c & x) + (c & (x >> 4));
  x = (d & x) + (d & (x >> 8));
  x = (e & x) + (e & (x >> 16));
  x = x + ~0;
  return x; 
 }
