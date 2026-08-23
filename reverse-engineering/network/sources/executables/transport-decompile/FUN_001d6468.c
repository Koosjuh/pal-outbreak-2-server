
void FUN_001d6468(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int iStack_68;
  int iStack_64;
  ushort auStack_60 [4];
  undefined4 uStack_58;
  int iStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  int iStack_40;
  
  lVar3 = FUN_001eb2d4(param_1[0x18] + 8);
  if (lVar3 != 0) {
    iStack_50 = FUN_001d5ae4(param_1);
    if (iStack_50 == 0) {
      iStack_50 = FUN_001eb434(param_1[0x18] + 8,&iStack_68);
      if (iStack_50 == 0) {
        lVar3 = FUN_001ebb90(iStack_68,0x1000);
        if (lVar3 != 0) {
          lVar3 = FUN_001ebb90(iStack_68,0x200);
          if (lVar3 != 0) {
            FUN_001d63b8(param_1,iStack_68);
          }
          uVar4 = FUN_001ed60c(iStack_68);
          FUN_001d5688(iStack_68,uVar4);
        }
        iStack_44 = param_1[0x18];
        iVar1 = FUN_001ebca8(iStack_68);
        if (param_1[0x10] == 0) {
          trap(7);
        }
        if ((uint)((iVar1 + param_1[0x10] + 0x1f) / (int)param_1[0x10]) < 0x12) {
          iStack_40 = 0x11;
        }
        else {
          iVar1 = FUN_001ebca8(iStack_68);
          iStack_40 = (iVar1 + param_1[0x10] + 0x1f) / (int)param_1[0x10];
          if (param_1[0x10] == 0) {
            trap(7);
          }
        }
        *(int *)(iStack_44 + 4) = iStack_40;
        lVar3 = FUN_001ebb90(iStack_68,0x8000);
        if (lVar3 != 0) {
          lVar3 = FUN_001ebb90(iStack_68,0x2000);
          if (lVar3 == 0) {
            if ((*(ushort *)(iStack_68 + 0x2c) & 0x8000) == 0) {
              iStack_64 = FUN_001ed6bc(iStack_68);
              FUN_001069a8(auStack_60,iStack_64,0x10);
              do {
                if ((auStack_60[0] & 0x8000) != 0) break;
                iStack_64 = FUN_001edad0(iStack_68,iStack_64,auStack_60);
              } while (iStack_64 != 0);
              if (iStack_64 != 0) {
                iVar1 = *(int *)param_1[0x16];
                *(int *)param_1[0x16] = iVar1 + 1;
                uStack_58 = FUN_001ed68c(iStack_68,iVar1);
                *(int *)(param_1[0x16] + 4) = *(int *)(param_1[0x16] + 4) + 1;
                FUN_001069a8(iStack_64,auStack_60,0x10);
              }
            }
            else {
              iVar1 = *(int *)param_1[0x16];
              *(int *)param_1[0x16] = iVar1 + 1;
              uVar2 = FUN_001ed68c(iStack_68,iVar1);
              *(undefined4 *)(iStack_68 + 0x34) = uVar2;
              *(int *)(param_1[0x16] + 4) = *(int *)(param_1[0x16] + 4) + 1;
            }
          }
          FUN_001ed4cc(iStack_68,param_2);
          iVar1 = FUN_001ebca8(iStack_68);
          if (param_1[0x10] == 0) {
            trap(7);
          }
          FUN_001ed474(iStack_68,
                       (iVar1 + param_1[0x10] + 0x1f) / (int)param_1[0x10] + param_1[0x144]);
        }
        lVar3 = FUN_001ebb90(iStack_68,0x2000);
        if (lVar3 == 0) {
          FUN_001edbb8(iStack_68);
          uStack_48 = FUN_001e2304(0xffffffffba476611);
          FUN_001ed74c(iStack_68,&uStack_48,4);
          FUN_001ebbd0(iStack_68,0x2000);
        }
        uVar4 = FUN_001ed6bc(iStack_68);
        uVar5 = FUN_001ebca8(iStack_68);
        iStack_4c = FUN_001e34dc(*param_1,uVar4,uVar5,0,param_1 + 0x12,0x10);
        iVar1 = FUN_001ebca8(iStack_68);
        if (iStack_4c == iVar1) {
          lVar3 = FUN_001ebb90(iStack_68,0x8000);
          if (lVar3 == 0) {
            iVar1 = FUN_001ec9e0(param_1[0x148],iStack_68);
          }
          else {
            iVar1 = FUN_001eb3b8(param_1[0x16] + 8,iStack_68);
          }
          if (iVar1 == 0) {
            *(undefined4 *)param_1[0x18] = param_2;
          }
        }
        else {
          param_1[0x143] = 500;
        }
      }
    }
    else {
      param_1[0x143] = 0x1f5;
    }
  }
  return;
}

