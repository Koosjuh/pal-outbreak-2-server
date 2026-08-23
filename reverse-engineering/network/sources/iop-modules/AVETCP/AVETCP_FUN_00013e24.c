FUNCTION FUN_00013e24 @ 0x00013e24 size=680
CALLERS (1): FUN_00014818@0x00014818
CALLEES (5): FUN_00013650@0x00013650, FUN_00013a88@0x00013a88, FUN_00011d48@0x00011d48, FUN_00013b74@0x00013b74, FUN_000139bc@0x000139bc

undefined4 FUN_00013e24(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_60 [64];
  undefined1 *local_20;
  undefined1 *local_1c;
  
  iVar4 = (&DAT_00016fa0)[param_1];
  local_20 = &DAT_000173a8;
  FUN_00011d48(&DAT_000173a8,0,0x800);
  *local_20 = *(undefined1 *)(iVar4 + 0xc19);
  local_20[1] = *(undefined1 *)(iVar4 + 0xc18);
  local_20[2] = 1;
  local_20[3] = 0;
  bVar1 = true;
  local_20[4] = 0;
  local_20[5] = 1;
  local_1c = (undefined1 *)(iVar4 + 0x818);
  local_20 = local_20 + 0xc;
  iVar2 = FUN_00013a88(auStack_60);
  uVar3 = 0xffffffff;
  if (iVar2 == 0) {
    local_1c = auStack_60;
    while (iVar2 = FUN_00013b74(&local_20,&local_1c), iVar2 != 0) {
      bVar1 = false;
    }
    if (bVar1) {
      local_1c = &DAT_00016fa8;
      do {
        iVar2 = FUN_00013b74(&local_20,&local_1c);
      } while (iVar2 != 0);
    }
    *local_20 = 7;
    local_20[1] = 0x69;
    local_20[2] = 0x6e;
    local_20[3] = 0x2d;
    local_20[4] = 0x61;
    local_20[5] = 100;
    local_20[6] = 100;
    local_20[7] = 0x72;
    local_20[8] = 4;
    local_20[9] = 0x61;
    local_20[10] = 0x72;
    local_20[0xb] = 0x70;
    local_20[0xc] = 0x61;
    local_20[0xd] = 0;
    local_20[0xe] = 0;
    local_20[0xf] = 0xc;
    local_20[0x10] = 0;
    local_20[0x11] = 1;
    local_20 = local_20 + 0x12;
    FUN_00011d48(iVar4 + 0xe,0,0x800);
    *(undefined4 *)(iVar4 + 4) = 1;
    iVar2 = FUN_00013650();
    *(int *)(iVar4 + 0x814) = iVar2 + param_3;
    uVar3 = FUN_000139bc(param_1,param_2,0x3500,&DAT_000173a8,local_20 + -0x173a8);
  }
  return uVar3;
}


================================================================