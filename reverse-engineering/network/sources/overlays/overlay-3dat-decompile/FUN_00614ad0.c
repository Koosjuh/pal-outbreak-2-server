FUNCTION FUN_00614ad0 @ 0x00614ad0  size=164
CALLERS (1): FUN_00610830@0x00610830
CALLEES (2): FUN_00637180@0x00637180, FUN_00634ab0@0x00634ab0
----------------------------------------------------------------

undefined4 FUN_00614ad0(void)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = FUN_00634ab0(iRam0070d1c0 + 0x58,uRam003433b8,uRam003433b0);
  if (cVar1 == -1) {
    FUN_00637180();
    uVar2 = 1;
  }
  else if (cVar1 == '\x01') {
    FUN_00637180();
    func_0x00109eb8(*(undefined4 *)(iRam0070d1c0 + 0x54),iRam0070d1c0 + 0x58);
    uVar2 = 1;
  }
  else if (cVar1 == '\0') {
    uRam0070d1c8 = 1;
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



================================================================