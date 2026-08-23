FUNCTION FUN_006336d0 @ 0x006336d0  size=360
CALLERS (2): FUN_00633930@0x00633930, FUN_00633ab0@0x00633ab0
CALLEES (3): FUN_00633650@0x00633650, FUN_00633590@0x00633590, FUN_006335f0@0x006335f0
----------------------------------------------------------------

void FUN_006336d0(undefined8 param_1,long param_2)

{
  bool bVar1;
  int iVar2;
  long extraout_t0;
  int extraout_t1_lo;
  long lVar3;
  int iVar4;
  
  if (*(char *)(iRam00715da8 + 0x36) != '\0') {
    func_0x00106b60(0x7158f0,0,0x240);
    func_0x00106b60(0x715b30,0,0x30);
    iVar4 = (int)param_1;
    if (param_2 == 0) {
      iVar2 = *(int *)(iRam00715da8 + 600) - iVar4;
      if (iVar4 + 3 <= *(int *)(iRam00715da8 + 600)) {
        iVar2 = 3;
      }
      lVar3 = 0;
      if (*(char *)(iRam00715da8 + 0x36) != '\0') {
        bVar1 = 0 < iVar2;
        while (bVar1) {
          FUN_006335f0(lVar3,param_1);
          lVar3 = (long)(extraout_t1_lo + 1);
          bVar1 = lVar3 < extraout_t0;
        }
        FUN_00633650();
      }
      iVar4 = 0;
      do {
        FUN_00633590(iVar4);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 3);
    }
    else {
      if (*(int *)(iRam00715da8 + 600) < iVar4 + 3) {
        iVar4 = *(int *)(iRam00715da8 + 600) - iVar4;
      }
      else {
        iVar4 = 3;
      }
      if (*(char *)(iRam00715da8 + 0x36) != '\0') {
        for (; -1 < iVar4 + -1; iVar4 = FUN_006335f0(iVar4 + -1,param_1)) {
        }
        FUN_00633650();
      }
      iVar4 = 2;
      do {
        FUN_00633590(iVar4);
        iVar4 = iVar4 + -1;
      } while (-1 < iVar4);
    }
  }
  return;
}



================================================================