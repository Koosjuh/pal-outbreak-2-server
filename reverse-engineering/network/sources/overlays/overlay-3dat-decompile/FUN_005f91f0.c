FUNCTION FUN_005f91f0 @ 0x005f91f0  size=136
CALLERS (1): FUN_005f9150@0x005f9150
CALLEES (5): FUN_005adc80@0x005adc80, FUN_005b6900@0x005b6900, FUN_005b68e0@0x005b68e0, FUN_005fe300@0x005fe300, FUN_005c0400@0x005c0400
----------------------------------------------------------------

void FUN_005f91f0(int param_1)

{
  undefined2 uVar1;
  
  if (*(char *)(param_1 + 0x10) == '\x01') {
    FUN_005b6900();
  }
  else if (*(char *)(param_1 + 0x10) == '\0') {
    FUN_005fe300();
    *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x97e) = 0;
    *(undefined1 *)(param_1 + 0x42b) = 10;
    uVar1 = FUN_005adc80(2);
    FUN_005c0400(uVar1,0x5fc2b0);
  }
  return;
}



================================================================