FUNCTION FUN_005d6920 @ 0x005d6920  size=228
CALLERS (1): FUN_005d8340@0x005d8340
CALLEES (4): FUN_005d67d0@0x005d67d0, FUN_005d68e0@0x005d68e0, FUN_005d6810@0x005d6810, FUN_005d6770@0x005d6770
----------------------------------------------------------------

void FUN_005d6920(undefined8 param_1,int param_2,undefined8 param_3)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  
  iVar3 = iRam00701018;
  cVar1 = *(char *)(param_2 + 0x10c);
  if (cVar1 == '\x06') {
    uVar2 = *(undefined1 *)(param_2 + 0x109);
    *(undefined1 *)(iRam00701018 + 0x108) = *(undefined1 *)(param_2 + 0x108);
    *(undefined1 *)(iVar3 + 0x109) = uVar2;
  }
  else if (cVar1 == '\x05') {
    iRam00701018 = FUN_005d6810(param_1,iRam00701018);
  }
  else if (cVar1 == '\x04') {
    iRam00701018 = FUN_005d67d0(param_1,iRam00701018);
  }
  else {
    iRam00701018 = FUN_005d68e0(param_1,iRam00701018);
    iVar3 = FUN_005d6770(param_1,param_3);
    uVar2 = *(undefined1 *)(param_2 + 0x109);
    iRam00701018 = iVar3;
    *(undefined1 *)(iVar3 + 0x108) = *(undefined1 *)(param_2 + 0x108);
    *(undefined1 *)(iVar3 + 0x109) = uVar2;
  }
  return;
}



================================================================