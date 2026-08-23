
undefined * FUN_001cc170(long param_1,uint param_2,long param_3,long param_4)

{
  uint uVar1;
  undefined *puVar2;
  
  uVar1 = param_2 >> 0x10;
  if ((param_1 < 0x100) || (0xfef < param_1)) {
    if ((param_1 < 0x1000) || (0x10ff < param_1)) {
      if ((param_1 < 0x1100) || (0x11ff < param_1)) {
        if ((param_1 < 0x1200) || (0x12ff < param_1)) {
          if ((param_1 < 0x1300) || (0x13ff < param_1)) {
            if ((param_1 < 0x1400) || (0x15ff < param_1)) {
              if ((param_1 < 0x1600) || (0x17ff < param_1)) {
                if ((param_1 < 0x1800) || (0x1fff < param_1)) {
                  if ((param_1 < 0x2100) || (0x23ff < param_1)) {
                    if ((param_1 < 0x2000) || (0x20ff < param_1)) {
                      if ((param_1 < 0x2400) || (0x24ff < param_1)) {
                        if ((param_1 < 0x2a00) || (0x2fff < param_1)) {
                          if ((param_1 < 0x3000) || (0x30ff < param_1)) {
                            if (param_1 < 0x2500) {
                              puVar2 = (undefined *)0x0;
                            }
                            else {
                              puVar2 = (undefined *)0x0;
                              if (param_1 < 0x2510) {
                                puVar2 = (&PTR_s_DATA_ROM_SCENE_PIT_TEX_GAME_ETC__0024a828)
                                         [param_2 & 0xffff];
                              }
                            }
                          }
                          else if (param_3 == 0) {
                            puVar2 = (undefined *)((param_2 & 0xffff) * 0x40 + 0x36bed0);
                          }
                          else {
                            puVar2 = (undefined *)((param_2 & 0xffff) * 0x40 + 0x36bad0);
                          }
                        }
                        else if (param_3 == 0) {
                          if (uVar1 == 0x29) {
                            puVar2 = (&PTR_s_DATA_ROM_TEX_IT_OBJS41_TEX_0024a7d0)[param_2 & 0xffff];
                          }
                          else if (uVar1 == 0x28) {
                            puVar2 = (&PTR_s_DATA_ROM_TEX_IT_OBJS40_TEX_0024a7a0)[param_2 & 0xffff];
                          }
                          else if (uVar1 == 0x23) {
                            puVar2 = (&PTR_s_DATA_ROM_TEX_IT_OBJS35_TEX_0024a770)[param_2 & 0xffff];
                          }
                          else if (uVar1 == 0x1e) {
                            puVar2 = (&PTR_s_DATA_ROM_TEX_IT_OBJS30_TEX_0024a740)[param_2 & 0xffff];
                          }
                          else if (uVar1 == 0x1d) {
                            puVar2 = (&PTR_s_DATA_ROM_TEX_IT_OBJS29_TEX_0024a710)[param_2 & 0xffff];
                          }
                          else if (uVar1 == 0x1c) {
                            puVar2 = (&PTR_s_DATA_ROM_TEX_IT_OBJS28_TEX_0024a6e0)[param_2 & 0xffff];
                          }
                          else if (uVar1 == 0x1b) {
                            puVar2 = (&PTR_s_DATA_ROM_TEX_IT_OBJS27_TEX_0024a6b0)[param_2 & 0xffff];
                          }
                          else if (uVar1 == 0x1a) {
                            puVar2 = (&PTR_s_DATA_ROM_TEX_IT_OBJS26_TEX_0024a680)[param_2 & 0xffff];
                          }
                          else if (uVar1 == 0x18) {
                            puVar2 = (&PTR_s_DATA_ROM_TEX_IT_OBJS24_TEX_0024a650)[param_2 & 0xffff];
                          }
                          else if (uVar1 == 0x17) {
                            puVar2 = (&PTR_s_DATA_ROM_TEX_IT_OBJS23_TEX_0024a620)[param_2 & 0xffff];
                          }
                          else if (uVar1 == 0x16) {
                            puVar2 = (&PTR_s_DATA_ROM_TEX_IT_OBJS22_TEX_0024a5f0)[param_2 & 0xffff];
                          }
                          else if (uVar1 == 0x15) {
                            puVar2 = (&PTR_s_DATA_ROM_TEX_IT_OBJS21_TEX_0024a5c0)[param_2 & 0xffff];
                          }
                          else if (uVar1 == 0x14) {
                            puVar2 = (&PTR_s_DATA_ROM_TEX_IT_OBJS20_TEX_0024a590)[param_2 & 0xffff];
                          }
                          else if (uVar1 == 0xf) {
                            puVar2 = (&PTR_s_DATA_ROM_TEX_IT_OBJS15_TEX_0024a560)[param_2 & 0xffff];
                          }
                          else if (uVar1 == 10) {
                            puVar2 = (&PTR_s_DATA_ROM_TEX_IT_OBJS10_TEX_0024a530)[param_2 & 0xffff];
                          }
                          else if (uVar1 == 6) {
                            puVar2 = (&PTR_s_DATA_ROM_TEX_IT_OBJS06_TEX_0024a500)[param_2 & 0xffff];
                          }
                          else if (uVar1 == 2) {
                            puVar2 = (&PTR_s_DATA_ROM_TEX_IT_OBJS02_TEX_0024a4d0)[param_2 & 0xffff];
                          }
                          else if (uVar1 == 1) {
                            puVar2 = (&PTR_s_DATA_ROM_TEX_IT_OBJS01_TEX_0024a4a0)[param_2 & 0xffff];
                          }
                          else if (uVar1 == 0) {
                            puVar2 = (&PTR_s_DATA_ROM_TEX_IT_OBJS40_TEX_0024a7a0)[param_2 & 0xffff];
                          }
                          else {
                            puVar2 = (&PTR_s_DATA_ROM_TEX_IT_OBJS24_TEX_0024a650)[param_2 & 0xffff];
                          }
                        }
                        else if (uVar1 == 0x29) {
                          puVar2 = (&PTR_s_DATA_ROM_MODEL_IT_OBJS41_0024c740)[param_2 & 0xffff];
                        }
                        else if (uVar1 == 0x28) {
                          puVar2 = (&PTR_s_DATA_ROM_MODEL_IT_OBJS40_0024c710)[param_2 & 0xffff];
                        }
                        else if (uVar1 == 0x23) {
                          puVar2 = (&PTR_s_DATA_ROM_MODEL_IT_OBJS35_0024c6e0)[param_2 & 0xffff];
                        }
                        else if (uVar1 == 0x1e) {
                          puVar2 = (&PTR_s_DATA_ROM_MODEL_IT_OBJS30_0024c6b0)[param_2 & 0xffff];
                        }
                        else if (uVar1 == 0x1d) {
                          puVar2 = (&PTR_s_DATA_ROM_MODEL_IT_OBJS29_0024c680)[param_2 & 0xffff];
                        }
                        else if (uVar1 == 0x1c) {
                          puVar2 = (&PTR_s_DATA_ROM_MODEL_IT_OBJS28_0024c650)[param_2 & 0xffff];
                        }
                        else if (uVar1 == 0x1b) {
                          puVar2 = (&PTR_s_DATA_ROM_MODEL_IT_OBJS27_0024c620)[param_2 & 0xffff];
                        }
                        else if (uVar1 == 0x1a) {
                          puVar2 = (&PTR_s_DATA_ROM_MODEL_IT_OBJS26_0024c5f0)[param_2 & 0xffff];
                        }
                        else if (uVar1 == 0x18) {
                          puVar2 = (&PTR_s_DATA_ROM_MODEL_IT_OBJS24_0024c5c0)[param_2 & 0xffff];
                        }
                        else if (uVar1 == 0x17) {
                          puVar2 = (&PTR_s_DATA_ROM_MODEL_IT_OBJS23_0024c590)[param_2 & 0xffff];
                        }
                        else if (uVar1 == 0x16) {
                          puVar2 = (&PTR_s_DATA_ROM_MODEL_IT_OBJS22_0024c560)[param_2 & 0xffff];
                        }
                        else if (uVar1 == 0x15) {
                          puVar2 = (&PTR_s_DATA_ROM_MODEL_IT_OBJS21_0024c530)[param_2 & 0xffff];
                        }
                        else if (uVar1 == 0x14) {
                          puVar2 = (&PTR_s_DATA_ROM_MODEL_IT_OBJS20_0024c500)[param_2 & 0xffff];
                        }
                        else if (uVar1 == 0xf) {
                          puVar2 = (&PTR_s_DATA_ROM_MODEL_IT_OBJS15_0024c4d0)[param_2 & 0xffff];
                        }
                        else if (uVar1 == 10) {
                          puVar2 = (&PTR_s_DATA_ROM_MODEL_IT_OBJS10_0024c4a0)[param_2 & 0xffff];
                        }
                        else if (uVar1 == 6) {
                          puVar2 = (&PTR_s_DATA_ROM_MODEL_IT_OBJS06_0024c470)[param_2 & 0xffff];
                        }
                        else if (uVar1 == 2) {
                          puVar2 = (&PTR_s_DATA_ROM_MODEL_IT_OBJS02_0024c440)[param_2 & 0xffff];
                        }
                        else if (uVar1 == 1) {
                          puVar2 = (&PTR_s_DATA_ROM_MODEL_IT_OBJS01_0024c410)[param_2 & 0xffff];
                        }
                        else if (uVar1 == 0) {
                          puVar2 = (&PTR_s_DATA_ROM_MODEL_IT_OBJS40_0024c710)[param_2 & 0xffff];
                        }
                        else {
                          puVar2 = (&PTR_s_DATA_ROM_MODEL_IT_OBJS24_0024c5c0)[param_2 & 0xffff];
                        }
                      }
                      else {
                        puVar2 = (undefined *)FUN_001cc100(param_2 & 0xffff,param_3);
                      }
                    }
                    else {
                      puVar2 = (undefined *)FUN_001cc090(param_2 & 0xffff,param_3);
                    }
                  }
                  else {
                    puVar2 = (undefined *)FUN_001cc010(uVar1,param_2 & 0xffff);
                  }
                }
                else {
                  puVar2 = (undefined *)FUN_001cbf80(param_3);
                }
              }
              else if (param_3 == 0) {
                puVar2 = (undefined *)FUN_001cbda0(0,param_2 & 0xffff,0x24c978);
              }
              else {
                puVar2 = (undefined *)FUN_001cbda0(param_3,param_2 & 0xffff,0x24c988);
              }
            }
            else if (param_3 == 0) {
              puVar2 = (undefined *)FUN_001cbda0(0,param_2 & 0xffff,0x24c928);
            }
            else {
              puVar2 = (undefined *)FUN_001cbda0(param_3,param_2 & 0xffff,0x24c938);
            }
          }
          else if (param_3 == 0) {
            puVar2 = (&PTR_s_DATA_ROM_TEX_EM_HE00_HE00_00_TEX_0024a3f0)[param_2 & 0xffff];
          }
          else {
            puVar2 = (&PTR_s_DATA_ROM_MODEL_EM_HE00_00_0024c360)[param_2 & 0xffff];
          }
        }
        else if (param_3 == 0) {
          puVar2 = (&PTR_s_DATA_ROM_TEX_EM_E00_E00_00_TEX_00249b30)[param_2 & 0xffff];
        }
        else {
          puVar2 = (&PTR_s_DATA_ROM_MODEL_EM_E00_00_0024bc90)[param_2 & 0xffff];
        }
      }
      else if (param_3 == 0) {
        puVar2 = (undefined *)FUN_001cbda0(0,param_2 & 0xffff,0x24c960);
      }
      else {
        puVar2 = (undefined *)FUN_001cbda0(param_3,param_2 & 0xffff,0x24c970);
      }
    }
    else if ((param_2 & 0x8000) == 0) {
      if (param_3 == 0) {
        puVar2 = (undefined *)FUN_001cbe50(0,param_2 & 0xffff,uVar1,0x24c940);
      }
      else if (param_4 == 0) {
        puVar2 = (undefined *)FUN_001cbe50(param_3,param_2 & 0xffff,uVar1,0x24c950);
      }
      else {
        puVar2 = (undefined *)FUN_001cbe50(param_3,param_2 & 0xffff,uVar1,0x24c958);
      }
    }
    else if (param_3 == 0) {
      puVar2 = (undefined *)FUN_001cbe50(0,param_2 & 0xffff,uVar1,0x24c928);
    }
    else {
      puVar2 = (undefined *)FUN_001cbe50(param_3,param_2 & 0xffff,uVar1,0x24c938);
    }
  }
  else if (param_3 == 0) {
    puVar2 = (&PTR_s_DATA_ROM_ETC_DE01_TEX_0024a7f8)[param_2 & 0xffff];
  }
  else {
    puVar2 = (&PTR_s_DATA_ROM_ETC_DE01_0024c768)[param_2 & 0xffff];
  }
  return puVar2;
}

