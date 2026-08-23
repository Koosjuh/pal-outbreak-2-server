FUNCTION FUN_005f5300 @ 0x005f5300  size=464
CALLERS (1): FUN_005f54d0@0x005f54d0
CALLEES (1): FUN_005af2c0@0x005af2c0
----------------------------------------------------------------

void FUN_005f5300(int param_1,char param_2)

{
  byte bVar1;
  long lVar2;
  int iVar3;
  
  iVar3 = iRam003435d4 + 0xc8000;
  if (param_2 == '\x02') {
    bVar1 = *(byte *)(param_1 + iVar3 + 0x13fa);
    if (((bVar1 == 0) || ((*(byte *)(bVar1 + 0x24eba9) & 4) == 0)) || (cRam006c50fb != '\0')) {
      if (cRam006c50fb == '\0') {
        FUN_005af2c0(0);
      }
      else {
        FUN_005af2c0(0x14);
      }
    }
    else {
      FUN_005af2c0(*(undefined1 *)((bVar1 - 0x30 & 7) + 0x649710));
    }
  }
  else if (param_2 == '\x01') {
    bVar1 = *(byte *)(param_1 + iVar3 + 0x13c8);
    if ((bVar1 == 0) || ((*(byte *)(bVar1 + 0x24eba9) & 4) == 0)) {
      lVar2 = func_0x00109d70(iVar3 + param_1 * 0x11 + 800,0x6c69cc);
      if (lVar2 == 0) {
        FUN_005af2c0(0x15);
      }
      else {
        FUN_005af2c0(0x11);
      }
    }
    else {
      FUN_005af2c0(*(undefined1 *)((bVar1 - 0x30 & 7) + 0x649710));
    }
  }
  else if (param_2 == '\0') {
    bVar1 = *(byte *)(param_1 + iVar3 + 0x1396);
    if ((bVar1 == 0) || ((*(byte *)(bVar1 + 0x24eba9) & 4) == 0)) {
      FUN_005af2c0(0x10);
    }
    else {
      FUN_005af2c0(*(undefined1 *)((bVar1 - 0x30 & 7) + 0x649710));
    }
  }
  return;
}



================================================================