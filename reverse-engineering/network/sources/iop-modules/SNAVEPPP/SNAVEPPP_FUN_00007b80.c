FUNCTION FUN_00007b80 @ 0x00007b80 size=548
CALLERS (1): FUN_00007660@0x00007660
CALLEES (1): FUN_00007da4@0x00007da4

undefined4 FUN_00007b80(int param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  uint uVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  byte *pbVar7;
  
  sVar3 = FUN_00007da4();
  pbVar7 = (byte *)(param_1 + sVar3);
  if (*pbVar7 == 0) {
    uVar4 = 0;
  }
  else {
    bVar6 = false;
    if (*pbVar7 == 0x22) {
      iVar5 = 0;
      bVar1 = pbVar7[1];
      pbVar7 = pbVar7 + 2;
      do {
        uVar2 = (uint)bVar1;
        if ((uVar2 == 0) || (uVar2 == 10)) goto LAB_00007d54;
        if (iVar5 == 0) {
          iVar5 = 0;
          if (bVar6) {
            if (uVar2 == 0x72) {
              *param_2 = 0xd;
              param_2 = param_2 + 1;
            }
            else if (uVar2 == 0x6e) {
              *param_2 = 10;
              param_2 = param_2 + 1;
            }
            else if ((uVar2 == 0x5c) || (uVar2 == 0x22)) {
              *param_2 = bVar1;
              param_2 = param_2 + 1;
            }
            else {
              bVar6 = false;
              if (uVar2 != 0x78) goto LAB_00007ce4;
              iVar5 = 2;
            }
            bVar6 = false;
          }
          else {
            if (uVar2 != 0x5c) {
              if (uVar2 != 0x22) {
                *param_2 = bVar1;
                goto LAB_00007ce0;
              }
              pbVar7 = pbVar7 + 1;
              goto LAB_00007d54;
            }
            bVar6 = true;
          }
        }
        else if (uVar2 - 0x30 < 10) {
          iVar5 = iVar5 + -1;
          if (iVar5 == 0) {
            *param_2 = bVar1;
LAB_00007ce0:
            param_2 = param_2 + 1;
          }
        }
        else {
          iVar5 = iVar5 + -1;
          if (uVar2 - 0x61 < 6) {
            if (iVar5 == 0) {
              *param_2 = bVar1;
              goto LAB_00007ce0;
            }
          }
          else {
            iVar5 = 0;
          }
        }
LAB_00007ce4:
        bVar1 = *pbVar7;
        pbVar7 = pbVar7 + 1;
      } while( true );
    }
    bVar1 = *pbVar7;
    while ((((pbVar7 = pbVar7 + 1, bVar1 != 0 && (bVar1 != 10)) && (bVar1 != 0x20)) &&
           ((bVar1 != 0x2c && (bVar1 != 0x22))))) {
      *param_2 = bVar1;
      param_2 = param_2 + 1;
      bVar1 = *pbVar7;
    }
LAB_00007d54:
    *param_2 = 0;
    sVar3 = FUN_00007da4(pbVar7 + -1);
    pbVar7 = pbVar7 + -1 + sVar3;
    if (*pbVar7 == 0x2c) {
      pbVar7 = pbVar7 + 1;
    }
    *param_3 = pbVar7;
    uVar4 = 1;
  }
  return uVar4;
}


================================================================