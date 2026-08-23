FUNCTION FUN_00006e04 @ 0x00006e04 size=200
CALLERS (0): 
CALLEES (2): FUN_000066dc@0x000066dc, FUN_00010c38@0x00010c38

void FUN_00006e04(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if (*(char *)(param_1 + 3) == '\0') {
    if ((DAT_00012efc & 2) != 0) {
      FUN_00010c38("  CHAP: timeout\n");
    }
    *(char **)(iVar1 + 8) = "Request retry exceeded";
    FUN_000066dc(param_1);
    *(undefined2 *)(param_1 + 8) = 1;
  }
  else {
    if ((DAT_00012efc & 2) != 0) {
      FUN_00010c38("  CHAP: rexmt(retry %d)\n",*(undefined1 *)(param_1 + 3));
    }
    *(char **)(iVar1 + 8) = "Request timeout";
    *(char *)(param_1 + 3) = *(char *)(param_1 + 3) + -1;
  }
  return;
}


================================================================