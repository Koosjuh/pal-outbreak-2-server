FUNCTION FUN_00003dd8 @ 0x00003dd8 size=144
CALLERS (0): 
CALLEES (1): FUN_0000810c@0x0000810c

undefined4 FUN_00003dd8(short param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_00008958);
    FUN_0000810c("ndg_info called (niId=0x%x).\n",(int)param_1);
  }
  uVar2 = DAT_0000de04;
  uVar1 = DAT_0000de00;
  *param_2 = DAT_0000ddfc;
  param_2[1] = uVar1;
  param_2[2] = uVar2;
  uVar1 = DAT_0000de0c;
  param_2[3] = DAT_0000de08;
  param_2[4] = uVar1;
  return 0;
}


================================================================