FUNCTION FUN_005b6300 @ 0x005b6300  size=336
CALLERS (0): 
CALLEES (1): FUN_00618890@0x00618890
----------------------------------------------------------------

void FUN_005b6300(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char cStack_18;
  undefined4 *puStack_8;
  byte bStack_1;
  
  if (cRam006c4b90 != '\x06') {
    cStack_18 = (char)*param_1;
    if (cStack_18 == '\0') {
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
      func_0x00106b60(uRam003435d4,0,0x8000);
      for (iVar2 = 0; iVar2 < (int)(uint)bStack_1; iVar2 = iVar2 + 1) {
        func_0x001069a8(*(undefined4 *)(iVar2 * 4 + 0x6c5480),uRam00697028,uRam00697020);
      }
      uRam006c4ba0 = 0;
      cRam006c4b9f = cRam006c4b9f + '\x01';
    }
    else if (cStack_18 == -1) {
      uRam006c4ba0 = 0;
      cRam006c4b9f = cRam006c4b9f + '\x01';
    }
  }
  return;
}



================================================================