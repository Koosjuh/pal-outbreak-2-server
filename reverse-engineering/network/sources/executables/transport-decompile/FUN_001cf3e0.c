
void FUN_001cf3e0(undefined8 param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint unaff_s2_lo;
  
  iVar2 = (int)param_1;
  uVar4 = (uint)*(byte *)(iVar2 + 0x549);
  uVar3 = param_2 & 0xff;
  if (cRam00343577 == '\0') {
    if (*(short *)(iVar2 + 0xbc8) == 0) {
      unaff_s2_lo = 0;
      if (uVar4 == 1) {
        FUN_001cbc20((uint)*(byte *)(iVar2 + 3) * 8 + 0x1100);
      }
      else {
        FUN_001cbc20((uint)*(byte *)(iVar2 + 3) * 8 + 0x1000);
      }
    }
    else {
      unaff_s2_lo = 0;
      if (uVar4 == 1) {
        FUN_001cbc20((uint)*(byte *)(iVar2 + 3) * 8 + 0x1100);
      }
      else {
        FUN_001cbc20((uint)*(byte *)(iVar2 + 3) * 8 + 0x1000);
        uVar3 = *(ushort *)(iVar2 + 0xbc8) - 1 | 0x8000;
      }
    }
  }
  FUN_001cf360();
  if (uVar4 == 1) {
    unaff_s2_lo = unaff_s2_lo + 1;
  }
  iVar2 = (uint)*(byte *)(iVar2 + 3) * 0x1468;
  uVar1 = FUN_001ab460(0x20,unaff_s2_lo | (param_2 & 0xff) << 0x10);
  *(undefined4 *)(iVar2 + 0x4ee098) = uVar1;
  *(int *)(iVar2 + 0x4ed890) = iVar2 + 0x4ee0b0;
  *(int *)(iVar2 + 0x4ed894) = iVar2 + 0x4ee2b0;
  *(int *)(iVar2 + 0x4ee0a8) = iVar2 + 0x4ee4b0;
  if ((cRam00343577 == '\0') &&
     (FUN_001cce80((param_3 & 0xff) << 0x10 | uVar3,0xffffffffffffffff,(int *)(iVar2 + 0x4ed890),
                   uVar4 << 0x1d | 2), uVar4 == 1)) {
    FUN_001cf570(param_1,param_2);
  }
  return;
}

