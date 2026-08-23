
undefined4 FUN_001d5768(ushort param_1,ushort param_2)

{
  undefined4 uStack_1c;
  
  uStack_1c = 0xffffffff;
  if ((param_1 & 1) != 0) {
    if (((param_2 & 1) != 0) || ((param_2 & 0x20) != 0)) {
      uStack_1c = 0x20;
    }
    if ((((param_2 & 2) != 0) || ((param_2 & 4) != 0)) || ((param_2 & 8) != 0)) {
      uStack_1c = 8;
    }
  }
  if ((param_1 & 2) != 0) {
    if (((param_2 & 2) != 0) || ((param_2 & 4) != 0)) {
      uStack_1c = 4;
    }
    if (((param_2 & 8) != 0) || ((param_2 & 0x10) != 0)) {
      uStack_1c = 0x10;
    }
  }
  if ((param_1 & 4) != 0) {
    if (((param_2 & 2) != 0) || ((param_2 & 4) != 0)) {
      uStack_1c = 4;
    }
    if (((param_2 & 8) != 0) || ((param_2 & 0x10) != 0)) {
      uStack_1c = 0x10;
    }
  }
  if ((param_1 & 0x20) != 0) {
    if (((param_2 & 1) != 0) || ((param_2 & 0x20) != 0)) {
      uStack_1c = 0x20;
    }
    if ((((param_2 & 2) != 0) || ((param_2 & 4) != 0)) || ((param_2 & 8) != 0)) {
      uStack_1c = 8;
    }
  }
  if (((param_1 & 8) != 0) && (((param_2 & 2) != 0 || ((param_2 & 4) != 0)))) {
    uStack_1c = 8;
  }
  if (((param_1 & 0x10) != 0) && (((param_2 & 2) != 0 || ((param_2 & 4) != 0)))) {
    uStack_1c = 0x10;
  }
  return uStack_1c;
}

