
undefined2
FUN_001f0070(short *param_1,short *param_2,undefined4 *param_3,short *param_4,undefined8 param_5)

{
  int iVar1;
  short *psVar2;
  undefined2 uVar3;
  
  FUN_001ef3e0();
  if (DAT_0024e400 == (short *)0x37aee8) {
    FUN_001ef400(0x1b,0x37cf00,0x20,0x37bf00,0x1030);
    psVar2 = (short *)0x37bf1c;
    if (sRam0037bf18 == 0) {
      for (; *psVar2 != -1; psVar2 = (short *)((int)psVar2 + iVar1)) {
        FUN_001069a8(DAT_0024e400,psVar2,psVar2[1] + 0xc + (uint)(ushort)psVar2[3]);
        iVar1 = psVar2[1] + 0xc + (uint)(ushort)psVar2[3];
        DAT_0024e400 = (short *)((int)DAT_0024e400 + iVar1);
      }
    }
    *DAT_0024e400 = -1;
    DAT_0024e400 = (short *)0x37aee8;
  }
  psVar2 = DAT_0024e400;
  if (*DAT_0024e400 == -1) {
    uVar3 = 0xffff;
    DAT_0024e400 = (short *)0x37aee8;
  }
  else {
    *param_1 = *DAT_0024e400;
    *param_2 = psVar2[1];
    *param_3 = *(undefined4 *)(psVar2 + 4);
    *param_4 = psVar2[2];
    uVar3 = 0;
    FUN_001069a8(param_5,psVar2 + 6,psVar2[1]);
    DAT_0024e400 = (short *)((int)DAT_0024e400 + psVar2[1] + 0xc + (uint)(ushort)psVar2[3]);
  }
  FUN_001ef3f0();
  return uVar3;
}

