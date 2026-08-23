FUNCTION FUN_00006478 @ 0x00006478 size=440
CALLERS (1): FUN_00007e28@0x00007e28
CALLEES (6): FUN_000060a8@0x000060a8, FUN_000062e0@0x000062e0, FUN_000086c8@0x000086c8, FUN_00009eec@0x00009eec, FUN_00006ea8@0x00006ea8, FUN_00011d90@0x00011d90

undefined4
FUN_00006478(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
            )

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  pcVar4 = *(char **)(param_5 + 0x10);
  if ((uint)(*(int *)(param_5 + 0x14) - (int)pcVar4) < 8) {
    if ((DAT_0001b850 & 1) != 0) {
      FUN_00011d90("# ERR # %s:%d: %s\n",s_icmp_c_0001b6e0,0x2f,"icmp_rcv - bad len");
    }
  }
  else {
    sVar1 = FUN_000060a8(0,pcVar4);
    if (sVar1 == -1) {
      *(ushort *)(pcVar4 + 4) = *(ushort *)(pcVar4 + 4) << 8 | *(ushort *)(pcVar4 + 4) >> 8;
      *(ushort *)(pcVar4 + 6) = *(ushort *)(pcVar4 + 6) << 8 | *(ushort *)(pcVar4 + 6) >> 8;
      *(int *)(param_5 + 0x10) = *(int *)(param_5 + 0x10) + 8;
      if (*pcVar4 == '\x03') {
        FUN_000086c8(pcVar4[1],*(undefined2 *)(pcVar4 + 4),*(undefined2 *)(pcVar4 + 6),param_5);
      }
      else if ((*pcVar4 == '\b') && (iVar2 = FUN_00006ea8(param_1,param_2), iVar2 == 0)) {
        FUN_000062e0(param_1,param_3,param_2,param_4,0,pcVar4[1],*(undefined2 *)(pcVar4 + 4),
                     *(undefined2 *)(pcVar4 + 6),param_5);
        return 0;
      }
    }
    else if ((DAT_0001b850 & 1) != 0) {
      FUN_00011d90("# ERR # %s:%d: %s\n",s_icmp_c_0001b6e0,0x31,"icmp_rcv - bad sum");
    }
  }
  uVar3 = FUN_00009eec(param_5);
  return uVar3;
}


================================================================