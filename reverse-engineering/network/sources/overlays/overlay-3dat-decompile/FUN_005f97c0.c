FUNCTION FUN_005f97c0 @ 0x005f97c0  size=500
CALLERS (1): FUN_005f9150@0x005f9150
CALLEES (5): FUN_00637180@0x00637180, FUN_006345e0@0x006345e0, FUN_00634ab0@0x00634ab0, FUN_006371d0@0x006371d0, FUN_00632ce0@0x00632ce0
----------------------------------------------------------------

void FUN_005f97c0(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x10);
  if (cVar1 == '\x03') {
    cVar1 = FUN_00634ab0(0x6970a2,uRam006c4610,uRam006c4618 | uRam006c4620);
    if ((cVar1 == -1) || (cVar1 == '\x01')) {
      *(undefined1 *)(param_1 + 0xf) = 2;
      *(undefined1 *)(param_1 + 0x10) = 0;
      FUN_00637180();
    }
  }
  else if (cVar1 == '\x02') {
    cVar1 = FUN_00634ab0(0x6970b2,uRam006c4610,uRam006c4618 | uRam006c4620);
    if ((cVar1 == -1) || (cVar1 == '\x01')) {
      FUN_00632ce0(0x6970b2);
      *(undefined1 *)(param_1 + 0xf) = 2;
      *(undefined1 *)(param_1 + 0x10) = 0;
      FUN_00637180();
    }
  }
  else if (cVar1 == '\x01') {
    cVar1 = *(char *)(param_1 + 0x908);
    if (cVar1 == '\n') {
      *(undefined1 *)(param_1 + 0xf) = 4;
      *(undefined1 *)(param_1 + 0x10) = 0;
    }
    else if (cVar1 == '\x01') {
      *(undefined1 *)(param_1 + 0x10) = 3;
      FUN_006371d0(0x42980000,0x118);
      FUN_006345e0(1,0,8,0x6970a2);
    }
    else if (cVar1 == '\0') {
      *(undefined1 *)(param_1 + 0x10) = 2;
      FUN_006371d0(0x42980000,0x118);
      FUN_006345e0(2,0,0xf,0x6970b2);
    }
  }
  else if ((cVar1 == '\0') &&
          (*(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + -1,
          *(short *)(param_1 + 0x16) < 0)) {
    *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
  }
  return;
}



================================================================