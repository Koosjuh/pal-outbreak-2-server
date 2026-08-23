
int FUN_001e3ba8(int param_1,int param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  undefined *puVar3;
  long lVar4;
  int iStack_50;
  uint uStack_3c;
  int iStack_34;
  
  bVar1 = false;
  iStack_34 = 0;
  iStack_50 = param_1;
  if (0x40 < param_1) {
    iStack_50 = 0x40;
  }
  for (uStack_3c = 0; (int)uStack_3c < iStack_50; uStack_3c = uStack_3c + 1) {
    bVar2 = false;
    if ((param_2 != 0) &&
       ((*(long *)(param_2 + (uStack_3c >> 6) * 8) >> ((long)(int)uStack_3c & 0x3fU) & 1U) != 0)) {
      puVar3 = PTR_DAT_0025b798 + uStack_3c * 0x24;
      if (*(short *)(puVar3 + 2) == 1) {
        FUN_001e4bec(puVar3);
        bVar2 = true;
        if ((*(short *)(puVar3 + 4) == 0xff4) || (*(short *)(puVar3 + 4) == 0xff6)) {
          iStack_34 = iStack_34 + 1;
        }
        else {
          *(ulong *)(param_2 + (uStack_3c >> 6) * 8) =
               *(ulong *)(param_2 + (uStack_3c >> 6) * 8) & ~(1L << ((long)(int)uStack_3c & 0x3fU));
        }
      }
      else if (*(short *)(puVar3 + 2) == 2) {
        if (!bVar1) {
          FUN_001e3a3c();
          bVar1 = true;
        }
        if (*(short *)(puVar3 + 4) == 0x7f) {
          lVar4 = FUN_001eb2d4(puVar3 + 8);
          if (lVar4 == 0) {
            *(ulong *)(param_2 + (uStack_3c >> 6) * 8) =
                 *(ulong *)(param_2 + (uStack_3c >> 6) * 8) &
                 ~(1L << ((long)(int)uStack_3c & 0x3fU));
          }
          else {
            iStack_34 = iStack_34 + 1;
          }
        }
        else {
          iStack_34 = iStack_34 + 1;
        }
      }
    }
    if ((param_3 != 0) &&
       ((*(long *)(param_3 + (uStack_3c >> 6) * 8) >> ((long)(int)uStack_3c & 0x3fU) & 1U) != 0)) {
      puVar3 = PTR_DAT_0025b798 + uStack_3c * 0x24;
      if (*(short *)(puVar3 + 2) == 1) {
        if (!bVar2) {
          FUN_001e4bec(puVar3);
        }
        if (*(short *)(puVar3 + 4) == 0x7f) {
          iStack_34 = iStack_34 + 1;
        }
        else {
          *(ulong *)(param_3 + (uStack_3c >> 6) * 8) =
               *(ulong *)(param_3 + (uStack_3c >> 6) * 8) & ~(1L << ((long)(int)uStack_3c & 0x3fU));
        }
      }
      else if (*(short *)(puVar3 + 2) == 2) {
        iStack_34 = iStack_34 + 1;
      }
    }
  }
  return iStack_34;
}

