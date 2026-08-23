FUNCTION FUN_0062f990 @ 0x0062f990  size=236
CALLERS (0): 
CALLEES (3): FUN_00618c20@0x00618c20, FUN_0062fc40@0x0062fc40, FUN_0062fc20@0x0062fc20
----------------------------------------------------------------

void FUN_0062f990(undefined8 param_1)

{
  int iVar1;
  
  if (cRam006c4fd5 == '\0') {
    iVar1 = (int)param_1;
    if (*(char *)(iVar1 + 4) != '\x01') {
      if (*(char *)(iVar1 + 4) != '\0') {
        return;
      }
      *(undefined1 *)(iVar1 + 1) = 1;
      *(char *)(iVar1 + 4) = *(char *)(iVar1 + 4) + '\x01';
      if (*(char *)(iVar1 + 3) == '\x02') {
        FUN_0062fc20();
      }
    }
    if (*(char *)(iVar1 + 3) == '\x02') {
      FUN_0062fc40(param_1);
      *(undefined4 *)(iVar1 + 0x30) = 1;
      *(undefined2 *)(iVar1 + 0x26) = *(undefined2 *)(&DAT_0066af68 + (uint)bRam006c4fd4 * 4);
      *(undefined2 *)(iVar1 + 0x28) = *(undefined2 *)(&DAT_0066af6a + (uint)bRam006c4fd4 * 4);
    }
  }
  else {
    FUN_00618c20();
  }
  return;
}



================================================================