FUNCTION FUN_005b9060 @ 0x005b9060  size=164
CALLERS (21): FUN_005b20c0@0x005b20c0, FUN_0062ab50@0x0062ab50, FUN_005ff760@0x005ff760, FUN_005fb9b0@0x005fb9b0, FUN_005ad530@0x005ad530, FUN_005ae510@0x005ae510, FUN_006178a0@0x006178a0, FUN_005f6a20@0x005f6a20, FUN_005b3590@0x005b3590, FUN_005ade20@0x005ade20, FUN_005b33f0@0x005b33f0, FUN_005b4a50@0x005b4a50, ...
CALLEES (1): FUN_00618ba0@0x00618ba0
----------------------------------------------------------------

void FUN_005b9060(ulong param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  long lVar2;
  
  uRam006c4fcf = 0;
  uRam006c4fcd = 0xff;
  uRam006c4fce = 1;
  lVar2 = FUN_00618ba0();
  if (lVar2 != 0) {
    puVar1 = (undefined1 *)lVar2;
    *puVar1 = 1;
    puVar1[2] = (char)param_1;
    *(undefined4 *)(puVar1 + 0x34) = 0xffffffe6;
    *(undefined4 *)(puVar1 + 0x10) = param_2;
    *(code **)(puVar1 + 0xc) = FUN_005ba2e0;
    if ((param_1 & 0x8000) == 0) {
      puVar1[3] = 0;
      *(undefined2 *)(puVar1 + 0x22) = 0x8d;
    }
    else {
      puVar1[3] = 1;
      *(undefined2 *)(puVar1 + 0x22) = 0x143;
    }
  }
  return;
}



================================================================