FUNCTION FUN_0060c1d0 @ 0x0060c1d0  size=88
CALLERS (0): 
CALLEES (0): 
----------------------------------------------------------------

void FUN_0060c1d0(undefined8 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)0x70ce00;
  do {
    puVar2 = puVar1;
    if (puVar2[2] == 0x70d0f4) {
      return;
    }
    puVar1 = (undefined4 *)puVar2[2];
  } while (puVar1[1] != param_2);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar2[2] = puVar1[2];
  puVar1[2] = 0;
  return;
}



================================================================