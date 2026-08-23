FUNCTION FUN_0000e304 @ 0x0000e304 size=196
CALLERS (0): 
CALLEES (3): FUN_00010c38@0x00010c38, FUN_0000dc38@0x0000dc38, FUN_000095dc@0x000095dc

void FUN_0000e304(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if (*(char *)(param_1 + 3) == '\0') {
    if ((DAT_00012efc & 2) != 0) {
      FUN_00010c38("  PAP: timeout\n");
    }
    *(char **)(iVar1 + 8) = "Request retry exceeded";
    FUN_0000dc38(param_1);
    *(undefined2 *)(param_1 + 8) = 1;
  }
  else {
    if ((DAT_00012efc & 2) != 0) {
      FUN_00010c38("  PAP: rexmt(retry %d)\n",*(undefined1 *)(param_1 + 3));
    }
    *(char **)(iVar1 + 8) = "Request timeout";
    FUN_000095dc(param_1);
  }
  return;
}


================================================================