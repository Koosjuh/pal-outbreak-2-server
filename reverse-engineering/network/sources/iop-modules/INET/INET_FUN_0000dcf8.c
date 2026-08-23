FUNCTION FUN_0000dcf8 @ 0x0000dcf8 size=536
CALLERS (1): FUN_0000709c@0x0000709c
CALLEES (9): FUN_0000a494@0x0000a494, FUN_00001108@0x00001108, FUN_00011d90@0x00011d90, FUN_00002428@0x00002428, FUN_00006ea8@0x00006ea8, FUN_00009eec@0x00009eec, FUN_0000daa8@0x0000daa8, FUN_000016ec@0x000016ec, FUN_0000db2c@0x0000db2c

void FUN_0000dcf8(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar1 = *(uint *)(*(int *)(param_2 + 0x10) + 0x10);
  uVar3 = uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 | uVar1 >> 0x18;
  uVar1 = *(uint *)(*(int *)(param_2 + 0x10) + 0xc);
  if (param_1 != 0) {
    uVar4 = *(uint *)(param_1 + 0x70);
  }
  if (uVar3 == 0) {
    uVar3 = 0x7f000001;
  }
  if (((uVar3 & 0xff000000) == 0x7f000000) || (uVar3 == uVar4)) {
    FUN_0000db2c(param_1,param_2,uVar3,uVar4);
  }
  else {
    iVar2 = FUN_00006ea8(param_1,uVar3);
    if ((iVar2 != 0) &&
       ((((uVar1 & 0xff) != 0 || (uVar1 & 0xff00) != 0) || (uVar1 >> 8 & 0xff00) != 0) ||
        uVar1 >> 0x18 != 0)) {
      FUN_0000db2c(param_1,param_2,uVar4,uVar4);
    }
    if ((*(uint *)(param_1 + 0x48) & 0x10) != 0) {
      FUN_00001108(param_1,param_2);
      return;
    }
    iVar2 = FUN_0000a494(param_2);
    if (iVar2 == 0) {
      return;
    }
    if ((DAT_0001b850 & 0x10) != 0) {
      FUN_00011d90(&PTR_DAT_0001b884,param_1 + 8);
      FUN_00011d90("%<TIME> S ");
      FUN_00002428(0,iVar2,0,0);
      FUN_00011d90(&DAT_0001b88c);
    }
    if ((DAT_0001b850 & 0x80) != 0) {
      FUN_000016ec(0,*(int *)(iVar2 + 0x10),*(int *)(iVar2 + 0x14) - *(int *)(iVar2 + 0x10));
    }
    FUN_0000daa8(param_1,iVar2);
  }
  FUN_00009eec(param_2);
  return;
}


================================================================