FUNCTION FUN_000091c8 @ 0x000091c8 size=188
CALLERS (7): FUN_000020f4@0x000020f4, FUN_00007974@0x00007974, FUN_000018b0@0x000018b0, FUN_00001198@0x00001198, FUN_00000da8@0x00000da8, FUN_000027e4@0x000027e4, FUN_00000fe4@0x00000fe4
CALLEES (4): FUN_00008cc8@0x00008cc8, FUN_000094b8@0x000094b8, FUN_00008c68@0x00008c68, FUN_0000968c@0x0000968c

undefined4 FUN_000091c8(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((DAT_0000c21c == FUN_00000000) || (iVar1 = FUN_00008c68(param_1,1), iVar1 == -1)) {
    uVar2 = FUN_0000968c(param_1);
  }
  else {
    uVar2 = (*DAT_0000c21c)(param_1);
    FUN_000094b8(*(undefined4 *)(&DAT_0000c334 + iVar1 * 0x124));
    *(undefined4 *)(&DAT_0000c334 + iVar1 * 0x124) = 0;
    FUN_00008cc8(param_1,1);
  }
  return uVar2;
}


================================================================