
undefined4 FUN_001a9c30(void)

{
  undefined4 uVar1;
  
  if (sRam0052d610 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *puRam0052c400;
    *puRam0052c400 = 0;
    puRam0052c400 = puRam0052c400 + 1;
    sRam0052d610 = sRam0052d610 + -1;
  }
  return uVar1;
}

