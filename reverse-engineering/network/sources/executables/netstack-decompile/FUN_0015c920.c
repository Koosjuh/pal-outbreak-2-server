
void FUN_0015c920(long param_1)

{
  float fVar1;
  long lVar2;
  undefined8 uVar3;
  float *pfVar4;
  
  if (param_1 != 0) {
    pcRam00269fb8 = s_MWSFD_PS2EE_Ver_2_88_Build_Jul_2_00256198;
    FUN_00161700();
    pfVar4 = (float *)param_1;
    fVar1 = (float)((int)pfVar4[2] + -2);
    if ((int)fVar1 < 0) {
      fVar1 = 0.0;
    }
    pfVar4[2] = fVar1;
    if (DAT_0022d9d0 == 0) {
      FUN_00128468();
      FUN_0013da78();
      FUN_0013d540();
      FUN_0013e2a0();
      lVar2 = FUN_00162688();
      if (lVar2 != 0) {
        FUN_0015cd70(0xffffffffffffff9b);
        FUN_001619d0(0x256260);
      }
      FUN_0015cae0(param_1);
      DAT_0022eadc = 0;
      uVar3 = FUN_001107b0(*pfVar4 * 1000.0);
      uVar3 = FUN_00110be8(uVar3,0x3fe0000000000000);
      uVar3 = FUN_00111298(uVar3);
      lVar2 = FUN_0015cdc0(uVar3);
      if (lVar2 != 0) {
        FUN_001619d0(0x256288);
      }
      DAT_0022d9d4 = 1;
      FUN_0015cc18(param_1);
      FUN_0013b818();
      FUN_0013b750(0x15c908,0);
      FUN_0015ed80();
      FUN_0015ca98(param_1);
    }
    DAT_0022d9d0 = DAT_0022d9d0 + 1;
    return;
  }
  FUN_001619d0(0x256238);
  return;
}

