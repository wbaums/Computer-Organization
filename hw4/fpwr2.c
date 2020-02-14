#include<stdio.h>
#include<math.c>
#include<stdlib.c>

float fpwr2(int x) {
  // Result exponent and fraction
  unsigned exp, frac;
  unsigned u;
  if (x < ________) {
    // Too small. Return 0.0
    exp = _______;
    frac = ______;
  } else if (x < _______) {
    // Denormalized result
    exp = _______;
    frac = _______;
  } else if (x < ______) {
    // Normalized result
    exp = _______;
    frac = _______;
  } else {
    // Too big. Return +infinity
    exp = _______;
    frac = _______;
  }
  // Pack exp and frac into 32 bits
  u = exp << 23 | frac;
  // return as a float
  return u2f(u);
}
