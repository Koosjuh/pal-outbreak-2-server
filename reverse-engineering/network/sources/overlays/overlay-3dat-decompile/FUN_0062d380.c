FUNCTION FUN_0062d380 @ 0x0062d380  size=76
CALLERS (1): FUN_0062cf50@0x0062cf50
CALLEES (2): FUN_0062d3d0@0x0062d3d0, FUN_0062d430@0x0062d430
----------------------------------------------------------------

undefined8 FUN_0062d380(undefined8 param_1,int param_2)

{
  undefined8 uVar1;
  
  if (*(char *)(param_2 + 1) == '\x01') {
    uVar1 = FUN_0062d430();
  }
  else if (*(char *)(param_2 + 1) == '\0') {
    uVar1 = FUN_0062d3d0();
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



================================================================