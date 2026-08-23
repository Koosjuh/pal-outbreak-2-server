FUNCTION FUN_000086c8 @ 0x000086c8 size=468
CALLERS (1): FUN_00006478@0x00006478
CALLEES (1): FUN_0001306c@0x0001306c

void FUN_000086c8(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  byte *pbVar3;
  
  pbVar3 = *(byte **)(param_4 + 0x10);
  *(ushort *)(pbVar3 + 2) = *(ushort *)(pbVar3 + 2) << 8 | *(ushort *)(pbVar3 + 2) >> 8;
  *(ushort *)(pbVar3 + 4) = *(ushort *)(pbVar3 + 4) << 8 | *(ushort *)(pbVar3 + 4) >> 8;
  *(ushort *)(pbVar3 + 6) = *(ushort *)(pbVar3 + 6) << 8 | *(ushort *)(pbVar3 + 6) >> 8;
  uVar1 = *(undefined4 *)(pbVar3 + 0xc);
  pbVar3[0xc] = (byte)((uint)uVar1 >> 0x18);
  pbVar3[0xd] = (byte)((uint)uVar1 >> 0x10);
  pbVar3[0xe] = (byte)((uint)uVar1 >> 8);
  pbVar3[0xf] = (byte)uVar1;
  uVar1 = *(undefined4 *)(pbVar3 + 0x10);
  pbVar3[0x10] = (byte)((uint)uVar1 >> 0x18);
  pbVar3[0x11] = (byte)((uint)uVar1 >> 0x10);
  pbVar3[0x12] = (byte)((uint)uVar1 >> 8);
  pbVar3[0x13] = (byte)uVar1;
  uVar2 = (*pbVar3 & 0xf) * 4;
  if ((((0x13 < uVar2) && ((int)uVar2 <= *(int *)(param_4 + 0x14) - *(int *)(param_4 + 0x10))) &&
      (*pbVar3 >> 4 == 4)) &&
     (*(uint *)(param_4 + 0x10) = *(int *)(param_4 + 0x10) + uVar2, pbVar3[9] == 6)) {
    FUN_0001306c(param_1,param_2,param_3,*(undefined4 *)(pbVar3 + 0xc),
                 *(undefined4 *)(pbVar3 + 0x10),pbVar3[1],param_4);
  }
  return;
}


================================================================