FUNCTION FUN_00011fac @ 0x00011fac size=148
CALLERS (2): FUN_00011da8@0x00011da8, FUN_00012608@0x00012608
CALLEES (2): FUN_00014f64@0x00014f64, FUN_00014f6c@0x00014f6c

undefined4 FUN_00011fac(undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_20 [8];
  int local_18;
  int local_14;
  
  iVar1 = FUN_00014f64(auStack_20);
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    FUN_00014f6c(auStack_20,&local_18,&local_14);
    *param_1 = 0;
    uVar2 = 0;
    *param_2 = local_18 * 1000 + local_14 / 1000;
  }
  return uVar2;
}


================================================================