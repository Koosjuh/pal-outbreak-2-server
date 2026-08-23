FUNCTION FUN_00631880 @ 0x00631880  size=144
CALLERS (1): FUN_006300a0@0x006300a0
CALLEES (2): FUN_00637e90@0x00637e90, FUN_00634160@0x00634160
----------------------------------------------------------------

void FUN_00631880(void)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  undefined2 uVar4;
  
  iVar2 = iRam00715da8;
  if (((*(char *)(iRam00715da8 + 0x2f) == '\0') && (*(short *)(iRam00715da8 + 0x260) == 0)) &&
     (uVar1 = *(ushort *)(iRam00715da8 + 0x2a), uVar3 = FUN_00637e90(iRam00715da8 + 0x4c),
     uVar1 < uVar3)) {
    uVar4 = FUN_00634160(iVar2 + 0x4c);
    *(undefined2 *)(iRam00715da8 + 0x2a) = uVar4;
  }
  *(undefined1 *)(iRam00715da8 + 0x28) = 0;
  *(undefined4 *)(iRam00715da8 + 0x248) = 1;
  return;
}



================================================================