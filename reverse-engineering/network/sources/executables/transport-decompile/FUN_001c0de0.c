
int FUN_001c0de0(void)

{
  if (uRam0035cc60 == 0) {
    uRam0035cc60 = 1;
  }
  else if (uRam0035cc60 == 2) {
    uRam0035cc60 = 0;
  }
  else if (uRam0035cc60 == 3) {
    uRam0035cc60 = 2;
  }
  else if (uRam0035cc60 == 1) {
    uRam0035cc60 = 3;
  }
  return -(uint)(bRam0035baa0 == uRam0035cc60);
}

