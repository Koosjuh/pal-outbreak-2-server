FUNCTION FUN_00003e68 @ 0x00003e68 size=152
CALLERS (0): 
CALLEES (1): FUN_0000810c@0x0000810c

undefined4 FUN_00003e68(short param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_00008958);
    FUN_0000810c("ndg_stat called (niId=0x%x).\n",(int)param_1);
  }
  uVar2 = DAT_0000de18;
  uVar1 = DAT_0000de14;
  *param_2 = DAT_0000de10;
  param_2[1] = uVar1;
  param_2[2] = uVar2;
  uVar2 = DAT_0000de24;
  uVar1 = DAT_0000de20;
  param_2[3] = DAT_0000de1c;
  param_2[4] = uVar1;
  param_2[5] = uVar2;
  return 0;
}


================================================================