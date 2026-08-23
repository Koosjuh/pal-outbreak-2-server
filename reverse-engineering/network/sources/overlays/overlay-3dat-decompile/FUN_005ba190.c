FUNCTION FUN_005ba190 @ 0x005ba190  size=332
CALLERS (0): 
CALLEES (2): FUN_00618c20@0x00618c20, FUN_005b9120@0x005b9120
----------------------------------------------------------------

void FUN_005ba190(undefined8 param_1)

{
  char cVar1;
  char *pcVar2;
  long lVar3;
  int iVar4;
  
  iVar4 = (int)param_1;
  pcVar2 = *(char **)(iVar4 + 0x10);
  lVar3 = FUN_005b9120();
  if (lVar3 == 0) {
    cVar1 = *(char *)(iVar4 + 4);
    if (cVar1 != '\x02') {
      if (cVar1 != '\x01') {
        if (cVar1 != '\0') {
          return;
        }
        *(undefined1 *)(iVar4 + 4) = 1;
        if (*(char *)(iVar4 + 0x38) != '\0') {
          *(ushort *)(iVar4 + 0x24) = *(ushort *)(iVar4 + 0x24) | 0x400;
          *(undefined4 *)(iVar4 + 0x2c) = 0xff00ff00;
          *(undefined2 *)(iVar4 + 0x3a) = 1;
        }
      }
      *(char *)(iVar4 + 4) = *(char *)(iVar4 + 4) + '\x01';
      *(undefined1 *)(iVar4 + 1) = 1;
    }
    *(short *)(iVar4 + 0x26) =
         (short)*(undefined4 *)(*pcVar2 * 4 + *(char *)(iVar4 + 3) * 8 + 0x639d80);
    *(short *)(iVar4 + 0x28) =
         (short)*(undefined4 *)(*pcVar2 * 4 + *(char *)(iVar4 + 3) * 8 + 0x639da0);
    if (*(char *)(iVar4 + 0x38) != '\0') {
      *(undefined2 *)(iVar4 + 0x42) = 0;
      *(undefined2 *)(iVar4 + 0x44) = 0x40;
      *(undefined2 *)(iVar4 + 0x46) = 0x40;
      *(short *)(iVar4 + 0x40) = *(short *)(iVar4 + 0x40) - *(short *)(iVar4 + 0x3a);
      *(ushort *)(iVar4 + 0x40) = *(ushort *)(iVar4 + 0x40) & 0x3f;
    }
    if (cRam006c4fd0 != '\0') {
      FUN_00618c20(param_1);
    }
  }
  else {
    FUN_00618c20(param_1);
  }
  return;
}



================================================================