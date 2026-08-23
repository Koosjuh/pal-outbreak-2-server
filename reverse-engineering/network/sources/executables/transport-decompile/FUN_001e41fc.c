
/* WARNING: Removing unreachable block (ram,0x001e4638) */
/* WARNING: Removing unreachable block (ram,0x001e4654) */

undefined4 FUN_001e41fc(long *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  long lVar4;
  undefined1 uStack_70;
  byte bStack_6f;
  byte bStack_6e;
  byte bStack_6d;
  byte bStack_6b;
  byte bStack_6a;
  byte bStack_69;
  int iStack_60;
  uint uStack_5c;
  uint uStack_58;
  int iStack_54;
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  
  uStack_40 = DAT_00259678;
  uStack_38 = DAT_00259680;
  uStack_30 = DAT_00259688;
  uStack_28 = DAT_00259690;
  uStack_20 = DAT_00259698;
  uStack_18 = DAT_002596a0;
  puVar2 = (undefined4 *)FUN_00103de8();
  *puVar2 = 0;
  if (DAT_0024daa0 == 0) {
    iStack_60 = FUN_00101d08(&uStack_70);
    if (iStack_60 == 0) {
      puVar2 = (undefined4 *)FUN_00103de8();
      *puVar2 = 0xe;
      return 0xffffffff;
    }
    uStack_5c = (uint)(bStack_69 >> 4) * 10 + (bStack_69 & 0xf);
    uStack_58 = (uint)(bStack_6a >> 4) * 10 + (bStack_6a & 0xf);
    iStack_54 = (uint)(bStack_6b >> 4) * 10 + (bStack_6b & 0xf);
    uStack_50 = (uint)(bStack_6d >> 4) * 10 + (bStack_6d & 0xf);
    uStack_4c = (uint)(bStack_6e >> 4) * 10 + (bStack_6e & 0xf);
    uStack_48 = (uint)(bStack_6f >> 4) * 10 + (bStack_6f & 0xf);
    if (uStack_5c < 0x46) {
      uStack_5c = uStack_5c + 2000;
    }
    else {
      uStack_5c = uStack_5c + 0x76c;
    }
    DAT_0024daa0 = (ulong)((uStack_5c - 0x7b2) * 0x16d);
    if (0x7b4 < uStack_5c) {
      DAT_0024daa0 = DAT_0024daa0 + (long)(int)(uStack_5c - 0x7b5 >> 2);
    }
    DAT_0024daa0 = DAT_0024daa0 +
                   (uint)(*(int *)((int)&uStack_40 + (uStack_58 - 1) * 4) + iStack_54);
    if (((uStack_5c & 3) == 0) && (2 < uStack_58)) {
      DAT_0024daa0 = DAT_0024daa0 + 1;
    }
    DAT_0024daa0 = ((DAT_0024daa0 * 0x18 + (ulong)uStack_50) * 0x3c + (ulong)uStack_4c) * 0x3c +
                   (ulong)uStack_48;
    DAT_0024daa8 = 0;
  }
  iVar3 = FUN_001e41d0();
  DAT_0025b7c4 = DAT_0025b7c4 + (iVar3 - DAT_0025b7c0);
  DAT_0025b7c0 = iVar3;
  if (300 < DAT_0025b7c4) {
    uVar1 = (int)DAT_0025b7c4 / 300;
    DAT_0025b7c4 = (int)DAT_0025b7c4 % 300;
    DAT_0024daa8 = DAT_0024daa8 + (ulong)uVar1;
    if (1000000 < DAT_0024daa8) {
      lVar4 = FUN_0010ea10(DAT_0024daa8,1000000);
      DAT_0024daa0 = DAT_0024daa0 + lVar4;
      DAT_0024daa8 = FUN_0010f0a8(DAT_0024daa8,1000000);
    }
  }
  param_1[1] = DAT_0024daa8;
  *param_1 = DAT_0024daa0;
  return 0;
}

