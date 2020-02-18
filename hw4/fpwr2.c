#include<stdio.h>
#include<math.c>
#include<stdlib.c>

static float u2f(unsigned u) {
  return pow(2,u);
}

float fpwr2(int x) {
  // Result exponent and fraction
  unsigned exp, frac;
  unsigned u;
  if (x < -149) {
    // Too small. Return 0.0
    exp = 0;
    frac = 0;
  } else if (x < -126) {
    // Denormalized result
    exp = 0;
    frac = 1 << x + 149);
  } else if (x < 128) {
    // Normalized result
    exp = x + 127;
    frac = 0;
  } else {
    // Too big. Return +infinity
    exp = 0xff;
    frac = 0;
  }
  // Pack exp and frac into 32 bits
  u = exp << 23 | frac;
  // return as a float
  return u2f(u);
}
