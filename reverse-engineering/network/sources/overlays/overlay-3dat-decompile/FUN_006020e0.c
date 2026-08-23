FUNCTION FUN_006020e0 @ 0x006020e0  size=332
CALLERS (2): FUN_005ffbe0@0x005ffbe0, FUN_00600200@0x00600200
CALLEES (6): FUN_005f58c0@0x005f58c0, FUN_005ba7b0@0x005ba7b0, FUN_00618b60@0x00618b60, FUN_00618ba0@0x00618ba0, FUN_005b7fd0@0x005b7fd0, FUN_005b6c90@0x005b6c90
----------------------------------------------------------------

void FUN_006020e0(int param_1)

{
  undefined1 *puVar1;
  long lVar2;
  
  *(undefined1 *)(param_1 + 0x43d) = 0xff;
  *(undefined1 *)(param_1 + 0x907) = *(undefined1 *)(param_1 + 0x909);
  FUN_00618b60();
  lVar2 = FUN_00618ba0();
  if (lVar2 != 0) {
    puVar1 = (undefined1 *)lVar2;
    *puVar1 = 1;
    puVar1[1] = 1;
    *(undefined2 *)(puVar1 + 0x22) = 0x8a;
    *(undefined4 *)(puVar1 + 0x30) = 1;
    puVar1[2] = 0;
    *(code **)(puVar1 + 0xc) = FUN_00602340;
    lVar2 = FUN_00618ba0();
    if (lVar2 != 0) {
      puVar1 = (undefined1 *)lVar2;
      *puVar1 = 1;
      puVar1[1] = 1;
      *(undefined2 *)(puVar1 + 0x22) = 0x8a;
      FUN_005b6c90(0xc,3,param_1 + 0x907);
      *(undefined1 *)(param_1 + 0x907) = 0;
      FUN_005b7fd0(0x1b,0,param_1 + 0x907,3);
      lVar2 = FUN_00618ba0();
      if (lVar2 != 0) {
        puVar1 = (undefined1 *)lVar2;
        *puVar1 = 1;
        puVar1[1] = 1;
        *(undefined2 *)(puVar1 + 0x22) = 0x37;
        *(undefined4 *)(puVar1 + 0x30) = 0;
        *(undefined4 *)(puVar1 + 0x34) = 0xffffffe6;
        *(undefined1 **)(puVar1 + 0xc) = &LAB_00602610;
        puVar1[3] = 1;
        lVar2 = FUN_00618ba0();
        if (lVar2 != 0) {
          puVar1 = (undefined1 *)lVar2;
          *puVar1 = 1;
          puVar1[1] = 1;
          *(undefined4 *)(puVar1 + 0x30) = 0;
          *(undefined4 *)(puVar1 + 0x34) = 0xffffffe6;
          *(undefined1 **)(puVar1 + 0xc) = &LAB_00603b30;
          puVar1[3] = 1;
          lVar2 = FUN_00618ba0();
          if (lVar2 != 0) {
            puVar1 = (undefined1 *)lVar2;
            *puVar1 = 1;
            puVar1[1] = 1;
            *(undefined4 *)(puVar1 + 0x30) = 0;
            puVar1[2] = 0;
            *(undefined1 **)(puVar1 + 0xc) = &LAB_00603c30;
            FUN_005f58c0();
            FUN_005ba7b0();
          }
        }
      }
    }
  }
  return;
}



================================================================