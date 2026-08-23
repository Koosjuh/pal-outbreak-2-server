FUNCTION FUN_00001684 @ 0x00001684 size=452
CALLERS (1): FUN_00001848@0x00001848
CALLEES (1): FUN_00002adc@0x00002adc

undefined8 FUN_00001684(int param_1,byte *param_2,int param_3)

{
  ushort *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ushort local_20 [4];
  
  iVar9 = *(int *)(param_1 + 4);
  FUN_00002adc(local_20,8);
  if (param_3 < 0) {
    iVar4 = 0xffff;
    if (param_2 != (byte *)0x0) {
LAB_00001714:
      uVar3 = 0xfffffe00;
      goto LAB_0000182c;
    }
    iVar4 = 3;
    puVar1 = local_20 + 3;
    do {
      *puVar1 = 0xffff;
      iVar4 = iVar4 + -1;
      puVar1 = puVar1 + -1;
    } while (-1 < iVar4);
  }
  else {
    iVar4 = param_3 / 6;
    if (param_3 != iVar4 * 6) goto LAB_00001714;
    if (param_2 != (byte *)0x0) {
      while (0 < iVar4) {
        iVar4 = iVar4 + -1;
        uVar5 = 0xffffffff;
        if ((*param_2 & 1) == 0) {
          param_2 = param_2 + 6;
        }
        else {
          iVar8 = 5;
          do {
            uVar6 = (uint)*param_2;
            param_2 = param_2 + 1;
            iVar7 = 7;
            do {
              uVar2 = uVar5 >> 0x1f;
              uVar5 = uVar5 << 1;
              if (((uVar2 ^ uVar6) & 1) != 0) {
                uVar5 = uVar5 ^ 0x4c11db7;
              }
              iVar7 = iVar7 + -1;
              uVar6 = uVar6 >> 1;
            } while (-1 < iVar7);
            iVar8 = iVar8 + -1;
          } while (-1 < iVar8);
          local_20[uVar5 >> 0x1e] = local_20[uVar5 >> 0x1e] | (ushort)(1 << (uVar5 >> 0x1a & 0xf));
        }
      }
    }
  }
  uVar3 = 0;
  *(uint *)(iVar9 + 0x40) = (uint)local_20[3] << 0x10;
  *(uint *)(iVar9 + 0x44) = (uint)local_20[2] << 0x10;
  *(uint *)(iVar9 + 0x48) = (uint)local_20[1] << 0x10;
  *(uint *)(iVar9 + 0x4c) = (uint)local_20[0] << 0x10;
  iVar4 = *(int *)(iVar9 + 0x4c);
LAB_0000182c:
  return CONCAT44(iVar4,uVar3);
}


================================================================