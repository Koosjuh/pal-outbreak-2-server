FUNCTION FUN_00631ac0 @ 0x00631ac0  size=232
CALLERS (2): FUN_00635030@0x00635030, FUN_006300a0@0x006300a0
CALLEES (5): FUN_00631910@0x00631910, FUN_00631a30@0x00631a30, FUN_00630c70@0x00630c70, FUN_00634010@0x00634010, FUN_00634160@0x00634160
----------------------------------------------------------------

void FUN_00631ac0(void)

{
  ushort uVar1;
  short sVar2;
  long lVar3;
  undefined2 extraout_a0_lo;
  
  lVar3 = FUN_00631a30();
  if (lVar3 == 1) {
    FUN_00631910();
    *(byte *)(iRam00715da8 + 0x4a) = *(byte *)(iRam00715da8 + 0x4a) & 0xfe;
  }
  else if ((*(char *)(iRam00715da8 + 0x2f) == '\0') && (*(short *)(iRam00715da8 + 0x260) == 0)) {
    uVar1 = FUN_00634160(iRam00715da8 + 0x4c);
    if (*(ushort *)(iRam00715da8 + 0x2a) < uVar1) {
      lVar3 = FUN_00630c70();
      if (lVar3 == 0) {
        sVar2 = FUN_00634010(iRam00715da8 + 0x4c,*(undefined2 *)(iRam00715da8 + 0x2a));
        *(short *)(iRam00715da8 + 0x2a) = *(short *)(iRam00715da8 + 0x2a) + sVar2;
      }
      else {
        *(undefined2 *)(iRam00715da8 + 0x2a) = extraout_a0_lo;
      }
      *(undefined1 *)(iRam00715da8 + 0x28) = 0;
      *(undefined4 *)(iRam00715da8 + 0x248) = 0;
    }
  }
  return;
}



================================================================