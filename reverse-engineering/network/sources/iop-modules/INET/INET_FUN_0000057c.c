FUNCTION FUN_0000057c @ 0x0000057c size=860
CALLERS (2): FUN_00000cc8@0x00000cc8, FUN_000008d8@0x000008d8
CALLEES (4): FUN_0000df10@0x0000df10, FUN_00011d90@0x00011d90, FUN_0000a9c0@0x0000a9c0, FUN_00009e60@0x00009e60

void FUN_0000057c(int param_1,int param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 *puVar5;
  ushort *puVar6;
  int iVar7;
  
  if (param_1 == 0) {
    if ((DAT_0001b850 & 1) != 0) {
      FUN_00011d90("# ERR # %s:%d: %s\n",s_arp_c_0001b3f8,0xa8,"arp_snd_reply - no ops");
    }
  }
  else {
    iVar7 = *(int *)(param_1 + 0x70);
    if ((iVar7 != 0) && (iVar7 == *(int *)(param_2 + 0x18))) {
      iVar4 = FUN_00009e60(0,0x2a);
      if (iVar4 == 0) {
        if ((DAT_0001b850 & 1) != 0) {
          FUN_00011d90("# ERR # %s:%d: %s\n",s_arp_c_0001b3f8,0xae,"arp_snd_reply - no space");
        }
      }
      else {
        puVar5 = *(undefined2 **)(iVar4 + 0x14);
        puVar5[6] = 0x806;
        *puVar5 = *(undefined2 *)(param_2 + 8);
        puVar5[1] = *(undefined2 *)(param_2 + 10);
        puVar5[2] = *(undefined2 *)(param_2 + 0xc);
        puVar5[3] = *(undefined2 *)(param_1 + 0x88);
        puVar5[4] = *(undefined2 *)(param_1 + 0x8a);
        puVar5[5] = *(undefined2 *)(param_1 + 0x8c);
        *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + 0xe;
        puVar5[6] = puVar5[6] << 8 | (ushort)puVar5[6] >> 8;
        puVar6 = *(ushort **)(iVar4 + 0x14);
        *puVar6 = 1;
        puVar6[1] = 0x800;
        *(undefined1 *)(puVar6 + 2) = 6;
        *(undefined1 *)((int)puVar6 + 5) = 4;
        puVar6[3] = 2;
        puVar6[4] = *(ushort *)(param_1 + 0x88);
        puVar6[5] = *(ushort *)(param_1 + 0x8a);
        uVar2 = *(ushort *)(param_1 + 0x8c);
        *(char *)(puVar6 + 7) = (char)iVar7;
        puVar6[6] = uVar2;
        *(char *)((int)puVar6 + 0xf) = (char)((uint)iVar7 >> 8);
        *(char *)(puVar6 + 8) = (char)((uint)iVar7 >> 0x10);
        *(char *)((int)puVar6 + 0x11) = (char)((uint)iVar7 >> 0x18);
        puVar6[9] = *(ushort *)(param_2 + 8);
        puVar6[10] = *(ushort *)(param_2 + 10);
        puVar6[0xb] = *(ushort *)(param_2 + 0xc);
        FUN_0000a9c0(param_2 + 0xe,puVar6 + 0xc,4);
        *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + 0x1c;
        uVar2 = puVar6[7];
        *puVar6 = *puVar6 << 8 | *puVar6 >> 8;
        puVar6[1] = puVar6[1] << 8 | puVar6[1] >> 8;
        puVar6[3] = puVar6[3] << 8 | puVar6[3] >> 8;
        uVar1 = *(undefined1 *)((int)puVar6 + 0xf);
        *(undefined1 *)(puVar6 + 7) = *(undefined1 *)((int)puVar6 + 0x11);
        *(char *)((int)puVar6 + 0xf) = (char)puVar6[8];
        *(undefined1 *)(puVar6 + 8) = uVar1;
        *(char *)((int)puVar6 + 0x11) = (char)uVar2;
        uVar3 = *(undefined4 *)(puVar6 + 0xc);
        *(char *)(puVar6 + 0xc) = (char)((uint)uVar3 >> 0x18);
        *(char *)((int)puVar6 + 0x19) = (char)((uint)uVar3 >> 0x10);
        *(char *)(puVar6 + 0xd) = (char)((uint)uVar3 >> 8);
        *(char *)((int)puVar6 + 0x1b) = (char)uVar3;
        FUN_0000df10(param_1,iVar4);
      }
    }
  }
  return;
}


================================================================