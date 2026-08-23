FUNCTION FUN_005dc2b0 @ 0x005dc2b0  size=232
CALLERS (1): FUN_005dc4b0@0x005dc4b0
CALLEES (4): FUN_00637180@0x00637180, FUN_00636890@0x00636890, FUN_00634ab0@0x00634ab0, FUN_006371d0@0x006371d0
----------------------------------------------------------------

int FUN_005dc2b0(void)

{
  char cVar1;
  int iVar2;
  
  func_0x001af060(0x16,0x16);
  cVar1 = FUN_00634ab0(iRam00701068 + 0x68e89,uRam003434a8,uRam003434a0);
  if (cVar1 == '\0') {
    FUN_006371d0(0x42840000,300);
    FUN_00636890(0);
    iVar2 = 0;
  }
  else if (cVar1 == -1) {
    FUN_00637180();
    *(undefined1 *)(iRam00701068 + 0x68e89) = 0xff;
    iVar2 = iRam00701068 + 0x68e89;
  }
  else if (cVar1 == '\x01') {
    FUN_00637180();
    iVar2 = iRam00701068 + 0x68e89;
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



================================================================