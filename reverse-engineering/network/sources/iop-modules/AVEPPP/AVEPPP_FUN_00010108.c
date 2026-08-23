FUNCTION FUN_00010108 @ 0x00010108 size=200
CALLERS (5): FUN_0000d8c0@0x0000d8c0, FUN_00005e78@0x00005e78, FUN_0000c028@0x0000c028, FUN_0000d9a8@0x0000d9a8, FUN_000073fc@0x000073fc
CALLEES (5): FUN_0001073c@0x0001073c, FUN_000041a0@0x000041a0, FUN_00010070@0x00010070, FUN_000103cc@0x000103cc, FUN_00010764@0x00010764

void FUN_00010108(void)

{
  int iVar1;
  int *piVar2;
  
  FUN_0001073c();
  FUN_000041a0();
  iVar1 = FUN_000103cc();
  for (piVar2 = (int *)DAT_00014968; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
    if ((*(char *)(piVar2 + 6) == '\x01') && ((uint)piVar2[2] < (uint)(iVar1 - piVar2[3]))) {
      FUN_00010070(piVar2);
      *(undefined1 *)(piVar2 + 6) = 2;
      if ((code *)piVar2[4] != (code *)0x0) {
        *(undefined1 *)(piVar2 + 6) = 0;
        (*(code *)piVar2[4])(piVar2[5]);
      }
    }
  }
  FUN_00010764();
  return;
}


================================================================