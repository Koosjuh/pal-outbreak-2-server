FUNCTION FUN_005d78d0 @ 0x005d78d0  size=268
CALLERS (1): FUN_005d7f80@0x005d7f80
CALLEES (4): FUN_005d6ce0@0x005d6ce0, FUN_005d6c10@0x005d6c10, FUN_005d6a70@0x005d6a70, FUN_005d6b40@0x005d6b40
----------------------------------------------------------------

long FUN_005d78d0(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = FUN_005d6a70(iRam00701068 + 0x4f47c,param_1);
  if (lVar2 == 0) {
    lVar2 = FUN_005d6c10(iRam00701068 + 0x4f47c,param_1);
    if (lVar2 == 0) {
      uVar3 = FUN_005d6b40(iRam00701068 + 0x4f47c);
      FUN_005d6ce0(uVar3);
      lVar2 = FUN_005d6c10(iRam00701068 + 0x4f47c,param_1);
    }
    *(undefined4 *)((int)lVar2 + 0x104) = 3;
  }
  else {
    iVar1 = (int)lVar2;
    if (*(int *)(iVar1 + 0x104) == 5) {
      if ((cRam00701000 == '\x05') && (*(char *)(iVar1 + 0x108) != *param_3)) {
        FUN_005d6ce0(lVar2);
        lVar2 = 0;
      }
      else {
        *(undefined4 *)(iVar1 + 0x104) = 2;
      }
    }
    else {
      lVar2 = 0;
    }
  }
  return lVar2;
}



================================================================