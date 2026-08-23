FUNCTION FUN_00002530 @ 0x00002530 size=84
CALLERS (1): FUN_00010800@0x00010800
CALLEES (2): FUN_00002d58@0x00002d58, FUN_0000fc50@0x0000fc50

int FUN_00002530(int param_1)

{
  short sVar1;
  
  sVar1 = FUN_0000fc50();
  if ((sVar1 == 0) && (param_1 != 0)) {
    FUN_00002d58(param_1);
  }
  return (int)sVar1;
}


================================================================