FUNCTION FUN_005dc010 @ 0x005dc010  size=460
CALLERS (0): 
CALLEES (6): FUN_005e2060@0x005e2060, FUN_005dfee0@0x005dfee0, FUN_005ddc20@0x005ddc20, FUN_005de330@0x005de330, FUN_005e1da0@0x005e1da0, FUN_005e1670@0x005e1670
----------------------------------------------------------------

void FUN_005dc010(int param_1)

{
  char cVar1;
  undefined8 uVar2;
  uint uVar3;
  float fVar4;
  
  cVar1 = *(char *)(param_1 + 6);
  if (cVar1 == 'c') {
    FUN_005dfee0();
    *(char *)(iRam00701068 + 0x60dc4) = *(char *)(iRam00701068 + 0x60dc4) + '\x01';
  }
  else if (((cVar1 != '\x01') && (cVar1 != '\0')) ||
          (FUN_005e2060(), *(char *)(param_1 + 6) != '\0')) {
    *(undefined4 *)(param_1 + 0x40) = 0x43520000;
    *(undefined4 *)(param_1 + 0x44) = 0x42dc0000;
    FUN_005e1670(*(float *)(param_1 + 0x34),*(float *)(param_1 + 0x38) - 20.0,
                 *(float *)(param_1 + 0x34) + *(float *)(param_1 + 0x40),
                 *(float *)(param_1 + 0x38) + *(float *)(param_1 + 0x44));
    uVar3 = 0;
    do {
      fVar4 = *(float *)(param_1 + 0x38);
      uVar2 = FUN_005de330(3);
      FUN_005ddc20(*(float *)(param_1 + 0x34) + 20.0,fVar4 + 20.0 + (float)(uVar3 * 0x14),0,
                   0xffffffffffffffff,0,0x14,uVar2);
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 3);
    func_0x001af030();
    fVar4 = *(float *)(param_1 + 0x38) + (float)((uint)*(byte *)(iRam00701078 + 2) * 0x14);
    FUN_005e1da0((*(float *)(param_1 + 0x34) + 20.0) - 2.0,fVar4 - 2.0,
                 *(float *)(param_1 + 0x34) + 190.0 + 2.0,fVar4 + 20.0 + 2.0,0xffffffffffffffff);
  }
  return;
}



================================================================