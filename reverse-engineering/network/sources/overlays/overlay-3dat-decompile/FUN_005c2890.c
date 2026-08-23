FUNCTION FUN_005c2890 @ 0x005c2890  size=84
CALLERS (3): FUN_0062eff0@0x0062eff0, FUN_005b5f60@0x005b5f60, FUN_00601060@0x00601060
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_005c2890(long param_1,undefined2 *param_2,undefined2 *param_3)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = ((uint)param_1 & 0xffff) * 0x144;
    *param_2 = *(undefined2 *)(iVar1 + 0x6cfa2c);
    *param_3 = *(undefined2 *)(iVar1 + 0x6cfa2e);
  }
  return 0;
}



================================================================