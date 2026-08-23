FUNCTION FUN_005f9e50 @ 0x005f9e50  size=272
CALLERS (1): FUN_005f9540@0x005f9540
CALLEES (2): FUN_005b14b0@0x005b14b0, FUN_005f9d40@0x005f9d40
----------------------------------------------------------------

void FUN_005f9e50(uint param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  long lVar4;
  byte bVar5;
  byte *pbVar6;
  byte bVar7;
  
  iVar3 = (param_1 & 0xff) * 0x14a8;
  pbVar6 = (byte *)(iVar3 + 0x69713a);
  bVar1 = *(byte *)(iVar3 + 0x69713c);
  bVar7 = *pbVar6;
  bVar2 = *(byte *)(iVar3 + 0x69713b);
  if (*(char *)(iVar3 + 0x697138) != '\0') {
    lVar4 = FUN_005b14b0(0x40004);
    if (lVar4 != 0) {
      bVar5 = bVar7 - 1;
      if ((long)(char)(bVar7 - 1) < (long)(ulong)bVar2) {
        bVar5 = bVar1;
      }
      func_0x001b0140(0);
      *pbVar6 = bVar5;
      goto LAB_005f9f3c;
    }
    lVar4 = FUN_005b14b0(0x80008);
    bVar5 = bVar7 + 1;
    if (lVar4 != 0) {
      bVar7 = bVar5;
      if ((long)(ulong)bVar1 < (long)(char)bVar5) {
        bVar7 = bVar2;
      }
      func_0x001b0140(0);
    }
  }
  *pbVar6 = bVar7;
LAB_005f9f3c:
  FUN_005f9d40();
  return;
}



================================================================