FUNCTION FUN_00613530 @ 0x00613530  size=196
CALLERS (1): FUN_00612d10@0x00612d10
CALLEES (2): FUN_006146e0@0x006146e0, FUN_00614720@0x00614720
----------------------------------------------------------------

void FUN_00613530(void)

{
  char cVar1;
  
  cVar1 = '\0';
  do {
    if (((uint)*(byte *)(iRam0070d1c0 + 0x25) & 1 << ((int)cVar1 & 0x1fU)) == 0) {
      FUN_00614720(0xffffffff80404040);
    }
    else {
      FUN_00614720(0xffffffff80808080);
    }
    FUN_006146e0(0xdb,(cVar1 * 8 - (short)cVar1) * 8 + 0xc4,(&PTR_PTR_00653f14)[cVar1]);
    cVar1 = cVar1 + '\x01';
  } while (cVar1 < '\x02');
  FUN_00614720(0xffffffff80808080);
  return;
}



================================================================