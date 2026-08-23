FUNCTION FUN_00003c4c @ 0x00003c4c size=844
CALLERS (1): FUN_000009e4@0x000009e4
CALLEES (10): FUN_00009638@0x00009638, FUN_00009180@0x00009180, FUN_0000141c@0x0000141c, FUN_000090f0@0x000090f0, FUN_000014ac@0x000014ac, FUN_00009284@0x00009284, FUN_00009138@0x00009138, FUN_000096f4@0x000096f4, FUN_00009658@0x00009658, FUN_000096bc@0x000096bc

undefined4 FUN_00003c4c(char *param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 auStack_160 [64];
  undefined1 auStack_120 [264];
  
  iVar3 = FUN_00009658(param_1,&DAT_00009978,2);
  if (iVar3 == 0) {
    cVar2 = *param_1;
    iVar3 = 0;
    cVar1 = *param_1;
    while (cVar1 != ':') {
      param_1 = param_1 + 1;
      (&DAT_0000bdf8)[iVar3] = cVar2;
      cVar2 = *param_1;
      iVar3 = iVar3 + 1;
      cVar1 = *param_1;
    }
    (&DAT_0000bdf8)[iVar3] = *param_1;
    (&DAT_0000bdf9)[iVar3] = 0;
    FUN_0000141c(&DAT_0000bdf8,0x100,"/BWNETCNF",0x4ac);
    iVar3 = FUN_000090f0(&DAT_0000bdf8);
    if (iVar3 < 0) {
LAB_00003db4:
      uVar5 = 0;
    }
    else {
      do {
        do {
          iVar4 = FUN_00009138(iVar3,auStack_160);
          if (iVar4 < 1) {
            FUN_00009284(iVar3);
            iVar3 = FUN_000096bc(&DAT_0000bdf8);
            if (iVar3 < 0) {
              return 0xfffffff9;
            }
            goto LAB_00003db4;
          }
          iVar4 = FUN_00009638(auStack_120,&DAT_00009a38);
        } while ((iVar4 == 0) || (iVar4 = FUN_00009638(auStack_120,&DAT_00009a3c), iVar4 == 0));
        FUN_000014ac(&DAT_0000bef8,0x100,&DAT_0000bdf8,auStack_120);
        iVar4 = FUN_00009180(&DAT_0000bef8);
      } while (-1 < iVar4);
      FUN_00009284(iVar3);
      uVar5 = 0xfffffff9;
    }
  }
  else {
    iVar3 = FUN_00009658(param_1,&DAT_0000997c,3);
    uVar5 = 0xffffffef;
    if (iVar3 == 0) {
      cVar2 = *param_1;
      iVar3 = 0;
      cVar1 = *param_1;
      while (cVar1 != ':') {
        param_1 = param_1 + 1;
        (&DAT_0000bdf8)[iVar3] = cVar2;
        cVar2 = *param_1;
        iVar3 = iVar3 + 1;
        cVar1 = *param_1;
      }
      (&DAT_0000bdf8)[iVar3] = *param_1;
      (&DAT_0000bdf9)[iVar3] = 0;
      FUN_0000141c(&DAT_0000bdf8,0x100,"/etc/network",0x4ca);
      iVar3 = FUN_000090f0(&DAT_0000bdf8);
      if (iVar3 < 0) {
        uVar5 = 0;
        if (iVar3 == -5) {
          uVar5 = 0xffffffee;
        }
      }
      else {
        do {
          do {
            iVar4 = FUN_00009138(iVar3,auStack_160);
            if (iVar4 < 1) {
              if (iVar4 == -5) {
                FUN_00009284(iVar3);
                return 0xffffffee;
              }
              FUN_00009284(iVar3);
              iVar3 = FUN_000096bc(&DAT_0000bdf8);
              if (iVar3 < 0) {
                if (iVar3 != -5) {
                  return 0xfffffff9;
                }
                return 0xffffffee;
              }
              iVar3 = FUN_000096f4(&DAT_0000bdf8,0);
              if (iVar3 == -5) {
                return 0xffffffee;
              }
              return 0;
            }
            iVar4 = FUN_00009638(auStack_120,&DAT_00009a38);
          } while ((iVar4 == 0) || (iVar4 = FUN_00009638(auStack_120,&DAT_00009a3c), iVar4 == 0));
          FUN_000014ac(&DAT_0000bef8,0x100,&DAT_0000bdf8,auStack_120);
          iVar4 = FUN_00009180(&DAT_0000bef8);
        } while (-1 < iVar4);
        FUN_00009284(iVar3);
        uVar5 = 0xfffffff9;
        if (iVar4 == -5) {
          uVar5 = 0xffffffee;
        }
      }
    }
  }
  return uVar5;
}


================================================================