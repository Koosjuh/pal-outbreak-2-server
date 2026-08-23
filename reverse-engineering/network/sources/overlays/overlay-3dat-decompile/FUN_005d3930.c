FUNCTION FUN_005d3930 @ 0x005d3930  size=3396
CALLERS (1): FUN_005d1e80@0x005d1e80
CALLEES (10): FUN_005cf5f0@0x005cf5f0, FUN_005d7540@0x005d7540, FUN_005d59f0@0x005d59f0, FUN_005dedf0@0x005dedf0, FUN_005d5c20@0x005d5c20, FUN_005d09d0@0x005d09d0, FUN_005d5a40@0x005d5a40, FUN_005d5cc0@0x005d5cc0, FUN_005d5b60@0x005d5b60, FUN_005d74a0@0x005d74a0
----------------------------------------------------------------

void FUN_005d3930(int param_1)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  
  if ((*(char *)(iRam00701070 + 0x38) == '\0') && (*(char *)(iRam00701070 + 0x3a) == '\0')) {
    param_1 = param_1 * 4;
    lVar7 = func_0x0010a050(*(undefined4 *)(*(int *)(param_1 + iRam00701068 + 0x5ffc0) + 0x60));
    if (lVar7 != 0) {
      uVar8 = func_0x0010a050(0x642e30);
      lVar7 = func_0x00106910(*(undefined4 *)(*(int *)(param_1 + iRam00701068 + 0x5ffc0) + 0x60),
                              0x642e30,uVar8);
      if (lVar7 == 0) {
        if (((*(char *)(iRam00701070 + 0x38) == '\0') && (*(char *)(iRam00701070 + 0x3a) == '\0'))
           && ((cVar1 = *(char *)(iRam00701070 + 0x2e), cVar1 != '\x01' &&
               ((cVar1 != '\b' && (cVar1 == '\n')))))) {
          FUN_005d09d0();
        }
      }
      else {
        uVar8 = func_0x0010a050(0x642e40);
        lVar7 = func_0x00106910(*(undefined4 *)(*(int *)(param_1 + iRam00701068 + 0x5ffc0) + 0x60),
                                0x642e40,uVar8);
        if (lVar7 == 0) {
          if (*(char *)(iRam00701070 + 0x2e) == '\b') {
            FUN_005d5c20(0xb);
          }
          else {
            uRam00701e18 = 1;
            FUN_005d5b60(0);
          }
        }
        else {
          uVar8 = func_0x0010a050(0x642e50);
          lVar7 = func_0x00106910(*(undefined4 *)(*(int *)(param_1 + iRam00701068 + 0x5ffc0) + 0x60)
                                  ,0x642e50,uVar8);
          if (lVar7 == 0) {
            if (*(char *)(iRam00701070 + 0x2e) == '\b') {
              FUN_005d5c20(0xc);
            }
            else {
              uRam00701e18 = 2;
              FUN_005d5b60(0);
            }
          }
          else {
            uVar8 = func_0x0010a050(0x642e60);
            lVar7 = func_0x00106910(*(undefined4 *)
                                     (*(int *)(param_1 + iRam00701068 + 0x5ffc0) + 0x60),0x642e60,
                                    uVar8);
            if (lVar7 == 0) {
              if (*(char *)(iRam00701070 + 0x2e) == '\b') {
                return;
              }
              iVar4 = func_0x0010a050(*(undefined4 *)
                                       (*(int *)(param_1 + iRam00701068 + 0x5ffc0) + 0x60));
              iVar6 = *(int *)(param_1 + iRam00701068 + 0x5ffc0);
              iVar5 = func_0x0010a050(0x642e60);
              iVar5 = *(int *)(iVar6 + 0x60) + iVar5;
              for (iVar6 = 0; iVar6 < (int)(uint)*(byte *)(iRam00701068 + 0x4f8b9);
                  iVar6 = iVar6 + 1) {
                lVar7 = func_0x0010a700(iVar5,0x642e70);
                iVar5 = (int)lVar7 + 1;
                if (lVar7 == 0) {
                  **(undefined1 **)(*(int *)(param_1 + iRam00701068 + 0x5ffc0) + 0x60) = 0;
                  goto LAB_005d3ccc;
                }
              }
              for (iVar6 = 0;
                  ((iVar6 < iVar4 && (cVar1 = *(char *)(iVar5 + iVar6), cVar1 != ';')) &&
                  (cVar1 != '\0')); iVar6 = iVar6 + 1) {
                *(char *)(*(int *)(*(int *)(param_1 + iRam00701068 + 0x5ffc0) + 0x60) + iVar6) =
                     cVar1;
              }
              *(undefined1 *)(*(int *)(*(int *)(param_1 + iRam00701068 + 0x5ffc0) + 0x60) + iVar6) =
                   0;
            }
LAB_005d3ccc:
            uVar8 = func_0x0010a050(0x642e80);
            lVar7 = func_0x00106910(*(undefined4 *)
                                     (*(int *)(param_1 + iRam00701068 + 0x5ffc0) + 0x60),0x642e80,
                                    uVar8);
            if (lVar7 == 0) {
              if (*(char *)(iRam00701070 + 0x2e) != '\b') {
                FUN_005d5cc0(0x642ea0);
                FUN_005d59f0();
              }
            }
            else {
              uVar8 = func_0x0010a050(0x642ec0);
              lVar7 = func_0x00106910(*(undefined4 *)
                                       (*(int *)(param_1 + iRam00701068 + 0x5ffc0) + 0x60),0x642ec0,
                                      uVar8);
              if (lVar7 == 0) {
                if (*(char *)(iRam00701070 + 0x2e) == '\n') {
                  if (((((*pcRam00701088 == '\0') || (pcRam00701088[0x14e] == '\0')) ||
                       (pcRam00701088[0x41] == '\0')) ||
                      ((pcRam00701088[0x4c] == '\0' || (pcRam00701088[0xcd] == '\0')))) ||
                     (pcRam00701088[0x14f] == '\0')) {
                    *(undefined1 *)(iRam00701068 + 0x68e85) = 8;
                    *(undefined1 *)(iRam00701078 + 1) = 6;
                    *(undefined1 *)(iRam00701078 + 2) = 1;
                  }
                  else {
                    *(undefined1 *)(iRam00701068 + 0x68e85) = 7;
                    *(undefined1 *)(iRam00701078 + 1) = 5;
                    *(undefined1 *)(iRam00701078 + 2) = 1;
                  }
                }
              }
              else {
                uVar8 = func_0x0010a050(0x642ee0);
                lVar7 = func_0x00106910(*(undefined4 *)
                                         (*(int *)(param_1 + iRam00701068 + 0x5ffc0) + 0x60),
                                        0x642ee0,uVar8);
                if (lVar7 == 0) {
                  if (*(char *)(iRam00701070 + 0x2e) == '\n') {
                    *(undefined1 *)(iRam00701068 + 0x68e85) = 9;
                    *(undefined1 *)(iRam00701078 + 1) = 8;
                    *(undefined1 *)(iRam00701078 + 2) = 1;
                    *(undefined1 *)(iRam00701078 + 2) = 1;
                  }
                }
                else {
                  uVar8 = func_0x0010a050(0x642f00);
                  lVar7 = func_0x00106910(*(undefined4 *)
                                           (*(int *)(param_1 + iRam00701068 + 0x5ffc0) + 0x60),
                                          0x642f00,uVar8);
                  if (lVar7 == 0) {
                    if (*(char *)(iRam00701070 + 0x2e) == '\n') {
                      *(undefined1 *)(iRam00701068 + 0x68e85) = 10;
                      *(undefined1 *)(iRam00701078 + 1) = 8;
                      *(undefined1 *)(iRam00701078 + 2) = 1;
                      *(undefined1 *)(iRam00701078 + 2) = 1;
                    }
                  }
                  else {
                    uVar8 = func_0x0010a050(0x642f20);
                    lVar7 = func_0x00106910(*(undefined4 *)
                                             (*(int *)(param_1 + iRam00701068 + 0x5ffc0) + 0x60),
                                            0x642f20,uVar8);
                    if (lVar7 == 0) {
                      if (*(char *)(iRam00701070 + 0x2e) != '\b') {
                        for (iVar6 = func_0x0010a050(0x642f20);
                            (bVar2 = *(byte *)(*(int *)(*(int *)(param_1 + iRam00701068 + 0x5ffc0) +
                                                       0x60) + iVar6), 0x2f < bVar2 &&
                            (bVar2 < 0x3a)); iVar6 = iVar6 + 1) {
                          *(char *)(iRam00701068 + 0x60dc9) =
                               *(char *)(iRam00701068 + 0x60dc9) * '\n' + (bVar2 - 0x30);
                        }
                        uRam00701e18 = 1;
                        FUN_005d5b60(0);
                      }
                    }
                    else {
                      uVar8 = func_0x0010a050(0x642f40);
                      lVar7 = func_0x00106910(*(undefined4 *)
                                               (*(int *)(param_1 + iRam00701068 + 0x5ffc0) + 0x60),
                                              0x642f40,uVar8);
                      if (lVar7 == 0) {
                        func_0x001069a8(0x870f10,pcRam00701088,0x1d0);
                        if (*(char *)(iRam00701070 + 0x2e) == '\b') {
                          FUN_005d5c20(0xb);
                        }
                        else {
                          uRam00701e18 = 1;
                          FUN_005d5b60(0);
                        }
                      }
                      else {
                        uVar8 = func_0x0010a050(0x642d80);
                        lVar7 = func_0x00106910(*(undefined4 *)
                                                 (*(int *)(param_1 + iRam00701068 + 0x5ffc0) + 0x60)
                                                ,0x642d80,uVar8);
                        if (lVar7 == 0) {
                          func_0x001069a8(pcRam00701088,0x870f10,0x1d0);
                          if (*(char *)(iRam00701070 + 0x2e) == '\b') {
                            FUN_005d5c20(0xc);
                          }
                          else {
                            uRam00701e18 = 2;
                            FUN_005d5b60(0);
                          }
                        }
                        else {
                          uVar8 = func_0x0010a050(0x642f60);
                          lVar7 = func_0x00106910(*(undefined4 *)
                                                   (*(int *)(param_1 + iRam00701068 + 0x5ffc0) +
                                                   0x60),0x642f60,uVar8);
                          if (lVar7 == 0) {
                            *(undefined4 *)(iRam00701078 + 0x20) = 0;
                            if ((*(char *)(iRam00701080 + 0x11d) != '\0') &&
                               (*(char *)(iRam00701080 + 0x11) != '\0')) {
                              FUN_005d5cc0(iRam00701080 + 0x11d);
                              FUN_005cf5f0();
                              if ((*(char *)(iRam00701070 + 0x55d) == '\0') ||
                                 (lVar7 = func_0x00109d70(iRam00701070 + 0x55d,iRam00701080),
                                 lVar7 == 0)) {
                                FUN_005d7540(0x642c20,iRam00701080);
                              }
                              else {
                                FUN_005d7540(0x642c20,iRam00701070 + 0x55d);
                              }
                              FUN_005d7540(0x642c28,iRam00701080 + 0x11);
                              *(undefined1 *)(iRam00701068 + 0x60dc8) = 1;
                              *(undefined1 *)(iRam00701068 + 0x60dc7) = 1;
                              *(undefined1 *)(iRam00701070 + 0x34) = 1;
                              *(undefined1 *)(iRam00701070 + 0x30) = 0;
                              if (*(char *)(iRam00701070 + 0x2e) == '\b') {
                                FUN_005d5c20(9);
                              }
                              else {
                                FUN_005d74a0(iRam00701068 + 0x4f97c);
                                uRam00700fe8 = 1;
                                FUN_005d5a40();
                              }
                            }
                          }
                          else if (**(char **)(*(int *)(param_1 + iRam00701068 + 0x5ffc0) + 0x60) ==
                                   '#') {
                            for (iVar6 = 0; iVar6 < 500; iVar6 = iVar6 + 1) {
                              iVar4 = iVar6 * 4;
                              pcVar3 = *(char **)(iRam00701068 + iVar4 + 0x5ffc0);
                              if (pcVar3 == (char *)0x0) {
                                return;
                              }
                              if (((*pcVar3 != '\0') && (pcVar3[2] == '\x0e')) &&
                                 (lVar7 = func_0x00109d70(*(undefined4 *)(pcVar3 + 0x60),
                                                          *(undefined4 *)
                                                           (*(int *)(param_1 + iRam00701068 +
                                                                    0x5ffc0) + 0x60)), lVar7 == 0))
                              {
                                *(int *)(iRam00701070 + 4) =
                                     (int)*(float *)(*(int *)(iVar4 + iRam00701068 + 0x5ffc0) + 0x34
                                                    );
                                *(int *)(iRam00701070 + 8) =
                                     (int)*(float *)(*(int *)(iVar4 + iRam00701068 + 0x5ffc0) + 0x38
                                                    );
                                if (*(int *)(iRam00701070 + 4) < 0) {
                                  *(undefined4 *)(iRam00701070 + 4) = 0;
                                }
                                iVar6 = *(int *)(iRam00701070 + 0xc) + -0x280;
                                if (iVar6 < *(int *)(iRam00701070 + 4)) {
                                  *(int *)(iRam00701070 + 4) = iVar6;
                                }
                                else {
                                  *(int *)(iRam00701070 + 4) = *(int *)(iRam00701070 + 4) + -0x14;
                                }
                                if (*(int *)(iRam00701070 + 8) < 0) {
                                  *(undefined4 *)(iRam00701070 + 8) = 0;
                                }
                                iVar6 = *(int *)(iRam00701070 + 8);
                                if (*(int *)(iRam00701070 + 0x10) + -0x1c0 < iVar6) {
                                  *(int *)(iRam00701070 + 8) = iVar6 + -0x184;
                                  return;
                                }
                                *(int *)(iRam00701070 + 8) = iVar6 + -0x28;
                                return;
                              }
                            }
                          }
                          else {
                            *(undefined1 *)(iRam00701068 + 0x60dce) = 1;
                            lVar7 = func_0x0010a700(*(undefined4 *)
                                                     (*(int *)(param_1 + iRam00701068 + 0x5ffc0) +
                                                     0x60),0x642f78);
                            if (lVar7 == 0) {
                              FUN_005d5cc0(*(undefined4 *)
                                            (*(int *)(param_1 + iRam00701068 + 0x5ffc0) + 0x60));
                            }
                            else {
                              func_0x00106b60(iRam00701070 + 0x3b,0,0x100);
                              func_0x00106b60(iRam00701070 + 0x43b,0,0x100);
                              func_0x00109eb8(iRam00701070 + 0x43b,lVar7);
                              for (iVar6 = 0;
                                  cVar1 = *(char *)(*(int *)(*(int *)(param_1 + iRam00701068 +
                                                                     0x5ffc0) + 0x60) + iVar6),
                                  cVar1 != '#'; iVar6 = iVar6 + 1) {
                                *(char *)(iRam00701070 + iVar6 + 0x3b) = cVar1;
                              }
                              *(undefined1 *)(iVar6 + iRam00701070 + 0x3b) = 0;
                              FUN_005dedf0(iRam00701068 + 0x4f97c,iRam00701070 + 0x3b);
                            }
                            *(undefined4 *)(iRam00701078 + 0x20) = 0;
                            if (*(char *)(iRam00701070 + 0x2e) == '\b') {
                              FUN_005d5c20();
                            }
                            else {
                              FUN_005d59f0();
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}



================================================================