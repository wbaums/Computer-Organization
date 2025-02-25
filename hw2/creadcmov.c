/*
long cread(long *xp) {
return (xp ? xp[-1] : -1);
}

Implementation using a conditional move is invalid. xp is dereferenced by the movq
 instructin even when the test fails, causing a null pointer dereferencing error. 
 */

long ret = -1;
long cread_alt(long *xp) {
  long *ptr = &ret;
  if (!(xp)) {
    ptr = &xp[-1];
  }
  return *ptr;
}


