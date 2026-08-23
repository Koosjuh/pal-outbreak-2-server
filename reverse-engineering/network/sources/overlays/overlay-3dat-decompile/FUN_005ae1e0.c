FUNCTION FUN_005ae1e0 @ 0x005ae1e0  size=40
CALLERS (1): FUN_005ae130@0x005ae130
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_005ae1e0(int param_1)

{
  *(char *)(param_1 + 0x993) = *(char *)(param_1 + 0x993) + '\x01';
  *(undefined1 *)(param_1 + 0x45a) = 0;
  uRam00701e10 = 0;
  *(undefined1 *)(param_1 + 0x44d) = 1;
  return 0;
}



================================================================