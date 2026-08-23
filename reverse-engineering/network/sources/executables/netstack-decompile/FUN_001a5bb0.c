
undefined4 FUN_001a5bb0(long param_1,undefined1 param_2)

{
  undefined4 uVar1;
  byte bVar2;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffff;
  }
  else if (cRam003435b5 == '\x02') {
    uVar1 = 0xffffffff;
  }
  else if (bRam0029f2f1 < 8) {
    bVar2 = bRam0029f2f3 + 1;
    if (7 < bVar2) {
      bVar2 = 0;
    }
    *(undefined2 *)((uint)bRam0029f2f3 * 2 + 0x29f304) = 0;
    *(undefined1 *)(bRam0029f2f3 + 0x29f2fc) = param_2;
    FUN_001069a8((uint)bRam0029f2f3 * 0x10 + 0x29f314,param_1,0x10);
    *(undefined1 *)((uint)bRam0029f2f3 * 0x10 + 0x29f323) = 0;
    bRam0029f2f1 = bRam0029f2f1 + 1;
    uVar1 = 0;
    bRam0029f2f3 = bVar2;
    if (cRam0029f2f0 == '\0') {
      cRam0029f2f0 = '\x01';
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

