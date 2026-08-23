FUNCTION FUN_005b1d20 @ 0x005b1d20  size=268
CALLERS (1): FUN_005acab0@0x005acab0
CALLEES (4): FUN_005b14b0@0x005b14b0, FUN_00637170@0x00637170, FUN_00618ba0@0x00618ba0, FUN_005b1e30@0x005b1e30
----------------------------------------------------------------

void FUN_005b1d20(int param_1)

{
  char *pcVar1;
  undefined1 *puVar2;
  long lVar3;
  
  pcVar1 = (char *)FUN_005b1e30();
  if (((((*(char *)(param_1 + 0x45a) != '\0') && (*(char *)(param_1 + 0x992) != '\0')) &&
       (lVar3 = FUN_00637170(), lVar3 == 0)) &&
      ((*(char *)(param_1 + 0x434) == '\0' && (lVar3 = FUN_005b14b0(0x8000), lVar3 != 0)))) &&
     ((*(char *)(param_1 + 0x42c) == '\0' &&
      ((*pcVar1 != '\0' && (lVar3 = FUN_00618ba0(), puVar2 = (undefined1 *)lVar3, lVar3 != 0)))))) {
    *puVar2 = 1;
    puVar2[1] = 1;
    *(undefined2 *)(puVar2 + 0x22) = 3;
    *(code **)(puVar2 + 0xc) = FUN_005b1b10;
    *(int *)(puVar2 + 0x10) = param_1;
    puVar2[2] = 0;
    *(undefined4 *)(puVar2 + 0x34) = 0xffffffe6;
    lVar3 = FUN_00618ba0();
    puVar2 = (undefined1 *)lVar3;
    if (lVar3 != 0) {
      *puVar2 = 1;
      puVar2[1] = 0;
      *(undefined2 *)(puVar2 + 0x22) = 4;
      *(code **)(puVar2 + 0xc) = FUN_005b1b10;
      *(int *)(puVar2 + 0x10) = param_1;
      puVar2[2] = 1;
      *(undefined4 *)(puVar2 + 0x34) = 0xffffffe6;
      *(undefined1 *)(param_1 + 0x42c) = 1;
      *(undefined1 *)(param_1 + 0x438) = 0;
      *(undefined1 *)(param_1 + 0x430) = 0;
      *(undefined1 *)(param_1 + 0x42f) = 0;
    }
  }
  return;
}



================================================================