
undefined4 FUN_001d46ec(undefined4 param_1,ushort param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  ushort uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  
  uStack_1c = param_1;
  FUN_001e1d88();
  puVar1 = (undefined4 *)FUN_001e1e4c(0x624);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    FUN_00106b60(puVar1,0,0x624);
    FUN_00109eb8(puVar1 + 5,param_1);
    *(undefined2 *)(puVar1 + 2) = 0;
    puVar1[3] = 0;
    uVar2 = FUN_001e2928(uStack_1c);
    puVar1[0xf] = uVar2;
    puVar1[0x143] = 0;
    *(undefined2 *)((int)puVar1 + 10) = 2000;
    puVar1[4] = 0;
    puVar1[0x10] = (uint)param_2;
    *(undefined1 *)(puVar1 + 0x135) = 0x53;
    *(undefined1 *)((int)puVar1 + 0x4d5) = 0x4e;
    *(undefined1 *)((int)puVar1 + 0x4d6) = 0x41;
    *(undefined1 *)((int)puVar1 + 0x4d7) = 0x50;
    *(undefined1 *)(puVar1 + 0x136) = 0x2d;
    *(undefined1 *)((int)puVar1 + 0x4d9) = 0x53;
    *(undefined1 *)((int)puVar1 + 0x4da) = 0x57;
    *(undefined1 *)((int)puVar1 + 0x4db) = 0x41;
    *(undefined1 *)(puVar1 + 0x137) = 0x4e;
    *(undefined1 *)((int)puVar1 + 0x4dd) = 0;
    iStack_18 = FUN_001ebed0(puVar1 + 0x148,0x6e,0xf,10);
    if (iStack_18 == 0) {
      FUN_001e2610(puVar1[0x148],param_3);
      lVar4 = FUN_001e1468(0x10);
      puVar1[0x16] = (int)lVar4;
      if (lVar4 == 0) {
        FUN_001ecdc0(puVar1[0x148]);
        FUN_001e2010(puVar1);
        uVar2 = 0xfffffffe;
      }
      else {
        lVar4 = FUN_001e1590(0x10);
        puVar1[0x17] = (int)lVar4;
        if (lVar4 == 0) {
          FUN_001e14e8(puVar1,puVar1[0x16]);
          FUN_001ecdc0(puVar1[0x148]);
          FUN_001e2010(puVar1);
          uVar2 = 0xfffffffd;
        }
        else {
          lVar4 = FUN_001d51e0(0x24);
          puVar1[0x18] = (int)lVar4;
          if (lVar4 == 0) {
            FUN_001e14e8(puVar1,puVar1[0x16]);
            FUN_001e1608(puVar1,puVar1[0x17]);
            FUN_001ecdc0(puVar1[0x148]);
            FUN_001e2010(puVar1);
            uVar2 = 0xfffffffc;
          }
          else {
            iStack_18 = FUN_001eb22c(puVar1 + 0x1a,0);
            if (iStack_18 == 0) {
              lVar4 = FUN_001e270c(2,2,0);
              *puVar1 = (int)lVar4;
              if (lVar4 == -1) {
                FUN_001d5138(puVar1,puVar1[0x18]);
                FUN_001e14e8(puVar1,puVar1[0x16]);
                FUN_001e1608(puVar1,puVar1[0x17]);
                FUN_001ecdc0(puVar1[0x148]);
                FUN_001e2010(puVar1);
                uVar2 = 0xfffffff8;
              }
              else {
                uStack_20 = 2000;
                while( true ) {
                  FUN_00102790(&uStack_30,0x10);
                  uStack_2e = FUN_001e234c(uStack_20);
                  uStack_30 = 2;
                  lVar4 = FUN_001e3100(*puVar1,&uStack_30,0x10);
                  if (-1 < lVar4) break;
                  uStack_20 = uStack_20 + 1;
                }
                puVar1[1] = *puVar1;
                *(ushort *)((int)puVar1 + 10) = uStack_20;
                iVar3 = FUN_001e2394(puVar1[0xf]);
                puVar1[0x11] = iVar3 << 0x10 | (uint)uStack_20;
                puVar1[0x142] = 0;
                DAT_0025b78c = puVar1;
                puVar1[0x145] = 0x22;
                puVar1[0x146] = 4;
                if (param_3 != 0) {
                  for (iStack_14 = 0; *(int *)(iStack_14 * 4 + param_3) != 0;
                      iStack_14 = iStack_14 + 1) {
                    lVar4 = FUN_00109d70(*(undefined4 *)(iStack_14 * 4 + param_3),0x259290);
                    if (lVar4 == 0) {
                      iStack_14 = iStack_14 + 1;
                      uVar2 = FUN_00102678(*(undefined4 *)(iStack_14 * 4 + param_3));
                      puVar1[0x145] = uVar2;
                    }
                    else {
                      lVar4 = FUN_00109d70(*(undefined4 *)(iStack_14 * 4 + param_3),0x2592a0);
                      if (lVar4 == 0) {
                        iStack_14 = iStack_14 + 1;
                        uVar2 = FUN_00102678(*(undefined4 *)(iStack_14 * 4 + param_3));
                        puVar1[0x146] = uVar2;
                      }
                      else {
                        iStack_14 = iStack_14 + 1;
                      }
                    }
                  }
                }
                puVar1[0x144] = puVar1[0x145];
                puVar1[0x149] = 0;
                puVar1[0x14a] = 0;
                puVar1[0x14b] = 0;
                puVar1[0x14c] = 0;
                puVar1[0x14d] = 0;
                puVar1[0x14e] = 0;
                puVar1[0x14f] = 0;
                puVar1[0x150] = 0;
                puVar1[0x151] = 0;
                uVar2 = 1;
              }
            }
            else {
              FUN_001d5138(puVar1,puVar1[0x18]);
              FUN_001e14e8(puVar1,puVar1[0x16]);
              FUN_001e1608(puVar1,puVar1[0x17]);
              FUN_001ecdc0(puVar1[0x148]);
              FUN_001e2010(puVar1);
              uVar2 = 0xfffffffb;
            }
          }
        }
      }
    }
    else {
      FUN_001e2010(puVar1);
      uVar2 = 0xffffff9d;
    }
  }
  return uVar2;
}

