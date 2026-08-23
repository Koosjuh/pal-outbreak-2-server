FUNCTION FUN_0001748c @ 0x0001748c size=172
CALLERS (1): FUN_0000eab8@0x0000eab8
CALLEES (4): FUN_00012c60@0x00012c60, FUN_0000d8cc@0x0000d8cc, FUN_00012e20@0x00012e20, FUN_000100c4@0x000100c4

void FUN_0001748c(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_0001b9a0;
  while (iVar1 = iVar2, iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 4);
    if (param_1 == *(int *)(iVar1 + 0xc)) {
      FUN_00012e20(*(undefined4 *)(iVar1 + 0xdc));
      *(undefined4 *)(iVar1 + 0xc) = 0;
      *(undefined4 *)(iVar1 + 0x30) = 0xfffffe09;
      if (*(int *)(iVar1 + 0x28) == 10) {
        FUN_00012c60(iVar1);
      }
      else {
        *(undefined4 *)(iVar1 + 0x28) = 0;
        FUN_0000d8cc(iVar1 + 0xcc);
        FUN_000100c4();
      }
    }
  }
  return;
}


================================================================