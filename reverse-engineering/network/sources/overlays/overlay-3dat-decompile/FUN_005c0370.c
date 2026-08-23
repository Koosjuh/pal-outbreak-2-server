FUNCTION FUN_005c0370 @ 0x005c0370  size=132
CALLERS (4): FUN_005b58e0@0x005b58e0, FUN_005fc0c0@0x005fc0c0, FUN_00601170@0x00601170, FUN_0062e9b0@0x0062e9b0
CALLEES (0): 
----------------------------------------------------------------

undefined8
FUN_005c0370(uint param_1,undefined2 *param_2,undefined2 *param_3,undefined2 *param_4,
            undefined2 *param_5,undefined2 *param_6)

{
  int iVar1;
  
  iVar1 = (param_1 & 0xffff) * 0x144;
  *param_2 = *(undefined2 *)(iVar1 + 0x6cfa22);
  *param_3 = *(undefined2 *)(iVar1 + 0x6cfa24);
  *param_4 = *(undefined2 *)(iVar1 + 0x6cfa26);
  *param_5 = *(undefined2 *)(iVar1 + 0x6cfa28);
  *param_6 = *(undefined2 *)(iVar1 + 0x6cfa2a);
  return 0;
}



================================================================