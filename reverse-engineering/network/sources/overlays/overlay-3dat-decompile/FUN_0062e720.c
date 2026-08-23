FUNCTION FUN_0062e720 @ 0x0062e720  size=220
CALLERS (1): FUN_0062e3c0@0x0062e3c0
CALLEES (7): FUN_00637180@0x00637180, FUN_005adc80@0x005adc80, FUN_005b6900@0x005b6900, FUN_005c0e30@0x005c0e30, FUN_005b68e0@0x005b68e0, FUN_005f74d0@0x005f74d0, FUN_00617a00@0x00617a00
----------------------------------------------------------------

void FUN_0062e720(undefined8 param_1)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  
  iVar3 = (int)param_1;
  cVar1 = *(char *)(iVar3 + 0x10);
  if (cVar1 == '\x02') {
    *(undefined1 *)(iVar3 + 0x146b) = 0;
    func_0x001b0140(10);
    if (*(char *)(iVar3 + 0x997) == '\x01') {
      FUN_005f74d0();
    }
    else if (*(char *)(iVar3 + 0x997) == '\x02') {
      FUN_00617a00(param_1);
    }
  }
  else if (cVar1 == '\x01') {
    FUN_005b6900();
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(iVar3 + 0x10) = 1;
    FUN_005b68e0();
    *(undefined1 *)(iVar3 + 0x42b) = 0x23;
    *(undefined1 *)(iVar3 + 0x997) = 0;
    uVar2 = FUN_005adc80(0);
    FUN_005c0e30(uVar2,0,0,0x62f480);
    FUN_00637180();
  }
  return;
}



================================================================