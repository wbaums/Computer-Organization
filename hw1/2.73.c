
/* Addition that saturates to Tmin or Tmax */
int saturating_add(int x, int y) {
  if (x > 0 && y > 0) {
    return (TMax - x) >= y ? x + y : INT_MAX;
  }
  else if (x < 0 && y < 0) {
    return (Tmin - x) <= y ? x + y : INT_MIN;
  }
  else {
    return x + y;
  }
}
