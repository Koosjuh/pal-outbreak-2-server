
undefined4 FUN_001ca6b0(long param_1,long param_2,ulong param_3,undefined8 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 extraout_a3;
  int extraout_t0_lo;
  undefined8 extraout_t0;
  int extraout_t1_lo;
  undefined8 extraout_t1;
  int extraout_t2_lo;
  int extraout_t2_lo_00;
  undefined8 extraout_t2;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar1 = 0xffffffff;
  }
  else {
    FUN_001ca660(param_2,4,param_3,param_4,param_3 & 0xffff);
    iVar2 = FUN_001ca660(extraout_t1_lo + 4);
    FUN_001ca610(extraout_t2,extraout_t1,5,extraout_a3,extraout_t0_lo + iVar2);
    FUN_001ca610(extraout_t2_lo + 5,extraout_t0);
    *(undefined1 *)(extraout_t2_lo_00 + 10) = 0;
    uVar1 = 0;
  }
  return uVar1;
}

