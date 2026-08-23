FUNCTION FUN_00001cdc @ 0x00001cdc size=884
CALLERS (3): FUN_000032bc@0x000032bc, FUN_000036ac@0x000036ac, FUN_000027e4@0x000027e4
CALLEES (13): FUN_00009650@0x00009650, FUN_00001bf4@0x00001bf4, FUN_0000198c@0x0000198c, FUN_00009638@0x00009638, FUN_00009180@0x00009180, FUN_000090f0@0x000090f0, FUN_00001ba8@0x00001ba8, FUN_00009330@0x00009330, FUN_000014ac@0x000014ac, FUN_00009284@0x00009284, FUN_00009138@0x00009138, FUN_00009658@0x00009658, FUN_00001a28@0x00001a28

int FUN_00001cdc(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined1 auStack_3b8 [256];
  undefined1 auStack_2b8 [256];
  undefined1 auStack_1b8 [64];
  undefined1 auStack_178 [6];
  undefined1 auStack_172 [258];
  undefined1 auStack_70 [8];
  int local_68;
  int local_30;
  
  bVar2 = true;
  local_30 = 1;
  iVar3 = FUN_0000198c(auStack_3b8,0x100,param_1);
  iVar4 = 0;
  if (iVar3 != 0) {
    iVar3 = FUN_000090f0(auStack_3b8);
    if (iVar3 < 0) {
      iVar4 = 0;
      if (iVar3 == -5) {
        iVar4 = -0x12;
      }
    }
    else {
LAB_00001d78:
      do {
        iVar4 = FUN_00009138(iVar3,auStack_1b8);
        if (iVar4 < 1) {
          if (iVar4 != -5) {
            FUN_00009284(iVar3);
            iVar3 = FUN_00009658(param_1,&DAT_00009978,2);
            if (iVar3 != 0) {
              return iVar4;
            }
            if ((!bVar2) && (local_30 == 0)) {
              return iVar4;
            }
            iVar3 = FUN_00001a28(param_1,param_3,param_4);
            return iVar3;
          }
          break;
        }
        iVar4 = FUN_00009650(auStack_178);
        if (iVar4 == 10) {
          iVar4 = FUN_00009658(auStack_172,&DAT_000099cc,4);
          if ((iVar4 == 0) || (iVar4 = FUN_00009658(auStack_172,&DAT_000099d4,4), iVar4 == 0)) {
            bVar1 = true;
            for (pcVar5 = param_2; (pcVar5 != (char *)0x0 && (*pcVar5 != '\0'));
                pcVar5 = (char *)FUN_00001ba8(pcVar5)) {
              FUN_00001bf4(auStack_2b8,pcVar5,2);
              iVar4 = FUN_00009638(auStack_178,auStack_2b8);
              if (iVar4 == 0) {
                bVar1 = false;
              }
            }
            if (!bVar1) goto LAB_00001d78;
          }
        }
        else {
          iVar4 = FUN_00009658(param_1,&DAT_00009978,2);
          if (iVar4 == 0) {
            iVar4 = FUN_00009638(auStack_178,"SYS_NET.ICO");
            if (iVar4 == 0) {
              FUN_000014ac(auStack_2b8,0x100,auStack_3b8,auStack_178);
              FUN_00009330(auStack_2b8,auStack_70);
              if (local_68 == 0x8398) {
                bVar2 = false;
              }
              else {
LAB_00001ed4:
                iVar4 = FUN_00009180(auStack_2b8);
joined_r0x00001f68:
                if (iVar4 == -5) break;
              }
            }
            else {
              iVar4 = FUN_00009638(auStack_178,"icon.sys");
              if (iVar4 == 0) {
                FUN_000014ac(auStack_2b8,0x100,auStack_3b8,auStack_178);
                FUN_00009330(auStack_2b8,auStack_70);
                if (local_68 != 0x3c4) goto LAB_00001ed4;
                local_30 = 0;
              }
              else {
                iVar4 = FUN_00009638(auStack_178,"BWNETCNF");
                if (iVar4 != 0) {
                  FUN_000014ac(auStack_2b8,0x100,auStack_3b8,auStack_178);
                  iVar4 = FUN_00009180(auStack_2b8);
                  goto joined_r0x00001f68;
                }
              }
            }
          }
          iVar4 = FUN_00009658(param_1,&DAT_0000997c,3);
          if ((iVar4 != 0) || (iVar4 = FUN_00009638(auStack_178,"net.db"), iVar4 == 0))
          goto LAB_00001d78;
        }
        FUN_000014ac(auStack_2b8,0x100,auStack_3b8,auStack_178);
        iVar4 = FUN_00009180(auStack_2b8);
      } while (iVar4 != -5);
      FUN_00009284(iVar3);
      iVar4 = -0x12;
    }
  }
  return iVar4;
}


================================================================