
/* Addition that saturates to TMin or TMax */
int saturating_add(int x, int y) {
  bool over = __builtin_add_overflow(x, y, (int) 0);
  return over ? (x >> 31) ^ INT_MAX : x + y;
}
