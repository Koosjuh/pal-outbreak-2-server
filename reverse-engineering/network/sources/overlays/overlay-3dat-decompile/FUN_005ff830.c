FUNCTION FUN_005ff830 @ 0x005ff830  size=148
CALLERS (2): FUN_005aec70@0x005aec70, FUN_005ff690@0x005ff690
CALLEES (4): FUN_00637180@0x00637180, FUN_005b1d10@0x005b1d10, FUN_005f4b70@0x005f4b70, FUN_005aec20@0x005aec20
----------------------------------------------------------------

void FUN_005ff830(undefined8 param_1,long param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if (param_2 == 0) {
    *(undefined1 *)(iVar1 + 1) = 0;
    *(undefined1 *)(iVar1 + 0xe) = 0;
    *(undefined1 *)(iVar1 + 0xf) = 8;
    *(undefined1 *)(iVar1 + 0x10) = 2;
    *(undefined1 *)(iVar1 + 0x11) = 0;
  }
  else {
    *(undefined1 *)(iVar1 + 1) = 0;
    *(undefined1 *)(iVar1 + 0xe) = 0;
    *(undefined1 *)(iVar1 + 0xf) = 8;
    *(undefined1 *)(iVar1 + 0x10) = 0;
    *(undefined1 *)(iVar1 + 0x11) = 0;
    *(undefined1 *)(iVar1 + 0x443) = 1;
  }
  FUN_005aec20(param_1);
  FUN_005f4b70();
  FUN_005b1d10(param_1);
  *(undefined1 *)(iVar1 + 0x43d) = 0x4c;
  *(undefined1 *)(iVar1 + 0x43e) = 0;
  FUN_00637180();
  *(undefined1 *)(iVar1 + 0x45d) = 2;
  return;
}



================================================================