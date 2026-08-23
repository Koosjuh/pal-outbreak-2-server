FUNCTION FUN_00000620 @ 0x00000620 size=68
CALLERS (1): FUN_0000fc50@0x0000fc50
CALLEES (2): FUN_0001037c@0x0001037c, FUN_00004fe0@0x00004fe0

bool FUN_00000620(void)

{
  bool bVar1;
  short sVar2;
  
  sVar2 = FUN_0001037c();
  if (sVar2 == 0) {
    sVar2 = FUN_00004fe0(0);
    bVar1 = sVar2 != 0;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}


================================================================