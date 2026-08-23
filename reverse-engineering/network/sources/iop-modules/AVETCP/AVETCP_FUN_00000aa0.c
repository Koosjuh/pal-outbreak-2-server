FUNCTION FUN_00000aa0 @ 0x00000aa0 size=1076
CALLERS (0): 
CALLEES (18): FUN_00013360@0x00013360, FUN_00014e24@0x00014e24, FUN_000132a0@0x000132a0, FUN_000123f4@0x000123f4, FUN_00013320@0x00013320, FUN_00011bb0@0x00011bb0, FUN_00014d48@0x00014d48, FUN_0000e304@0x0000e304, FUN_00013280@0x00013280, FUN_00011938@0x00011938, FUN_00013270@0x00013270, FUN_00012248@0x00012248, FUN_00013170@0x00013170, FUN_0000e2b0@0x0000e2b0, FUN_00011cf0@0x00011cf0, FUN_000132b0@0x000132b0, FUN_00013290@0x00013290, FUN_000133d8@0x000133d8

int FUN_00000aa0(undefined4 param_1)

{
  short sVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  if (DAT_00016178 != 0) {
    FUN_00014e24("AT_init: called.\n");
  }
  iVar4 = 0x38;
  DAT_00017bc4 = 0x350;
  DAT_00017bc8 = 0x36c;
  DAT_00017bcc = 0x390;
  DAT_00017bd0 = 0x398;
  DAT_00017bd4 = 0x3a0;
  DAT_00017bd8 = 0x3c4;
  DAT_00017be0 = 1000;
  DAT_00017be4 = 0x40c;
  DAT_00017c00 = 0x430;
  DAT_00017c04 = 0x454;
  DAT_00017c08 = 0x478;
  DAT_00017c0c = 0x4d0;
  DAT_00017c10 = 0x4f4;
  DAT_00017c14 = 0x518;
  DAT_00017c18 = 0x53c;
  DAT_00017c1c = 0x564;
  DAT_00017c20 = 0x594;
  DAT_00017c24 = 0x5b8;
  DAT_00017c28 = 0x5dc;
  DAT_00017c2c = 0x600;
  DAT_00017c30 = 0x624;
  DAT_00017c40 = 0x648;
  DAT_00017bc0 = 0x364;
  DAT_00017bdc = 0x364;
  DAT_00017be8 = 0x364;
  DAT_00017bec = 0x364;
  DAT_00017bf0 = 0x364;
  DAT_00017bf4 = 0x364;
  DAT_00017bf8 = 0x364;
  DAT_00017bfc = 0x364;
  DAT_00017c34 = 0x364;
  DAT_00017c38 = 0x364;
  DAT_00017c3c = 0x364;
  DAT_00017c44 = 0x66c;
  DAT_00017c48 = 0x690;
  DAT_00017c50 = 0x6b4;
  DAT_00017c54 = 0x6d8;
  DAT_00017c78 = 0x6fc;
  DAT_00017c7c = 0x720;
  DAT_00017c80 = 0x744;
  DAT_00017c84 = 0x768;
  DAT_00017c88 = 0x78c;
  DAT_00017c90 = 0x7b0;
  DAT_00017c94 = 0x7d4;
  DAT_00017c4c = 0x364;
  DAT_00017c58 = 0x364;
  DAT_00017c5c = 0x364;
  DAT_00017c60 = 0x364;
  DAT_00017c64 = 0x364;
  DAT_00017c68 = 0x364;
  DAT_00017c6c = 0x364;
  DAT_00017c70 = 0x364;
  DAT_00017c74 = 0x364;
  DAT_00017c8c = 0x364;
  DAT_00017c98 = 0x7f8;
  DAT_00017c9c = 0x364;
  iVar2 = 0xe0;
  do {
    *(undefined4 *)((int)&DAT_00017bc0 + iVar2) = 0x364;
    iVar4 = iVar4 + 1;
    iVar2 = iVar4 * 4;
  } while (iVar4 < 0x8f);
  sVar1 = FUN_00013270();
  if (sVar1 != 0) {
    FUN_000132b0();
  }
  sVar1 = FUN_00013280();
  if (sVar1 != 0) {
    FUN_00013320();
  }
  sVar1 = FUN_00013290();
  if (sVar1 != 0) {
    FUN_00013360();
  }
  FUN_00014d48();
  sVar1 = FUN_000132a0();
  if (sVar1 != 0) {
    FUN_000133d8();
  }
  DAT_00017cc4 = 0x81c;
  DAT_00017cc8 = 0x84c;
  DAT_00017ccc = 0x874;
  DAT_00017cd0 = 0x8a4;
  sVar1 = FUN_00011bb0();
  iVar2 = (int)sVar1;
  if (iVar2 == 0) {
    sVar1 = FUN_00013170(param_1);
    if (sVar1 != 0) {
      if (DAT_00016178 == 0) {
        return -1;
      }
      FUN_00014e24("AT_init: argument error. return %d\n",0xffffffff);
      return -1;
    }
    FUN_00012248();
    iVar4 = FUN_0000e2b0();
    iVar2 = (iVar4 << 0x10) >> 0x10;
    if (iVar4 << 0x10 == 0) {
      sVar1 = FUN_00011938(param_1);
      iVar2 = (int)sVar1;
    }
    if (iVar2 == 0) {
      if (DAT_00016178 == 0) {
        return 0;
      }
      FUN_00014e24("AT_init: return %d\n",0);
      return 0;
    }
    FUN_000123f4();
    FUN_00011cf0();
    FUN_0000e304();
    if (DAT_00016178 == 0) {
      return iVar2;
    }
    pcVar3 = "AT_init: initialize error. return %d\n";
  }
  else {
    if (DAT_00016178 == 0) {
      return iVar2;
    }
    pcVar3 = "AT_init: Can\'t allocate buffers. return %d\n";
  }
  FUN_00014e24(pcVar3,iVar2);
  return iVar2;
}


================================================================