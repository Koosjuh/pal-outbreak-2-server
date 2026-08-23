FUNCTION FUN_0062eff0 @ 0x0062eff0  size=112
CALLERS (0): 
CALLEES (2): FUN_005c0f00@0x005c0f00, FUN_005c2890@0x005c2890
----------------------------------------------------------------

void FUN_0062eff0(undefined4 *param_1)

{
  char cStack_10;
  undefined2 uStack_2;
  
  cStack_10 = (char)*param_1;
  if (cStack_10 == '\0') {
    FUN_005c0f00(&uStack_2);
    FUN_005c2890(uStack_2,0x6c4fe6,0x6c4fe8);
  }
  else {
    uRam006c4fe6 = 0;
    uRam006c4fe8 = 0;
  }
  return;
}



================================================================