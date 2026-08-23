FUNCTION FUN_005e0570 @ 0x005e0570  size=588
CALLERS (2): FUN_005dcb90@0x005dcb90, FUN_005e2fa0@0x005e2fa0
CALLEES (2): FUN_005ddb40@0x005ddb40, FUN_005e00e0@0x005e00e0
----------------------------------------------------------------

void FUN_005e0570(float param_1,float param_2,char param_3)

{
  undefined8 uVar1;
  
  if (param_3 == '\x1b') {
    uVar1 = FUN_005e00e0(0);
    FUN_005ddb40(0xffffffffffffffff,uVar1,(int)param_1,(int)param_2,0x14,0x14,0xf0,0xd0);
  }
  else if (param_3 == '\x1a') {
    uVar1 = FUN_005e00e0(0);
    FUN_005ddb40(0xffffffffffffffff,uVar1,(int)param_1,(int)param_2,0x14,0x14,0xe0,0xd0);
  }
  else if (param_3 == '\x19') {
    uVar1 = FUN_005e00e0(0);
    FUN_005ddb40(0xffffffffffffffff,uVar1,(int)param_1,(int)param_2,0x14,0x14,0xf0,0xc0);
  }
  else if (param_3 == '\x18') {
    uVar1 = FUN_005e00e0(0);
    FUN_005ddb40(0xffffffffffffffff,uVar1,(int)param_1,(int)param_2,0x14,0x14,0xe0,0xc0);
  }
  else if (param_3 == '\x01') {
    uVar1 = FUN_005e00e0(0);
    FUN_005ddb40(0xffffffffffffffff,uVar1,(int)(param_1 + -3.0),(int)(param_2 + -3.0),0x20,0x20,0xa1
                 ,0x41);
  }
  else if (param_3 == '\0') {
    uVar1 = FUN_005e00e0(0);
    FUN_005ddb40(0xffffffffffffffff,uVar1,(int)(param_1 + -3.0),(int)(param_2 + -3.0),0x20,0x20,0xc1
                 ,0x41);
  }
  return;
}



================================================================