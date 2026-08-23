FUNCTION FUN_005df170 @ 0x005df170  size=460
CALLERS (1): FUN_005df340@0x005df340
CALLEES (7): FUN_005df780@0x005df780, FUN_005def30@0x005def30, FUN_005dee60@0x005dee60, FUN_005deee0@0x005deee0, FUN_005df020@0x005df020, FUN_005df060@0x005df060, FUN_005deea0@0x005deea0
----------------------------------------------------------------

undefined8 FUN_005df170(undefined8 param_1,undefined8 param_2,long param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined1 *extraout_a1_lo;
  long extraout_a2;
  long extraout_a3;
  char *extraout_t0_lo;
  int iVar6;
  
  cVar1 = FUN_005df780(param_2);
  if (cVar1 == '\0') {
    if (*(char *)param_1 == '\0') {
      return 0;
    }
    uVar3 = FUN_005dee60(param_1);
    if (*(char *)param_2 == '/') {
      lVar4 = FUN_005def30(param_1,uVar3);
    }
    else {
      lVar4 = FUN_005deea0(param_1,uVar3);
    }
    if (lVar4 == 0) {
      return 0;
    }
    iVar6 = ((int)lVar4 - (int)(char *)param_1) + 1;
    iVar2 = func_0x0010a050(param_2);
    func_0x00106a58((char *)param_2 + iVar6,param_2,iVar2 + 1);
    func_0x001069a8(param_2,param_1,iVar6);
    cVar1 = FUN_005df780(param_2);
  }
  func_0x0010a050(param_2);
  uVar3 = FUN_005dee60(param_2);
  lVar4 = FUN_005deee0(param_2,uVar3);
  if (((lVar4 == 0) && (*extraout_t0_lo == '\0')) && (param_3 != 0)) {
    if (0xfe < extraout_a3) {
      return 0;
    }
    if (extraout_t0_lo[-1] != '/') {
      *extraout_t0_lo = '/';
      extraout_t0_lo[1] = '\0';
    }
  }
  uVar3 = param_2;
  if (cVar1 != '\x01') {
    func_0x0010a050(param_2);
    uVar5 = FUN_005dee60(param_2);
    iVar2 = FUN_005df060(param_2,uVar5);
    lVar4 = FUN_005df020(iVar2 + 2);
    if (((lVar4 == 0) && (uVar3 = 0, extraout_a2 < 0xff)) &&
       (uVar3 = param_2, extraout_a1_lo[-1] != '/')) {
      *extraout_a1_lo = 0x2f;
      extraout_a1_lo[1] = 0;
    }
  }
  return uVar3;
}



================================================================