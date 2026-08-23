FUNCTION FUN_005aeb10 @ 0x005aeb10  size=216
CALLERS (1): FUN_005ae8a0@0x005ae8a0
CALLEES (1): FUN_00618890@0x00618890
----------------------------------------------------------------

void FUN_005aeb10(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puStack_8;
  byte bStack_1;
  
  FUN_00618890(&bStack_1,&puStack_8);
  for (iVar2 = 0; iVar2 < (int)(uint)bStack_1; iVar2 = iVar2 + 1) {
    iVar1 = iVar2 * 0xc;
    uVar3 = puStack_8[1];
    uVar4 = puStack_8[2];
    *(undefined4 *)(iVar1 + 0x697020) = *puStack_8;
    *(undefined4 *)(iVar1 + 0x697024) = uVar3;
    *(undefined4 *)(iVar1 + 0x697028) = uVar4;
    puStack_8 = puStack_8 + 3;
  }
  func_0x001069a8(uRam006c5484,uRam006c5480,0x177c);
  uVar4 = uRam006c5480;
  uVar3 = uRam00697028;
  func_0x00106b60(uRam006c5480,0,uRam00697020);
  func_0x001069a8(uVar4,uVar3,uRam00697020);
  return;
}



================================================================