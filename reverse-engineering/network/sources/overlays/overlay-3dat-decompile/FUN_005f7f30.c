FUNCTION FUN_005f7f30 @ 0x005f7f30  size=244
CALLERS (1): FUN_005f7800@0x005f7800
CALLEES (5): FUN_0062d4e0@0x0062d4e0, FUN_00627760@0x00627760, FUN_005add90@0x005add90, FUN_00627d40@0x00627d40, FUN_005f5ea0@0x005f5ea0
----------------------------------------------------------------

void FUN_005f7f30(int param_1)

{
  char cVar1;
  int iVar2;
  ulong uVar3;
  
  cVar1 = *(char *)(param_1 + 0x907);
  if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0xe) = 4;
    *(undefined1 *)(param_1 + 0xf) = 0;
    *(undefined1 *)(param_1 + 0x10) = 0;
  }
  else {
    uVar3 = (ulong)uRam006c45fe;
    if (6 < uVar3) {
      uVar3 = 6;
    }
    if ((long)cVar1 < (long)uVar3) {
      *(ushort *)(param_1 + 6) = (ushort)*(byte *)(cVar1 + 0x70b410);
      *(short *)(param_1 + 0x53a) = (short)*(char *)(param_1 + 0x907);
      FUN_0062d4e0();
    }
    else {
      *(char *)(param_1 + 0x10b6) = cVar1;
      iVar2 = (int)*(char *)(param_1 + 0x907) - (int)uVar3;
      if (iVar2 == 3) {
        FUN_005add90();
      }
      else if (iVar2 == 2) {
        FUN_00627760();
      }
      else if (iVar2 == 1) {
        FUN_005f5ea0();
      }
      else if ((int)*(char *)(param_1 + 0x907) == (int)uVar3) {
        FUN_00627d40();
      }
    }
  }
  return;
}



================================================================