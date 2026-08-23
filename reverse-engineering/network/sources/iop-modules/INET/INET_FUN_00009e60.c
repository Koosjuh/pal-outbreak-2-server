FUNCTION FUN_00009e60 @ 0x00009e60 size=140
CALLERS (23): FUN_0000709c@0x0000709c, FUN_000062e0@0x000062e0, FUN_000169bc@0x000169bc, FUN_000038a4@0x000038a4, FUN_00013264@0x00013264, FUN_00011b08@0x00011b08, FUN_00000994@0x00000994, FUN_0000a494@0x0000a494, FUN_00006d98@0x00006d98, FUN_0000df10@0x0000df10, FUN_00007abc@0x00007abc, FUN_0000b220@0x0000b220, FUN_0000b5c4@0x0000b5c4, FUN_00001108@0x00001108, FUN_00007e28@0x00007e28, FUN_0000a29c@0x0000a29c, FUN_0001311c@0x0001311c, FUN_00006630@0x00006630, FUN_0000057c@0x0000057c, FUN_00018170@0x00018170, FUN_00018de4@0x00018de4, FUN_0001442c@0x0001442c, FUN_00016368@0x00016368
CALLEES (2): FUN_0000a60c@0x0000a60c, FUN_0000a9c0@0x0000a9c0

undefined4 * FUN_00009e60(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)FUN_0000a60c(param_2 + 0x18);
  puVar3 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = puVar1 + 6;
    puVar1[1] = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
    puVar1[2] = 0;
    puVar1[5] = puVar2;
    puVar1[4] = puVar2;
    puVar3 = puVar1;
    if (param_1 != 0) {
      FUN_0000a9c0(param_1,puVar2,param_2);
      puVar1[5] = puVar1[5] + param_2;
    }
  }
  return puVar3;
}


================================================================