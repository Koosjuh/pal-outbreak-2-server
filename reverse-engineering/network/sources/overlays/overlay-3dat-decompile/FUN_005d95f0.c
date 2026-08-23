FUNCTION FUN_005d95f0 @ 0x005d95f0  size=168
CALLERS (1): FUN_005ef3f0@0x005ef3f0
CALLEES (2): FUN_005da730@0x005da730, FUN_005cab10@0x005cab10
----------------------------------------------------------------

void FUN_005d95f0(char *param_1)

{
  long lVar1;
  
  lVar1 = FUN_005da730();
  if (lVar1 == 0) {
    if (*param_1 == '\0') {
      *(undefined1 *)(iRam00701068 + 0x68e7e) = 3;
    }
    else {
      *(undefined1 *)(iRam00701068 + 0x68e7e) = 1;
      FUN_005cab10(0xd,1,0,0,0,0,0xffffffffff000001,0x10);
    }
  }
  return;
}



================================================================