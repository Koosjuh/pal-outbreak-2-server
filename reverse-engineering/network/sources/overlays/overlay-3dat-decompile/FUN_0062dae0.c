FUNCTION FUN_0062dae0 @ 0x0062dae0  size=340
CALLERS (1): FUN_0062d950@0x0062d950
CALLEES (0): 
----------------------------------------------------------------

void FUN_0062dae0(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined1 *)(param_1 + 0x45a) = 1;
  iVar2 = 0;
LAB_0062db94:
  do {
    iVar1 = iVar2 * 0x15c;
    if ((int)(uint)uRam006c4602 <= iVar2) {
      iVar2 = 0;
      while( true ) {
        if ((int)(uint)uRam006c4602 <= iVar2) {
          iVar2 = *(int *)(param_1 + 0x9a0) + -1;
          *(int *)(param_1 + 0x9a0) = iVar2;
          if (iVar2 < 0) {
            *(undefined1 *)(param_1 + 0xf) = 4;
            *(undefined1 *)(param_1 + 0x10) = 0;
            *(undefined1 *)(param_1 + 0x11) = 0;
            *(undefined1 *)(param_1 + 0x45a) = 0;
          }
          return;
        }
        if (*(char *)(iVar2 * 0x15c + 0x6c076e) == '\x01') break;
        iVar2 = iVar2 + 1;
      }
      uRam006c4600 = (undefined1)*(undefined2 *)(iVar2 * 0x15c + 0x6c0760);
      *(undefined1 *)(param_1 + 0xf) = 3;
      *(undefined1 *)(param_1 + 0x10) = 0;
      *(undefined1 *)(param_1 + 0x45a) = 0;
      func_0x001b0140(0xb);
      return;
    }
    if ((*(char *)(iVar1 + 0x6c076e) == '\x03') && (*(char *)(param_1 + iVar2 + 0x9ac) == '\0')) {
      if ((*(uint *)(iVar1 + 0x6c0774) & 0x20000) != 0) {
        if (cRam00343571 == '\x02') {
LAB_0062db70:
          uRam006c4600 = (undefined1)*(undefined2 *)(iVar1 + 0x6c0760);
          *(undefined1 *)(param_1 + 0xf) = 2;
          *(undefined1 *)(param_1 + 0x10) = 0;
          *(undefined1 *)(param_1 + 0x45a) = 0;
          return;
        }
        iVar2 = iVar2 + 1;
        goto LAB_0062db94;
      }
      if (((*(uint *)(iVar1 + 0x6c0774) & 0x10000) == 0) || (cRam00343571 != '\x02'))
      goto LAB_0062db70;
    }
    iVar2 = iVar2 + 1;
  } while( true );
}



================================================================