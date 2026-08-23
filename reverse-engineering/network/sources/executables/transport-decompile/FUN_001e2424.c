
void FUN_001e2424(int param_1)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  int iStack_2c;
  undefined2 *puStack_24;
  int iStack_20;
  
  bVar1 = false;
  puStack_24 = (undefined2 *)PTR_DAT_0025b798;
  DAT_0025b7a8 = DAT_0025b7a8 + 1;
  if (DAT_0025b7a8 < 2) {
    if (param_1 != 0) {
      for (iStack_2c = 0; *(int *)(iStack_2c * 4 + param_1) != 0; iStack_2c = iStack_2c + 2) {
        lVar3 = FUN_00109d70(*(undefined4 *)(iStack_2c * 4 + param_1),0x2595c8);
        if (lVar3 == 0) {
          bVar1 = true;
        }
      }
    }
    iVar2 = FUN_001010a8(0);
    if (iVar2 == 0) {
      FUN_00114ac8(0x2595d8,0);
    }
    if (bVar1) {
      iStack_20 = FUN_00101c38(2);
    }
    else {
      iStack_20 = FUN_00101c38(1);
    }
    if (iStack_20 == 0) {
      FUN_00114ac8(0x259600,0);
    }
    DAT_0025b7a0 = 0;
  }
  for (iStack_2c = 0; iStack_2c < 0x40; iStack_2c = iStack_2c + 1) {
    if (DAT_0025b7a8 < 2) {
      *puStack_24 = 0xffff;
      puStack_24[1] = 0xffff;
      puStack_24[2] = 0xffff;
    }
    FUN_001eb22c(puStack_24 + 4,0);
    puStack_24 = puStack_24 + 0x12;
  }
  return;
}

