FUNCTION FUN_00008bb4 @ 0x00008bb4 size=72
CALLERS (1): FUN_000093e4@0x000093e4
CALLEES (0): 

void FUN_00008bb4(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    *(undefined4 *)((int)&DAT_0000c220 + iVar1) = 0xffffffff;
    *(undefined4 *)((int)&DAT_0000c338 + iVar1) = 0;
    *(undefined4 *)((int)&DAT_0000c340 + iVar1) = 0;
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0x124;
  } while (iVar2 < 4);
  return;
}


================================================================