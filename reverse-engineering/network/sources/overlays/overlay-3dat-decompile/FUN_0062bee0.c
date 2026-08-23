FUNCTION FUN_0062bee0 @ 0x0062bee0  size=324
CALLERS (1): FUN_0062bda0@0x0062bda0
CALLEES (3): FUN_005c3ef0@0x005c3ef0, FUN_005b9110@0x005b9110, FUN_005b68e0@0x005b68e0
----------------------------------------------------------------

void FUN_0062bee0(int param_1,undefined1 *param_2)

{
  uint uVar1;
  
  if (param_2[2] == '\x01') {
    if (*(char *)(param_1 + 0x10b4) != '\0') {
      param_2[2] = 0;
      *(undefined2 *)(param_2 + 4) = 6;
      FUN_005b9110(0x4c);
      if (*(char *)(param_1 + 0x10b4) == '\x01') {
        param_2[1] = 3;
        param_2[*(int *)(param_1 + 0x1460) + 0x10] = 0xff;
      }
      else {
        param_2[1] = 2;
        param_2[*(int *)(param_1 + 0x1460) + 0x10] = 1;
      }
    }
  }
  else if (param_2[2] == '\0') {
    *(undefined1 *)(param_1 + 0x10b4) = 0;
    while (uVar1 = *(uint *)(param_1 + 0x1460), uVar1 < 3) {
      if (*(char *)(param_1 + uVar1 * 0x25 + 0x1055) != '\0') {
        param_2[2] = 1;
        FUN_005b68e0();
        *(undefined1 *)(param_1 + 0x42b) = 0x1e;
        FUN_005c3ef0(param_1 + *(int *)(param_1 + 0x1460) * 0x25 + 0x1055,0x62cc60);
        return;
      }
      *(uint *)(param_1 + 0x1460) = uVar1 + 1;
    }
    *param_2 = 1;
    param_2[1] = 0;
    param_2[2] = 0;
    func_0x001b0140(4);
  }
  return;
}



================================================================