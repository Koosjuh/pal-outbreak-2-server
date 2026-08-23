FUNCTION FUN_005af120 @ 0x005af120  size=100
CALLERS (6): FUN_005acda0@0x005acda0, FUN_005acea0@0x005acea0, FUN_005f74d0@0x005f74d0, FUN_005f7570@0x005f7570, FUN_0062e440@0x0062e440, FUN_005acd60@0x005acd60
CALLEES (0): 
----------------------------------------------------------------

void FUN_005af120(int param_1,int param_2)

{
  *(undefined2 *)(param_1 + 0x1468) = *(undefined2 *)(param_2 * 2 + param_1 + 0x1464);
  if (cRam0034363e == '\x01') {
    *(short *)(param_1 + 0x1468) =
         (short)(int)(DAT_00692670 * (float)(int)*(short *)(param_1 + 0x1468));
  }
  *(int *)(param_1 + 0x146c) = param_2;
  *(undefined1 *)(param_1 + 0x146a) = 0;
  *(undefined1 *)(param_1 + 0x146b) = 1;
  return;
}



================================================================