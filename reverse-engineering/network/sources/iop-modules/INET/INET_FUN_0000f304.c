FUNCTION FUN_0000f304 @ 0x0000f304 size=264
CALLERS (0): 
CALLEES (5): FUN_0000d3d4@0x0000d3d4, FUN_0000e180@0x0000e180, FUN_0000cdd4@0x0000cdd4, FUN_0000a9c0@0x0000a9c0, FUN_0000d41c@0x0000d41c

int FUN_0000f304(uint param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_28 [8];
  
  uVar3 = 0;
  if ((param_1 & 0x80) != 0) {
    uVar3 = param_7;
  }
  iVar1 = FUN_0000e180(param_4);
  iVar2 = -0x200;
  if ((((iVar1 == 0) && (param_2 != 0)) && (0 < param_3)) && ((param_1 & 4) == 0)) {
    iVar2 = FUN_0000d3d4();
    if (iVar2 == 0) {
      FUN_0000a9c0(param_4 + 4,auStack_28,4);
      iVar2 = FUN_0000cdd4(auStack_28,param_2,param_5,param_6,param_3,uVar3,param_1 >> 6 & 1);
      FUN_0000d41c();
    }
  }
  return iVar2;
}


================================================================