FUNCTION FUN_00000998 @ 0x00000998 size=2092
CALLERS (2): FUN_00001298@0x00001298, FUN_000011c4@0x000011c4
CALLEES (4): FUN_000029f4@0x000029f4, FUN_00002b40@0x00002b40, FUN_00000000@0x00000000, FUN_000000a0@0x000000a0

undefined4 FUN_00000998(int param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  ushort uVar3;
  short sVar4;
  uint uVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  ushort *puVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  ushort uVar13;
  uint uVar14;
  int iVar15;
  int unaff_gp;
  ushort local_38 [4];
  ushort local_30;
  ushort local_2e;
  
  iVar15 = *(int *)(unaff_gp + -0x7fdc);
  iVar12 = *(int *)(param_1 + 4);
  uVar14 = 0;
  if (*(int *)(unaff_gp + -0x7fe0) != 0) {
    FUN_000029f4("smap: Resetting PHY\n");
  }
  FUN_00000000(iVar12,0,0x8000);
  iVar10 = 9;
  while (uVar5 = FUN_000000a0(iVar12,0), (uVar5 & 0x8000) != 0) {
    if (iVar10 < 1) {
      FUN_000029f4("smap: PHY reset error\n");
      return 0xffffffff;
    }
    if (*(int *)(param_1 + 0x30) != 0) {
      return 0;
    }
    FUN_00002b40(1000);
    iVar10 = iVar10 + -1;
  }
  if (iVar15 == 0) {
    if (*(int *)(unaff_gp + -0x7fe0) != 0) {
      FUN_000029f4("smap: no auto mode (conf=0x%x)\n",*(undefined4 *)(unaff_gp + -0x7fd4));
    }
    uVar14 = (uint)((*(uint *)(unaff_gp + -0x7fd4) & 0x180) != 0);
    uVar5 = uVar14 << 0xd;
    if ((*(uint *)(unaff_gp + -0x7fd4) & 0x140) != 0) {
      uVar5 = uVar5 | 0x100;
    }
    FUN_00000000(iVar12,0,uVar5);
    goto LAB_00000a90;
  }
  if (*(int *)(unaff_gp + -0x7fd8) == 0) {
    FUN_00000000(iVar12,0,0);
    uVar3 = FUN_000000a0(iVar12,1);
    uVar5 = *(uint *)(unaff_gp + -0x7fd4);
    if ((uVar3 & 0x4000) == 0) {
      *(uint *)(unaff_gp + -0x7fd4) = uVar5 & 0xfffffeff;
    }
    if ((uVar3 & 0x2000) == 0) {
      *(uint *)(unaff_gp + -0x7fd4) = *(uint *)(unaff_gp + -0x7fd4) & 0xffffff7f;
    }
    if ((uVar3 & 0x1000) == 0) {
      *(uint *)(unaff_gp + -0x7fd4) = *(uint *)(unaff_gp + -0x7fd4) & 0xffffffbf;
    }
    if ((uVar3 & 0x800) == 0) {
      *(uint *)(unaff_gp + -0x7fd4) = *(uint *)(unaff_gp + -0x7fd4) & 0xffffffdf;
    }
    if (*(int *)(unaff_gp + -0x7fe0) != 0) {
      FUN_000029f4("smap: no strap mode (conf=0x%x->0x%x, bmsr=0x%x)\n",uVar5,
                   *(undefined4 *)(unaff_gp + -0x7fd4),uVar3);
    }
    uVar5 = FUN_000000a0(iVar12,4);
    uVar11 = uVar5 & 0x1f | *(uint *)(unaff_gp + -0x7fd4) & 0x5e0;
    if (*(int *)(unaff_gp + -0x7fe0) != 0) {
      FUN_000029f4("smap: anar=0x%x->0x%x\n",uVar5 & 0xffff,uVar11);
    }
    FUN_00000000(iVar12,4,uVar11);
    FUN_00000000(iVar12,0,0x1200);
  }
  else {
    uVar5 = FUN_000000a0(iVar12,0);
    if ((uVar5 & 0x1000) == 0) {
      iVar15 = 0;
      goto LAB_00000a90;
    }
  }
  uVar1 = FUN_000000a0(iVar12,0);
  uVar2 = FUN_000000a0(iVar12,4);
  FUN_000029f4("smap: auto mode (BMCR=0x%x ANAR=0x%x)\n",uVar1,uVar2);
  do {
    iVar10 = 0;
    do {
      iVar8 = 0;
      do {
        FUN_00002b40(1000000);
        iVar8 = iVar8 + 1;
        if (*(int *)(param_1 + 0x30) != 0) {
          return 0;
        }
      } while (iVar8 < 3);
      uVar3 = FUN_000000a0(iVar12,1);
      if ((uVar3 & 0x30) == 0x20) {
        iVar8 = 0;
        do {
          FUN_00002b40(200000);
          if (*(int *)(param_1 + 0x30) != 0) {
            return 0;
          }
          uVar5 = FUN_000000a0(iVar12,1);
          if ((uVar5 & 4) != 0) goto LAB_00000e54;
          iVar8 = iVar8 + 1;
        } while (iVar8 < 0x14);
      }
      iVar8 = *(int *)(unaff_gp + -0x7fe0);
      *(undefined4 *)(param_1 + 0x38) = 0;
      if (iVar8 != 0) {
        uVar1 = FUN_000000a0(iVar12,0);
        FUN_000029f4("smap: restarting auto nego (BMCR=0x%x, BMSR=0x%x)\n",uVar1,uVar3);
      }
      FUN_00000000(iVar12,0,0x1200);
      iVar10 = iVar10 + 1;
    } while (iVar10 < 3);
    if (*(int *)(unaff_gp + -0x7fe0) != 0) {
      FUN_000029f4("smap: waiting valid link for 100Mbps Half-Duplex\n");
    }
    FUN_00000000(iVar12,0,0x2000);
    FUN_00002b40(1000000);
    if (*(int *)(param_1 + 0x30) != 0) {
      return 0;
    }
    iVar10 = 0;
    do {
      uVar5 = FUN_000000a0(iVar12,1);
      if ((uVar5 & 4) != 0) goto LAB_00000e54;
      FUN_00002b40(100000);
      iVar10 = iVar10 + 1;
      if (*(int *)(param_1 + 0x30) != 0) {
        return 0;
      }
    } while (iVar10 < 0x1e);
    if (*(int *)(unaff_gp + -0x7fe0) != 0) {
      FUN_000029f4("smap: waiting valid link for 10Mbps Half-Duplex\n");
    }
    FUN_00000000(iVar12,0,0);
    FUN_00002b40(1000000);
    if (*(int *)(param_1 + 0x30) != 0) {
      return 0;
    }
    iVar10 = 0;
    do {
      uVar5 = FUN_000000a0(iVar12,1);
      if ((uVar5 & 4) != 0) goto LAB_00000e54;
      FUN_00002b40(100000);
      iVar10 = iVar10 + 1;
      if (*(int *)(param_1 + 0x30) != 0) {
        return 0;
      }
    } while (iVar10 < 0x1e);
  } while( true );
LAB_00000e54:
  *(undefined4 *)(param_1 + 0x38) = 1;
  iVar10 = 0;
  puVar9 = local_38;
  do {
    uVar3 = FUN_000000a0(iVar12,iVar10);
    *puVar9 = uVar3;
    iVar10 = iVar10 + 1;
    puVar9 = puVar9 + 1;
  } while (iVar10 < 6);
  if (*(int *)(unaff_gp + -0x7fe0) != 0) {
    FUN_000029f4("smap: PHY: %04x %04x %04x %04x %04x %04x\n",local_38[0],local_38[1],local_38[2],
                 local_38[3],local_30,local_2e);
  }
  if ((local_38[2] != 0x2000) || ((local_38[3] & 0xfff0) != 0x5c20)) goto LAB_00001048;
  if (iVar15 == 0) {
LAB_00000f7c:
    FUN_000029f4("smap: PHY chip: DP83846A%d\n",(local_38[3] & 0xf) + 1);
    if (iVar15 == 0) {
      if ((local_38[0] & 0x2100) == 0) goto LAB_00000fd0;
    }
    else if ((local_30 & 0x1e0) == 0x20) {
LAB_00000fd0:
      FUN_00000000(iVar12,0x1a,0x104);
    }
    if ((local_38[3] & 0xf) == 0) {
      FUN_00000000(iVar12,0x13,1);
      FUN_00000000(iVar12,0x19,0x1898);
      FUN_00000000(iVar12,0x1f,0);
      FUN_00000000(iVar12,0x1d,0x5040);
      FUN_00000000(iVar12,0x1e,0x8c);
      FUN_00000000(iVar12,0x13,0);
    }
LAB_00001048:
    uVar14 = 0;
    if ((local_38[0] & 0x1000) == 0) {
      uVar13 = local_38[0] >> 0xd & 1;
      uVar3 = local_38[0] >> 8 & 1;
      uVar14 = *(uint *)(unaff_gp + -0x7fd4) >> 10 & 1;
    }
    else {
      local_30 = local_30 & local_2e;
      uVar13 = (ushort)((local_30 & 0x180) != 0);
      uVar3 = (ushort)((local_30 & 0x140) != 0);
      if (uVar3 != 0) {
        uVar14 = (uint)((local_30 & 0x400) != 0);
      }
    }
    if (uVar13 == 0) {
      uVar6 = 2;
      if (uVar3 == 0) {
        uVar6 = 1;
      }
    }
    else {
      uVar6 = 8;
      if (uVar3 == 0) {
        uVar6 = 4;
      }
    }
    *(undefined4 *)(param_1 + 0x3c) = uVar6;
    if (uVar14 != 0) {
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x40;
    }
    pcVar7 = (char *)(unaff_gp + -0x7fd0);
    if (uVar13 != 0) {
      pcVar7 = "100BaseTX";
    }
    iVar15 = unaff_gp + -0x7fc0;
    if (uVar3 != 0) {
      iVar15 = unaff_gp + -0x7fc8;
    }
    iVar10 = unaff_gp + -0x7fb0;
    if (uVar14 != 0) {
      iVar10 = unaff_gp + -0x7fb8;
    }
    FUN_000029f4("smap: %s %s Duplex Mode %s Flow Control\n",pcVar7,iVar15,iVar10);
    uVar5 = (*(uint *)(iVar12 + 4) & 0x67ff) << 0x10 | *(uint *)(iVar12 + 4) >> 0x10;
    if (uVar3 != 0) {
      uVar5 = uVar5 | 0x80000000;
    }
    if (uVar14 != 0) {
      uVar5 = uVar5 | 0x18000000;
    }
    *(uint *)(iVar12 + 4) = uVar5 << 0x10 | uVar5 >> 0x10;
    return 0;
  }
  FUN_000000a0(iVar12,0x14);
  FUN_000000a0(iVar12,0x15);
  FUN_00002b40(500000);
  uVar3 = FUN_000000a0(iVar12,0x14);
  sVar4 = FUN_000000a0(iVar12,0x15);
  if ((sVar4 == 0) && (uVar3 < 0x11)) goto LAB_00000f7c;
  if (*(int *)(unaff_gp + -0x7fe0) != 0) {
    FUN_000029f4("smap: FCSCR=%d RECR=%d\n",uVar3);
  }
  FUN_00000000(iVar12,0,0);
  iVar15 = 0;
LAB_00000a90:
  uVar6 = 10;
  if (uVar14 != 0) {
    uVar6 = 100;
  }
  iVar10 = 0;
  FUN_000029f4("smap: Waiting Valid Link for %dMbps\n",uVar6);
  while( true ) {
    FUN_00002b40(200000);
    if (*(int *)(param_1 + 0x30) != 0) {
      return 0;
    }
    uVar5 = FUN_000000a0(iVar12,1);
    iVar10 = iVar10 + 1;
    if ((uVar5 & 4) != 0) break;
    if (4 < iVar10) {
      *(undefined4 *)(param_1 + 0x38) = 0;
    }
  }
  goto LAB_00000e54;
}


================================================================