
int FUN_001e1e4c(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint uStack_2c;
  int iStack_20;
  int iStack_1c;
  
  iStack_1c = param_1 + 0x1f;
  if (iStack_1c < 0) {
    iStack_1c = param_1 + 0x3e;
  }
  iVar2 = (iStack_1c >> 5) * 0x20;
  iStack_20 = 0;
  uStack_2c = 0;
  do {
    if (51999 < uStack_2c) {
LAB_001e1fd4:
      if (52000 < uStack_2c) {
        iStack_20 = 0;
      }
      return iStack_20;
    }
    piVar3 = (int *)(uStack_2c + 0x36d758);
    if (*piVar3 == -0x5050506) {
      uVar1 = *(uint *)(uStack_2c + 0x36d75c);
      if (iVar2 + 8U <= uVar1) {
        iStack_20 = uStack_2c + 0x36d760;
        *(int *)(uStack_2c + 0x36d75c) = iVar2;
        *piVar3 = -0x5050506;
        *piVar3 = -0x4040405;
        puVar4 = (undefined4 *)(uStack_2c + 0x36d760 + iVar2);
        puVar4[1] = uVar1 + (iStack_1c >> 5) * -0x20 + -8;
        *puVar4 = 0xfafafafa;
        goto LAB_001e1fd4;
      }
    }
    else if (*piVar3 != -0x4040405) {
      FUN_00102648();
    }
    uStack_2c = uStack_2c + *(int *)(uStack_2c + 0x36d75c) + 8;
  } while( true );
}

