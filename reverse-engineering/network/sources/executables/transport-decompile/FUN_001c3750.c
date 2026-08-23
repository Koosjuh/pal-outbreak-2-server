
uint FUN_001c3750(byte *param_1,byte param_2,int param_3,char param_4)

{
  undefined8 uVar1;
  uint uVar2;
  int iVar3;
  byte abStack_10 [16];
  
  iVar3 = 0;
  if (param_1 == (byte *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    FUN_00106b60(abStack_10,0,0x10);
    uVar1 = FUN_0010a050(PTR_s_TUlOQU1JT0g__00248738);
    FUN_001c3490(PTR_s_TUlOQU1JT0g__00248738,abStack_10,uVar1,0x10);
    for (uVar2 = 0; (int)uVar2 < param_3; uVar2 = uVar2 + 1) {
      *param_1 = abStack_10[uVar2 & 7] ^ *param_1 ^ param_4 + param_2 + (char)uVar2;
      iVar3 = iVar3 + (uint)*param_1;
      param_1 = param_1 + 1;
    }
    uVar2 = iVar3 + (uint)param_2 * 0x101 & 0x7fff;
  }
  return uVar2;
}

