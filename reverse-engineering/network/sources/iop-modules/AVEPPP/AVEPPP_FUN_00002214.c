FUNCTION FUN_00002214 @ 0x00002214 size=88
CALLERS (2): FUN_00008270@0x00008270, FUN_00007fb4@0x00007fb4
CALLEES (2): FUN_00010c38@0x00010c38, FUN_00010bc0@0x00010bc0

undefined4 FUN_00002214(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00010bc0(param_2,param_1);
  uVar2 = 0;
  if ((iVar1 != 0) && (uVar2 = 0xffffffff, (DAT_00012efc & 1) != 0)) {
    FUN_00010c38("aveppp: PP_ComWrite return (ERROR)\n");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


================================================================