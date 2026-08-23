FUNCTION FUN_00004dd0 @ 0x00004dd0 size=148
CALLERS (3): FUN_000065bc@0x000065bc, FUN_000007d4@0x000007d4, FUN_000062ec@0x000062ec
CALLEES (0): 

void FUN_00004dd0(int param_1)

{
  undefined **ppuVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_0000abd4;
  if (PTR_DAT_0000abdc != (undefined *)0x0) {
    ppuVar1 = &PTR_DAT_0000abdc;
    do {
      switch(*puVar2) {
      case 0x31:
      case 0x62:
      case 99:
        ppuVar1[-1][param_1] = 0xff;
        break;
      case 0x34:
      case 0x44:
      case 0x4c:
      case 0x50:
      case 0x54:
        *(undefined4 *)(ppuVar1[-1] + param_1) = 0xffffffff;
      }
      ppuVar1 = ppuVar1 + 3;
      puVar2 = puVar2 + 3;
    } while (*ppuVar1 != (undefined *)0x0);
  }
  return;
}


================================================================