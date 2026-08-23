FUNCTION FUN_005bbc20 @ 0x005bbc20  size=468
CALLERS (1): FUN_005bba20@0x005bba20
CALLEES (6): FUN_005bf1e0@0x005bf1e0, FUN_005c60d0@0x005c60d0, FUN_005c6050@0x005c6050, FUN_005bdfe0@0x005bdfe0, FUN_005c4f00@0x005c4f00, FUN_005bdf90@0x005bdf90
----------------------------------------------------------------

void FUN_005bbc20(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  ushort *puVar6;
  bool bVar7;
  int iVar8;
  ushort uVar9;
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
  uVar2 = FUN_005bf1e0(2);
  iVar3 = (uVar2 & 0xffff) - 1;
  bVar7 = false;
  iVar8 = 0;
  puVar6 = (ushort *)(iVar3 * 0x144 + 0x6cfb70);
  bVar1 = *(byte *)puVar6;
  uVar9 = (ushort)bVar1;
  iVar5 = 0;
  do {
    if (*(int *)(iVar5 + 0x7006d4) == param_1) {
      bVar7 = true;
    }
    iVar8 = iVar8 + 1;
    iVar5 = iVar8 * 8;
  } while (iVar8 < 4);
  if (!bVar7) {
    iVar5 = 0;
    while( true ) {
      if (3 < iVar5) break;
      if (*(int *)(iVar5 * 8 + 0x7006d4) == 0) {
        uVar9 = bVar1 + 1 & 0xff;
        *(int *)(iVar5 * 8 + 0x7006d4) = param_1;
        if (4 < uVar9) {
          uVar9 = 4;
        }
        break;
      }
      iVar5 = iVar5 + 1;
    }
  }
  sRam006d2158 = (short)iVar3 + 1;
  *puVar6 = uVar9;
  auStack_4[0] = (char)uVar9;
  FUN_005c6050(param_1,auStack_4);
  uRam006cbc84 = 0;
  uRam006cbc7e = 0x10;
  FUN_005bdfe0(0x21);
  iVar3 = 0;
  auStack_8[0] = (char)uVar9;
  do {
    iVar5 = *(int *)(iVar3 * 8 + 0x7006d4);
    if ((iVar5 != 0) && (iVar5 != param_1)) {
      FUN_005c60d0(iVar5,auStack_8);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  lVar4 = FUN_005c4f00();
  if (((bRam006ff2b0 & lVar4 == 1) != 0) && (bRam007006a5 <= uVar9)) {
    FUN_005bdf90(1,0);
  }
  return;
}



================================================================