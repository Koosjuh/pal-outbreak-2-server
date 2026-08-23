FUNCTION FUN_00008fac @ 0x00008fac size=104
CALLERS (6): FUN_0000cf68@0x0000cf68, FUN_0000b3d8@0x0000b3d8, FUN_0000b708@0x0000b708, FUN_0000b8d0@0x0000b8d0, FUN_0000d108@0x0000d108, FUN_0000cc4c@0x0000cc4c
CALLEES (1): FUN_0000075c@0x0000075c

undefined4 FUN_00008fac(undefined1 *param_1,undefined4 param_2)

{
  short sVar1;
  undefined4 uVar2;
  undefined1 local_10;
  undefined1 local_f;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    sVar1 = FUN_0000075c(param_2,&local_10,2);
    uVar2 = 0xffffffff;
    if (1 < sVar1) {
      *param_1 = local_10;
      uVar2 = 0;
      param_1[1] = local_f;
    }
  }
  return uVar2;
}


================================================================