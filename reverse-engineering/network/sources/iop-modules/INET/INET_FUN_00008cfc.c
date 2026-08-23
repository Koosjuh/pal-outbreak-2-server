FUNCTION FUN_00008cfc @ 0x00008cfc size=104
CALLERS (1): FUN_00017e68@0x00017e68
CALLEES (2): FUN_00008bb8@0x00008bb8, FUN_0000a7e0@0x0000a7e0

void FUN_00008cfc(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*(int *)(param_1 + 0xc);
  while (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    FUN_00008bb8(piVar1);
    FUN_0000a7e0(piVar1);
    piVar1 = (int *)iVar2;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}


================================================================