
/* WARNING: Removing unreachable block (ram,0x001abf44) */

void FUN_001abf00(undefined8 param_1,undefined8 param_2,int param_3,undefined8 param_4,
                 undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  undefined8 uStack_18;
  undefined8 uStack_10;
  undefined8 uStack_8;
  
  uStack_18 = param_6;
  uStack_10 = param_7;
  uStack_8 = param_8;
  FUN_0010e778(0x2a5540,param_5,&uStack_18);
  FUN_001ac140(param_4);
  FUN_001ac390(*(undefined1 *)(param_3 * 2 + 0x245708),(&DAT_00245709)[param_3 * 2]);
  FUN_001ac110(param_1,param_2);
  FUN_001ac1a0(0x2a5540);
  FUN_001ac390(8,8);
  FUN_001ac140(0xffffffffffffffff);
  return;
}

