
uint FUN_001c3650(byte *param_1,byte *param_2,byte param_3,int param_4,char param_5)

{
  byte bVar1;
  undefined8 uVar2;
  uint uVar3;
  int iVar4;
  byte abStack_10 [16];
  
  iVar4 = 0;
  if ((param_1 == (byte *)0x0) || (param_2 == (byte *)0x0)) {
    uVar3 = 0xffffffff;
  }
  else {
    FUN_00106b60(abStack_10,0,0x10);
    uVar2 = FUN_0010a050(PTR_s_TUlOQU1JT0g__00248738);
    FUN_001c3490(PTR_s_TUlOQU1JT0g__00248738,abStack_10,uVar2,0x10);
    for (uVar3 = 0; (int)uVar3 < param_4; uVar3 = uVar3 + 1) {
      bVar1 = *param_2;
      iVar4 = iVar4 + (uint)bVar1;
      param_2 = param_2 + 1;
      *param_1 = bVar1 ^ abStack_10[uVar3 & 7] ^ param_5 + param_3 + (char)uVar3;
      param_1 = param_1 + 1;
    }
    uVar3 = iVar4 + (uint)param_3 * 0x101 & 0x7fff;
  }
  return uVar3;
}

