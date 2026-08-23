FUNCTION FUN_00004284 @ 0x00004284 size=140
CALLERS (2): FUN_00002ecc@0x00002ecc, FUN_00007b48@0x00007b48
CALLEES (3): FUN_000080bc@0x000080bc, FUN_0000810c@0x0000810c, FUN_000080c4@0x000080c4

void FUN_00004284(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 local_18 [2];
  
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_00008c20);
    FUN_0000810c("sceInetPktEnQ()   %08x\n",param_2);
  }
  FUN_000080bc(local_18);
  puVar1 = (undefined4 *)param_1[1];
  param_2[1] = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    *param_1 = param_2;
  }
  else {
    *puVar1 = param_2;
  }
  *param_2 = 0;
  param_1[1] = param_2;
  FUN_000080c4(local_18[0]);
  return;
}


================================================================