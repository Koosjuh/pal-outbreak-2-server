FUNCTION FUN_005b45f0 @ 0x005b45f0  size=424
CALLERS (2): FUN_005b3ed0@0x005b3ed0, FUN_005b41b0@0x005b41b0
CALLEES (9): FUN_00637180@0x00637180, FUN_005ba7b0@0x005ba7b0, FUN_006345e0@0x006345e0, FUN_00618b60@0x00618b60, FUN_005ba570@0x005ba570, FUN_005f5c10@0x005f5c10, FUN_00634ab0@0x00634ab0, FUN_006371d0@0x006371d0, FUN_005b4c80@0x005b4c80
----------------------------------------------------------------

undefined4 FUN_005b45f0(int param_1,undefined1 param_2)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *(char *)(param_1 + 3);
  if (cVar1 == '\x03') {
    iVar2 = *(int *)(param_1 + 0x18) + -1;
    *(int *)(param_1 + 0x18) = iVar2;
    if (iVar2 < 0) {
      return 1;
    }
  }
  else if (cVar1 == '\x02') {
    cVar1 = FUN_00634ab0(*(char *)(param_1 + 7) * 0x14 + 0x6c4674,uRam006c4610,
                         uRam006c4618 | uRam006c4620);
    if ((cVar1 == -1) || (cVar1 == '\x01')) {
      FUN_005f5c10(*(char *)(param_1 + 7) * 0x14 + 0x6c4674,0x14);
      *(char *)(param_1 + 3) = *(char *)(param_1 + 3) + '\x01';
      *(undefined4 *)(param_1 + 0x18) = 2;
      FUN_00637180();
    }
  }
  else if (cVar1 == '\x01') {
    *(undefined1 *)(param_1 + 3) = 2;
    FUN_006371d0(0x42980000,0x118);
    FUN_006345e0(1,0,0x10,*(char *)(param_1 + 7) * 0x14 + 0x6c4674);
  }
  else {
    if (cVar1 != '\0') {
      return 0;
    }
    *(undefined1 *)(param_1 + 3) = 1;
    FUN_00618b60();
    FUN_005b4c80(param_2);
    FUN_005ba570(0x20);
    FUN_005ba7b0();
  }
  return 0;
}



================================================================