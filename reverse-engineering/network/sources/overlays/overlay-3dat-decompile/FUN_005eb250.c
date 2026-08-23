FUNCTION FUN_005eb250 @ 0x005eb250  size=168
CALLERS (4): FUN_005eb1d0@0x005eb1d0, FUN_005f0e10@0x005f0e10, FUN_005f10a0@0x005f10a0, FUN_005eb0f0@0x005eb0f0
CALLEES (2): FUN_005effc0@0x005effc0, FUN_005f0070@0x005f0070
----------------------------------------------------------------

undefined4 FUN_005eb250(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = iRam007012a0 +
          ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
          (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
  iVar1 = *(int *)(iVar2 + 0x24e0);
  if (iVar1 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    *(undefined1 *)(iRam007012a0 + 0x18d) = 0;
    *(undefined1 *)(iVar2 + 0x252c) = 0;
    if (*(char *)(iRam007012a0 + 0x186) == -10) {
      *(undefined4 *)(iVar2 + 0x24f4) = *param_1;
    }
    FUN_005effc0(iVar2 + 0x24e0,iVar1);
    FUN_005f0070(iVar2 + 0x24e0,iVar1);
    uVar3 = 0;
  }
  return uVar3;
}



================================================================