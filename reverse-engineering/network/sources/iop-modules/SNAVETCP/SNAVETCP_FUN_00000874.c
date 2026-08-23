FUNCTION FUN_00000874 @ 0x00000874 size=48
CALLERS (0): 
CALLEES (1): FUN_0000e540@0x0000e540

undefined4 FUN_00000874(short *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0000e540((int)*param_1);
  *param_2 = uVar1;
  return 0;
}


================================================================