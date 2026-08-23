FUNCTION FUN_0062c750 @ 0x0062c750  size=96
CALLERS (1): FUN_0062c350@0x0062c350
CALLEES (2): FUN_0062cb00@0x0062cb00, FUN_0062c9f0@0x0062c9f0
----------------------------------------------------------------

void FUN_0062c750(undefined8 param_1,int param_2)

{
  long lVar1;
  
  *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + -1;
  if (*(short *)(param_2 + 4) < 1) {
    *(char *)(param_2 + 1) = *(char *)(param_2 + 1) + '\x01';
    lVar1 = FUN_0062c9f0();
    if (lVar1 == 0) {
      FUN_0062cb00(param_1);
    }
    else {
      *(char *)((int)param_1 + 0x10b4) = (char)lVar1 + '\x02';
    }
  }
  return;
}



================================================================