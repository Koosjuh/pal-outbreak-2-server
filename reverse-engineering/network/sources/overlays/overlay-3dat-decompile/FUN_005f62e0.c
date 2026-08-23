FUNCTION FUN_005f62e0 @ 0x005f62e0  size=460
CALLERS (1): FUN_005f5fe0@0x005f5fe0
CALLEES (5): FUN_005ba7b0@0x005ba7b0, FUN_00618b60@0x00618b60, FUN_00618ba0@0x00618ba0, FUN_005ba570@0x005ba570, FUN_005b7fd0@0x005b7fd0
----------------------------------------------------------------

void FUN_005f62e0(undefined8 param_1)

{
  bool bVar1;
  undefined1 *puVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  int iVar6;
  
  FUN_00618b60();
  lVar3 = FUN_00618ba0();
  if (lVar3 != 0) {
    puVar2 = (undefined1 *)lVar3;
    *puVar2 = 1;
    puVar2[1] = 1;
    *(undefined2 *)(puVar2 + 0x22) = 0x13a;
    *(undefined4 *)(puVar2 + 0x30) = 1;
    puVar2[2] = 0;
    lVar3 = FUN_00618ba0();
    if (lVar3 != 0) {
      puVar2 = (undefined1 *)lVar3;
      *puVar2 = 1;
      puVar2[1] = 1;
      *(undefined2 *)(puVar2 + 0x22) = 0x13b;
      *(undefined4 *)(puVar2 + 0x34) = 0xffffffe6;
      iVar6 = (int)param_1;
      lVar3 = (long)*(short *)(iVar6 + 8);
      lVar5 = 0;
      if (7 < lVar3) {
        lVar3 = 7;
      }
      bVar1 = 0 < lVar3;
      while (bVar1) {
        lVar4 = FUN_00618ba0();
        if (lVar4 == 0) {
          return;
        }
        puVar2 = (undefined1 *)lVar4;
        *puVar2 = 1;
        puVar2[1] = 1;
        *(undefined2 *)(puVar2 + 0x22) = 0x6c;
        *(undefined4 *)(puVar2 + 0x30) = 1;
        *(undefined2 *)(puVar2 + 0x26) = 0x28;
        *(undefined2 *)(puVar2 + 0x28) = *(undefined2 *)(&DAT_00649720 + (int)lVar5 * 2);
        *(undefined1 **)(puVar2 + 0xc) = &LAB_005f6750;
        puVar2[3] = (char)lVar5;
        *(int *)(puVar2 + 0x10) = iVar6;
        lVar4 = FUN_00618ba0();
        if (lVar4 == 0) {
          return;
        }
        puVar2 = (undefined1 *)lVar4;
        *puVar2 = 1;
        *(undefined4 *)(puVar2 + 0x30) = 1;
        *(code **)(puVar2 + 0xc) = FUN_005f6790;
        puVar2[3] = (char)lVar5;
        *(int *)(puVar2 + 0x10) = iVar6;
        lVar5 = (long)((int)lVar5 + 1);
        bVar1 = lVar5 < lVar3;
      }
      lVar3 = FUN_00618ba0();
      if (lVar3 != 0) {
        puVar2 = (undefined1 *)lVar3;
        *puVar2 = 1;
        puVar2[1] = 0;
        *(undefined2 *)(puVar2 + 0x22) = 0x6d;
        *(undefined4 *)(puVar2 + 0x30) = 1;
        puVar2[2] = 0;
        *(code **)(puVar2 + 0xc) = FUN_005f6610;
        *(int *)(puVar2 + 0x10) = iVar6;
        lVar3 = FUN_00618ba0();
        if (lVar3 != 0) {
          puVar2 = (undefined1 *)lVar3;
          *puVar2 = 1;
          puVar2[1] = 0;
          *(undefined2 *)(puVar2 + 0x22) = 0x6e;
          *(undefined4 *)(puVar2 + 0x30) = 1;
          puVar2[2] = 1;
          *(code **)(puVar2 + 0xc) = FUN_005f6610;
          *(int *)(puVar2 + 0x10) = iVar6;
          if (*(short *)(iVar6 + 8) != 0) {
            FUN_005b7fd0(0x22,0,param_1,2);
          }
          FUN_005ba570(0x24);
          FUN_005ba7b0();
        }
      }
    }
  }
  return;
}



================================================================