FUNCTION FUN_005c76e0 @ 0x005c76e0  size=168
CALLERS (1): FUN_005c7540@0x005c7540
CALLEES (1): FUN_005bdfe0@0x005bdfe0
----------------------------------------------------------------

void FUN_005c76e0(int param_1)

{
  if (*(char *)(param_1 + 0x25) != '\0') {
    if (*(char *)(param_1 + 0x25) == '\x01') {
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
      if (*(uint *)(param_1 + 0xc) < 4) {
        *(undefined1 *)(param_1 + 0x21) = 1;
      }
      else {
        *(undefined1 *)(param_1 + 0x25) = 0;
        *(undefined1 *)(param_1 + 0x24) = 0;
        *(undefined1 *)(param_1 + 0x20) = 0;
        uRam006cbc7e = 0x10;
        uRam006d2158 = 1;
        uRam006cbc84 = 0;
        uRam006cf286 = uRam006ff2a6;
        FUN_005bdfe0(0x14);
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x25) = 0;
      *(undefined1 *)(param_1 + 0x24) = 0;
      *(undefined1 *)(param_1 + 0x20) = 0;
    }
  }
  return;
}



================================================================