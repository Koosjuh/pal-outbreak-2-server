FUNCTION FUN_00614c80 @ 0x00614c80  size=468
CALLERS (3): FUN_00613b10@0x00613b10, FUN_00612120@0x00612120, FUN_00612ae0@0x00612ae0
CALLEES (1): FUN_00614e60@0x00614e60
----------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00614d50) */

void FUN_00614c80(int param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  byte bVar2;
  float fVar3;
  
  param_1 = param_1 * 4;
  FUN_00614e60((uint)(byte)(&DAT_0064c2b0)[param_1] * 0xc + 0x64b9b0,(&DAT_0064c2b1)[param_1],
               param_2,param_3,0xffffffffffffffff);
  cVar1 = (&DAT_0064c2b3)[param_1];
  if (cVar1 != '\0') {
    func_0x001a7b70(0x5e,0x12);
    bVar2 = (&DAT_0064c2b2)[param_1];
    fVar3 = (float)func_0x001886c0(((DAT_00693928 * (float)*(byte *)(iRam0070d1c0 + 0x29)) / 2.0) /
                                   16.0);
    fVar3 = fVar3 * 127.0 + 128.0;
    if (2.1474836e+09 <= fVar3) {
      fVar3 = fVar3 - 2.1474836e+09;
    }
    FUN_00614e60((uint)bVar2 * 0xc + 0x64b9b0,cVar1,param_2,param_3,(int)fVar3 << 0x18 | 0xffffff);
    func_0x001a7b70(0x5e,0x32);
  }
  return;
}



================================================================