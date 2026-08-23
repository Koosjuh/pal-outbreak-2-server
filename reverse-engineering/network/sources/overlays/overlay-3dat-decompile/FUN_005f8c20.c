FUNCTION FUN_005f8c20 @ 0x005f8c20  size=212
CALLERS (3): FUN_005aec70@0x005aec70, FUN_005f8fc0@0x005f8fc0, FUN_005f9540@0x005f9540
CALLEES (3): FUN_00637180@0x00637180, FUN_005b9110@0x005b9110, FUN_005aec20@0x005aec20
----------------------------------------------------------------

void FUN_005f8c20(undefined8 param_1,long param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if (param_2 == 3) {
    *(undefined1 *)(iVar1 + 0xe) = 4;
    *(undefined1 *)(iVar1 + 0xf) = 2;
    *(undefined1 *)(iVar1 + 0x10) = 2;
    *(undefined1 *)(iVar1 + 0x11) = 0;
  }
  else if (param_2 == 2) {
    *(undefined1 *)(iVar1 + 0xe) = 4;
    *(undefined1 *)(iVar1 + 0xf) = 2;
    *(undefined1 *)(iVar1 + 0x10) = 0;
    *(undefined1 *)(iVar1 + 0x11) = 0;
  }
  else if (param_2 == 1) {
    *(undefined1 *)(iVar1 + 0xe) = 4;
    *(undefined1 *)(iVar1 + 0xf) = 3;
    *(undefined1 *)(iVar1 + 0x10) = 0;
    *(undefined1 *)(iVar1 + 0x11) = 0;
  }
  else {
    if (param_2 != 0) {
      *(undefined1 *)(iVar1 + 1) = 0;
      goto LAB_005f8cb8;
    }
    *(undefined1 *)(iVar1 + 0xe) = 4;
    *(undefined1 *)(iVar1 + 0xf) = 0;
    *(undefined1 *)(iVar1 + 0x10) = 2;
    *(undefined1 *)(iVar1 + 0x11) = 0;
  }
  *(undefined1 *)(iVar1 + 1) = 0;
LAB_005f8cb8:
  *(undefined1 *)(iVar1 + 0x992) = 0;
  FUN_005aec20(param_1);
  FUN_005b9110(0x4c);
  *(undefined1 *)(iVar1 + 0x443) = 1;
  *(undefined1 *)(iVar1 + 0x45c) = 2;
  *(undefined1 *)(iVar1 + 0x45d) = 2;
  FUN_00637180();
  return;
}



================================================================