FUNCTION FUN_0000059c @ 0x0000059c size=472
CALLERS (3): FUN_00001c6c@0x00001c6c, FUN_00002c3c@0x00002c3c, FUN_00001b80@0x00001b80
CALLEES (3): FUN_0000018c@0x0000018c, FUN_00003d7c@0x00003d7c, FUN_00003d84@0x00003d84

uint FUN_0000059c(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined *puVar5;
  undefined1 *puVar6;
  char local_40 [32];
  undefined1 local_20 [8];
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_0000018c(param_2,4,local_20,1);
    uVar1 = 0xffffffff;
    if (iVar2 == 0) {
      iVar2 = FUN_0000018c(param_2,5,local_40,0x1f);
      uVar1 = 0xffffffff;
      if (iVar2 == 0) {
        switch(local_20[0]) {
        case 0:
          FUN_00003d7c(&DAT_00004fc8,s_Unknown_000045f0);
          break;
        case 1:
          iVar2 = FUN_00003d7c(&DAT_00004fc8,&DAT_000045f8);
          puVar6 = &DAT_00004fc8 + iVar2;
          iVar2 = 0;
          pcVar4 = local_40;
          do {
            if (*pcVar4 == '\0') break;
            puVar5 = &DAT_0000460c;
            if (0 < iVar2) {
              puVar5 = &DAT_00004608;
            }
            iVar2 = iVar2 + 1;
            iVar3 = FUN_00003d7c(puVar6,&DAT_00004600,puVar5,*pcVar4);
            puVar6 = puVar6 + iVar3;
            pcVar4 = local_40 + iVar2;
          } while (iVar2 < 7);
          break;
        case 2:
          FUN_00003d7c(&DAT_00004fc8,&DAT_00004610);
          break;
        case 3:
          FUN_00003d7c(&DAT_00004fc8,s_PCMCIA_00004618);
          break;
        case 4:
          FUN_00003d7c(&DAT_00004fc8,s_PSEUDO_00004620);
          break;
        case 5:
          FUN_00003d7c(&DAT_00004fc8,&DAT_00004628);
          break;
        default:
          FUN_00003d7c(&DAT_00004fc8,s_0x_02x_0000462c);
        }
        iVar2 = FUN_00003d84(param_1,&DAT_00004fc8);
        uVar1 = (uint)(iVar2 != 0);
      }
    }
  }
  return uVar1;
}


================================================================