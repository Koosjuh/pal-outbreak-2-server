
void FUN_001ef400(undefined8 param_1,undefined8 param_2,uint param_3,undefined8 param_4,uint param_5
                 )

{
  uint uVar1;
  
  uVar1 = param_5 & 0xf;
  if (((int)param_5 < 0) && (uVar1 != 0)) {
    uVar1 = uVar1 - 0x10;
  }
  if (uVar1 != 0) {
    param_5 = (0x10 - uVar1) + param_5;
  }
  uVar1 = param_3 & 0xf;
  if (((int)param_3 < 0) && (uVar1 != 0)) {
    uVar1 = uVar1 - 0x10;
  }
  if (uVar1 != 0) {
    param_3 = (0x10 - uVar1) + param_3;
  }
  FUN_00115c68(0x37df10,param_1,0,0x37cf00,param_3,0x37bf00,param_5,0);
  return;
}

