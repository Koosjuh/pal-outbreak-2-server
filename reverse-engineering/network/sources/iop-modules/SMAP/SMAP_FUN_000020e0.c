FUNCTION FUN_000020e0 @ 0x000020e0 size=1600
CALLERS (1): FUN_00002758@0x00002758
CALLEES (15): FUN_00002a28@0x00002a28, FUN_00002aec@0x00002aec, FUN_00002a40@0x00002a40, FUN_00002adc@0x00002adc, FUN_00002acc@0x00002acc, FUN_00001f8c@0x00001f8c, FUN_00002af4@0x00002af4, FUN_00002a48@0x00002a48, FUN_00002a50@0x00002a50, FUN_00001f60@0x00001f60, FUN_00002b40@0x00002b40, FUN_00002a58@0x00002a58, FUN_00002ae4@0x00002ae4, FUN_00002000@0x00002000, FUN_00001d70@0x00001d70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_000020e0(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  ushort *puVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  short sVar9;
  ushort local_28 [4];
  
  sVar9 = 0;
joined_r0x00002114:
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            while( true ) {
              while( true ) {
                param_1 = param_1 + -1;
                if (param_1 < 1) {
                  if (param_1 == 0) {
                    DAT_000032a0 = 0xb0000100;
                    DAT_000032a4 = &DAT_b0002000;
                    if ((_DAT_b0000004 & 1) == 0) {
                      DAT_000032a0 = 0xb0000100;
                      return 0xffffffff;
                    }
                    if (0x10 < _DAT_b0000002) {
                      FUN_00002a40(0x7c);
                      DAT_b0001000 = 1;
                      iVar2 = 9;
                      while( true ) {
                        if ((DAT_b0001000 & 1) == 0) {
                          DAT_b0001030 = 1;
                          iVar2 = 9;
                          while ((DAT_b0001030 & 1) != 0) {
                            if (iVar2 < 1) {
                              return 0xfffffffd;
                            }
                            FUN_00002b40(1000);
                            iVar2 = iVar2 + -1;
                          }
                          iVar2 = 9;
                          _DAT_b0002000 = 0x2000;
                          while( true ) {
                            if ((_DAT_b0002000 & 0x2000) == 0) {
                              DAT_b0000102 = 0;
                              puVar4 = (undefined2 *)&DAT_b0003000;
                              iVar2 = 0;
                              do {
                                *puVar4 = 0;
                                puVar4[1] = 0;
                                puVar4[2] = 0;
                                puVar4[3] = 0;
                                iVar2 = iVar2 + 1;
                                puVar4 = puVar4 + 4;
                              } while (iVar2 < 0x40);
                              puVar4 = (undefined2 *)&DAT_b0003200;
                              iVar2 = 0;
                              do {
                                *puVar4 = 0x8000;
                                puVar4[1] = 0;
                                puVar4[2] = 0;
                                puVar4[3] = 0;
                                iVar2 = iVar2 + 1;
                                puVar4 = puVar4 + 4;
                              } while (iVar2 < 0x40);
                              _DAT_b0000128 = 0x7c;
                              FUN_00002adc(local_28,8);
                              iVar2 = FUN_00002a48(local_28);
                              iVar8 = 0;
                              if (iVar2 < 0) {
                                uVar6 = 0xfffffff8;
                                if (iVar2 == -1) {
                                  uVar6 = 0xfffffffb;
                                }
                              }
                              else {
                                puVar5 = local_28;
                                do {
                                  iVar8 = iVar8 + 1;
                                  sVar9 = sVar9 + *puVar5;
                                  puVar5 = puVar5 + 1;
                                } while (iVar8 < 3);
                                if ((((local_28[0] != 0) || (local_28[1] != 0)) ||
                                    (uVar6 = 0xfffffffa, local_28[2] != 0)) &&
                                   (uVar6 = 0xfffffffa, local_28[3] == sVar9)) {
                                  _DAT_b0002004 = 0x80008164;
                                  _DAT_b000200c = 0x380f;
                                  _DAT_b0002010 = 0xc058;
                                  _DAT_b0002014 = 0x1c00000;
                                  _DAT_b0002018 = 0x1c00000;
                                  _DAT_b000201c =
                                       ((uint)(local_28[0] >> 8) | (local_28[0] & 0xff) << 8) <<
                                       0x10;
                                  _DAT_b0002020 =
                                       ((uint)(local_28[2] >> 8) | (local_28[2] & 0xff) << 8) <<
                                       0x10 | (uint)(local_28[1] >> 8) | (local_28[1] & 0xff) << 8;
                                  _DAT_b000202c = 0xffff0000;
                                  _DAT_b0002040 = 0;
                                  _DAT_b0002044 = 0;
                                  iVar2 = 2;
                                  _DAT_b0002048 = 0;
                                  _DAT_b000204c = 0;
                                  _DAT_b0002058 = 0x40000;
                                  _DAT_b0002060 = 0x6000;
                                  _DAT_b0002064 = 0x40000800;
                                  do {
                                    FUN_00002a28(iVar2,FUN_00001240);
                                    iVar2 = iVar2 + 1;
                                  } while (iVar2 < 7);
                                  FUN_00002a50(1,0x180);
                                  FUN_00002a58(1,0x1b0);
                                  uVar6 = FUN_00001d70();
                                }
                              }
                              return uVar6;
                            }
                            if (iVar2 < 1) break;
                            FUN_00002b40(1000);
                            iVar2 = iVar2 + -1;
                          }
                          return 0xfffffffc;
                        }
                        if (iVar2 < 1) break;
                        FUN_00002b40(1000);
                        iVar2 = iVar2 + -1;
                      }
                      return 0xfffffffe;
                    }
                    DAT_000032a0 = 0xb0000100;
                    return 0xfffffff9;
                  }
                  goto LAB_00002364;
                }
                param_2 = param_2 + 1;
                iVar2 = FUN_00002ae4(s__help_00003244,*param_2);
                if (iVar2 == 0) goto LAB_00002364;
                iVar2 = FUN_00002ae4("-version",*param_2);
                if (iVar2 == 0) {
                  uVar6 = FUN_00001f60();
                  return uVar6;
                }
                iVar2 = FUN_00002ae4("-verbose",*param_2);
                if (iVar2 != 0) break;
                DAT_00003200 = 1;
              }
              iVar2 = FUN_00002ae4(s__auto_0000324c,*param_2);
              if (iVar2 != 0) break;
              DAT_00003204 = 1;
            }
            iVar2 = FUN_00002ae4("-no_auto",*param_2);
            if (iVar2 != 0) break;
            DAT_00003204 = 0;
          }
          iVar2 = FUN_00002ae4(s__strap_00003254,*param_2);
          if (iVar2 != 0) break;
          DAT_00003208 = 1;
        }
        iVar2 = FUN_00002ae4("-no_strap",*param_2);
        if (iVar2 != 0) break;
        DAT_00003208 = 0;
      }
      iVar2 = FUN_00002aec(s_thpri__0000325c,*param_2,6);
      if (iVar2 != 0) break;
      iVar2 = *param_2;
      pcVar7 = (char *)(iVar2 + 6);
      uVar3 = FUN_00002acc((int)*(char *)(iVar2 + 6));
      if (((uVar3 & 4) == 0) || (DAT_000031f8 = FUN_00002af4(pcVar7,0,10), 0x72 < DAT_000031f8 - 9U)
         ) goto LAB_00002364;
      if (*(char *)(iVar2 + 6) != '\0') {
        do {
          uVar3 = FUN_00002acc((int)*pcVar7);
          if ((uVar3 & 4) == 0) goto LAB_00002354;
          pcVar7 = pcVar7 + 1;
          cVar1 = '\0';
        } while (*pcVar7 != '\0');
LAB_0000235c:
        if (cVar1 != '\0') goto LAB_00002364;
      }
    }
    iVar2 = FUN_00002aec("thstack=",*param_2,8);
    if (iVar2 == 0) {
      iVar2 = *param_2;
      pcVar7 = (char *)(iVar2 + 8);
      uVar3 = FUN_00002acc((int)*(char *)(iVar2 + 8));
      if ((uVar3 & 4) == 0) goto LAB_00002364;
      PTR_FUN_000031fc = (undefined *)FUN_00002af4(pcVar7,0,10);
      cVar1 = *(char *)(iVar2 + 8);
      while ((cVar1 != '\0' && (uVar3 = FUN_00002acc((int)*pcVar7), (uVar3 & 4) != 0))) {
        pcVar7 = pcVar7 + 1;
        cVar1 = *pcVar7;
      }
      iVar2 = FUN_00002ae4(pcVar7,&DAT_00003264);
      if (iVar2 != 0) {
LAB_00002354:
        cVar1 = *pcVar7;
        goto LAB_0000235c;
      }
      PTR_FUN_000031fc = (undefined *)((int)PTR_FUN_000031fc << 10);
      goto joined_r0x00002114;
    }
    iVar2 = FUN_00002000(*param_2,&DAT_0000320c);
    if (iVar2 != 0) {
LAB_00002364:
      uVar6 = FUN_00001f8c();
      return uVar6;
    }
  } while( true );
}


================================================================