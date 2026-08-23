FUNCTION FUN_00003a9c @ 0x00003a9c size=144
CALLERS (0): 
CALLEES (3): FUN_0000810c@0x0000810c, FUN_00002d4c@0x00002d4c, FUN_00002e18@0x00002e18

int FUN_00003a9c(short param_1)

{
  short sVar1;
  int iVar2;
  
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_00008958);
    FUN_0000810c("ndg_open called (niId=0x%x).\n",(int)param_1);
  }
  iVar2 = -1;
  if (param_1 == 0) {
    iVar2 = FUN_00002d4c();
    if (iVar2 << 0x10 < 0) {
      iVar2 = -1;
    }
    else {
      sVar1 = FUN_00002e18(&DAT_0000ddfc);
      iVar2 = (int)sVar1;
    }
  }
  return iVar2;
}


================================================================