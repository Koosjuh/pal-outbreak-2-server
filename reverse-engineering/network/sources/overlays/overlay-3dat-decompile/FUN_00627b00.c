FUNCTION FUN_00627b00 @ 0x00627b00  size=392
CALLERS (2): FUN_0062d1b0@0x0062d1b0, FUN_00627f20@0x00627f20
CALLEES (2): FUN_005b68e0@0x005b68e0, FUN_005c4380@0x005c4380
----------------------------------------------------------------

void FUN_00627b00(void)

{
  int iVar1;
  uint uVar2;
  
  if (cRam007154c8 == '\x02') {
    if (cRam006c5c44 == '\x01') {
      uRam007154f2 = 2;
      uVar2 = (uint)uRam007154f0;
      *(undefined2 *)(uVar2 * 0x14 + 0x715512) = 0x1518;
      *(undefined1 *)(uVar2 * 0x14 + 0x715511) = 2;
      cRam007154c8 = '\0';
      cRam006c4fdf = '\0';
    }
    else if (cRam006c5c44 == '\x02') {
      uRam007154f2 = (ushort)bRam006c5c4f;
      iVar1 = (uint)uRam007154f0 * 0x14;
      *(undefined2 *)(iVar1 + 0x715512) = 0x1518;
      if (uRam007154f2 == 0) {
        *(undefined1 *)(iVar1 + 0x715511) = 1;
      }
      else {
        *(undefined1 *)(iVar1 + 0x715511) = 3;
      }
      cRam007154c8 = '\0';
      cRam006c4fdf = '\0';
    }
  }
  else if (cRam007154c8 == '\x01') {
    FUN_005b68e0();
    cRam007154c8 = '\x02';
    uRam007154cc = 0x708;
    uRam006c4fbb = 0x24;
    cRam006c5c44 = '\0';
    FUN_005c4380(0x7154e0,0x627c90);
  }
  else if ((cRam007154c8 == '\0') && (cRam006c4fdf != '\0')) {
    cRam007154c8 = '\x01';
  }
  return;
}



================================================================