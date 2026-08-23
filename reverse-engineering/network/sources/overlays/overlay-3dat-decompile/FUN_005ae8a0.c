FUNCTION FUN_005ae8a0 @ 0x005ae8a0  size=264
CALLERS (1): FUN_005ae770@0x005ae770
CALLEES (7): FUN_00637180@0x00637180, FUN_00618800@0x00618800, FUN_005aeb10@0x005aeb10, FUN_005b6900@0x005b6900, FUN_005b9110@0x005b9110, FUN_005b68e0@0x005b68e0, FUN_005bb0b0@0x005bb0b0
----------------------------------------------------------------

void FUN_005ae8a0(int param_1)

{
  char cVar1;
  long lVar2;
  
  cVar1 = *(char *)(param_1 + 0x5198);
  if (cVar1 == '\x03') {
    FUN_005aeb10();
    if (bRam006c45f8 == 0) {
      *(undefined1 *)(param_1 + 0x5196) = 0;
      *(undefined1 *)(param_1 + 0x5197) = 0;
      *(undefined1 *)(param_1 + 0x5198) = 0;
    }
    else {
      lVar2 = FUN_005bb0b0(bRam006c45f8 - 1);
      if (lVar2 == 0) {
        *(undefined1 *)(param_1 + 0x5196) = 0;
        *(undefined1 *)(param_1 + 0x5197) = 0;
        *(undefined1 *)(param_1 + 0x5198) = 0;
      }
      else {
        FUN_005b9110(0x4c);
        FUN_00637180();
        *(char *)(param_1 + 0x5197) = *(char *)(param_1 + 0x5197) + '\x01';
        *(undefined1 *)(param_1 + 0x5198) = 0;
        *(undefined2 *)(param_1 + 0x519a) = 0;
      }
    }
  }
  else if (cVar1 == '\x02') {
    FUN_005b6900();
  }
  else if (cVar1 == '\x01') {
    *(undefined1 *)(param_1 + 0x5198) = 2;
    FUN_005b68e0();
    FUN_00618800(iRam003435d4 + 0x8000,0x5aebf0);
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0x5198) = 1;
  }
  return;
}



================================================================