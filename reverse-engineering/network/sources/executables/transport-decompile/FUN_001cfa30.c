
void FUN_001cfa30(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  if (cRam00343577 == '\0') {
    FUN_001cbc20((uint)bRam005a9048 * 0x80 + 0x1800);
    uRam004de3a8 = FUN_001ab460(0x80,6);
    uRam004de3b8 = 0;
    FUN_001cce80(param_3 & 0xff | (param_1 & 0xff) << 0x10 | (param_2 & 0xff) << 8,
                 0xffffffffffffffff,0x4ddba0,2);
    for (iVar1 = 0; iVar1 < (int)(uint)uRam004de3b2; iVar1 = iVar1 + 1) {
      *(undefined1 *)(iVar1 + 0x4de3e0) = 1;
    }
  }
  else {
    FUN_001a0eb0(uRam0034357a,uRam0034357c,uRam0034357e);
  }
  return;
}

