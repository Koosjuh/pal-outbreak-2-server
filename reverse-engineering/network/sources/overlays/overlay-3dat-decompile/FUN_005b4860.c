FUNCTION FUN_005b4860 @ 0x005b4860  size=492
CALLERS (1): FUN_005b41b0@0x005b41b0
CALLEES (3): FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_005b09b0@0x005b09b0
----------------------------------------------------------------

undefined4 FUN_005b4860(int param_1,int param_2,byte param_3,char param_4)

{
  int iVar1;
  long lVar2;
  
  switch(*(char *)(param_2 + 3)) {
  case '\0':
    *(char *)(param_2 + 3) = *(char *)(param_2 + 3) + '\x01';
    *(undefined4 *)(param_2 + 0x18) = 0x10;
    break;
  case '\x01':
    iVar1 = *(int *)(param_2 + 0x18) + -1;
    *(int *)(param_2 + 0x18) = iVar1;
    if (iVar1 < 0) {
      *(char *)(param_2 + 3) = *(char *)(param_2 + 3) + '\x01';
    }
    break;
  case '\x02':
    lVar2 = FUN_005b14b0(0x10);
    if (lVar2 == 0) {
      lVar2 = FUN_005b14b0(0x200);
      if (lVar2 == 0) {
        FUN_005b09b0(param_1 + 0x43c,param_3 - 1,3);
      }
      else {
        if (param_4 == '\x02') {
          return 0;
        }
        if (param_4 == '\0') {
          *(undefined1 *)(param_2 + 3) = 5;
          func_0x001b0140();
          *(undefined1 *)(param_1 + 0x443) = 1;
          *(undefined4 *)(param_2 + 0x18) = 6;
          FUN_005b9110(0x4c);
        }
        else if ((param_4 == '\x01') &&
                ((long)*(char *)(param_1 + 0x43c) != (long)(int)(param_3 - 1))) {
          func_0x001b0140();
          *(char *)(param_1 + 0x43c) = (char)(param_3 - 1);
        }
      }
    }
    else {
      *(char *)(param_2 + 3) = *(char *)(param_2 + 3) + '\x01';
      func_0x001b0140(1);
      *(undefined1 *)(param_1 + 0x43f) = 1;
      *(undefined4 *)(param_2 + 0x18) = 8;
    }
    break;
  case '\x03':
    iVar1 = *(int *)(param_2 + 0x18) + -1;
    *(int *)(param_2 + 0x18) = iVar1;
    if (iVar1 < 0) {
      *(char *)(param_2 + 3) = *(char *)(param_2 + 3) + '\x01';
      *(undefined1 *)(param_1 + 0x443) = 1;
      *(undefined4 *)(param_2 + 0x18) = 6;
      FUN_005b9110(0x4c);
    }
    break;
  case '\x04':
    iVar1 = *(int *)(param_2 + 0x18) + -1;
    *(int *)(param_2 + 0x18) = iVar1;
    if (iVar1 < 0) {
      return 1;
    }
    break;
  case '\x05':
    iVar1 = *(int *)(param_2 + 0x18) + -1;
    *(int *)(param_2 + 0x18) = iVar1;
    if (iVar1 < 0) {
      *(undefined1 *)(param_1 + 0x43c) = 0xff;
      return 1;
    }
  }
  return 0;
}



================================================================