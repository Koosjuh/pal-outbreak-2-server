FUNCTION FUN_005aec20 @ 0x005aec20  size=72
CALLERS (16): FUN_005ff8d0@0x005ff8d0, FUN_00616bd0@0x00616bd0, FUN_006179e0@0x006179e0, FUN_005f7610@0x005f7610, FUN_0062d4e0@0x0062d4e0, FUN_005f7690@0x005f7690, FUN_0062d560@0x0062d560, FUN_00617a00@0x00617a00, FUN_005fe500@0x005fe500, FUN_0062e800@0x0062e800, FUN_005f8b50@0x005f8b50, FUN_0062e8e0@0x0062e8e0, ...
CALLEES (2): FUN_005be060@0x005be060, FUN_005be080@0x005be080
----------------------------------------------------------------

void FUN_005aec20(int param_1)

{
  func_0x00106b60(param_1 + 0x45b,0,3);
  *(undefined1 *)(param_1 + 0x455) = 0;
  *(undefined1 *)(param_1 + 0x991) = 0;
  *(undefined1 *)(param_1 + 0x42b) = 0;
  FUN_005be060();
  FUN_005be080();
  return;
}



================================================================