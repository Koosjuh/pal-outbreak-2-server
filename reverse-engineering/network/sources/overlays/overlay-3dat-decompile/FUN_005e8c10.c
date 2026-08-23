FUNCTION FUN_005e8c10 @ 0x005e8c10  size=132
CALLERS (0): 
CALLEES (2): FUN_005ef040@0x005ef040, FUN_005ef780@0x005ef780
----------------------------------------------------------------

undefined8 FUN_005e8c10(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  FUN_005ef040(param_2);
  if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
    *(undefined2 *)(iRam007012a0 + 0x12) = 0x3c;
  }
  else {
    iVar1 = iRam007012a0 +
            ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
            (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
    FUN_005ef780(iVar1 + 0x24e0);
    *(undefined2 *)(iVar1 + 0x251e) = 0x3c;
  }
  return 0;
}



================================================================