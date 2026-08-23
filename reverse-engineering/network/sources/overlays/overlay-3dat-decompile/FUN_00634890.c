FUNCTION FUN_00634890 @ 0x00634890  size=216
CALLERS (1): FUN_006345e0@0x006345e0
CALLEES (3): FUN_00637540@0x00637540, FUN_00637690@0x00637690, FUN_006322c0@0x006322c0
----------------------------------------------------------------

void FUN_00634890(byte param_1)

{
  int iVar1;
  
  *(byte *)(iRam00715da8 + 0x1d) = param_1;
  *(undefined4 *)(iRam00715da8 + 0x20) = *(undefined4 *)(&DAT_00690d30 + (uint)param_1 * 4);
  if (*(int *)(*(int *)(iRam00715da8 + 0x10) + 0x28) == 0) {
    *(uint *)(iRam00715da8 + 0x20) = *(uint *)(iRam00715da8 + 0x20) | 0x20;
  }
  if (*(int *)(*(int *)(iRam00715da8 + 0x10) + 0x20) == 0) {
    *(uint *)(iRam00715da8 + 0x20) = *(uint *)(iRam00715da8 + 0x20) | 0x10;
  }
  iVar1 = (uint)param_1 * 2;
  *(undefined *)(iRam00715da8 + 0x1e) = (&DAT_00690d10)[iVar1];
  *(undefined *)(iRam00715da8 + 0x33) = (&DAT_00690d11)[iVar1];
  FUN_00637540();
  FUN_00637690();
  FUN_006322c0();
  return;
}



================================================================