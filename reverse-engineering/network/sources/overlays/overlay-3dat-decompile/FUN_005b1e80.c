FUNCTION FUN_005b1e80 @ 0x005b1e80  size=288
CALLERS (1): FUN_005b1b10@0x005b1b10
CALLEES (5): FUN_005af2e0@0x005af2e0, FUN_005af2c0@0x005af2c0, FUN_005b1e30@0x005b1e30, FUN_0062fe20@0x0062fe20, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_005b1e80(uint param_1)

{
  byte bVar1;
  byte *pbVar2;
  undefined8 uVar3;
  int iVar4;
  long lVar5;
  
  FUN_005af2e0(0x12);
  FUN_005af2c0(0);
  pbVar2 = (byte *)FUN_005b1e30();
  lVar5 = 0;
  while (lVar5 < (long)(ulong)*pbVar2) {
    iVar4 = (int)lVar5;
    bVar1 = pbVar2[iVar4 + 1];
    if (cRam006c4fbf == lVar5) {
      FUN_005af2c0(0xf);
    }
    else {
      FUN_005af2c0(0);
    }
    uVar3 = FUN_0062fe20(bVar1,0);
    FUN_005af1e0(0x68,*(undefined2 *)(&DAT_00638c50 + iVar4 * 2),2,uVar3);
    lVar5 = (long)(iVar4 + 1);
  }
  FUN_005af2c0(0x15);
  bVar1 = pbVar2[(param_1 & 0xff) + 1];
  uVar3 = FUN_0062fe20((uint)bVar1 * 2,1);
  FUN_005af1e0(0x68,0x150,2,uVar3);
  uVar3 = FUN_0062fe20((uint)bVar1 * 2 + 1,1);
  FUN_005af1e0(0x68,0x166,2,uVar3);
  return;
}



================================================================