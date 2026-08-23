FUNCTION FUN_00000da8 @ 0x00000da8 size=572
CALLERS (2): FUN_00005e78@0x00005e78, FUN_00008614@0x00008614
CALLEES (10): FUN_00000d10@0x00000d10, FUN_00001374@0x00001374, FUN_000092cc@0x000092cc, FUN_000094b8@0x000094b8, FUN_00008ddc@0x00008ddc, FUN_000091c8@0x000091c8, FUN_00009470@0x00009470, FUN_00009028@0x00009028, FUN_00001284@0x00001284, FUN_00001324@0x00001324

int FUN_00000da8(undefined4 param_1,int *param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar3 = FUN_00000d10();
  if (-1 < iVar3) {
    FUN_00001284(&DAT_0000b208);
    iVar4 = FUN_00008ddc(param_1,1,0);
    if (iVar4 < 0) {
      iVar3 = -3;
      if (iVar4 == -5) {
        iVar3 = -0x12;
      }
    }
    else {
      iVar3 = FUN_000092cc(iVar4);
      if (iVar3 < 0) {
        FUN_000091c8(iVar4);
      }
      else {
        puVar5 = (ushort *)FUN_00009470(iVar3 + 1);
        *param_2 = (int)puVar5;
        if (puVar5 == (ushort *)0x0) {
          FUN_000091c8(iVar4);
          iVar3 = -2;
        }
        else {
          iVar7 = 0;
          iVar6 = 0;
          iVar8 = iVar3;
          while (iVar3 = iVar6, iVar8 != 0) {
            if (iVar8 < 2) {
              iVar6 = FUN_00009028(iVar4,puVar5,1);
              if (iVar6 < 0) {
                FUN_000094b8(*param_2);
                FUN_000091c8(iVar4);
                return -4;
              }
              uVar2 = *puVar5;
              *(byte *)puVar5 = ~(byte)uVar2;
              iVar6 = iVar7 + 1;
              bVar1 = FUN_00001324(~(byte)uVar2,(&DAT_0000b1f0)[iVar7]);
              *(byte *)puVar5 = bVar1;
              iVar7 = 0;
              if (iVar6 != 0x18) {
                iVar7 = iVar6;
              }
              iVar8 = iVar8 + -1;
              iVar6 = iVar3 + 1;
            }
            else {
              iVar6 = FUN_00009028(iVar4,puVar5,2);
              if (iVar6 < 0) {
                FUN_000094b8(*param_2);
                FUN_000091c8(iVar4);
                if (iVar6 == -5) {
                  return -0x12;
                }
                return -4;
              }
              uVar2 = *puVar5;
              *puVar5 = ~uVar2;
              iVar6 = iVar7 + 1;
              uVar2 = FUN_00001374(~uVar2,(&DAT_0000b1f0)[iVar7]);
              *puVar5 = uVar2;
              iVar7 = 0;
              if (iVar6 != 0x18) {
                iVar7 = iVar6;
              }
              puVar5 = puVar5 + 1;
              iVar8 = iVar8 + -2;
              iVar6 = iVar3 + 2;
            }
          }
          *(undefined1 *)(*param_2 + iVar3) = 0;
          FUN_000091c8(iVar4);
        }
      }
    }
  }
  return iVar3;
}


================================================================