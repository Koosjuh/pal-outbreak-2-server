
void FUN_001cad10(int param_1)

{
  if (((iRam003688d0 == 0) && (iRam003688d8 == 0)) &&
     (DAT_00248850 + (uint)*(ushort *)(param_1 + 4) < 0x36b900)) {
    FUN_001069a8();
    DAT_00248850 = DAT_00248850 + (uint)*(ushort *)(param_1 + 4);
    iRam003688c8 = iRam003688c8 + (uint)*(ushort *)(param_1 + 4);
  }
  return;
}

