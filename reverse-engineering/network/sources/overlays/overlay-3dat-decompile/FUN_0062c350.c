FUNCTION FUN_0062c350 @ 0x0062c350  size=152
CALLERS (1): FUN_0062ba70@0x0062ba70
CALLEES (6): FUN_0062c750@0x0062c750, FUN_0062c580@0x0062c580, FUN_0062c870@0x0062c870, FUN_0062c7b0@0x0062c7b0, FUN_0062c3f0@0x0062c3f0, FUN_0062c970@0x0062c970
----------------------------------------------------------------

undefined8 FUN_0062c350(undefined8 param_1,int param_2)

{
  switch(*(undefined1 *)(param_2 + 1)) {
  case 0:
    FUN_0062c3f0();
    break;
  case 1:
    FUN_0062c580();
    break;
  case 2:
    FUN_0062c750();
    break;
  case 3:
    FUN_0062c7b0();
    break;
  case 4:
    FUN_0062c870();
    break;
  case 5:
    FUN_0062c970();
  }
  return 0;
}



================================================================