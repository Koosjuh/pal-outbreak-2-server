FUNCTION FUN_0000c444 @ 0x0000c444 size=1800
CALLERS (1): FUN_0000cb4c@0x0000cb4c
CALLEES (6): FUN_0000c2b8@0x0000c2b8, FUN_00011d90@0x00011d90, FUN_0000c33c@0x0000c33c, FUN_0000c1dc@0x0000c1dc, FUN_000199bc@0x000199bc, FUN_0000c3d8@0x0000c3d8

/* WARNING: Type propagation algorithm not settling */

undefined4
FUN_0000c444(uint *param_1,ushort *param_2,uint param_3,undefined4 param_4,undefined4 param_5,
            ushort param_6,int param_7)

{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined1 *puVar8;
  uint uVar9;
  undefined1 *puVar10;
  short local_30;
  short local_2e;
  undefined4 local_2c;
  
  local_2c = 0xfffffdfb;
  if (param_3 < 0xc) {
    uVar6 = 0xe1;
    goto joined_r0x0000c70c;
  }
  *param_2 = *param_2 << 8 | *param_2 >> 8;
  param_2[2] = param_2[2] << 8 | param_2[2] >> 8;
  param_2[3] = param_2[3] << 8 | param_2[3] >> 8;
  param_2[4] = param_2[4] << 8 | param_2[4] >> 8;
  param_2[5] = param_2[5] << 8 | param_2[5] >> 8;
  if (*param_2 != param_6) {
    local_2c = 0xfffffdfc;
    if ((DAT_0001b850 & 1) == 0) {
      return 0xfffffdfc;
    }
    uVar6 = 0xe6;
    goto LAB_0000ca68;
  }
  uVar2 = param_2[1];
  if ((uVar2 & 0x80) == 0) {
    uVar6 = 0xe9;
  }
  else if ((uVar2 & 0x78) == 0) {
    if ((uVar2 & 2) == 0) {
      if ((uVar2 & 0xf00) == 0) {
        puVar4 = param_2 + 6;
        if (param_2[2] == 1) {
          uVar9 = (uint)param_2[2];
          puVar10 = (undefined1 *)((int)param_2 + param_3);
          if (uVar9 != 0) {
            do {
              uVar9 = uVar9 - 1;
              iVar3 = FUN_0000c1dc(param_4,param_2,puVar4,puVar10);
              if (iVar3 == 0) {
                uVar6 = 0xfa;
                goto joined_r0x0000c70c;
              }
              iVar3 = FUN_0000c2b8(&local_30,iVar3,puVar10);
              if (iVar3 == 0) {
                uVar6 = 0xfc;
                goto joined_r0x0000c70c;
              }
              puVar4 = (ushort *)FUN_0000c2b8(&local_2e,iVar3,puVar10);
              if (puVar4 == (ushort *)0x0) {
                uVar6 = 0xfe;
                goto joined_r0x0000c70c;
              }
              iVar3 = FUN_0000c33c(param_4,param_5);
              if (iVar3 != 0) {
                uVar6 = 0x100;
                goto joined_r0x0000c70c;
              }
              if (param_7 < 1) {
                if (local_30 != 1) {
                  uVar6 = 0x106;
                  goto joined_r0x0000c70c;
                }
              }
              else if (local_30 != 0xc) {
                uVar6 = 0x103;
                goto joined_r0x0000c70c;
              }
              if (local_2e != 1) {
                uVar6 = 0x109;
                goto joined_r0x0000c70c;
              }
            } while (0 < (int)uVar9);
          }
          uVar9 = (uint)param_2[3];
          while( true ) {
            bVar1 = (int)uVar9 < 1;
            uVar9 = uVar9 - 1;
            if (bVar1) {
              return 0xfffffdfa;
            }
            iVar3 = FUN_0000c1dc(param_4,param_2,puVar4,puVar10);
            if (iVar3 == 0) break;
            iVar3 = FUN_0000c2b8(&local_30,iVar3,puVar10);
            if (iVar3 == 0) {
              uVar6 = 0x10f;
              goto joined_r0x0000c70c;
            }
            iVar3 = FUN_0000c2b8(&local_2e,iVar3,puVar10);
            if (iVar3 == 0) {
              uVar6 = 0x111;
              goto joined_r0x0000c70c;
            }
            if (puVar10 <= (undefined1 *)(iVar3 + 4)) {
              uVar6 = 0x113;
              goto joined_r0x0000c70c;
            }
            puVar8 = (undefined1 *)(iVar3 + 6);
            if (puVar10 <= puVar8) {
              uVar6 = 0x116;
              goto joined_r0x0000c70c;
            }
            uVar7 = (uint)CONCAT11(*(undefined1 *)(iVar3 + 4),*(undefined1 *)(iVar3 + 5));
            puVar4 = (ushort *)(puVar8 + uVar7);
            iVar5 = FUN_0000c33c(param_4,param_5);
            if ((iVar5 == 0) && (local_2e == 1)) {
              if (local_30 == 5) {
                iVar3 = FUN_0000c1dc(param_4,param_2,puVar8,puVar10);
                if (iVar3 == 0) {
                  uVar6 = 0x11f;
                  goto joined_r0x0000c70c;
                }
                FUN_000199bc(param_5,param_4);
                if ((DAT_0001b850 & 4) != 0) {
                  FUN_00011d90("res_getanswer - CNAME %s\n",param_5);
                }
              }
              else if (param_7 < 1) {
                if ((local_30 == 1) && (uVar7 == 4)) {
                  *param_1 = (uint)*(byte *)(iVar3 + 6) << 0x18 | (uint)*(byte *)(iVar3 + 7) << 0x10
                             | (uint)*(byte *)(iVar3 + 8) << 8 | (uint)*(byte *)(iVar3 + 9);
                  return 0;
                }
              }
              else if (((local_30 == 0xc) && (uVar7 != 0)) && (uVar7 < 0x200)) {
                FUN_0000c3d8(param_4,puVar8);
                return 0;
              }
            }
          }
          uVar6 = 0x10d;
        }
        else {
          uVar6 = 0xf6;
        }
      }
      else {
        if ((uVar2 & 0xf00) == 0x300) {
          uVar6 = 0xfffffdfd;
LAB_0000c62c:
          local_2c = uVar6;
        }
        else {
          uVar6 = 0xfffffdfc;
          if ((uVar2 & 0xf00) == 0x200) goto LAB_0000c62c;
        }
        uVar6 = 0xf3;
      }
    }
    else {
      uVar6 = 0xed;
    }
  }
  else {
    uVar6 = 0xeb;
  }
joined_r0x0000c70c:
  if ((DAT_0001b850 & 1) == 0) {
    return local_2c;
  }
LAB_0000ca68:
  FUN_00011d90("# ERR # %s:%d: %s\n","resolv.c",uVar6,"res_getanswer");
  return local_2c;
}


================================================================