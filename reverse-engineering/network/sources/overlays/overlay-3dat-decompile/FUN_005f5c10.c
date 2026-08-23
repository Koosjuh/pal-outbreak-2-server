FUNCTION FUN_005f5c10 @ 0x005f5c10  size=76
CALLERS (1): FUN_005b45f0@0x005b45f0
CALLEES (1): FUN_005f5a40@0x005f5a40
----------------------------------------------------------------

void FUN_005f5c10(char *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_2;
  if ((*param_1 == -0x7f) && (uVar1 = 0, param_1[1] == '@')) {
    func_0x00106b60();
  }
  else {
    FUN_005f5a40(param_1,uVar1,param_2);
  }
  return;
}



================================================================