FUNCTION FUN_00011514 @ 0x00011514 size=220
CALLERS (1): FUN_00000200@0x00000200
CALLEES (3): FUN_00001454@0x00001454, FUN_000013ac@0x000013ac, FUN_000010c0@0x000010c0

undefined4 FUN_00011514(undefined4 param_1,int param_2,short param_3)

{
  int iVar1;
  short sVar2;
  short sVar3;
  undefined1 auStack_20 [8];
  
  FUN_000013ac(auStack_20,param_1);
  sVar3 = 0;
  for (; param_3 != 0; param_3 = param_3 - sVar2) {
    iVar1 = param_2 + sVar3 * 0xc;
    sVar2 = param_3;
    if (-1 < (int)param_3 - (int)*(short *)(iVar1 + 8)) {
      sVar2 = *(short *)(iVar1 + 8);
    }
    FUN_000010c0(auStack_20,sVar3 * 0xc + param_2 + 0xc,(int)sVar2);
    FUN_00001454(auStack_20,(int)sVar2);
    sVar3 = sVar3 + 1;
  }
  return 0;
}


================================================================