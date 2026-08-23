FUNCTION FUN_00003d48 @ 0x00003d48 size=144
CALLERS (0): 
CALLEES (2): FUN_000030dc@0x000030dc, FUN_0000810c@0x0000810c

int FUN_00003d48(short param_1,short param_2)

{
  short sVar1;
  int iVar2;
  
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_00008958);
    FUN_0000810c("ndg_endRecv called (niId=0x%x).\n",(int)param_1);
  }
  if ((param_2 == 0x608) || (param_2 == 8)) {
    sVar1 = FUN_000030dc();
    iVar2 = (int)sVar1;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}


================================================================