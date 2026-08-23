FUNCTION FUN_00609be0 @ 0x00609be0  size=116
CALLERS (1): FUN_00608c80@0x00608c80
CALLEES (0): 
----------------------------------------------------------------

void FUN_00609be0(undefined1 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5)

{
  undefined1 *puVar1;
  long lVar2;
  
  lVar2 = (**(code **)(param_5 + 0x28))(*(undefined4 *)(param_5 + 0x30),1,0x1c);
  if (lVar2 != 0) {
    puVar1 = (undefined1 *)lVar2;
    *puVar1 = 0;
    puVar1[0x10] = param_1;
    puVar1[0x11] = param_2;
    *(undefined4 *)(puVar1 + 0x14) = param_3;
    *(undefined4 *)(puVar1 + 0x18) = param_4;
  }
  return;
}



================================================================