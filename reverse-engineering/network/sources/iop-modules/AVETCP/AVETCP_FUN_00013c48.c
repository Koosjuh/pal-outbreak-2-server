FUNCTION FUN_00013c48 @ 0x00013c48 size=476
CALLERS (1): FUN_000143e4@0x000143e4
CALLEES (4): FUN_00013650@0x00013650, FUN_00011d48@0x00011d48, FUN_00013b74@0x00013b74, FUN_000139bc@0x000139bc

undefined4 FUN_00013c48(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 *local_20;
  undefined1 *local_1c;
  
  iVar4 = (&DAT_00016fa0)[param_1];
  if (iVar4 == 0) {
    uVar2 = 0;
  }
  else {
    local_20 = &DAT_000173a8;
    FUN_00011d48(&DAT_000173a8,0,0x800);
    *local_20 = *(undefined1 *)(iVar4 + 0xc19);
    local_20[1] = *(undefined1 *)(iVar4 + 0xc18);
    local_20[2] = 1;
    local_20[3] = 0;
    local_20[4] = 0;
    bVar1 = true;
    local_20[5] = 1;
    local_1c = (undefined1 *)(iVar4 + 0x818);
    local_20 = local_20 + 0xc;
    while (iVar3 = FUN_00013b74(&local_20,&local_1c), iVar3 != 0) {
      bVar1 = false;
    }
    if (bVar1) {
      local_1c = &DAT_00016fa8;
      do {
        iVar3 = FUN_00013b74(&local_20,&local_1c);
      } while (iVar3 != 0);
    }
    *local_20 = 0;
    local_20[1] = 0;
    local_20[2] = 1;
    local_20[3] = 0;
    local_20[4] = 1;
    local_20 = local_20 + 5;
    FUN_00011d48(iVar4 + 0xe,0,0x800);
    *(undefined4 *)(iVar4 + 4) = 1;
    iVar3 = FUN_00013650();
    *(int *)(iVar4 + 0x814) = iVar3 + param_3;
    uVar2 = FUN_000139bc(param_1,param_2,0x3500,&DAT_000173a8,local_20 + -0x173a8);
  }
  return uVar2;
}


================================================================