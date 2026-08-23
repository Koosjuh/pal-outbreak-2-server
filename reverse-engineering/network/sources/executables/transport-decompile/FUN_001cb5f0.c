
long FUN_001cb5f0(uint param_1)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  undefined8 extraout_a1;
  uint *puVar4;
  undefined1 auStack_50 [4];
  undefined2 uStack_4c;
  undefined2 uStack_48;
  undefined2 uStack_3c;
  
  lVar2 = FUN_001cb4e0();
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  else {
    uVar1 = FUN_00184370(extraout_a1,4);
    puVar4 = (uint *)lVar2;
    *puVar4 = uVar1;
    if (*puVar4 == 0) {
      FUN_001cb530(lVar2);
      lVar2 = 0;
    }
    else {
      lVar3 = FUN_00194240(auStack_50,*puVar4 & 0xffff);
      if (lVar3 == 1) {
        puVar4[1] = param_1;
        *(undefined2 *)(puVar4 + 2) = uStack_4c;
        *(undefined2 *)((int)puVar4 + 10) = uStack_48;
        *(undefined2 *)(puVar4 + 3) = uStack_3c;
        *(undefined2 *)((int)puVar4 + 0xe) = 1;
      }
    }
  }
  return lVar2;
}

