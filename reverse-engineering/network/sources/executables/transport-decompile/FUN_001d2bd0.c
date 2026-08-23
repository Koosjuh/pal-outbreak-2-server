
void FUN_001d2bd0(void)

{
  undefined *puVar1;
  code *pcVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  undefined **ppuVar6;
  int aiStack_10 [4];
  
  FUN_00106b60(piRam003435d0,0,0x300000);
  FUN_001d2b30();
  uVar4 = 0;
  piVar5 = piRam003435d0;
  do {
    uVar4 = uVar4 + 1;
    *piVar5 = (int)piRam003435d0 + *piVar5;
    piVar3 = piRam003435d0;
    piVar5 = piVar5 + 2;
  } while (uVar4 < 0x20);
  ppuVar6 = &PTR_FUN_0024d050;
  aiStack_10[0] = 0;
  aiStack_10[2] = (int)piRam003435d0 + 0x180003U & 0xfffffffc;
  aiStack_10[1] = 0;
LAB_001d2dcc:
  do {
    if (ppuVar6[3] == (undefined *)0x3e7) {
      return;
    }
    if (ppuVar6[1] != (undefined *)0x63) {
      puVar1 = ppuVar6[2];
      if (puVar1 != (undefined *)0x63) {
        piVar5 = piVar3 + (int)ppuVar6[1] * 2;
        if ((*piVar5 == 0) || (piVar5[1] == 0)) {
          aiStack_10[(int)puVar1] = 0;
        }
        else {
          if (puVar1 == (undefined *)0x1) {
            aiStack_10[3] = aiStack_10[2] + aiStack_10[0] + 3U & 0xfffffffc;
          }
          FUN_001840d0(aiStack_10[(int)(puVar1 + 2)]);
          aiStack_10[(int)ppuVar6[2]] = piVar5[1];
        }
      }
    }
    pcVar2 = (code *)*ppuVar6;
    if (pcVar2 != (code *)0x0) {
      puVar1 = ppuVar6[3];
      if (puVar1 == (undefined *)0x2) {
        if ((aiStack_10[0] != 0) && (aiStack_10[1] != 0)) {
          (*pcVar2)(aiStack_10[2],aiStack_10[3]);
        }
      }
      else if (puVar1 == (undefined *)0x1) {
        if (aiStack_10[1] != 0) {
          (*pcVar2)(aiStack_10[3]);
        }
      }
      else if (puVar1 == (undefined *)0x0) {
        if (aiStack_10[0] != 0) {
          (*pcVar2)(aiStack_10[2]);
        }
      }
      else {
        if (puVar1 != (undefined *)0x63) {
          ppuVar6 = ppuVar6 + 4;
          goto LAB_001d2dcc;
        }
        (*pcVar2)();
      }
    }
    ppuVar6 = ppuVar6 + 4;
  } while( true );
}

