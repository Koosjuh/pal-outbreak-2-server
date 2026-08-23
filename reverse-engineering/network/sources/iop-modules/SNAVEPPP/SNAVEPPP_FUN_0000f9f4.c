FUNCTION FUN_0000f9f4 @ 0x0000f9f4 size=596
CALLERS (2): FUN_0000f42c@0x0000f42c, FUN_0000e90c@0x0000e90c
CALLEES (2): FUN_00000710@0x00000710, FUN_0000075c@0x0000075c

uint FUN_0000f9f4(ushort *param_1,undefined4 *param_2)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ushort *puVar8;
  uint uVar9;
  ushort local_30;
  ushort local_2e;
  uint local_2c;
  uint local_28;
  byte local_24;
  byte local_23;
  ushort local_22;
  ushort local_20;
  ushort local_1e;
  
  uVar3 = FUN_0000075c(param_2,&local_30,0x14);
  *param_1 = local_30 << 8 | local_30 >> 8;
  param_1[1] = local_2e << 8 | local_2e >> 8;
  *(uint *)(param_1 + 2) =
       local_2c >> 0x18 | local_2c >> 8 & 0xff00 | (local_2c & 0xff00) << 8 | local_2c << 0x18;
  *(uint *)(param_1 + 4) =
       local_28 >> 0x18 | local_28 >> 8 & 0xff00 | (local_28 & 0xff00) << 8 | local_28 << 0x18;
  *(byte *)((int)param_1 + 0x15) = local_23 & 0x20;
  *(byte *)(param_1 + 0xb) = local_23 & 0x10;
  *(byte *)((int)param_1 + 0x17) = local_23 & 8;
  *(byte *)(param_1 + 0xc) = local_23 & 4;
  *(byte *)((int)param_1 + 0x19) = local_23 & 2;
  *(byte *)(param_1 + 0xd) = local_23 & 1;
  param_1[6] = local_22 << 8 | local_22 >> 8;
  uVar9 = (local_24 & 0xf0) >> 2;
  param_1[7] = local_20 << 8 | local_20 >> 8;
  param_1[9] = 0;
  *(char *)((int)param_1 + 0x1b) = (char)(uVar9 - 0x14);
  param_1[8] = local_1e << 8 | local_1e >> 8;
  if (0x13 < uVar3) {
    if (uVar9 < 0x14) {
      return 0xffff;
    }
    if ((uVar9 - 0x14 & 0xfc) == 0) {
      return uVar9;
    }
    bVar1 = *(byte *)((int)param_1 + 0x1b);
    sVar4 = FUN_00000710(*param_2);
    if ((short)(ushort)bVar1 <= sVar4) {
      puVar8 = param_1 + 0xe;
      FUN_0000075c(param_2,puVar8,*(undefined1 *)((int)param_1 + 0x1b));
      uVar7 = (uint)*(byte *)((int)param_1 + 0x1b);
      uVar5 = uVar7;
      while( true ) {
        if (uVar5 == 0) {
          return uVar9;
        }
        cVar2 = (char)*puVar8;
        if (cVar2 == '\0') break;
        uVar6 = 1;
        if ((cVar2 != '\x01') && (uVar6 = (uint)*(byte *)((int)puVar8 + 1), uVar6 == 0)) {
          return uVar9;
        }
        if ((cVar2 == '\x02') && (uVar6 == 4)) {
          param_1[9] = CONCAT11((char)puVar8[1],*(char *)((int)puVar8 + 3));
        }
        uVar7 = uVar7 - uVar6;
        uVar5 = uVar7 & 0xffff;
        puVar8 = (ushort *)(uVar6 + (int)puVar8);
      }
      return uVar9;
    }
  }
  return 0xffff;
}


================================================================