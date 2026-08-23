FUNCTION FUN_0062d9f0 @ 0x0062d9f0  size=240
CALLERS (1): FUN_0062d950@0x0062d950
CALLEES (3): FUN_005b6900@0x005b6900, FUN_005b68e0@0x005b68e0, FUN_005bff20@0x005bff20
----------------------------------------------------------------

void FUN_0062d9f0(int param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  cVar1 = *(char *)(param_1 + 0x10);
  if (cVar1 == '\x02') {
    FUN_005b6900();
  }
  else if (cVar1 == '\x01') {
    *(undefined1 *)(param_1 + 0x10) = 2;
    func_0x00106b60(0x6c0760,0,0x28c8);
    func_0x00106b60(param_1 + 0x9ac,0,0x1e);
    iVar4 = 0;
    iVar3 = 0;
    do {
      sVar2 = (short)iVar4;
      iVar4 = iVar4 + 1;
      *(short *)(iVar3 + 0x6c0760) = sVar2 + 1;
      iVar3 = iVar4 * 0x15c;
    } while (iVar4 < 0x1e);
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 9;
    FUN_005bff20(0,0xb7,0x62e9b0);
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0x10) = 1;
    *(undefined1 *)(param_1 + 0x449) = 0;
    *(undefined1 *)(param_1 + 0x448) = 0;
    *(undefined1 *)(param_1 + 0x45a) = 0;
    *(undefined1 *)(param_1 + 0x97e) = 0;
  }
  return;
}



================================================================