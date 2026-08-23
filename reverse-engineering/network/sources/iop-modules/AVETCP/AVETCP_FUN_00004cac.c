FUNCTION FUN_00004cac @ 0x00004cac size=536
CALLERS (1): FUN_000110d0@0x000110d0
CALLEES (5): FUN_000013bc@0x000013bc, FUN_00011d00@0x00011d00, FUN_00004ec4@0x00004ec4, FUN_00004610@0x00004610, FUN_00003b30@0x00003b30

undefined4
FUN_00004cac(int *param_1,short param_2,int param_3,undefined1 param_4,undefined1 param_5,
            undefined1 param_6,undefined1 param_7,undefined2 param_8,undefined4 param_9)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  ushort local_30;
  undefined1 local_2e;
  
  iVar4 = (int)param_2;
  if (((iVar4 < (int)(uint)DAT_0001619d) && (-1 < iVar4)) &&
     (*(short *)(iVar4 * 0x14 + DAT_000161a8) != 0)) {
    local_2e = param_4;
    sVar1 = FUN_00004610();
    uVar2 = 0xffffffff;
    if (sVar1 != -1) {
      if (param_3 == 0) {
        param_3 = *(int *)(iVar4 * 0x14 + DAT_000161a8 + 4);
      }
      if ((*(char *)(param_2 * 0x14 + DAT_000161a8 + 0x10) == '\x01') && (*param_1 == 1)) {
        iVar4 = FUN_000013bc(param_1 + 3,param_3);
        FUN_00011d00(&local_30,iVar4 + 2,2);
        if (local_30 == 0) {
          uVar3 = FUN_00003b30(0,param_1,1);
          local_30 = (ushort)((uVar3 & 0xff) << 8) | (ushort)(uVar3 >> 8) & 0xff;
          FUN_00011d00(iVar4 + 2,&local_30,2);
        }
      }
      sVar1 = FUN_00004ec4(param_1,param_3,local_2e,param_5,param_6,param_7,param_8,param_9,
                           *(undefined1 *)(param_2 * 0x14 + DAT_000161a8 + 0x10),0);
      uVar2 = 0xffffffff;
      if (sVar1 == 0) {
        uVar2 = 0;
      }
    }
  }
  else {
    uVar2 = 0xfffffffc;
  }
  return uVar2;
}


================================================================