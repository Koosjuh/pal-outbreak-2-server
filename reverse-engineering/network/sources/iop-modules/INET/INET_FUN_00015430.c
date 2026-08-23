FUNCTION FUN_00015430 @ 0x00015430 size=1528
CALLERS (1): FUN_00007e28@0x00007e28
CALLEES (12): FUN_00012ce8@0x00012ce8, FUN_00011d90@0x00011d90, FUN_00013b50@0x00013b50, FUN_000137c8@0x000137c8, FUN_00006ea8@0x00006ea8, FUN_00012c60@0x00012c60, FUN_0000d8cc@0x0000d8cc, FUN_00015324@0x00015324, FUN_00012ac8@0x00012ac8, FUN_00006200@0x00006200, FUN_000100c4@0x000100c4, FUN_00009eec@0x00009eec

void FUN_00015430(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  undefined4 uVar8;
  ushort *puVar9;
  int iVar10;
  uint uVar11;
  
  puVar9 = *(ushort **)(param_5 + 0x10);
  uVar2 = puVar9[6];
  *(int *)(*(int *)(param_1 + 0x1a0) + 0x2c) = *(int *)(*(int *)(param_1 + 0x1a0) + 0x2c) + 1;
  uVar11 = (uint)(byte)((byte)uVar2 >> 4) * 4;
  iVar4 = FUN_00006ea8();
  if (iVar4 == 0) {
    iVar4 = FUN_00006ea8(param_1,param_3);
    if (iVar4 != 0) goto LAB_0001549c;
    if ((uVar11 < 0x14) || (*(int *)(param_5 + 0x14) - *(int *)(param_5 + 0x10) < (int)uVar11)) {
      DAT_0001b854 = DAT_0001b854 + 1;
      if ((DAT_0001b850 & 1) != 0) {
        FUN_00011d90("# ERR # %s:%d: %s\n",s_tcp_c_0001b920,0x461,"tcp_rcv - bad len");
      }
    }
    else {
      sVar3 = FUN_00006200(6,param_2,param_3,param_5);
      if (sVar3 == -1) {
        DAT_0001b9ec = DAT_0001b9ec + 1;
        *puVar9 = *puVar9 << 8 | *puVar9 >> 8;
        puVar9[1] = puVar9[1] << 8 | puVar9[1] >> 8;
        uVar8 = *(undefined4 *)(puVar9 + 2);
        *(char *)(puVar9 + 2) = (char)((uint)uVar8 >> 0x18);
        *(char *)((int)puVar9 + 5) = (char)((uint)uVar8 >> 0x10);
        *(char *)(puVar9 + 3) = (char)((uint)uVar8 >> 8);
        *(char *)((int)puVar9 + 7) = (char)uVar8;
        uVar8 = *(undefined4 *)(puVar9 + 4);
        *(char *)(puVar9 + 4) = (char)((uint)uVar8 >> 0x18);
        *(char *)((int)puVar9 + 9) = (char)((uint)uVar8 >> 0x10);
        *(char *)(puVar9 + 5) = (char)((uint)uVar8 >> 8);
        *(char *)((int)puVar9 + 0xb) = (char)uVar8;
        puVar9[7] = puVar9[7] << 8 | puVar9[7] >> 8;
        puVar9[9] = puVar9[9] << 8 | puVar9[9] >> 8;
        *(uint *)(param_5 + 0x10) = *(int *)(param_5 + 0x10) + uVar11;
        if ((puVar9[1] == 0) || (*puVar9 == 0)) {
          iVar4 = FUN_00012ac8(0,param_3,puVar9[1],param_2,*puVar9);
          if (iVar4 != 0) goto LAB_000157a8;
          uVar8 = 0x46c;
        }
        else {
          iVar4 = FUN_00012ce8(param_3,puVar9[1],param_2,*puVar9);
          if (iVar4 != 0) {
LAB_000157a8:
            *(int *)(iVar4 + 0xc) = param_1;
            uVar6 = *(byte *)((int)puVar9 + 0xd) & 1;
            if ((*(byte *)((int)puVar9 + 0xd) & 2) != 0) {
              uVar6 = uVar6 + 1;
            }
            iVar10 = (*(int *)(param_5 + 0x14) - *(int *)(param_5 + 0x10)) + uVar6;
            iVar5 = FUN_00015324(iVar4,puVar9,iVar10,param_5);
            if (iVar5 == 0) {
              FUN_000137c8(iVar4,puVar9);
            }
            else {
              if (0x14 < uVar11) {
                uVar2 = puVar9[6];
                puVar7 = puVar9 + 10;
                do {
                  if ((puVar9 + (uint)(byte)((byte)uVar2 >> 4) * 2 <= puVar7) ||
                     (cVar1 = (char)*puVar7, cVar1 == '\0')) break;
                  if (cVar1 != '\x01') {
                    if (cVar1 == '\x02') {
                      if (*(char *)((int)puVar7 + 1) != '\x04') break;
                      *(uint *)(iVar4 + 0x54) =
                           (uint)CONCAT11((char)puVar7[1],*(char *)((int)puVar7 + 3));
                    }
                    if ((puVar9 + (uint)(byte)((byte)uVar2 >> 4) * 2 <= (ushort *)((int)puVar7 + 1))
                       || (*(byte *)((int)puVar7 + 1) < 2)) break;
                    puVar7 = (ushort *)((int)puVar7 + (*(byte *)((int)puVar7 + 1) - 1));
                  }
                  puVar7 = (ushort *)((int)puVar7 + 1);
                } while( true );
              }
              param_5 = (*(code *)(&PTR_FUN_0001b380)[*(int *)(iVar4 + 0x28)])
                                  (iVar4,puVar9,iVar10,param_5);
              if (((*(int *)(iVar4 + 0x84) == 0) && ((*(uint *)(iVar4 + 0x2c) & 0x2000000) != 0)) &&
                 ((iVar5 = *(int *)(iVar4 + 0x28), iVar5 - 3U < 2 || (iVar5 == 7)))) {
                *(uint *)(iVar4 + 0x2c) = *(uint *)(iVar4 + 0x2c) | 0x2010;
                uVar8 = 5;
                if (iVar5 == 7) {
                  uVar8 = 9;
                }
                *(undefined4 *)(iVar4 + 0x28) = uVar8;
                *(uint *)(iVar4 + 0x2c) = *(uint *)(iVar4 + 0x2c) | 0x400000;
              }
              if (((*(uint *)(iVar4 + 0x2c) & 0xf000) != 0) &&
                 ((*(int *)(iVar4 + 0x6c) == 0 || (0 < *(int *)(iVar4 + 0x40))))) {
                FUN_00013b50(iVar4);
              }
            }
            if ((*(int *)(iVar4 + 0x28) == 0) && ((*(uint *)(iVar4 + 0x2c) & 0x20000) == 0)) {
              FUN_00012c60(iVar4);
            }
            else {
              FUN_0000d8cc(iVar4 + 0xcc);
              FUN_000100c4();
            }
            goto LAB_000159fc;
          }
          uVar8 = 0x46e;
        }
        if ((DAT_0001b850 & 1) != 0) {
          FUN_00011d90("# ERR # %s:%d: %s\n",s_tcp_c_0001b920,uVar8,"tcp_rcv - no space");
        }
      }
      else {
        DAT_0001b854 = DAT_0001b854 + 1;
        if ((DAT_0001b850 & 1) != 0) {
          FUN_00011d90("# ERR # %s:%d: %s\n",s_tcp_c_0001b920,0x465,"tcp_rcv - bad sum");
        }
      }
    }
  }
  else {
LAB_0001549c:
    if ((DAT_0001b850 & 1) != 0) {
      FUN_00011d90("# ERR # %s:%d: %s\n",s_tcp_c_0001b920,0x45e,"tcp_rcv - invalid adr");
    }
  }
  *(int *)(*(int *)(param_1 + 0x1a0) + 0x34) = *(int *)(*(int *)(param_1 + 0x1a0) + 0x34) + 1;
LAB_000159fc:
  FUN_00009eec(param_5);
  return;
}


================================================================