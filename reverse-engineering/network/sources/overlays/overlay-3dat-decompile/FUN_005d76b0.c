FUNCTION FUN_005d76b0 @ 0x005d76b0  size=164
CALLERS (1): FUN_005cccf0@0x005cccf0
CALLEES (4): FUN_005df7b0@0x005df7b0, FUN_005d7410@0x005d7410, FUN_005d6630@0x005d6630, FUN_005d7310@0x005d7310
----------------------------------------------------------------

void FUN_005d76b0(undefined4 *param_1)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  
  iVar3 = FUN_005d6630(iRam00701068 + 0x4f694,*param_1);
  *(undefined4 *)(iVar3 + 0x104) = 4;
  *(undefined1 *)(iVar3 + 0x10c) = 1;
  *(undefined1 *)(iVar3 + 0x10d) = 2;
  uVar4 = FUN_005d7410();
  *(undefined4 *)(iVar3 + 0x110) = uVar4;
  puVar5 = (undefined1 *)FUN_005d7310();
  uVar1 = puVar5[1];
  *(undefined1 *)(iVar3 + 0x108) = *puVar5;
  *(undefined1 *)(iVar3 + 0x109) = uVar1;
  cVar2 = FUN_005df7b0(*param_1);
  if (cVar2 == '\0') {
    *(undefined4 *)(iVar3 + 0x104) = 6;
    *(undefined1 *)(iVar3 + 0x124) = 2;
    *(undefined1 *)(iVar3 + 0x125) = 0;
  }
  return;
}



================================================================