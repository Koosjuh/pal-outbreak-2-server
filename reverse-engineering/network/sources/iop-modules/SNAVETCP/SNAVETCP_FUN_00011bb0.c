FUNCTION FUN_00011bb0 @ 0x00011bb0 size=320
CALLERS (1): FUN_00000aa0@0x00000aa0
CALLEES (0): 

undefined4 FUN_00011bb0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar1 = 0;
  iVar3 = 0;
  DAT_00016180 = &DAT_00017f70;
  DAT_000161a0 = &DAT_00017e80;
  DAT_000161a8 = &DAT_00017e20;
  DAT_00016188 = &DAT_00018460;
  DAT_00016184 = &DAT_00018870;
  DAT_0001619b = 3;
  DAT_0001619d = 1;
  DAT_0001619c = 5;
  DAT_000161a4 = 0x1000;
  DAT_0001618e = 0x20;
  DAT_0001617c = 0x32;
  DAT_0001619e = 8;
  DAT_00016198 = 100;
  DAT_0001617e = 4;
  DAT_0001619a = 4;
  DAT_0001618c = 4;
  DAT_00016194 = 0;
  DAT_00016196 = 1;
  do {
    *(undefined4 *)((int)&DAT_00017e50 + iVar3) = 0xffffffff;
    *(undefined4 *)((int)&DAT_00018828 + iVar1) = 0xffffffff;
    (&DAT_00018854)[iVar2 * 2] = 0xffffffff;
    *(undefined4 *)((int)&DAT_00017f48 + iVar1) = 0xffffffff;
    iVar1 = iVar1 + 0xc;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x14;
  } while (iVar2 < 3);
  return 0;
}


================================================================