FUNCTION FUN_000029ac @ 0x000029ac size=800
CALLERS (1): FUN_00001d38@0x00001d38
CALLEES (3): FUN_0000046c@0x0000046c, FUN_00001568@0x00001568, FUN_000012ac@0x000012ac

undefined4 FUN_000029ac(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int local_18 [2];
  
  iVar5 = param_1 + 0xec;
  FUN_0000046c(0xf,4,param_1 + 0x10);
  DAT_00002eb4 = 0;
  iVar1 = FUN_000012ac(iVar5,1,local_18);
  if (iVar1 == 4) {
    DAT_00002eb4 = DAT_00002eb4 + 1;
    FUN_0000046c(1,4,local_18[0]);
  }
  else {
    uVar2 = DAT_00004138 << 0x18;
    if ((int)(DAT_00004138 >> 0x18 | DAT_00004138 >> 8 & 0xff00 | (DAT_00004138 & 0xff00) << 8 |
             uVar2) < 0) {
      uVar4 = 0xffff0000;
      if (((uVar2 & 0xc0000000) != 0x80000000) && (uVar4 = 0, (uVar2 & 0xe0000000) == 0xc0000000)) {
        uVar4 = 0xffffff00;
      }
    }
    else {
      uVar4 = 0xff000000;
    }
    FUN_0000046c(1,0,0);
    DAT_0000413c = uVar4 >> 0x18 | uVar4 >> 8 & 0xff00 | (uVar4 & 0xff00) << 8;
  }
  iVar1 = FUN_000012ac(iVar5,0x1c,local_18);
  if (iVar1 == 4) {
    DAT_00002eb4 = DAT_00002eb4 + 1;
    FUN_0000046c(2,4,local_18[0]);
  }
  else {
    FUN_0000046c(2,0,0);
    DAT_00004140 = ~DAT_0000413c | DAT_00004138;
  }
  if (DAT_00004254 != (uint *)0x0) {
    *DAT_00004254 = DAT_00004138;
    DAT_00004254 = (uint *)0x0;
  }
  if (DAT_00004258 != (uint *)0x0) {
    *DAT_00004258 = DAT_0000413c;
    DAT_00004258 = (uint *)0x0;
  }
  if (DAT_0000425c != (uint *)0x0) {
    *DAT_0000425c = DAT_00004140;
    DAT_0000425c = (uint *)0x0;
  }
  FUN_00001568(iVar5);
  iVar1 = FUN_000012ac(iVar5,0xf,local_18);
  if (iVar1 == 0) {
    iVar3 = 1;
    iVar1 = 0;
  }
  else {
    iVar3 = (int)(short)iVar1;
    iVar1 = local_18[0];
  }
  FUN_0000046c(3,iVar3,iVar1);
  uVar2 = FUN_000012ac(iVar5,6,local_18);
  if ((uVar2 < 4) || ((uVar2 & 3) != 0)) {
    FUN_0000046c(4,4,0);
  }
  else {
    FUN_0000046c(4,4,local_18[0]);
    if (4 < uVar2) {
      iVar1 = local_18[0] + 4;
      goto LAB_00002c64;
    }
  }
  iVar1 = 0;
LAB_00002c64:
  FUN_0000046c(5,4,iVar1);
  uVar2 = FUN_000012ac(iVar5,3,local_18);
  if ((uVar2 < 4) || ((uVar2 & 3) != 0)) {
    local_18[0] = 0;
  }
  FUN_0000046c(6,4,local_18[0]);
  return 0;
}


================================================================