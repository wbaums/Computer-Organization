#include<stdio.h>

int for_loop(int num) {
  int total = 0;
  for(int i = 0; i < num; i++) {
    total += i;
  }
  return total;
}
