FUNCTION FUN_00003bc4 @ 0x00003bc4 size=204
CALLERS (0): 
CALLEES (3): FUN_00002ecc@0x00002ecc, FUN_00002ec4@0x00002ec4, FUN_0000810c@0x0000810c

undefined4 FUN_00003bc4(short param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  undefined4 uVar2;
  
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_00008958);
    FUN_0000810c("ndg_send called (niId=0x%x).\n",(int)param_1);
  }
  sVar1 = FUN_00002ec4();
  uVar2 = 0xffffffff;
  if (sVar1 == 0) {
    sVar1 = FUN_00002ecc(param_2,param_3);
    uVar2 = 0xffffffff;
    if ((sVar1 == 0) && (uVar2 = 0, (DAT_00009710 & 1) != 0)) {
      FUN_0000810c(&PTR_DAT_00008958);
      FUN_0000810c("ndg_send Successfully sent %d bytes.\n",param_3);
      uVar2 = 0;
    }
  }
  return uVar2;
}


================================================================