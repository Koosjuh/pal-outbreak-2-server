
void FUN_001d2970(undefined8 param_1,byte param_2,byte param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 uVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  
  pcVar6 = (char *)(param_2 + 0x4fa6f0);
  if (*pcVar6 == -1) {
    for (uVar8 = 0; ((int)uVar8 < 6 && (*(char *)(uVar8 * 0xc84 + 0x4fe481) != '\0'));
        uVar8 = uVar8 + 1) {
    }
    if (uVar8 != 6) {
      *pcVar6 = (char)uVar8;
      iVar2 = *(int *)((uint)param_2 * 8 + 0x3c18b0);
      iVar7 = uVar8 * 0xc84 + 0x4fe480;
      lVar4 = FUN_001ce6d0(iVar7,param_2,param_3,uVar8 & 0xffff);
      uVar3 = uRam003435bc;
      if (lVar4 != 1) {
        uVar5 = FUN_001cb360(*(undefined4 *)
                              ((uint)*(byte *)((uint)param_3 * 0x10 + iVar2 + 2) * 4 + 0x3c2e80),
                             uRam003435bc,0x20001,0);
        FUN_001d09e0(uVar3,iVar7,uVar5,200,0);
      }
      uVar3 = uRam003435bc;
      bVar1 = *(byte *)((uint)param_3 * 0x10 + iVar2 + 2);
      if ((bVar1 < 0x1b) &&
         (lVar4 = FUN_001cb360(*(undefined4 *)((uint)bVar1 * 4 + 0x3c3440),uRam003435bc,1,0),
         0 < lVar4)) {
        FUN_001d0a10(uVar3,uVar8 * 0x3ec + 0x4fccf0);
      }
    }
  }
  return;
}

