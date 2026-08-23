
undefined4 FUN_001edbb8(undefined4 param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  long lVar4;
  int iStack_38;
  ushort *puStack_34;
  ushort *puStack_30;
  ushort auStack_20 [8];
  
  iStack_38 = FUN_001ebca8(param_1);
  puStack_34 = (ushort *)FUN_001ed6bc(param_1);
  while( true ) {
    if (puStack_34 == (ushort *)0x0) {
      return 0;
    }
    if (iStack_38 < 0x10) break;
    lVar4 = FUN_001eda10(param_1,puStack_34);
    if (lVar4 == 0) {
      FUN_001069a8(auStack_20,puStack_34,0x10);
      puStack_30 = auStack_20;
    }
    else {
      puStack_30 = puStack_34;
    }
    uVar1 = *puStack_30;
    uVar2 = FUN_001e234c(*puStack_30);
    *puStack_30 = uVar2;
    uVar2 = FUN_001e234c(puStack_30[1]);
    puStack_30[1] = uVar2;
    uVar3 = FUN_001e2304(*(undefined4 *)(puStack_30 + 2));
    *(undefined4 *)(puStack_30 + 2) = uVar3;
    uVar3 = FUN_001e2304(*(undefined4 *)(puStack_30 + 4));
    *(undefined4 *)(puStack_30 + 4) = uVar3;
    uVar3 = FUN_001e2304(*(undefined4 *)(puStack_30 + 6));
    *(undefined4 *)(puStack_30 + 6) = uVar3;
    lVar4 = FUN_001eda10(param_1,puStack_34);
    if (lVar4 == 0) {
      FUN_001069a8(puStack_34,auStack_20,0x10);
    }
    iStack_38 = iStack_38 - (uVar1 & 0x3ff);
    if (iStack_38 == 0) {
      return 0;
    }
    puStack_34 = (ushort *)FUN_001ee060(param_1,puStack_34,uVar1 & 0x3ff);
  }
  return 0xffffe0c3;
}

