FUNCTION FUN_00007974 @ 0x00007974 size=460
CALLERS (1): FUN_00007b40@0x00007b40
CALLEES (6): FUN_00008ddc@0x00008ddc, FUN_000090a8@0x000090a8, FUN_00009720@0x00009720, FUN_00005ee4@0x00005ee4, FUN_000091c8@0x000091c8, FUN_00000fe4@0x00000fe4

undefined4 FUN_00007974(undefined4 *param_1,undefined *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  undefined *puVar5;
  undefined *puVar6;
  int iVar7;
  
  iVar7 = param_1[3] - param_1[2];
  if (param_1[10] != 0) {
    puVar5 = (undefined *)*param_1;
    if (puVar5 == (undefined *)0x0) {
      puVar5 = &DAT_0000a98c;
    }
    puVar6 = param_2;
    if (param_2 == (undefined *)0x0) {
      puVar6 = &DAT_0000a98c;
    }
    FUN_00009720("netcnf: dir=%s path=%s\n",puVar5,puVar6);
  }
  iVar1 = FUN_00005ee4(param_1,param_2);
  uVar2 = 0xffffffff;
  if (iVar1 != 0) {
    if (param_1[10] != 0) {
      FUN_00009720("netcnf: writing \"%s\" as ",iVar1);
      pcVar4 = "NET_CNF";
      if (param_3 != 0) {
        pcVar4 = "ATTACH_CNF";
      }
      FUN_00009720(pcVar4);
      FUN_00009720(&DAT_0000a700);
    }
    if ((param_3 == 0) || (param_1[9] != 0)) {
      iVar1 = FUN_00008ddc(iVar1,0x602,0x1ff);
      if (iVar1 < 0) {
        param_1[0xb] = param_1[0xb] + 1;
        uVar2 = 0xfffffffd;
        if (iVar1 == -5) {
          uVar2 = 0xffffffee;
        }
      }
      else {
        iVar3 = FUN_000090a8(iVar1,param_1[2],iVar7);
        if (iVar7 == iVar3) {
          FUN_000091c8(iVar1);
          uVar2 = 0;
        }
        else {
          param_1[0xb] = param_1[0xb] + 1;
          FUN_000091c8(iVar1);
          uVar2 = 0xfffffffb;
          if (iVar3 == -5) {
            uVar2 = 0xffffffee;
          }
        }
      }
    }
    else {
      iVar7 = FUN_00000fe4(iVar1,param_1[2],iVar7);
      uVar2 = 0;
      if (iVar7 < 0) {
        uVar2 = 0xffffffff;
        param_1[0xb] = param_1[0xb] + 1;
      }
    }
  }
  return uVar2;
}


================================================================