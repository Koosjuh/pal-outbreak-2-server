
long FUN_001c8dd0(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if (cRam0035ccb4 == '\x01') {
    *(undefined4 *)(iVar2 + 0xdc) = 0xffffffff;
    *(undefined1 *)(iVar2 + 0xc) = 7;
    lVar1 = 0;
    *(undefined1 *)(iVar2 + 0xd) = 0;
    *(undefined1 *)(iVar2 + 0xe) = 0;
    *(undefined1 *)(iVar2 + 0xf) = 0;
    *(undefined2 *)(iVar2 + 0x10) = 0;
    *(undefined2 *)(iVar2 + 0x12) = 0;
    *(undefined2 *)(iVar2 + 0x14) = 0;
    *(undefined2 *)(iVar2 + 0x16) = 0;
  }
  else {
    FUN_001c3c90(param_1,5,1,0);
    **(ushort **)(iVar2 + 0x28) = *(ushort *)(iVar2 + 0x38) << 8 | *(ushort *)(iVar2 + 0x38) >> 8;
    FUN_001ee590(*(undefined4 *)(iVar2 + 0x1c),*(undefined4 *)(iVar2 + 0x28),
                 (short)*(undefined4 *)(iVar2 + 0x38) + 8);
    lVar1 = FUN_001c3840(param_1);
    if (-2 < lVar1) {
      lVar1 = 0;
    }
  }
  return lVar1;
}

