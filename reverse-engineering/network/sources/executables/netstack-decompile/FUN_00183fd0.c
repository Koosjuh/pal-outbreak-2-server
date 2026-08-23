
undefined8 FUN_00183fd0(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined1 auStack_800 [2048];
  
  FUN_00109eb8(auStack_800,0x22f6c8);
  iVar1 = FUN_0010a050(auStack_800);
  FUN_00109ab0(auStack_800,param_1);
  FUN_0010bca0(auStack_800 + iVar1);
  FUN_00109ab0(auStack_800,0x22f6d0);
  FUN_00183c80(auStack_800);
  FUN_00129ff8();
  lVar2 = FUN_00116cf0(auStack_800,1);
  if (lVar2 < 0) {
    FUN_0012a010();
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_001170f8(lVar2,0,2);
    FUN_00116f78(lVar2);
    FUN_0012a010();
  }
  return uVar3;
}

