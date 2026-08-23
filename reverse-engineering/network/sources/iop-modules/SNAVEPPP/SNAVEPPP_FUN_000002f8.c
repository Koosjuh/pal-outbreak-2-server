FUNCTION FUN_000002f8 @ 0x000002f8 size=548
CALLERS (2): FUN_0000f42c@0x0000f42c, FUN_0000e90c@0x0000e90c
CALLEES (1): FUN_0000075c@0x0000075c

uint FUN_000002f8(uint *param_1,int *param_2)

{
  short sVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  byte local_30;
  undefined1 local_2f;
  ushort local_2e;
  ushort local_2c;
  ushort local_2a;
  undefined1 local_28;
  undefined1 local_27;
  ushort local_26;
  uint local_24;
  uint local_20;
  
  iVar5 = *param_2;
  sVar1 = FUN_0000075c(param_2,&local_30,0x14);
  uVar2 = 0xffff;
  if (sVar1 == 0x14) {
    *(byte *)((int)param_1 + 0x13) = local_30 >> 4;
    *(undefined1 *)(param_1 + 5) = local_2f;
    *(ushort *)(param_1 + 2) = local_2e << 8 | local_2e >> 8;
    *(ushort *)((int)param_1 + 10) = local_2c << 8 | local_2c >> 8;
    uVar3 = local_2a << 8;
    *(ushort *)(param_1 + 3) = (uVar3 & 0x1fff | local_2a >> 8) << 3;
    if ((uVar3 & 0x2000) == 0) {
      *(undefined1 *)((int)param_1 + 0x12) = 0;
    }
    else {
      *(undefined1 *)((int)param_1 + 0x12) = 1;
    }
    if ((uVar3 & 0x4000) == 0) {
      *(undefined1 *)((int)param_1 + 0x11) = 0;
    }
    else {
      *(undefined1 *)((int)param_1 + 0x11) = 1;
    }
    *(undefined1 *)((int)param_1 + 0x15) = local_28;
    *(undefined1 *)((int)param_1 + 0x16) = local_27;
    *(ushort *)((int)param_1 + 0xe) = local_26 << 8 | local_26 >> 8;
    *param_1 = local_24 >> 0x18 | local_24 >> 8 & 0xff00 | (local_24 & 0xff00) << 8 |
               local_24 << 0x18;
    param_1[1] = local_20 >> 0x18 | local_20 >> 8 & 0xff00 | (local_20 & 0xff00) << 8 |
                 local_20 << 0x18;
    iVar4 = (ushort)param_1[2] - 0x14;
    if (iVar4 < (int)(uint)*(ushort *)(iVar5 + 4)) {
      *(short *)(iVar5 + 4) = (short)iVar4;
    }
    uVar2 = (local_30 & 0xf) * 4;
    if (uVar2 < 0x14) {
      *(undefined1 *)((int)param_1 + 0x17) = 0;
      uVar2 = 0xffff;
    }
    else {
      *(char *)((int)param_1 + 0x17) = (char)(uVar2 - 0x14);
      if (((uVar2 - 0x14 & 0xfc) != 0) &&
         (sVar1 = FUN_0000075c(param_2,param_1 + 6,*(undefined1 *)((int)param_1 + 0x17)),
         sVar1 < (short)(ushort)*(byte *)((int)param_1 + 0x17))) {
        return 0xffff;
      }
    }
  }
  return uVar2;
}


================================================================