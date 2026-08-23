FUNCTION FUN_005ed530 @ 0x005ed530  size=256
CALLERS (1): FUN_005ed6e0@0x005ed6e0
CALLEES (3): FUN_005ed460@0x005ed460, FUN_005eced0@0x005eced0, FUN_005f2710@0x005f2710
----------------------------------------------------------------

void FUN_005ed530(short *param_1,short *param_2,short param_3,undefined8 param_4)

{
  short sVar1;
  
  if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
    if (*(char *)(iRam007012a0 + 0x186) == '\0') {
      sVar1 = FUN_005eced0(*(undefined4 *)param_4);
      *param_1 = *param_1 + *(short *)(iRam007012a0 + 0xd8c4) + sVar1;
    }
    else if ((*(short *)(iRam007012a0 + 0xd8bc) != 0) &&
            (*(ushort *)(iRam007012a0 + 0x10) < (ushort)(*param_1 + param_3))) {
      sVar1 = FUN_005ed460(param_4);
      *param_1 = sVar1;
      *param_2 = *(short *)(iRam007012a0 + 0xd8c6) + *(short *)(iRam007012a0 + 0xd8be);
    }
  }
  else {
    FUN_005f2710();
  }
  return;
}



================================================================