FUNCTION FUN_00000cc8 @ 0x00000cc8 size=828
CALLERS (1): FUN_00001004@0x00001004
CALLEES (5): FUN_000049e0@0x000049e0, FUN_00000344@0x00000344, FUN_0000057c@0x0000057c, FUN_00011d90@0x00011d90, FUN_00009eec@0x00009eec

int FUN_00000cc8(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  ushort uVar3;
  ushort *puVar4;
  
  puVar4 = *(ushort **)(param_2 + 0x10);
  if ((uint)(*(int *)(param_2 + 0x14) - (int)puVar4) < 0x1c) {
    DAT_0001b854 = DAT_0001b854 + 1;
    if ((DAT_0001b850 & 1) != 0) {
      FUN_00011d90("# ERR # %s:%d: %s\n",s_arp_c_0001b3f8,0x107,"arp_rcv - bad len");
    }
  }
  else {
    *puVar4 = *puVar4 << 8 | *puVar4 >> 8;
    uVar3 = puVar4[7];
    puVar4[1] = puVar4[1] << 8 | puVar4[1] >> 8;
    puVar4[3] = puVar4[3] << 8 | puVar4[3] >> 8;
    uVar1 = *(undefined1 *)((int)puVar4 + 0xf);
    *(undefined1 *)(puVar4 + 7) = *(undefined1 *)((int)puVar4 + 0x11);
    *(char *)((int)puVar4 + 0xf) = (char)puVar4[8];
    *(undefined1 *)(puVar4 + 8) = uVar1;
    *(char *)((int)puVar4 + 0x11) = (char)uVar3;
    uVar2 = *(undefined4 *)(puVar4 + 0xc);
    *(char *)(puVar4 + 0xc) = (char)((uint)uVar2 >> 0x18);
    *(char *)((int)puVar4 + 0x19) = (char)((uint)uVar2 >> 0x10);
    *(char *)(puVar4 + 0xd) = (char)((uint)uVar2 >> 8);
    *(char *)((int)puVar4 + 0x1b) = (char)uVar2;
    if (((*puVar4 == 1) && (puVar4[1] == 0x800)) && (puVar4[2] == 0x406)) {
      if ((puVar4[3] != 0) && (puVar4[3] < 3)) {
        FUN_00000344(param_1,*(undefined4 *)(puVar4 + 7),puVar4 + 4);
        if (puVar4[3] == 2) {
          FUN_00000344(param_1,*(undefined4 *)(puVar4 + 0xc),puVar4 + 9);
        }
        if (puVar4[3] == 1) {
          FUN_0000057c(param_1,puVar4);
        }
        else if (((param_1 != 0) && ((*(uint *)(param_1 + 0x48) & 0x20) != 0)) &&
                (*(int *)(param_1 + 0x70) == 0)) {
          FUN_000049e0(param_1,*(undefined4 *)(puVar4 + 7));
        }
      }
      param_2 = FUN_00009eec(param_2);
    }
    else if ((DAT_0001b850 & 1) != 0) {
      FUN_00011d90("# ERR # %s:%d: %s\n",s_arp_c_0001b3f8,0x10e,"arp_rcv - bad data");
    }
  }
  return param_2;
}


================================================================