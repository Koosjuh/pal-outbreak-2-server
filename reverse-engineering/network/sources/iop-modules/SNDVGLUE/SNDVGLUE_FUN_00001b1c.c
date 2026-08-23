FUNCTION FUN_00001b1c @ 0x00001b1c size=248
CALLERS (0): 
CALLEES (4): FUN_000080bc@0x000080bc, FUN_000081e8@0x000081e8, FUN_000080c4@0x000080c4, FUN_0000810c@0x0000810c

undefined4 FUN_00001b1c(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_18 [2];
  
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_000083f0);
    FUN_0000810c("sceModemUnregisterDevice():\n");
  }
  FUN_000080bc(local_18);
  iVar3 = 0;
  FUN_000081e8(*(undefined4 *)(param_1 + 0x3c));
  piVar2 = &DAT_00009718;
  do {
    iVar1 = *piVar2;
    if (iVar1 == param_1) {
      if (*(int *)(iVar1 + 0x5c) == 0) {
        *piVar2 = 0;
        DAT_000096e0 = 1;
        DAT_000096e4 = DAT_000096e4 + -1;
      }
      else {
        *(undefined4 *)(iVar1 + 0x60) = 1;
      }
      break;
    }
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar3 < 2);
  FUN_000080c4(local_18[0]);
  if (iVar3 < 2) {
    FUN_0000810c("  Unregister ModemDev [%d]\n",iVar3);
  }
  return 0;
}


================================================================