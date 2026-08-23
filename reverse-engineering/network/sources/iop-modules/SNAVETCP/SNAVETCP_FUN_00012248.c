FUNCTION FUN_00012248 @ 0x00012248 size=428
CALLERS (1): FUN_00000aa0@0x00000aa0
CALLEES (7): FUN_00011f54@0x00011f54, FUN_00011dcc@0x00011dcc, FUN_00012040@0x00012040, FUN_00011da8@0x00011da8, FUN_000120b0@0x000120b0, FUN_00014e24@0x00014e24, FUN_00013260@0x00013260

void FUN_00012248(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  DAT_000161b0 = 1;
  DAT_000161c0 = 2;
  DAT_000161bc = 3;
  DAT_000161b4 = 3;
  DAT_000161b8 = 2;
  DAT_000161ac = 0;
  DAT_000161ae = 0;
  iVar1 = FUN_00013260();
  uVar3 = *(undefined4 *)(iVar1 + 4);
  if (DAT_00016178 != 0) {
    FUN_00014e24("avetcp: thread priority -> %d\n",uVar3);
  }
  uVar2 = FUN_00011f54(1,0,1,1);
  if (uVar2 == 0) {
    iVar1 = FUN_00011f54(3,0,1,1);
    uVar2 = (uint)(iVar1 != 0);
    if (uVar2 == 0) goto LAB_00012310;
  }
  FUN_00011da8(uVar2);
LAB_00012310:
  iVar1 = FUN_00011f54(2,0,1,1);
  if (iVar1 != 0) {
    FUN_00011da8(iVar1);
  }
  iVar1 = FUN_00011dcc(3,1,0x1800,uVar3,0x2000);
  if ((iVar1 != 0) || (iVar1 = FUN_00012040(3,0), iVar1 != 0)) {
    FUN_00011da8(iVar1);
  }
  iVar1 = FUN_00011dcc(2,1,FUN_00001930,uVar3,0x2000);
  if ((iVar1 != 0) || (iVar1 = FUN_00012040(2,0), iVar1 != 0)) {
    FUN_00011da8(iVar1);
  }
  while (DAT_000161ac < 2) {
    FUN_000120b0(100);
  }
  return;
}


================================================================