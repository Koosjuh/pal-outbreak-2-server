FUNCTION FUN_00003b2c @ 0x00003b2c size=152
CALLERS (0): 
CALLEES (2): FUN_00002df0@0x00002df0, FUN_0000810c@0x0000810c

int FUN_00003b2c(short param_1)

{
  short sVar1;
  int iVar2;
  
  if (param_1 == 0) {
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_00008958);
      FUN_0000810c("ndg_close niType=%d.\n",DAT_0000dbd4);
    }
    if (DAT_0000dbd4 == 4) {
      iVar2 = 0;
    }
    else {
      sVar1 = FUN_00002df0();
      iVar2 = (int)sVar1;
    }
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}


================================================================