FUNCTION FUN_00000fa0 @ 0x00000fa0 size=120
CALLERS (11): FUN_0000af84@0x0000af84, FUN_00002d9c@0x00002d9c, FUN_00002cb4@0x00002cb4, FUN_00002f1c@0x00002f1c, FUN_000110d0@0x000110d0, FUN_00005828@0x00005828, FUN_00010e10@0x00010e10, FUN_00001ab0@0x00001ab0, FUN_000060c0@0x000060c0, FUN_0000b3d4@0x0000b3d4, FUN_00010f40@0x00010f40
CALLEES (0): 

undefined * FUN_00000fa0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    iVar1 = (iVar1 >> 0x10) * 0x9c;
    iVar2 = iVar2 + 1;
    if ((&DAT_00016268)[iVar1] == '\0') {
      (&DAT_00016268)[iVar1] = 1;
      return &DAT_000161d0 + iVar1;
    }
    iVar1 = iVar2 * 0x10000;
  } while (iVar2 * 0x10000 >> 0x10 < 5);
  return (undefined *)0x0;
}


================================================================