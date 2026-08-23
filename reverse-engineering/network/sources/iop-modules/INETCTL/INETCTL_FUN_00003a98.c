FUNCTION FUN_00003a98 @ 0x00003a98 size=56
CALLERS (1): FUN_00003ad0@0x00003ad0
CALLEES (1): FUN_00003efc@0x00003efc

uint FUN_00003a98(void)

{
  undefined1 auStack_10 [4];
  uint local_c;
  
  local_c = 0xffffffff;
  FUN_00003efc(auStack_10,1,&local_c);
  return ~local_c >> 0x1f;
}


================================================================