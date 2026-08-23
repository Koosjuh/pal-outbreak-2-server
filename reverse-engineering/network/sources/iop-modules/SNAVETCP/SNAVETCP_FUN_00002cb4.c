FUNCTION FUN_00002cb4 @ 0x00002cb4 size=232
CALLERS (2): FUN_00002728@0x00002728, FUN_00002394@0x00002394
CALLEES (5): FUN_00000fa0@0x00000fa0, FUN_00004314@0x00004314, FUN_00001018@0x00001018, FUN_00011d00@0x00011d00, FUN_00003220@0x00003220

undefined4 FUN_00002cb4(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    puVar3 = (undefined4 *)FUN_00000fa0();
    uVar2 = 0xffffffff;
    if (puVar3 != (undefined4 *)0x0) {
      puVar4 = *(undefined2 **)(param_1 + 8);
      while (puVar4 != (undefined2 *)0x0) {
        *puVar3 = 1;
        *(undefined2 *)(puVar3 + 2) = *puVar4;
        FUN_00011d00(puVar3 + 3,*(undefined4 *)(puVar4 + 2),8);
        sVar1 = FUN_00004314(puVar3,param_1 + 0x18,0,(int)*(short *)(param_1 + 4));
        if (sVar1 != 0) {
          FUN_00001018(puVar3);
          return 0xffffffff;
        }
        sVar1 = FUN_00003220(param_1);
        if (sVar1 != 0) {
          return 0xffffffff;
        }
        puVar4 = *(undefined2 **)(param_1 + 8);
      }
      FUN_00001018(puVar3);
      uVar2 = 0;
    }
  }
  return uVar2;
}


================================================================