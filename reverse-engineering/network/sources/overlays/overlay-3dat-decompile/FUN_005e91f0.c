FUNCTION FUN_005e91f0 @ 0x005e91f0  size=116
CALLERS (0): 
CALLEES (1): FUN_005ee470@0x005ee470
----------------------------------------------------------------

undefined8 FUN_005e91f0(void)

{
  long lVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar2 = iRam007012a0 + iVar3;
    iVar3 = iVar3 + 1;
    *(undefined *)(iVar2 + 0x1528) = (&DAT_00648370)[*(byte *)(iVar2 + 0x1528)];
  } while (iVar3 < 0x10);
  lVar1 = func_0x00109d70(iRam007012a0 + 0x1528,0x648510);
  if (lVar1 == 0) {
    FUN_005ee470();
  }
  return 0;
}



================================================================