FUNCTION FUN_000097cc @ 0x000097cc size=1220
CALLERS (2): FUN_0000d9c8@0x0000d9c8, FUN_00007000@0x00007000
CALLEES (6): FUN_00001454@0x00001454, FUN_0000139c@0x0000139c, FUN_00011d00@0x00011d00, FUN_000105ec@0x000105ec, FUN_000010c0@0x000010c0, FUN_00010880@0x00010880

undefined4 FUN_000097cc(uint param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_48 [8];
  short local_40;
  short local_3e;
  undefined4 local_3c;
  undefined1 auStack_38 [4];
  undefined1 local_34;
  undefined1 local_2c;
  undefined1 auStack_28 [4];
  undefined1 local_24;
  
  if ((*(uint *)(param_2 + 0xd8) & 1) == 1) {
    local_34 = 1;
    local_2c = 1;
    local_24 = 1;
    if (param_1 == 0) {
      return 0;
    }
    if (*(int *)(param_2 + 8) == 0) {
      return 0;
    }
    FUN_0000139c(auStack_28,auStack_48);
    FUN_00011d00(auStack_38,param_2,8);
    if (*(int *)(param_2 + 0xc) != 0) {
      FUN_00001454(auStack_38,(*(int *)(param_2 + 0xc) << 0x14) >> 0x10);
    }
    FUN_000010c0(auStack_28,auStack_38,0x10);
    if ((uint)(int)local_40 <= param_1) {
      do {
        if (*(int *)(param_2 + 8) == 0) break;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + -1;
        uVar1 = (uint)DAT_0001619e;
        param_1 = param_1 - (int)local_40;
        *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) - (int)local_40;
        if (*(uint *)(param_2 + 0xc) < uVar1) {
          *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) + 1;
        }
        else {
          *(undefined4 *)(param_2 + 0xc) = 0;
        }
        if (*(int *)(param_2 + 8) == 0) {
          *(undefined4 *)(param_2 + 0x10) = 0;
          *(undefined4 *)(param_2 + 0xc) = 0;
          *(uint *)(param_2 + 0xd8) = *(uint *)(param_2 + 0xd8) & 0xfffffffe;
        }
        FUN_00010880((param_2 - DAT_00016180) * -0x69184000 >> 0x10,local_3c,0,auStack_48);
        iVar3 = *(int *)(param_2 + 0xc);
        FUN_00011d00(auStack_38,param_2,8);
        if (iVar3 != 0) {
          FUN_00001454(auStack_38,(iVar3 << 0x14) >> 0x10);
        }
        FUN_000010c0(auStack_28,auStack_38,0x10);
      } while ((uint)(int)local_40 <= param_1);
    }
    if (param_1 == 0) {
      return 0;
    }
    if (*(int *)(param_2 + 8) == 0) {
      return 0;
    }
    *(uint *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) - param_1;
    local_40 = local_40 - (short)param_1;
    local_3e = local_3e + (short)param_1;
    FUN_000010c0(auStack_38,auStack_28,0x10);
    return 0;
  }
  if (param_1 != 0) {
    uVar1 = *(uint *)(param_2 + 8);
    psVar4 = (short *)(param_2 + 0x1c);
    if (uVar1 < param_1) {
      param_1 = param_1 - uVar1;
      *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_2 + 0x10);
      iVar3 = 0;
      *(undefined4 *)(param_2 + 8) = 0;
      *(uint *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) - param_1;
      if (*(int *)(param_2 + 0x14) != 0) {
        do {
          if (param_1 == 0) break;
          if (param_1 < (uint)(int)*psVar4) {
            *psVar4 = *psVar4 - (short)param_1;
            FUN_00001454(psVar4 + 2,(int)(short)param_1);
            param_1 = 0;
          }
          else {
            param_1 = param_1 - (int)*psVar4;
            *psVar4 = 0;
          }
          iVar3 = iVar3 + 1;
          psVar4 = psVar4 + 6;
        } while ((uint)(iVar3 * 0x10000 >> 0x10) < *(uint *)(param_2 + 0x14));
      }
    }
    else {
      *(uint *)(param_2 + 8) = uVar1 - param_1;
      uVar1 = (uint)(short)DAT_000161a4;
      param_1 = *(int *)(param_2 + 0xc) + param_1;
      *(uint *)(param_2 + 0xc) = param_1;
      if (uVar1 <= param_1) {
        *(uint *)(param_2 + 0xc) = param_1 - uVar1;
      }
    }
  }
  if (*(uint *)(param_2 + 0x18) == 0) {
    uVar2 = *(undefined4 *)(param_2 + 0xd0);
    iVar3 = DAT_00016180;
  }
  else {
    if ((uint)((int)(short)DAT_000161a4 - *(int *)(param_2 + 8)) < *(uint *)(param_2 + 0x18)) {
      return 0;
    }
    FUN_00011d00(auStack_48,param_2,8);
    iVar3 = 0;
    FUN_00001454(auStack_48,(int)*(short *)(param_2 + 0x10));
    psVar4 = (short *)(param_2 + 0x1c);
    if (*(int *)(param_2 + 0x14) != 0) {
      iVar6 = param_2 + 0x20;
      do {
        if (0 < *psVar4) {
          uVar1 = (uint)DAT_000161a4 - (uint)*(ushort *)(param_2 + 0x10);
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + (int)*psVar4;
          if ((uVar1 & 0xffff) < (uint)(int)*psVar4) {
            FUN_000010c0(auStack_48,iVar6,uVar1 & 0xffff);
            FUN_00001454(iVar6,(int)(uVar1 * 0x10000) >> 0x10);
            *psVar4 = *psVar4 - (short)uVar1;
            *(undefined4 *)(param_2 + 0x10) = 0;
            *(uint *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) - (uVar1 & 0xffff);
            FUN_00011d00(auStack_48,param_2,8);
          }
          iVar5 = (int)*psVar4;
          FUN_000010c0(auStack_48,iVar6,iVar5);
          *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + iVar5;
          FUN_00001454(auStack_48,iVar5);
          *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) - iVar5;
          *psVar4 = 0;
        }
        iVar6 = iVar6 + 0xc;
        iVar3 = iVar3 + 1;
        psVar4 = psVar4 + 6;
      } while ((uint)(iVar3 * 0x10000 >> 0x10) < *(uint *)(param_2 + 0x14));
    }
    iVar3 = DAT_00016180;
    if (*(int *)(param_2 + 0x18) != 0) {
      return 0;
    }
    uVar2 = *(undefined4 *)(param_2 + 0xd0);
    *(undefined4 *)(param_2 + 0x18) = 0;
    *(undefined4 *)(param_2 + 0x14) = 0;
  }
  FUN_000105ec((param_2 - iVar3) * -0x69184000 >> 0x10,uVar2,0);
  return 0;
}


================================================================