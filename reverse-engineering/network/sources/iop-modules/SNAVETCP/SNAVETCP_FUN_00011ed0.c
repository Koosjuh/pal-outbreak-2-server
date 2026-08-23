FUNCTION FUN_00011ed0 @ 0x00011ed0 size=132
CALLERS (0): 
CALLEES (3): FUN_00014f34@0x00014f34, FUN_00014f3c@0x00014f3c, FUN_00011e30@0x00011e30

undefined4 FUN_00011ed0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_58 [8];
  undefined4 local_50;
  undefined4 local_3c;
  
  uVar1 = FUN_00011e30();
  iVar2 = FUN_00014f34(uVar1,auStack_58);
  if (iVar2 == -100) {
    uVar1 = FUN_00011e30(param_1);
    FUN_00014f3c(uVar1,auStack_58);
  }
  *param_2 = local_3c;
  *param_3 = local_50;
  return 0;
}


================================================================