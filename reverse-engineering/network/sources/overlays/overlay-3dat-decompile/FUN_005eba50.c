FUNCTION FUN_005eba50 @ 0x005eba50  size=152
CALLERS (0): 
CALLEES (2): FUN_005ec1b0@0x005ec1b0, FUN_005ec6d0@0x005ec6d0
----------------------------------------------------------------

undefined8 FUN_005eba50(undefined8 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined1 auStack_110 [272];
  
  FUN_005ec1b0(param_1,auStack_110,0x100);
  if (*(char *)(iRam007012a0 + 0x186) == -10) {
    iVar1 = *(int *)(((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
                     (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4 + iRam007012a0 + 0x24e0);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = *(undefined2 *)(iVar1 + 0x1c);
    }
    uVar2 = FUN_005ec6d0(auStack_110,uVar2);
    *(undefined2 *)(iRam007012a0 + 0xf10) = uVar2;
  }
  return 0;
}



================================================================