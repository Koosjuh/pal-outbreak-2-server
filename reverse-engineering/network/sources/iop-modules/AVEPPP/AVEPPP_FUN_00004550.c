FUNCTION FUN_00004550 @ 0x00004550 size=2512
CALLERS (1): FUN_000041a0@0x000041a0
CALLEES (13): FUN_00003b50@0x00003b50, FUN_00009044@0x00009044, FUN_00010ae4@0x00010ae4, FUN_00010c38@0x00010c38, FUN_0000985c@0x0000985c, FUN_00006f6c@0x00006f6c, FUN_000036b0@0x000036b0, FUN_0000f42c@0x0000f42c, FUN_0000e0e0@0x0000e0e0, FUN_0000075c@0x0000075c, FUN_00001c68@0x00001c68, FUN_0000efbc@0x0000efbc, FUN_0000d458@0x0000d458

void FUN_00004550(int *param_1)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  ushort uVar6;
  uint uVar7;
  int *local_res0 [4];
  undefined1 local_20;
  undefined1 local_1f;
  ushort local_1e;
  int local_18 [2];
  
  if (param_1 == (int *)0x0) {
    return;
  }
  local_res0[0] = param_1;
  if ((((DAT_00012ef8 == 0) && (*(char *)*param_1 == -1)) && (((char *)*param_1)[1] == '\x03')) &&
     (sVar2 = FUN_0000075c(local_res0,&DAT_000132e8,2), sVar2 == 2)) {
    FUN_00001c68(&DAT_000132e8);
  }
  local_20 = 0xff;
  local_1f = 3;
  if ((local_res0[0] == (int *)0x0) || (*(ushort *)(local_res0[0] + 1) < 2)) {
    sVar2 = FUN_0000075c(local_res0,&DAT_000132ec,1);
    local_1e = 0xffff;
    if (sVar2 == 1) {
      local_1e = (ushort)DAT_000132ec;
    }
  }
  else {
    *(ushort *)(local_res0[0] + 1) = *(ushort *)(local_res0[0] + 1) - 1;
    local_1e = (ushort)*(byte *)*local_res0[0];
    *local_res0[0] = (int)((byte *)*local_res0[0] + 1);
  }
  if ((local_1e & 1) == 0) {
    uVar6 = local_1e << 8;
    if ((local_res0[0] == (int *)0x0) || (*(ushort *)(local_res0[0] + 1) < 2)) {
      sVar2 = FUN_0000075c(local_res0,&DAT_000132ec,1);
      if (sVar2 == 1) {
        local_1e = uVar6 | DAT_000132ec;
      }
      else {
        local_1e = 0xffff;
      }
    }
    else {
      *(ushort *)(local_res0[0] + 1) = *(ushort *)(local_res0[0] + 1) - 1;
      bVar1 = *(byte *)*local_res0[0];
      *local_res0[0] = (int)((byte *)*local_res0[0] + 1);
      local_1e = uVar6 | bVar1;
    }
  }
  if (local_1e == 0x8021) {
    if ((DAT_00012efc & 2) != 0) {
      uVar4 = FUN_00010ae4();
      FUN_00010c38("%010u ",uVar4);
      if (((DAT_00012efc & 2) != 0) && (FUN_00010c38("PPP RECV [IPCP]\n"), (DAT_00012efc & 2) != 0))
      {
        uVar7 = 0;
        if ((short)local_res0[0][1] != 0) {
          do {
            FUN_00010c38("%02x ",*(undefined1 *)(*local_res0[0] + uVar7));
            uVar5 = uVar7;
            if ((int)uVar7 < 0) {
              uVar5 = uVar7 + 0xf;
            }
            if (uVar7 + ((int)uVar5 >> 4) * -0x10 == 0xf) {
              FUN_00010c38(&DAT_00011680);
            }
            uVar7 = uVar7 + 1;
          } while ((int)uVar7 < (int)(uint)*(ushort *)(local_res0[0] + 1));
        }
        if ((uVar7 & 0xf) != 0) {
          FUN_00010c38(&DAT_00011680);
        }
      }
    }
    if (DAT_00014990 == 3) {
      DAT_00014a8c = DAT_00014a8c + 1;
      FUN_0000985c(&DAT_000149fc,local_res0[0]);
      return;
    }
  }
  else {
    if (0x8021 < local_1e) {
      if (local_1e == 0xc023) {
        if ((DAT_00012efc & 2) != 0) {
          uVar4 = FUN_00010ae4();
          FUN_00010c38("%010u ",uVar4);
          if (((DAT_00012efc & 2) != 0) &&
             (FUN_00010c38("PPP RECV [PAP]\n"), (DAT_00012efc & 2) != 0)) {
            uVar7 = 0;
            if ((short)local_res0[0][1] != 0) {
              do {
                FUN_00010c38("%02x ",*(undefined1 *)(*local_res0[0] + uVar7));
                uVar5 = uVar7;
                if ((int)uVar7 < 0) {
                  uVar5 = uVar7 + 0xf;
                }
                if (uVar7 + ((int)uVar5 >> 4) * -0x10 == 0xf) {
                  FUN_00010c38(&DAT_00011680);
                }
                uVar7 = uVar7 + 1;
              } while ((int)uVar7 < (int)(uint)*(ushort *)(local_res0[0] + 1));
            }
            if ((uVar7 & 0xf) != 0) {
              FUN_00010c38(&DAT_00011680);
            }
          }
        }
        if (DAT_00014990 - 2 < 2) {
          DAT_00014a8a = DAT_00014a8a + 1;
          FUN_0000e0e0(&DAT_000149c8,local_res0[0]);
          return;
        }
LAB_00004bb4:
        DAT_00014a96 = DAT_00014a96 + 1;
        if (DAT_00014990 != 0) {
          return;
        }
        FUN_0000d458(&DAT_00014994);
        return;
      }
      if (local_1e < 0xc024) {
        if (local_1e == 0xc021) {
          if ((DAT_00012efc & 2) != 0) {
            uVar4 = FUN_00010ae4();
            FUN_00010c38("%010u ",uVar4);
            if (((DAT_00012efc & 2) != 0) &&
               (FUN_00010c38("PPP RECV [LCP]\n"), (DAT_00012efc & 2) != 0)) {
              uVar7 = 0;
              if ((short)local_res0[0][1] != 0) {
                do {
                  FUN_00010c38("%02x ",*(undefined1 *)(*local_res0[0] + uVar7));
                  uVar5 = uVar7;
                  if ((int)uVar7 < 0) {
                    uVar5 = uVar7 + 0xf;
                  }
                  if (uVar7 + ((int)uVar5 >> 4) * -0x10 == 0xf) {
                    FUN_00010c38(&DAT_00011680);
                  }
                  uVar7 = uVar7 + 1;
                } while ((int)uVar7 < (int)(uint)*(ushort *)(local_res0[0] + 1));
              }
              if ((uVar7 & 0xf) != 0) {
                FUN_00010c38(&DAT_00011680);
              }
            }
          }
          DAT_00014a88 = DAT_00014a88 + 1;
          FUN_0000985c(&DAT_00014994,local_res0[0]);
          return;
        }
      }
      else if (local_1e == 0xc223) {
        if ((DAT_00012efc & 2) != 0) {
          uVar4 = FUN_00010ae4();
          FUN_00010c38("%010u ",uVar4);
          if (((DAT_00012efc & 2) != 0) &&
             (FUN_00010c38("PPP RECV [CHAP]\n"), (DAT_00012efc & 2) != 0)) {
            uVar7 = 0;
            if ((short)local_res0[0][1] != 0) {
              do {
                FUN_00010c38("%02x ",*(undefined1 *)(*local_res0[0] + uVar7));
                uVar5 = uVar7;
                if ((int)uVar7 < 0) {
                  uVar5 = uVar7 + 0xf;
                }
                if (uVar7 + ((int)uVar5 >> 4) * -0x10 == 0xf) {
                  FUN_00010c38(&DAT_00011680);
                }
                uVar7 = uVar7 + 1;
              } while ((int)uVar7 < (int)(uint)*(ushort *)(local_res0[0] + 1));
            }
            if ((uVar7 & 0xf) != 0) {
              FUN_00010c38(&DAT_00011680);
            }
          }
        }
        if (DAT_00014990 - 2 < 2) {
          DAT_00014a8e = DAT_00014a8e + 1;
          FUN_00006f6c(&DAT_00014a30,local_res0[0]);
          return;
        }
        goto LAB_00004bb4;
      }
      goto LAB_00004d48;
    }
    if (local_1e == 0x2d) {
      if ((DAT_000149fc != '\x05') || ((*(ushort *)(DAT_00014a2c + 0x28) & 4) == 0))
      goto LAB_00004d10;
      iVar3 = FUN_0000efbc(*(undefined4 *)(DAT_00014a2c + 0x98),local_res0);
    }
    else {
      if (local_1e < 0x2e) {
        if (local_1e != 0x21) {
LAB_00004d48:
          if ((DAT_00012efc & 2) != 0) {
            uVar4 = FUN_00010ae4();
            FUN_00010c38("%010u ",uVar4);
            if (((DAT_00012efc & 2) != 0) &&
               (FUN_00010c38("PPP RECV [unknown protocol = %04x]\n",local_1e),
               (DAT_00012efc & 2) != 0)) {
              uVar7 = 0;
              if ((short)local_res0[0][1] != 0) {
                do {
                  FUN_00010c38("%02x ",*(undefined1 *)(*local_res0[0] + uVar7));
                  uVar5 = uVar7;
                  if ((int)uVar7 < 0) {
                    uVar5 = uVar7 + 0xf;
                  }
                  if (uVar7 + ((int)uVar5 >> 4) * -0x10 == 0xf) {
                    FUN_00010c38(&DAT_00011680);
                  }
                  uVar7 = uVar7 + 1;
                } while ((int)uVar7 < (int)(uint)*(ushort *)(local_res0[0] + 1));
              }
              if ((uVar7 & 0xf) != 0) {
                FUN_00010c38(&DAT_00011680);
              }
            }
          }
          DAT_00014a90 = DAT_00014a90 + 1;
          local_18[0] = FUN_00003b50(&local_20,local_res0[0]);
          if (local_18[0] == 0) {
            DAT_00014a98 = DAT_00014a98 + 1;
            return;
          }
          sVar2 = FUN_0000075c(local_18,&DAT_000132e8,2);
          if (sVar2 == 2) {
            FUN_00001c68(&DAT_000132e8);
          }
          FUN_00009044(&DAT_00014994,8,0,local_18[0]);
          if (DAT_00012efc == 0) {
            return;
          }
          FUN_00010c38("ave-ppp %s:","ppp_proc");
          FUN_00010c38("Unsupported protocol packet 0x%x rejected.\n",local_1e);
          return;
        }
        if (DAT_000149fc != '\x05') goto LAB_00004d10;
        goto LAB_00004810;
      }
      if (local_1e != 0x2f) goto LAB_00004d48;
      if ((DAT_000149fc != '\x05') || ((*(ushort *)(DAT_00014a2c + 0x28) & 4) == 0))
      goto LAB_00004d10;
      iVar3 = FUN_0000f42c(*(undefined4 *)(DAT_00014a2c + 0x98),local_res0);
    }
    if (0 < iVar3 << 0x10) {
LAB_00004810:
      FUN_000036b0(*local_res0[0],(short)local_res0[0][1],0);
      return;
    }
  }
LAB_00004d10:
  DAT_00014a96 = DAT_00014a96 + 1;
  return;
}


================================================================