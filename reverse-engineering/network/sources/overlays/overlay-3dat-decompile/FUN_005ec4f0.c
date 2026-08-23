FUNCTION FUN_005ec4f0 @ 0x005ec4f0  size=340
CALLERS (7): FUN_005eabd0@0x005eabd0, FUN_005ef220@0x005ef220, FUN_005ebc50@0x005ebc50, FUN_005ef3f0@0x005ef3f0, FUN_005eac40@0x005eac40, FUN_005eb3a0@0x005eb3a0, FUN_005e7710@0x005e7710
CALLEES (0): 
----------------------------------------------------------------

int FUN_005ec4f0(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  undefined1 auStack_100 [256];
  
  iVar4 = 0;
  iVar1 = func_0x0010a050();
  lVar2 = func_0x0010a338(param_1,0x6494e0,1);
  pbVar5 = (byte *)param_1;
  if (lVar2 == 0) {
    for (iVar3 = 1; pbVar5 = pbVar5 + 1, iVar3 < iVar1; iVar3 = iVar3 + 1) {
      if ((&DAT_006492b0)[*pbVar5] != 0) {
        iVar4 = iVar4 * 0x10 + ((byte)(&DAT_006492b0)[*pbVar5] - 1);
      }
    }
  }
  else {
    iVar1 = func_0x0010a050(param_1);
    for (iVar4 = 0; iVar4 < iVar1; iVar4 = iVar4 + 1) {
      auStack_100[iVar4] = (&DAT_006493b0)[pbVar5[iVar4]];
    }
    auStack_100[iVar4] = 0;
    for (iVar1 = 0; iVar4 = iVar1 * 8, iVar1 < 0x93; iVar1 = iVar1 + 1) {
      lVar2 = func_0x0010a338(auStack_100,(&PTR_s_ALICEBLUE_00648d10)[iVar1 * 2],
                              (&DAT_00648d14)[iVar4]);
      if (lVar2 == 0) {
        return (uint)(byte)(&DAT_00648d17)[iVar4] +
               (uint)(byte)(&DAT_00648d15)[iVar4] * 0x10000 +
               (uint)(byte)(&DAT_00648d16)[iVar4] * 0x100;
      }
    }
    iVar4 = -1;
  }
  return iVar4;
}



================================================================