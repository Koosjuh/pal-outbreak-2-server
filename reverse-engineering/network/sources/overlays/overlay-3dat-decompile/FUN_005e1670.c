FUNCTION FUN_005e1670 @ 0x005e1670  size=820
CALLERS (5): FUN_005e5200@0x005e5200, FUN_005e5650@0x005e5650, FUN_005e4f10@0x005e4f10, FUN_005dc010@0x005dc010, FUN_005e4b00@0x005e4b00
CALLEES (2): FUN_005ddb40@0x005ddb40, FUN_005e00e0@0x005e00e0
----------------------------------------------------------------

void FUN_005e1670(float param_1,float param_2,float param_3,float param_4)

{
  undefined8 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar3 = (param_3 - param_1) - 64.0;
  fVar4 = (param_4 - param_2) - 64.0;
  uVar1 = FUN_005e00e0(0);
  FUN_005ddb40(0xffffffffffffffff,uVar1,(int)param_1,(int)param_2,0x20,0x20,2,2);
  fVar2 = param_1 + 32.0;
  uVar1 = FUN_005e00e0(0);
  FUN_005ddb40(0xffffffffffffffff,uVar1,(int)fVar2,(int)param_2,(int)fVar3,0x20,0x22,2);
  uVar1 = FUN_005e00e0(0);
  FUN_005ddb40(0xffffffffffffffff,uVar1,(int)(param_3 - 32.0),(int)param_2,0x20,0x20);
  param_2 = param_2 + 32.0;
  uVar1 = FUN_005e00e0(0);
  FUN_005ddb40(0xffffffffffffffff,uVar1,(int)param_1,(int)param_2,0x20,(int)fVar4,2,0x18);
  uVar1 = FUN_005e00e0(0);
  FUN_005ddb40(0xffffffffffffffff,uVar1,(int)fVar2,(int)param_2,(int)fVar3,(int)fVar4,0x18,0x18);
  uVar1 = FUN_005e00e0(0);
  FUN_005ddb40(0xffffffffffffffff,uVar1,(int)(param_3 - 32.0),(int)param_2,0x20,(int)fVar4,0x22,0x1a
              );
  uVar1 = FUN_005e00e0(0);
  FUN_005ddb40(0xffffffffffffffff,uVar1,(int)param_1,(int)(param_4 - 32.0),0x20,0x20);
  uVar1 = FUN_005e00e0(0);
  FUN_005ddb40(0xffffffffffffffff,uVar1,(int)fVar2,(int)(param_4 - 32.0),(int)fVar3,0x20,0x22,0x22);
  uVar1 = FUN_005e00e0(0);
  FUN_005ddb40(0xffffffffffffffff,uVar1,(int)(param_3 - 32.0),(int)(param_4 - 32.0),0x20,0x20,0x22,
               0x22);
  return;
}



================================================================