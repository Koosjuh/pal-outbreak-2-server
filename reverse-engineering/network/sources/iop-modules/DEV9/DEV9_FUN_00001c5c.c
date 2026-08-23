FUNCTION FUN_00001c5c @ 0x00001c5c size=1260
CALLERS (1): FUN_00000c9c@0x00000c9c
CALLEES (3): FUN_00001b1c@0x00001b1c, FUN_00001a70@0x00001a70, FUN_000021e0@0x000021e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00001c5c(void)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  uint local_2c [5];
  
  if ((_DAT_b0000004 & 1) != 0) {
    DAT_b0001000 = 1;
    iVar3 = 9;
    while ((DAT_b0001000 & 1) != 0) {
      if (iVar3 < 1) {
        return 1;
      }
      FUN_000021e0(1000);
      iVar3 = iVar3 + -1;
    }
    DAT_b0001030 = 1;
    iVar3 = 9;
    while ((DAT_b0001030 & 1) != 0) {
      if (iVar3 < 1) {
        return 2;
      }
      FUN_000021e0(1000);
      iVar3 = iVar3 + -1;
    }
    iVar3 = 9;
    _DAT_b0002000 = 0x2000;
    _DAT_b0002002 = 0;
    while ((_DAT_b0002000 & 0x2000) != 0) {
      if (iVar3 < 1) {
        return 3;
      }
      FUN_000021e0(1000);
      iVar3 = iVar3 + -1;
    }
    if (0x10 < _DAT_b0000002) {
      DAT_b0000102 = 1;
    }
    puVar2 = (undefined2 *)&DAT_b0003000;
    iVar3 = 0;
    do {
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 4;
    } while (iVar3 < 0x40);
    puVar2 = (undefined2 *)&DAT_b0003200;
    iVar3 = 0;
    do {
      *puVar2 = 0x80;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 4;
    } while (iVar3 < 0x40);
    _DAT_b0000128 = 0x7c;
    if (_DAT_b0000002 < 0x11) {
      DAT_b0000100 = 1;
    }
    _DAT_b0002004 = 0x8164;
    _DAT_b0002006 = 0x8000;
    _DAT_b000200c = 0x380f;
    _DAT_b000200e = 0;
    _DAT_b0002010 = 0x3f00;
    _DAT_b0002012 = 0;
    _DAT_b0002014 = 0;
    _DAT_b0002016 = 0x1c0;
    _DAT_b0002018 = 0;
    _DAT_b000201a = 0x1c0;
    _DAT_b000201c = 0;
    _DAT_b000201e = 0;
    _DAT_b0002020 = 0;
    _DAT_b0002022 = 0;
    _DAT_b000202c = 0;
    _DAT_b000202e = 0xffff;
    _DAT_b0002058 = 0;
    _DAT_b000205a = 4;
    _DAT_b0002060 = 0x6000;
    _DAT_b0002062 = 0;
    iVar3 = 9;
    _DAT_b0002064 = 0x800;
    _DAT_b0002066 = 0x4000;
    FUN_00001a70(&DAT_b0002000,0,0x8000);
    while( true ) {
      iVar1 = FUN_00001b1c(&DAT_b0002000,0,local_2c);
      if (iVar1 != 0) {
        return 4;
      }
      if ((local_2c[0] & 0x8000) == 0) break;
      if (iVar3 < 1) {
        return 5;
      }
      FUN_000021e0(1000);
      iVar3 = iVar3 + -1;
    }
    FUN_00001a70(&DAT_b0002000,0,0x6100);
    FUN_000021e0(&DAT_00002710);
    local_2c[1] = 0x18000000;
    _DAT_b0002000 = 0x1800;
    _DAT_b0002002 = 0;
    iVar3 = 0;
    do {
      _DAT_b0001100 = iVar3;
      iVar3 = _DAT_b0001100 + 4;
    } while (_DAT_b0001100 + 4 < 0x5ea);
    iVar3 = 9;
    _DAT_b0003004 = 0xea05;
    _DAT_b0003006 = (ushort)(_DAT_b0001004 + 0x1000U) >> 8 | _DAT_b0001004 << 8;
    local_2c[2] = 0x80000000;
    DAT_b0001010 = 0;
    _DAT_b0003000 = 0x83;
    _DAT_b0002008 = 0x8000;
    _DAT_b000200a = 0;
    while (local_2c[0] = (uint)_DAT_b0000028, (local_2c[0] & 0x34) != 0x34) {
      if (iVar3 < 1) {
        return 6;
      }
      FUN_000021e0(1000);
      iVar3 = iVar3 + -1;
    }
    _DAT_b0002000 = 0x2000;
    _DAT_b0002002 = 0;
  }
  return 0;
}


================================================================