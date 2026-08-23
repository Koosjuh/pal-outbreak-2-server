
undefined4 FUN_0019a260(undefined8 param_1,undefined8 param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  long lVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  lVar3 = FUN_00199f70();
  if (lVar3 == 0) {
    uVar2 = 0;
  }
  else {
    lVar3 = FUN_0019a350(lVar3,0x50000,0);
    if (lVar3 == 0) {
      uVar2 = 0;
    }
    else {
      uVar1 = *(uint *)((int)lVar3 + 4);
      puVar4 = (undefined4 *)((int)lVar3 + 0xc);
      for (uVar5 = 0; uVar2 = 1, uVar5 < uVar1; uVar5 = uVar5 + 1) {
        *(undefined4 *)(param_3 + uVar5 * 4) = *puVar4;
        puVar4 = puVar4 + 1;
      }
    }
  }
  return uVar2;
}

