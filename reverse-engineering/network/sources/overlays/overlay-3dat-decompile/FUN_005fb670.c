FUNCTION FUN_005fb670 @ 0x005fb670  size=156
CALLERS (7): FUN_005faa60@0x005faa60, FUN_0062dc40@0x0062dc40, FUN_005fb010@0x005fb010, FUN_005fb270@0x005fb270, FUN_005fa490@0x005fa490, FUN_005fada0@0x005fada0, FUN_005fb060@0x005fb060
CALLEES (4): FUN_00637180@0x00637180, FUN_005adc80@0x005adc80, FUN_005b9110@0x005b9110, FUN_005b1d10@0x005b1d10
----------------------------------------------------------------

undefined4 FUN_005fb670(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_005adc80(2);
  cVar1 = *(char *)((iVar2 + -1) * 0x15c + 0x6c076e);
  if ((cVar1 == '\x04') || (cVar1 == '\x03')) {
    uVar3 = 0;
  }
  else {
    uRam006c4fd3 = 1;
    FUN_005b1d10(0x6c4b90);
    uRam006c4fce = 0;
    uRam006c4fcd = 0x4c;
    FUN_00637180();
    FUN_005b9110(0x4c);
    uVar3 = 1;
  }
  return uVar3;
}



================================================================