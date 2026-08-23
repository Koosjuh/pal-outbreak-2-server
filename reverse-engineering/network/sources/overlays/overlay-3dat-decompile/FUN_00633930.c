FUNCTION FUN_00633930 @ 0x00633930  size=384
CALLERS (4): FUN_00630f20@0x00630f20, FUN_00631d60@0x00631d60, FUN_00635030@0x00635030, FUN_00631c80@0x00631c80
CALLEES (2): FUN_006336d0@0x006336d0, FUN_00637e60@0x00637e60
----------------------------------------------------------------

void FUN_00633930(void)

{
  if ((*(char *)(iRam00715da8 + 0x2f) == '\x01') && (*(char *)(iRam00715da8 + 0x36) != '\0')) {
    *(int *)(iRam00715da8 + 0x24c) = *(int *)(iRam00715da8 + 0x24c) + -1;
    if (*(int *)(iRam00715da8 + 0x24c) < 0) {
      *(int *)(iRam00715da8 + 0x24c) = *(int *)(iRam00715da8 + 600) + -1;
      *(int *)(iRam00715da8 + 0x250) = (*(int *)(iRam00715da8 + 600) + -1) / 3;
      FUN_006336d0(*(int *)(iRam00715da8 + 0x250) * 3);
    }
    else if (*(int *)(iRam00715da8 + 0x24c) < *(int *)(iRam00715da8 + 0x250) * 3) {
      *(int *)(iRam00715da8 + 0x250) = *(int *)(iRam00715da8 + 0x250) + -1;
      FUN_006336d0(*(int *)(iRam00715da8 + 0x250) * 3);
    }
    func_0x00106b60(iRam00715da8 + 0x47c,0,0x10);
    FUN_00637e60(iRam00715da8 + 0x47c,(*(int *)(iRam00715da8 + 0x24c) % 3) * 0x12 + 0x7158f2);
    *(uint *)(iRam00715da8 + 0x254) =
         (uint)*(byte *)((*(int *)(iRam00715da8 + 0x24c) % 3) * 0x12 + 0x7158f0);
  }
  return;
}



================================================================