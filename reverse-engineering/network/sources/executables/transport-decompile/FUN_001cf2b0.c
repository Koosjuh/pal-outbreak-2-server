
undefined4 FUN_001cf2b0(undefined8 param_1)

{
  undefined8 uVar1;
  undefined1 auStack_40 [64];
  
  FUN_00106b60(auStack_40,0,0x40);
  uVar1 = FUN_0010a6b0(param_1,0x2e);
  FUN_001069a8(auStack_40,param_1,(int)uVar1 - (int)param_1);
  FUN_00106b60(0x36c2d0,0,0x40);
  FUN_00109728(0x36c2d0,0x24cb68,auStack_40,(&PTR_DAT_0024c830)[bRam0034359d],uVar1);
  return 0x36c2d0;
}

