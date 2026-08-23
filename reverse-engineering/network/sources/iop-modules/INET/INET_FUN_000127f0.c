FUNCTION FUN_000127f0 @ 0x000127f0 size=704
CALLERS (0): 
CALLEES (3): FUN_00011d90@0x00011d90, FUN_000015c0@0x000015c0, FUN_00001530@0x00001530

void FUN_000127f0(void)

{
  char *pcVar1;
  int iVar2;
  
  FUN_00011d90("TCP out=%ld rex=%ld inp=%ld\n",DAT_0001b9f0,DAT_0001b9e8,DAT_0001b9ec);
  iVar2 = DAT_0001b9a0;
  do {
    if (iVar2 == 0) {
      return;
    }
    FUN_00011d90(&DAT_0001b8e4);
    FUN_00001530(*(undefined4 *)(iVar2 + 0x10));
    FUN_00011d90(&DAT_0001b8e8);
    FUN_000015c0(*(undefined2 *)(iVar2 + 0x18));
    FUN_00011d90(&DAT_0001b8ec);
    FUN_00001530(*(undefined4 *)(iVar2 + 0x14));
    FUN_00011d90(&DAT_0001b8e8);
    FUN_000015c0(*(undefined2 *)(iVar2 + 0x1a));
    FUN_00011d90(&DAT_0001b8f0);
    switch(*(undefined4 *)(iVar2 + 0x28)) {
    case 0:
      pcVar1 = s_Closed_0001b8f4;
      break;
    case 1:
      pcVar1 = s_Listen_0001b8fc;
      break;
    case 2:
      pcVar1 = "Syn-Sent";
      break;
    case 3:
      pcVar1 = "Syn-Received";
      break;
    case 4:
      pcVar1 = "Established";
      break;
    case 5:
      pcVar1 = "Fin-Wait-1";
      break;
    case 6:
      pcVar1 = "Fin-Wait-2";
      break;
    case 7:
      pcVar1 = "Close-Wait";
      break;
    case 8:
      pcVar1 = s_Closing_0001b904;
      break;
    case 9:
      pcVar1 = "Last-Ack";
      break;
    case 10:
      pcVar1 = "Time-Wait";
      break;
    default:
      goto switchD_000128bc_default;
    }
    FUN_00011d90(pcVar1);
switchD_000128bc_default:
    if (0 < *(int *)(iVar2 + 0x80)) {
      FUN_00011d90(s_sb__ld_0001b90c);
    }
    if (0 < *(int *)(iVar2 + 0x8c)) {
      FUN_00011d90(" una=%ld");
    }
    if (0 < *(int *)(iVar2 + 0x94)) {
      FUN_00011d90(s_rb__ld_0001b914);
    }
    if (0 < *(int *)(iVar2 + 0xb0)) {
      FUN_00011d90(" rexmit=%ld",*(int *)(iVar2 + 0xb0) / 1000);
    }
    if (0 < *(int *)(iVar2 + 0xb4)) {
      FUN_00011d90(" persist=%ld",*(int *)(iVar2 + 0xb4) / 1000);
    }
    if (0 < *(int *)(iVar2 + 0xb8)) {
      FUN_00011d90(" timewait=%ld",*(int *)(iVar2 + 0xb8) / 1000);
    }
    if (0 < *(int *)(iVar2 + 0xbc)) {
      FUN_00011d90(" user=%ld",*(int *)(iVar2 + 0xbc) / 1000);
    }
    if (0 < *(int *)(iVar2 + 0xc0)) {
      FUN_00011d90(" syn_rcvd=%ld",*(int *)(iVar2 + 0xc0) / 1000);
    }
    FUN_00011d90(&DAT_0001b91c);
    iVar2 = *(int *)(iVar2 + 4);
  } while( true );
}


================================================================