FUNCTION FUN_005c2a40 @ 0x005c2a40  size=40
CALLERS (8): FUN_005c2a70@0x005c2a70, FUN_005c2ae0@0x005c2ae0, FUN_005c2ab0@0x005c2ab0, FUN_005c2a90@0x005c2a90, FUN_005c2b70@0x005c2b70, FUN_005c2b90@0x005c2b90, FUN_005c2b50@0x005c2b50, FUN_005c2b20@0x005c2b20
CALLEES (0): 
----------------------------------------------------------------

int FUN_005c2a40(uint param_1)

{
  return iRam00368474 + (param_1 & 0xffff) * 0x1e4;
}



================================================================