FUNCTION FUN_006341d0 @ 0x006341d0  size=168
CALLERS (6): FUN_00631ec0@0x00631ec0, FUN_00631f80@0x00631f80, FUN_00632390@0x00632390, FUN_00631810@0x00631810, FUN_00635cb0@0x00635cb0, FUN_006320f0@0x006320f0
CALLEES (2): FUN_00637d10@0x00637d10, FUN_00637e90@0x00637e90
----------------------------------------------------------------

short FUN_006341d0(short *param_1,ushort param_2)

{
  short sVar1;
  short sVar2;
  long lVar3;
  ushort uVar4;
  undefined1 auStack_4 [4];
  
  uVar4 = 0;
  sVar2 = 0;
  lVar3 = FUN_00637e90();
  if (lVar3 == 0) {
    sVar2 = 0;
  }
  else {
    for (; (*param_1 != 0 && (uVar4 < param_2)); uVar4 = uVar4 + sVar1) {
      FUN_00637d10(*param_1,auStack_4);
      sVar1 = func_0x001af420(auStack_4);
      param_1 = param_1 + 1;
      sVar2 = sVar2 + 1;
    }
  }
  return sVar2;
}



================================================================