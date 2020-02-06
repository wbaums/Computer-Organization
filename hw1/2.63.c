unsigned long srl(unsigned long x, int k) {
  /* Perform shift arithmatically */
  unsigned long xsra = (int) x >> k;
  // create mask 
  int w = 8*sizeof(int);
  unsigned long m = (1 << (w - k)) - 1;
  // bitwise  & with xsra/mask
  return m & xsra;
}

long sra(long x, int k) {
  /* Perform shift logically */
  long xsrl = (unsigned) x >> k;
  // create mask if needed (x < 0)
  int m = -1 << ((8 * sizeof(int)) - k);
  // return value of arithmatic right shift
  return x > 0 ? xsrl :  m & xsrl;
}
