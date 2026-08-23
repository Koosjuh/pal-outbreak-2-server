
undefined4 FUN_001a5440(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = (uint *)(uRam0029afe8 * 0xc + 0x29b000);
  if ((int)*puVar3 < 0) {
    *puVar3 = (uint)((ulong)((long)(int)((param_1 & 0xff) << 0x10) << 0x28) >> 0x28) | 0x4a000000;
    uVar2 = uRam0029afe8 + 1;
    uRam0029afe8 = uVar2 & 0x1f;
    if (((int)uVar2 < 0) && (uRam0029afe8 != 0)) {
      uRam0029afe8 = uRam0029afe8 - 0x20;
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

