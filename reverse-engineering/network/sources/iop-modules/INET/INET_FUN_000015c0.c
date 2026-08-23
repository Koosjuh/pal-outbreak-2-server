FUNCTION FUN_000015c0 @ 0x000015c0 size=300
CALLERS (3): FUN_000127f0@0x000127f0, FUN_000022f4@0x000022f4, FUN_00001f88@0x00001f88
CALLEES (1): FUN_00011d90@0x00011d90

void FUN_000015c0(undefined2 param_1)

{
  switch(param_1) {
  case 0:
    FUN_00011d90(&DAT_0001b400);
    break;
  default:
    FUN_00011d90(&DAT_0001b448,param_1);
    break;
  case 7:
    FUN_00011d90(&DAT_0001b404);
    break;
  case 9:
    FUN_00011d90(s_discard_0001b40c);
    break;
  case 0xd:
    FUN_00011d90(s_daytime_0001b414);
    break;
  case 0x13:
    FUN_00011d90(s_chargen_0001b41c);
    break;
  case 0x14:
    FUN_00011d90("ftp-data");
    break;
  case 0x15:
    FUN_00011d90(&DAT_0001b424);
    break;
  case 0x35:
    FUN_00011d90(s_domain_0001b428);
    break;
  case 0x43:
    FUN_00011d90(s_bootps_0001b430);
    break;
  case 0x44:
    FUN_00011d90(s_bootpc_0001b438);
    break;
  case 0x45:
    FUN_00011d90(&DAT_0001b440);
  }
  return;
}


================================================================