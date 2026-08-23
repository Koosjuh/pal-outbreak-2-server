
undefined4 FUN_001e0774(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  long lVar2;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    iStack_18 = DAT_0025b78c;
    if (*(int *)(DAT_0025b78c + 0x50c) == 0) {
      uStack_24 = param_4;
      if (0x367 < param_4) {
        uStack_24 = 0x368;
      }
      uStack_2c = param_2;
      uStack_28 = param_3;
      iStack_1c = FUN_001d5288(DAT_0025b78c,uStack_24);
      if (iStack_1c == 0) {
        DAT_0025b790 = 0x65;
        uVar1 = 0xffffffff;
      }
      else {
        iStack_20 = FUN_001ed2c0(iStack_1c,(undefined2)uStack_24);
        if (iStack_20 == 0) {
          FUN_001ec9e0(*(undefined4 *)(iStack_18 + 0x520),iStack_1c);
          DAT_0025b790 = 0x65;
          uVar1 = 0xffffffff;
        }
        else {
          FUN_001069a8(iStack_20,&uStack_2c,4);
          FUN_001069a8(iStack_20 + 4,uStack_28,uStack_24);
          lVar2 = FUN_001e180c(iStack_18,iStack_1c,0xb000,(uStack_24 & 0xffff) + 4 & 0xffff,0x3f,0);
          if (lVar2 == 0) {
            uVar1 = 0;
          }
          else {
            DAT_0025b790 = 0x66;
            uVar1 = 0xffffffff;
          }
        }
      }
    }
    else {
      DAT_0025b790 = 0x66;
      uVar1 = 0xffffffff;
    }
  }
  else {
    DAT_0025b790 = 100;
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

