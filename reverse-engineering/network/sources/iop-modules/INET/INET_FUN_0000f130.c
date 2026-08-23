FUNCTION FUN_0000f130 @ 0x0000f130 size=336
CALLERS (0): 
CALLEES (7): FUN_0000d3d4@0x0000d3d4, FUN_0000ae24@0x0000ae24, FUN_000199b4@0x000199b4, FUN_0000cdd4@0x0000cdd4, FUN_0000a9c0@0x0000a9c0, FUN_0000d41c@0x0000d41c, FUN_0000bdb0@0x0000bdb0

int FUN_0000f130(uint param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_28 [2];
  
  iVar2 = 0;
  local_28[0] = 0;
  if (param_3 != 0) {
    uVar3 = 0;
    if ((param_1 & 0x80) != 0) {
      uVar3 = param_6;
    }
    if (((param_1 & 1) != 0) || (iVar1 = FUN_0000bdb0(local_28,param_3), iVar1 == 0)) {
      if (((param_1 & 2) == 0) && (iVar1 = FUN_000199b4("localhost",param_3), iVar1 == 0)) {
        local_28[0] = 0x7f000001;
      }
      else {
        iVar2 = -0x200;
        if ((param_1 & 4) == 0) {
          iVar1 = FUN_0000d3d4();
          if (iVar1 == 0) {
            iVar2 = FUN_0000cdd4(local_28,param_3,param_4,param_5,0xffffffff,uVar3,param_1 >> 6 & 1)
            ;
            FUN_0000d41c();
          }
        }
      }
    }
  }
  if (iVar2 == 0) {
    FUN_0000ae24(param_2,0x10);
    FUN_0000a9c0(local_28,param_2 + 4,4);
  }
  return iVar2;
}


================================================================