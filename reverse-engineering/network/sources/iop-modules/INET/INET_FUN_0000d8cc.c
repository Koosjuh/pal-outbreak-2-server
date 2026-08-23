FUNCTION FUN_0000d8cc @ 0x0000d8cc size=112
CALLERS (17): FUN_00015430@0x00015430, FUN_000160a0@0x000160a0, FUN_00011314@0x00011314, FUN_00016d00@0x00016d00, FUN_00011d90@0x00011d90, FUN_0000e848@0x0000e848, FUN_0000b944@0x0000b944, FUN_000193cc@0x000193cc, FUN_000183f0@0x000183f0, FUN_00017bf4@0x00017bf4, FUN_00017ad8@0x00017ad8, FUN_0001748c@0x0001748c, FUN_00016f74@0x00016f74, FUN_00015a28@0x00015a28, FUN_000100c4@0x000100c4, FUN_000179cc@0x000179cc, FUN_0000b220@0x0000b220
CALLEES (2): FUN_00011d90@0x00011d90, FUN_00019a94@0x00019a94

int FUN_0000d8cc(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (param_1 = (int *)*param_1; param_1 != (int *)0x0; param_1 = (int *)*param_1) {
    iVar1 = FUN_00019a94(param_1[3],1);
    if (iVar1 != 0) {
      FUN_00011d90("inet: SetEventFlag (%d)\n",iVar1);
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}


================================================================