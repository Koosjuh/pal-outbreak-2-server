FUNCTION FUN_0000c268 @ 0x0000c268 size=48
CALLERS (1): FUN_0000d5a8@0x0000d5a8
CALLEES (0): 

undefined4 FUN_0000c268(ushort *param_1,short param_2)

{
  ushort uVar1;
  
  if (param_2 == 0) {
    uVar1 = *param_1 | 0x80;
  }
  else {
    uVar1 = *param_1 & 0xff7f;
  }
  *param_1 = uVar1;
  return 0;
}


================================================================