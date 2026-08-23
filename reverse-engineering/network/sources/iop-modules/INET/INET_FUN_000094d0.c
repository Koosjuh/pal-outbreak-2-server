FUNCTION FUN_000094d0 @ 0x000094d0 size=156
CALLERS (1): FUN_00009768@0x00009768
CALLEES (0): 

int FUN_000094d0(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  undefined **ppuVar4;
  int iVar5;
  
  iVar5 = 0x1b1e0;
  if (PTR_s_PROTO_0001b1e4 != (undefined *)0x0) {
    ppuVar4 = &PTR_s_PROTO_0001b1e4;
    do {
      pcVar3 = *ppuVar4;
      pcVar2 = (char *)(param_1 + 1);
      if (*(char *)(param_1 + 1) == *pcVar3) {
        pcVar1 = (char *)(param_1 + 2);
        do {
          pcVar2 = pcVar1;
          pcVar3 = pcVar3 + 1;
          pcVar1 = pcVar2 + 1;
        } while (*pcVar2 == *pcVar3);
      }
      if ((*pcVar2 == '>') && (*pcVar3 == '\0')) {
        return iVar5;
      }
      ppuVar4 = ppuVar4 + 5;
      iVar5 = iVar5 + 0x14;
    } while (*ppuVar4 != (undefined *)0x0);
  }
  return 0;
}


================================================================