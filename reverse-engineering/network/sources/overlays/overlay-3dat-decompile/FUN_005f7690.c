FUNCTION FUN_005f7690 @ 0x005f7690  size=96
CALLERS (2): FUN_005aec70@0x005aec70, FUN_005f7c80@0x005f7c80
CALLEES (2): FUN_005b9110@0x005b9110, FUN_005aec20@0x005aec20
----------------------------------------------------------------

void FUN_005f7690(undefined8 param_1,long param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(undefined1 *)(iVar1 + 1) = 0;
  *(undefined1 *)(iVar1 + 0xe) = 3;
  if (param_2 == 0) {
    *(undefined1 *)(iVar1 + 0xf) = 0;
    *(undefined1 *)(iVar1 + 0x10) = 2;
  }
  else {
    *(undefined1 *)(iVar1 + 0xf) = 0;
    *(undefined1 *)(iVar1 + 0x10) = 0;
  }
  FUN_005aec20(param_1);
  FUN_005b9110(0x4c);
  *(undefined1 *)(iVar1 + 0x45b) = 2;
  return;
}



================================================================