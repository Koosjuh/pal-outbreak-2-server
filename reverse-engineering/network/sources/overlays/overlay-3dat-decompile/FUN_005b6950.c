FUNCTION FUN_005b6950 @ 0x005b6950  size=828
CALLERS (1): FUN_005b25c0@0x005b25c0
CALLEES (1): FUN_005bdd60@0x005bdd60
----------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

void FUN_005b6950(int param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  long lVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char cVar9;
  int iVar10;
  char acStack_e0 [32];
  undefined1 auStack_c0 [32];
  bool bStack_a0;
  undefined1 uStack_9f;
  char cStack_9e;
  char cStack_9d;
  int aiStack_9c [2];
  char acStack_94 [54];
  undefined1 auStack_5e [51];
  undefined1 auStack_2b [16];
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined2 uStack_16;
  undefined2 uStack_10;
  undefined2 uStack_e;
  undefined2 uStack_c;
  undefined2 uStack_a;
  char cStack_2;
  char cStack_1;
  
  func_0x00106b60(&bStack_a0,0,0x9c);
  uStack_1b = (undefined1)uRam00874f9c;
  func_0x001069a8(auStack_2b,0x874fa0,0x10);
  func_0x007deac0(aiStack_9c,aiStack_9c + 1);
  bStack_a0 = aiStack_9c[0] != 0;
  uStack_9f = uRam00874f33;
  bVar1 = (bRam00337de1 & 8) != 0;
  bVar2 = (bRam00337de1 & 2) != 0;
  bVar3 = (bRam00337de1 & 1) != 0;
  if (cRam00337e05 != '\0' || (bVar3 || (bVar2 || bVar1))) {
    aiStack_9c[0] = 0;
    aiStack_9c[1] = 0;
  }
  bStack_a0 = (cRam00337e05 == '\0' && (!bVar3 && (!bVar2 && !bVar1))) && bStack_a0;
  cStack_9d = (char)uRam00874f38;
  *(ushort *)(param_1 + 0xc) = uRam00874f38 & 0xff;
  bVar1 = cRam00874f3a != '\0';
  *(char *)(param_1 + 9) = cRam00874f3a;
  if (bVar1) {
    cStack_9d = cStack_9d + '\b';
  }
  *(undefined1 *)(param_1 + 8) = uRam00874f37;
  cStack_9e = cRam00874f3b + -1;
  uStack_1a = uRam00874fd8;
  uStack_19 = uRam00874fd9;
  uStack_16 = func_0x001bf030();
  iVar8 = 0;
  iVar10 = 0;
  uStack_10 = (undefined2)uRam00354230;
  uStack_e = (undefined2)uRam00354220;
  uStack_c = (undefined2)uRam00354224;
  uStack_a = uRam00343390;
  do {
    func_0x00106b60(auStack_c0,0,0x11);
    func_0x00106b60(acStack_e0,0,0x11);
    func_0x007df500((char)iVar8,&cStack_1,&cStack_2,auStack_c0,acStack_e0);
    if ((acStack_e0[0] != '\0') &&
       (lVar5 = func_0x00109d70(acStack_e0,0x874fc0), cVar4 = cStack_1, lVar5 != 0)) {
      acStack_94[iVar10 + 3] = cStack_1;
      cVar9 = '\0';
      if (cStack_2 != '\0') {
        iVar7 = 0;
        acStack_94[iVar10 + 3] = acStack_94[iVar10 + 3] + '\b';
        while( true ) {
          uVar6 = (uint)*(ushort *)(iVar7 * 0xc + 0x3c4d50);
          cVar9 = cVar4;
          if (uVar6 == 999) break;
          if ((int)cVar4 - 1U == uVar6) {
            cStack_1 = *(char *)(iVar7 * 0xc + 0x3c4d52);
            break;
          }
          iVar7 = iVar7 + 1;
        }
      }
      cVar4 = func_0x007df7f0(cStack_1,cVar9);
      if (cVar4 == '\0') {
        acStack_94[iVar10] = '\x02';
      }
      else {
        acStack_94[iVar10] = '\x01';
      }
      func_0x00109eb8(acStack_94 + iVar10 * 0x10 + 6,auStack_c0);
      func_0x00109eb8(auStack_5e + iVar10 * 0x11,acStack_e0);
      iVar10 = iVar10 + 1;
    }
    iVar8 = iVar8 + 1;
    if (3 < iVar8) {
      FUN_005bdd60(&bStack_a0);
      *(undefined1 *)(param_1 + 0x439) = 0;
      if (cRam00874f35 == '\x03') {
        if (aiStack_9c[0] == 0) {
          *(undefined1 *)(param_1 + 0x439) = 0;
        }
        else {
          lVar5 = func_0x007df8f0();
          if (lVar5 == 0) {
            *(undefined1 *)(param_1 + 0x439) = 1;
          }
        }
      }
      return;
    }
  } while( true );
}



================================================================