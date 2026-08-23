FUNCTION FUN_00001cb0 @ 0x00001cb0 size=92
CALLERS (1): FUN_000054a8@0x000054a8
CALLEES (2): FUN_000020c4@0x000020c4, FUN_00004f20@0x00004f20

int FUN_00001cb0(undefined4 param_1,short param_2,short param_3,short param_4,short param_5,
                short param_6)

{
  short sVar1;
  
  sVar1 = FUN_000020c4((int)param_2,(int)param_3,(int)param_4,(int)param_5,(int)param_6);
  FUN_00004f20(0x82);
  return (int)sVar1;
}


================================================================