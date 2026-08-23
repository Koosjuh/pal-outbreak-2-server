FUNCTION FUN_00002720 @ 0x00002720 size=56
CALLERS (1): FUN_00002758@0x00002758
CALLEES (1): FUN_00002bc0@0x00002bc0

uint FUN_00002720(void)

{
  undefined1 auStack_10 [4];
  uint local_c;
  
  local_c = 0xffffffff;
  FUN_00002bc0(auStack_10,1,&local_c);
  return ~local_c >> 0x1f;
}


================================================================