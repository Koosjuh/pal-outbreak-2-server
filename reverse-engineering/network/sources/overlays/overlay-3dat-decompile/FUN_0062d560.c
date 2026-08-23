FUNCTION FUN_0062d560 @ 0x0062d560  size=124
CALLERS (1): FUN_005aec70@0x005aec70
CALLEES (1): FUN_005aec20@0x005aec20
----------------------------------------------------------------

void FUN_0062d560(undefined8 param_1,long param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if (param_2 == 0) {
    *(undefined1 *)(iVar1 + 1) = 0;
    *(undefined1 *)(iVar1 + 0xe) = 3;
    *(undefined1 *)(iVar1 + 0xf) = 3;
    *(undefined1 *)(iVar1 + 0x10) = 0;
    *(undefined1 *)(iVar1 + 0x11) = 0;
  }
  else {
    *(undefined1 *)(iVar1 + 1) = 0;
    *(undefined1 *)(iVar1 + 0xe) = 3;
    *(undefined1 *)(iVar1 + 0xf) = 2;
    *(undefined1 *)(iVar1 + 0x10) = 0;
    *(undefined1 *)(iVar1 + 0x11) = 0;
    *(undefined1 *)(iVar1 + 0x443) = 1;
    *(undefined1 *)(iVar1 + 0x4b7) = 1;
  }
  FUN_005aec20(param_1);
  *(undefined1 *)(iVar1 + 0x45d) = 2;
  *(undefined1 *)(iVar1 + 0x146b) = 0;
  return;
}



================================================================