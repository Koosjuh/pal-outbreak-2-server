FUNCTION FUN_005acea0 @ 0x005acea0  size=388
CALLERS (1): FUN_005ace00@0x005ace00
CALLEES (8): FUN_005af120@0x005af120, FUN_005b2470@0x005b2470, FUN_005af2f0@0x005af2f0, FUN_005b6900@0x005b6900, FUN_00618b60@0x00618b60, FUN_005bf340@0x005bf340, FUN_005b68e0@0x005b68e0, FUN_005f4b70@0x005f4b70
----------------------------------------------------------------

void FUN_005acea0(undefined8 param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = (int)param_1;
  cVar1 = *(char *)(iVar3 + 0xf);
  if (cVar1 == '\x03') {
    *(undefined1 *)(iVar3 + 0xe) = 1;
    *(undefined1 *)(iVar3 + 0xf) = 0;
    *(undefined1 *)(iVar3 + 0x10) = 0;
  }
  else if (cVar1 == '\x02') {
    FUN_005b6900();
  }
  else if (cVar1 == '\x01') {
    FUN_005b68e0();
    *(undefined1 *)(iVar3 + 0x42b) = 3;
    FUN_005bf340(0,0xf,0x5ad890);
    *(char *)(iVar3 + 0xf) = *(char *)(iVar3 + 0xf) + '\x01';
  }
  else if (cVar1 == '\0') {
    FUN_005f4b70();
    FUN_005af2f0(0,10);
    FUN_005af120(param_1,0);
    FUN_00618b60();
    func_0x00106b60(iVar3 + 0x900,0,0x20);
    *(char *)(iVar3 + 0x907) = cRam006c45f8 + -1;
    if (*(char *)(iVar3 + 0x907) < '\x01') {
      *(undefined1 *)(iVar3 + 0x907) = 0;
    }
    cRam006c45f8 = '\0';
    uRam006c45fc = 0;
    uRam006c4600 = 0;
    func_0x00106b60(0x6c3860,0,0xd98);
    func_0x00106b60(0x6c3030,0,0x828);
    iVar4 = 0;
    do {
      iVar2 = iVar4 * 0x15c;
      iVar4 = iVar4 + 1;
      *(undefined1 *)(iVar2 + 0x6c386e) = 0;
    } while (iVar4 < 10);
    *(char *)(iVar3 + 0xf) = *(char *)(iVar3 + 0xf) + '\x01';
    func_0x003adb70();
    FUN_005b2470(3);
    *(undefined1 *)(iVar3 + 0x992) = 0;
  }
  return;
}



================================================================