FUNCTION FUN_005f8ec0 @ 0x005f8ec0  size=248
CALLERS (1): FUN_005f8e20@0x005f8e20
CALLEES (6): FUN_005af190@0x005af190, FUN_005b6900@0x005b6900, FUN_005fba80@0x005fba80, FUN_005b68e0@0x005b68e0, FUN_005bff20@0x005bff20, FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

void FUN_005f8ec0(undefined8 param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = (int)param_1;
  cVar1 = *(char *)(iVar4 + 0xf);
  if (cVar1 == '\x02') {
    FUN_005b6900();
  }
  else if (cVar1 == '\x01') {
    *(undefined1 *)(iVar4 + 0xf) = 2;
    func_0x00106b60(0x6c0760,0,0x28c8);
    iVar5 = 0;
    iVar3 = 0;
    do {
      sVar2 = (short)iVar5;
      iVar5 = iVar5 + 1;
      *(short *)(iVar3 + 0x6c0760) = sVar2 + 1;
      iVar3 = iVar5 * 0x15c;
    } while (iVar5 < 0x1e);
    FUN_005b68e0();
    *(undefined1 *)(iVar4 + 0x42b) = 9;
    FUN_005bff20(0,0xb7,0x5fc0c0);
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(iVar4 + 0xf) = 1;
    *(undefined1 *)(iVar4 + 0x97c) = 0;
    FUN_005fba80();
    FUN_005b8cf0(0x76);
    *(undefined1 *)(iVar4 + 0x45a) = 1;
    FUN_005af190(param_1);
  }
  return;
}



================================================================