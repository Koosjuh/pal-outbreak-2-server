FUNCTION FUN_005fc000 @ 0x005fc000  size=192
CALLERS (0): 
CALLEES (1): FUN_00618c20@0x00618c20
----------------------------------------------------------------

void FUN_005fc000(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 4);
  if (cVar1 == '\x02') {
    FUN_00618c20();
  }
  else {
    if (cVar1 != '\x01') {
      if (cVar1 != '\0') {
        return;
      }
      *(undefined1 *)(param_1 + 4) = 1;
      *(undefined2 *)(param_1 + 0x26) = *(undefined2 *)(&DAT_00649890 + *(char *)(param_1 + 3) * 4);
      *(undefined2 *)(param_1 + 0x28) = *(undefined2 *)(&DAT_00649892 + *(char *)(param_1 + 3) * 4);
    }
    if (*(char *)(((int)cRam006c4fd8 + (int)*(char *)(param_1 + 3)) * 0x15c + 0x6c076f) == '\0') {
      *(undefined1 *)(param_1 + 1) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 1) = 1;
    }
  }
  return;
}



================================================================