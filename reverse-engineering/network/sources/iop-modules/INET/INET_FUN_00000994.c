FUNCTION FUN_00000994 @ 0x00000994 size=792
CALLERS (3): FUN_00004b68@0x00004b68, FUN_00001108@0x00001108, FUN_000000c4@0x000000c4
CALLEES (4): FUN_0000df10@0x0000df10, FUN_0000ae24@0x0000ae24, FUN_00011d90@0x00011d90, FUN_00009e60@0x00009e60

void FUN_00000994(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 *puVar5;
  code *pcVar6;
  undefined2 *puVar7;
  ushort *puVar8;
  ushort *puVar9;
  undefined4 uVar10;
  
  uVar10 = 0;
  if (param_1 != 0) {
    uVar10 = *(undefined4 *)(param_1 + 0x70);
  }
  iVar4 = FUN_00009e60(0,0x2a);
  uVar3 = DAT_0001b3e8;
  if (iVar4 == 0) {
    if ((DAT_0001b850 & 1) != 0) {
      FUN_00011d90("# ERR # %s:%d: %s\n",s_arp_c_0001b3f8,0xe2,"arp_snd_request - no space");
    }
  }
  else {
    puVar7 = *(undefined2 **)(iVar4 + 0x14);
    puVar7[6] = 0x806;
    *puVar7 = uVar3;
    puVar7[1] = DAT_0001b3ea;
    puVar5 = (undefined2 *)0x0;
    puVar7[2] = DAT_0001b3ec;
    if (param_1 != 0) {
      puVar5 = (undefined2 *)(param_1 + 0x88);
    }
    pcVar6 = (code *)0x2;
    puVar7[3] = *puVar5;
    if (param_1 != 0) {
      pcVar6 = (code *)(param_1 + 0x8a);
    }
    puVar5 = (undefined2 *)0x4;
    puVar7[4] = *(undefined2 *)pcVar6;
    if (param_1 != 0) {
      puVar5 = (undefined2 *)(param_1 + 0x8c);
    }
    puVar7[5] = *puVar5;
    *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + 0xe;
    puVar8 = (ushort *)0x0;
    puVar7[6] = puVar7[6] << 8 | (ushort)puVar7[6] >> 8;
    puVar9 = *(ushort **)(iVar4 + 0x14);
    puVar9[1] = 0x800;
    *(undefined1 *)(puVar9 + 2) = 6;
    *puVar9 = 1;
    *(undefined1 *)((int)puVar9 + 5) = 4;
    puVar9[3] = 1;
    if (param_1 != 0) {
      puVar8 = (ushort *)(param_1 + 0x88);
    }
    pcVar6 = (code *)0x2;
    puVar9[4] = *puVar8;
    if (param_1 != 0) {
      pcVar6 = (code *)(param_1 + 0x8a);
    }
    puVar8 = (ushort *)0x4;
    puVar9[5] = *(ushort *)pcVar6;
    if (param_1 != 0) {
      puVar8 = (ushort *)(param_1 + 0x8c);
    }
    uVar2 = *puVar8;
    *(char *)(puVar9 + 7) = (char)uVar10;
    puVar9[6] = uVar2;
    *(char *)((int)puVar9 + 0xf) = (char)((uint)uVar10 >> 8);
    *(char *)(puVar9 + 8) = (char)((uint)uVar10 >> 0x10);
    *(char *)((int)puVar9 + 0x11) = (char)((uint)uVar10 >> 0x18);
    FUN_0000ae24(puVar9 + 9,6);
    *(char *)(puVar9 + 0xc) = (char)param_2;
    *(char *)((int)puVar9 + 0x19) = (char)((uint)param_2 >> 8);
    *(char *)(puVar9 + 0xd) = (char)((uint)param_2 >> 0x10);
    *(char *)((int)puVar9 + 0x1b) = (char)((uint)param_2 >> 0x18);
    *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + 0x1c;
    uVar2 = puVar9[7];
    *puVar9 = *puVar9 << 8 | *puVar9 >> 8;
    puVar9[1] = puVar9[1] << 8 | puVar9[1] >> 8;
    puVar9[3] = puVar9[3] << 8 | puVar9[3] >> 8;
    uVar1 = *(undefined1 *)((int)puVar9 + 0xf);
    *(undefined1 *)(puVar9 + 7) = *(undefined1 *)((int)puVar9 + 0x11);
    *(char *)((int)puVar9 + 0xf) = (char)puVar9[8];
    *(undefined1 *)(puVar9 + 8) = uVar1;
    *(char *)((int)puVar9 + 0x11) = (char)uVar2;
    uVar10 = *(undefined4 *)(puVar9 + 0xc);
    *(char *)(puVar9 + 0xc) = (char)((uint)uVar10 >> 0x18);
    *(char *)((int)puVar9 + 0x19) = (char)((uint)uVar10 >> 0x10);
    *(char *)(puVar9 + 0xd) = (char)((uint)uVar10 >> 8);
    *(char *)((int)puVar9 + 0x1b) = (char)uVar10;
    FUN_0000df10(param_1,iVar4);
  }
  return;
}


================================================================