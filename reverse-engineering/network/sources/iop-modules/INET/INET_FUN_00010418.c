FUNCTION FUN_00010418 @ 0x00010418 size=1976
CALLERS (1): FUN_00010cc0@0x00010cc0
CALLEES (6): FUN_000199c4@0x000199c4, FUN_0000ae24@0x0000ae24, FUN_00019a94@0x00019a94, FUN_0000e180@0x0000e180, FUN_0000a9c0@0x0000a9c0, FUN_00005f48@0x00005f48

int FUN_00010418(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int unaff_gp;
  
  if ((param_2 & 0x30000) == 0) {
    if (param_3 == 0) {
      return -0x200;
    }
  }
  else {
    if (param_3 != 0) {
      return -0x200;
    }
    if (param_4 != 0) {
      return -0x200;
    }
  }
  if ((int)param_2 < 0x111) {
    if (0x10e < (int)param_2) {
      iVar4 = FUN_00005f48(param_1,param_2,param_3,param_4);
      return iVar4;
    }
    if (param_2 == 10) {
      if (param_4 != 0x10) {
        return -0x200;
      }
      FUN_0000ae24(param_3,0x10);
      iVar4 = param_1 + 0x74;
      param_3 = param_3 + 4;
    }
    else {
      if ((int)param_2 < 0xb) {
        if (param_2 == 4) {
          iVar1 = 1;
          iVar4 = param_1 + 0x20;
          if (param_4 != 1) {
            return -0x200;
          }
          goto LAB_00010ba8;
        }
        if ((int)param_2 < 5) {
          if (param_2 == 1) {
            iVar1 = FUN_000199c4(*(undefined4 *)(param_1 + 0x14));
            iVar1 = iVar1 + 1;
            if ((int)param_4 < iVar1) {
              return -0x200;
            }
            iVar4 = *(int *)(param_1 + 0x14);
          }
          else if ((int)param_2 < 2) {
            if (param_2 != 0) {
              return -0x200;
            }
            iVar1 = 9;
            iVar4 = param_1 + 8;
            if (param_4 != 9) {
              return -0x200;
            }
          }
          else if (param_2 == 2) {
            iVar1 = FUN_000199c4(*(undefined4 *)(param_1 + 0x18));
            iVar1 = iVar1 + 1;
            if ((int)param_4 < iVar1) {
              return -0x200;
            }
            iVar4 = *(int *)(param_1 + 0x18);
          }
          else {
            if (param_2 != 3) {
              return -0x200;
            }
            iVar1 = FUN_000199c4(*(undefined4 *)(param_1 + 0x1c));
            iVar1 = iVar1 + 1;
            if ((int)param_4 < iVar1) {
              return -0x200;
            }
            iVar4 = *(int *)(param_1 + 0x1c);
          }
          goto LAB_00010ba8;
        }
        if (param_2 == 7) {
          iVar4 = param_1 + 0x42;
        }
        else {
          if (7 < (int)param_2) {
            if (param_2 == 8) {
              if (param_4 != 4) {
                return -0x200;
              }
              iVar4 = param_1 + 0x48;
            }
            else {
              if (param_2 != 9) {
                return -0x200;
              }
              if (param_4 != 0x10) {
                return -0x200;
              }
              FUN_0000ae24(param_3,0x10);
              iVar4 = param_1 + 0x70;
              param_3 = param_3 + 4;
            }
            goto LAB_00010ba4;
          }
          if (param_2 == 5) {
            iVar1 = 0x1f;
            iVar4 = param_1 + 0x21;
            if (param_4 != 0x1f) {
              return -0x200;
            }
            goto LAB_00010ba8;
          }
          if (param_2 != 6) {
            return -0x200;
          }
          iVar4 = param_1 + 0x40;
        }
        iVar1 = 2;
        if (param_4 != 2) {
          return -0x200;
        }
        goto LAB_00010ba8;
      }
      if (param_2 == 0xf) {
        iVar4 = param_1 + 0x19c;
joined_r0x000109f4:
        iVar1 = 4;
        if (param_4 != 4) {
          return -0x200;
        }
        goto LAB_00010ba8;
      }
      if ((int)param_2 < 0x10) {
        if (param_2 == 0xc) {
          iVar4 = param_1 + 0x84;
          goto joined_r0x000109f4;
        }
        if (0xb < (int)param_2) {
          if (param_2 != 0xd) {
            if (param_2 != 0xe) {
              return -0x200;
            }
            if (*(short *)(param_1 + 0x40) == 0) {
              return -0x201;
            }
            iVar4 = *(int *)(param_1 + 0x198);
            if ((int)param_4 < iVar4) {
              return -0x200;
            }
            FUN_0000a9c0(param_1 + 0x98,param_3,iVar4);
            return iVar4;
          }
          iVar1 = 0x10;
          iVar4 = param_1 + 0x88;
          if (param_4 != 0x10) {
            return -0x200;
          }
          goto LAB_00010ba8;
        }
        if (param_4 != 0x10) {
          return -0x200;
        }
        FUN_0000ae24(param_3,0x10);
        iVar4 = param_1 + 0x78;
        param_3 = param_3 + 4;
      }
      else if (param_2 == 0x10b) {
        if (param_4 != 0x10) {
          return -0x200;
        }
        iVar4 = FUN_0000e180(param_3);
        if (iVar4 != 0) {
          return -0x200;
        }
        iVar4 = param_3 + 4;
        param_3 = param_1 + 0x78;
      }
      else if ((int)param_2 < 0x10c) {
        if (param_2 == 0x109) {
          if (param_4 != 0x10) {
            return -0x200;
          }
          iVar4 = FUN_0000e180(param_3);
          if (iVar4 != 0) {
            return -0x200;
          }
          iVar4 = param_3 + 4;
          param_3 = param_1 + 0x70;
        }
        else {
          if (param_2 != 0x10a) {
            return -0x200;
          }
          if (param_4 != 0x10) {
            return -0x200;
          }
          iVar4 = FUN_0000e180(param_3);
          if (iVar4 != 0) {
            return -0x200;
          }
          iVar4 = param_3 + 4;
          param_3 = param_1 + 0x74;
        }
      }
      else {
        if (param_2 != 0x10c) {
          if (param_2 != 0x10e) {
            return -0x200;
          }
          if (*(short *)(param_1 + 0x40) != 0) {
            if (0x100 < param_4) {
              return -0x200;
            }
            FUN_0000a9c0(param_3,param_1 + 0x98,param_4);
            *(uint *)(param_1 + 0x198) = param_4;
            return 0;
          }
          return -0x201;
        }
        if (param_4 != 4) {
          return -0x200;
        }
        iVar4 = param_3;
        param_3 = param_1 + 0x84;
      }
    }
  }
  else {
    if (param_2 == 0x20a) {
      iVar4 = *(int *)(param_1 + 0x1a0) + 0x44;
    }
    else if ((int)param_2 < 0x20b) {
      if (param_2 == 0x204) {
        iVar4 = *(int *)(param_1 + 0x1a0) + 0x2c;
      }
      else if ((int)param_2 < 0x205) {
        if (param_2 == 0x201) {
          iVar4 = *(int *)(param_1 + 0x1a0) + 0x20;
        }
        else if ((int)param_2 < 0x202) {
          if (param_2 != 0x200) {
            return -0x200;
          }
          iVar4 = *(int *)(param_1 + 0x1a0) + 0x1c;
        }
        else if (param_2 == 0x202) {
          iVar4 = *(int *)(param_1 + 0x1a0) + 0x24;
        }
        else {
          if (param_2 != 0x203) {
            return -0x200;
          }
          iVar4 = *(int *)(param_1 + 0x1a0) + 0x28;
        }
      }
      else if (param_2 == 0x207) {
        iVar4 = *(int *)(param_1 + 0x1a0) + 0x38;
      }
      else if ((int)param_2 < 0x208) {
        if (param_2 == 0x205) {
          iVar4 = *(int *)(param_1 + 0x1a0) + 0x30;
        }
        else {
          if (param_2 != 0x206) {
            return -0x200;
          }
          iVar4 = *(int *)(param_1 + 0x1a0) + 0x34;
        }
      }
      else if (param_2 == 0x208) {
        iVar4 = *(int *)(param_1 + 0x1a0) + 0x3c;
      }
      else {
        if (param_2 != 0x209) {
          return -0x200;
        }
        iVar4 = *(int *)(param_1 + 0x1a0) + 0x40;
      }
    }
    else {
      if (param_2 == 0x10004) {
        *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 0x20;
        return 0;
      }
      if (0x10004 < (int)param_2) {
        if (param_2 == 0x11001) {
          *(uint *)(param_1 + 0x19c) = *(uint *)(param_1 + 0x19c) & 0xfffffffe;
          return 0;
        }
        if ((int)param_2 < 0x11002) {
          if (param_2 != 0x10005) {
            if (param_2 == 0x11000) {
              *(uint *)(param_1 + 0x19c) = *(uint *)(param_1 + 0x19c) | 1;
              return 0;
            }
            return -0x200;
          }
          uVar2 = *(uint *)(param_1 + 0x48);
          uVar3 = 0xffffffdf;
        }
        else {
          if (param_2 == 0x20000) {
            if ((*(uint *)(param_1 + 0x48) & 0x200) != 0) {
              return 0;
            }
            if (*(undefined4 **)(unaff_gp + -0x7b50) != (undefined4 *)0x0) {
              iVar4 = (*(code *)**(undefined4 **)(unaff_gp + -0x7b50))(param_1);
              if (-1 < iVar4) {
                *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 0x200;
                return 0;
              }
              return 0;
            }
            *(int *)(param_1 + 0x1b4) = *(int *)(param_1 + 0x1b4) + 1;
            *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 0x200;
            return 0;
          }
          if (param_2 != 0x20001) {
            return -0x200;
          }
          if (((*(uint *)(param_1 + 0x48) & 0x200) != 0) && (*(int *)(unaff_gp + -0x7b50) != 0)) {
            (**(code **)(*(int *)(unaff_gp + -0x7b50) + 4))(param_1);
          }
          uVar2 = *(uint *)(param_1 + 0x48);
          uVar3 = 0xfffffdff;
        }
LAB_00010ad8:
        *(uint *)(param_1 + 0x48) = uVar2 & uVar3;
        return 0;
      }
      if (param_2 == 0x10001) {
        uVar6 = 0x20000;
        uVar5 = *(undefined4 *)(param_1 + 0x4c);
        uVar2 = *(uint *)(param_1 + 0x48) & 0xfffffffe;
LAB_00010930:
        *(uint *)(param_1 + 0x48) = uVar2;
        FUN_00019a94(uVar5,uVar6);
        return 0;
      }
      if (0x10001 < (int)param_2) {
        if (param_2 == 0x10002) {
          *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 4;
          return 0;
        }
        if (param_2 != 0x10003) {
          return -0x200;
        }
        uVar2 = *(uint *)(param_1 + 0x48);
        uVar3 = 0xfffffffb;
        goto LAB_00010ad8;
      }
      if (param_2 != 0x20b) {
        uVar6 = 0x10000;
        if (param_2 != 0x10000) {
          return -0x200;
        }
        uVar5 = *(undefined4 *)(param_1 + 0x4c);
        uVar2 = *(uint *)(param_1 + 0x48) | 1;
        goto LAB_00010930;
      }
      iVar4 = *(int *)(param_1 + 0x1a0) + 0x48;
    }
    if (param_4 != 4) {
      return -0x200;
    }
  }
LAB_00010ba4:
  iVar1 = 4;
LAB_00010ba8:
  FUN_0000a9c0(iVar4,param_3,iVar1);
  return 0;
}


================================================================