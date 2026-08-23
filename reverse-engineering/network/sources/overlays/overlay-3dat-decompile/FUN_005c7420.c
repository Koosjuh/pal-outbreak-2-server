FUNCTION FUN_005c7420 @ 0x005c7420  size=284
CALLERS (1): FUN_005c72d0@0x005c72d0
CALLEES (2): FUN_005bf1e0@0x005bf1e0, FUN_005bdfe0@0x005bdfe0
----------------------------------------------------------------

void FUN_005c7420(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(char *)(param_1 + 0x25) == '\x01') {
    *(undefined1 *)(param_1 + 0x25) = 0;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    if (*(uint *)(param_1 + 0xc) < 4) {
      *(undefined1 *)(param_1 + 0x21) = 0;
    }
    else {
      *(char *)(param_1 + 0x20) = *(char *)(param_1 + 0x20) + '\x01';
      *(undefined1 *)(param_1 + 0x21) = 0;
      uVar1 = FUN_005bf1e0(0);
      iVar4 = (uVar1 & 0xffff) - 1;
      iVar3 = 0;
      *(undefined2 *)(iVar4 * 0x144 + 0x6ce5e0) = uRam006ff2a4;
      do {
        iVar2 = iVar3 * 4;
        iVar3 = iVar3 + 1;
        *(undefined4 *)(iVar2 + 0x7006b0) = *(undefined4 *)(iVar2 + 0x7006c0);
      } while (iVar3 < 4);
      sRam006d2158 = (short)iVar4 + 1;
      uRam006cbc84 = 0;
      uRam006cbc7e = 0x10;
      FUN_005bdfe0(0xf);
    }
  }
  else if (*(char *)(param_1 + 0x25) == '\x02') {
    *(undefined1 *)(param_1 + 0x25) = 0;
    *(char *)(param_1 + 0x20) = *(char *)(param_1 + 0x20) + '\x01';
    *(undefined1 *)(param_1 + 0x21) = 0;
  }
  return;
}



================================================================