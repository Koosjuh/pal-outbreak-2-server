FUNCTION FUN_0000e08c @ 0x0000e08c size=96
CALLERS (17): FUN_0000ce88@0x0000ce88, FUN_0000cf80@0x0000cf80, FUN_0000dbac@0x0000dbac, FUN_0000dfe4@0x0000dfe4, FUN_0000d058@0x0000d058, FUN_0000d7fc@0x0000d7fc, FUN_0000ca20@0x0000ca20, FUN_0000d634@0x0000d634, FUN_0000d884@0x0000d884, FUN_0000de60@0x0000de60, FUN_0000d204@0x0000d204, FUN_0000d704@0x0000d704, FUN_0000d39c@0x0000d39c, FUN_0000decc@0x0000decc, FUN_0000dcd8@0x0000dcd8, FUN_0000cc3c@0x0000cc3c, FUN_0000d9c8@0x0000d9c8
CALLEES (0): 

undefined4 FUN_0000e08c(short param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if (((iVar1 < (int)(uint)DAT_0001619b) && (-1 < iVar1)) &&
     (*(short *)(iVar1 * 0x17c + DAT_00016180 + 0x138) == 1)) {
    return 0;
  }
  return 0xfffffffc;
}


================================================================