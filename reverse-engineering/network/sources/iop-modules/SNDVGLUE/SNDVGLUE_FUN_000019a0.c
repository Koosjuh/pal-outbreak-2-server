FUNCTION FUN_000019a0 @ 0x000019a0 size=380
CALLERS (0): 
CALLEES (4): FUN_000081e0@0x000081e0, FUN_000080bc@0x000080bc, FUN_000080c4@0x000080c4, FUN_0000810c@0x0000810c

undefined4 FUN_000019a0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_18 [2];
  
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_000083f0);
    FUN_0000810c("sceModemRegisterDevice():\n");
  }
  FUN_000080bc(local_18);
  iVar3 = 0;
  iVar2 = 0;
  do {
    if (*(int *)((int)&DAT_00009718 + iVar2) == 0) {
      *(int *)((int)&DAT_00009718 + iVar2) = param_1;
      DAT_000096e0 = 1;
      DAT_000096e4 = DAT_000096e4 + 1;
      break;
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar3 * 4;
  } while (iVar3 < 2);
  if (iVar3 < 2) {
    local_28 = 2;
    local_20 = 0;
    local_24 = 0;
    uVar1 = FUN_000081e0(&local_28);
    *(undefined4 *)(param_1 + 0x3c) = uVar1;
    *(undefined4 *)(param_1 + 0x5c) = 0;
    *(undefined4 *)(param_1 + 0x60) = 0;
    *(undefined4 *)(param_1 + 100) = 0;
    FUN_000080c4(local_18[0]);
    FUN_0000810c("  Register ModemDev [%d]\n",iVar3);
    FUN_0000810c("    module_name %s\n",*(undefined4 *)(param_1 + 8));
    FUN_0000810c("    vendor_name %s\n",*(undefined4 *)(param_1 + 0xc));
    FUN_0000810c("    device_name %s\n",*(undefined4 *)(param_1 + 0x10));
    uVar1 = 0;
  }
  else {
    FUN_000080c4(local_18[0]);
    uVar1 = 0xffffffff;
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_000083f0);
      FUN_0000810c("sceModemRegisterNetDevice(): error\n");
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}


================================================================