FUNCTION FUN_005ff690 @ 0x005ff690  size=196
CALLERS (1): FUN_005fe730@0x005fe730
CALLEES (4): FUN_005b6900@0x005b6900, FUN_005ff830@0x005ff830, FUN_005b68e0@0x005b68e0, FUN_005c44a0@0x005c44a0
----------------------------------------------------------------

void FUN_005ff690(undefined8 param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  cVar1 = *(char *)(iVar2 + 0x10);
  if (cVar1 == '\x03') {
    *(short *)(iVar2 + 0x16) = *(short *)(iVar2 + 0x16) + -1;
    if (*(short *)(iVar2 + 0x16) < 0) {
      FUN_005ff830(param_1,0);
    }
  }
  else if (cVar1 == '\x02') {
    *(undefined1 *)(iVar2 + 0x10) = 3;
    *(undefined1 *)(iVar2 + 0x907) = 0;
    *(undefined2 *)(iVar2 + 0x16) = 10;
  }
  else if (cVar1 == '\x01') {
    FUN_005b6900();
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(iVar2 + 0x10) = 1;
    FUN_005b68e0();
    *(undefined1 *)(iVar2 + 0x42b) = 0x18;
    FUN_005c44a0(0,0x601390);
  }
  return;
}



================================================================