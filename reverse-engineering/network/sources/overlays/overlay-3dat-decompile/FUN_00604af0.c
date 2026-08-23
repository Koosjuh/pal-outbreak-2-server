FUNCTION FUN_00604af0 @ 0x00604af0  size=412
CALLERS (1): FUN_00603f30@0x00603f30
CALLEES (4): FUN_005ba7b0@0x005ba7b0, FUN_00618ba0@0x00618ba0, FUN_005ba570@0x005ba570, FUN_005b7fd0@0x005b7fd0
----------------------------------------------------------------

void FUN_00604af0(int param_1)

{
  bool bVar1;
  undefined1 *puVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  lVar3 = FUN_00618ba0();
  if (lVar3 != 0) {
    puVar2 = (undefined1 *)lVar3;
    *puVar2 = 1;
    puVar2[1] = 1;
    *(undefined2 *)(puVar2 + 0x22) = 0x6b;
    *(undefined4 *)(puVar2 + 0x30) = 1;
    puVar2[2] = 0;
    lVar3 = (long)*(char *)(param_1 + 0x905);
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
      *(undefined2 *)(puVar2 + 0x28) = *(undefined2 *)(&DAT_00649ff0 + (int)lVar5 * 2);
      *(undefined1 **)(puVar2 + 0xc) = &LAB_00605090;
      puVar2[3] = (char)lVar5;
      lVar4 = FUN_00618ba0();
      if (lVar4 == 0) {
        return;
      }
      puVar2 = (undefined1 *)lVar4;
      *puVar2 = 1;
      puVar2[1] = 1;
      *(undefined2 *)(puVar2 + 0x22) = 100;
      *(undefined4 *)(puVar2 + 0x30) = 1;
      *(code **)(puVar2 + 0xc) = FUN_006050d0;
      puVar2[3] = (char)lVar5;
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
      *(code **)(puVar2 + 0xc) = FUN_00604e70;
      lVar3 = FUN_00618ba0();
      if (lVar3 != 0) {
        puVar2 = (undefined1 *)lVar3;
        *puVar2 = 1;
        puVar2[1] = 0;
        *(undefined2 *)(puVar2 + 0x22) = 0x6e;
        *(undefined4 *)(puVar2 + 0x30) = 1;
        puVar2[2] = 1;
        *(code **)(puVar2 + 0xc) = FUN_00604e70;
        if (*(char *)(param_1 + 0x905) != '\0') {
          FUN_005b7fd0(10,0,param_1 + 0x909,2);
        }
        FUN_005ba570(0xc);
        FUN_005ba7b0();
      }
    }
  }
  return;
}



================================================================