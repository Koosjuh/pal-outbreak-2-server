FUNCTION FUN_00613aa0 @ 0x00613aa0  size=112
CALLERS (1): FUN_00612d10@0x00612d10
CALLEES (2): FUN_006146e0@0x006146e0, FUN_00614870@0x00614870
----------------------------------------------------------------

void FUN_00613aa0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  undefined1 auStack_40 [64];
  
  if (*(char *)param_1 == '\0') {
    FUN_006146e0(param_3,param_4,param_2);
  }
  else {
    FUN_00614870(auStack_40,param_1,param_5);
    FUN_006146e0(param_3,param_4,auStack_40);
  }
  return;
}



================================================================