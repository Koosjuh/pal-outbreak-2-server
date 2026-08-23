FUNCTION FUN_0000550c @ 0x0000550c size=112
CALLERS (4): FUN_00002ecc@0x00002ecc, FUN_00003250@0x00003250, FUN_00007b48@0x00007b48, FUN_00007874@0x00007874
CALLEES (1): FUN_0000810c@0x0000810c

int FUN_0000550c(int param_1)

{
  int iVar1;
  
  iVar1 = (&DAT_00009720)[param_1];
  if ((iVar1 == 0) && (iVar1 = 0, (DAT_00009710 & 1) != 0)) {
    FUN_0000810c(&PTR_DAT_00008c20);
    FUN_0000810c("netdevifGetInetDevOps id %d unregisterd\n",param_1);
    iVar1 = 0;
  }
  return iVar1;
}


================================================================