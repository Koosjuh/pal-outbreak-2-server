
int FUN_001d53cc(void)

{
  int iVar1;
  long lVar2;
  int aiStack_40 [2];
  undefined8 uStack_38;
  undefined1 auStack_30 [16];
  
  lVar2 = FUN_001e41fc(aiStack_40,auStack_30);
  if (lVar2 < 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = FUN_0010ea10(uStack_38,1000);
    iVar1 = aiStack_40[0] * 1000 + iVar1;
  }
  return iVar1;
}

