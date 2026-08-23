FUNCTION FUN_005f8340 @ 0x005f8340  size=372
CALLERS (1): FUN_005f78c0@0x005f78c0
CALLEES (5): FUN_005ba7b0@0x005ba7b0, FUN_005ba7c0@0x005ba7c0, FUN_00618ba0@0x00618ba0, FUN_005ba570@0x005ba570, FUN_005b6cf0@0x005b6cf0
----------------------------------------------------------------

void FUN_005f8340(long param_1,undefined2 *param_2)

{
  undefined1 *puVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  
  lVar2 = param_1;
  for (iVar4 = 0; iVar4 < 2; iVar4 = iVar4 + 1) {
    lVar2 = FUN_00618ba0(lVar2,param_2,(int)param_1 + 0x907);
    if (lVar2 == 0) {
      return;
    }
    puVar1 = (undefined1 *)lVar2;
    *puVar1 = 1;
    puVar1[1] = 1;
    iVar3 = iVar4 * 6;
    param_2 = (undefined2 *)(&DAT_00649758 + iVar3);
    *(undefined2 *)(puVar1 + 0x22) = *param_2;
    *(int *)(puVar1 + 0x34) = (int)*(short *)(&DAT_0064975a + iVar3);
    lVar2 = (long)*(short *)(&DAT_0064975c + iVar3);
    *(int *)(puVar1 + 0x30) = (int)*(short *)(&DAT_0064975c + iVar3);
    puVar1[2] = (char)iVar4;
    *(code **)(puVar1 + 0xc) = FUN_005f84c0;
  }
  FUN_005b6cf0(0xe,0xf);
  for (iVar4 = 0; iVar4 < 2; iVar4 = iVar4 + 1) {
    lVar2 = FUN_00618ba0();
    if (lVar2 == 0) {
      return;
    }
    puVar1 = (undefined1 *)lVar2;
    *puVar1 = 1;
    *(undefined1 **)(puVar1 + 0xc) = &LAB_005f8ab0;
    puVar1[3] = (char)iVar4;
  }
  lVar2 = FUN_00618ba0();
  if (lVar2 != 0) {
    puVar1 = (undefined1 *)lVar2;
    *puVar1 = 1;
    puVar1[3] = 1;
    *(undefined1 **)(puVar1 + 0xc) = &LAB_005f8960;
    lVar2 = FUN_00618ba0();
    if (lVar2 != 0) {
      *(undefined1 *)lVar2 = 1;
      *(undefined1 **)((undefined1 *)lVar2 + 0xc) = &LAB_005f8960;
      for (iVar4 = 0; iVar4 < 10; iVar4 = iVar4 + 1) {
        lVar2 = FUN_00618ba0(5);
        if (lVar2 == 0) {
          return;
        }
        puVar1 = (undefined1 *)lVar2;
        *puVar1 = 1;
        *(code **)(puVar1 + 0xc) = FUN_005f85e0;
        puVar1[3] = (char)iVar4;
      }
      FUN_005ba570();
      FUN_005ba7c0();
      FUN_005ba7b0();
    }
  }
  return;
}



================================================================