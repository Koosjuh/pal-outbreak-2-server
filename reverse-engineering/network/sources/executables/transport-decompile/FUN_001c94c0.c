
long FUN_001c94c0(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  uint uVar4;
  
  piVar3 = (int *)param_1;
  if ((*piVar3 == 0) || (*piVar3 == 7)) {
    iVar1 = FUN_0010a050(0x365dd1);
    uVar4 = 0x300 - (iVar1 + 0xc);
    if ((uint)(piVar3[0x1c] - piVar3[0x12]) <= uVar4) {
      uVar4 = piVar3[0x1c] - piVar3[0x12];
    }
    FUN_001c3c90(param_1,0xd,1,0);
    FUN_001c4020(param_1,0x365dd1);
    FUN_001c3ea0(param_1,piVar3[0x12]);
    FUN_001c3e10(param_1,uVar4 & 0xffff);
    *(ushort *)piVar3[10] = *(ushort *)(piVar3 + 0xe) << 8 | *(ushort *)(piVar3 + 0xe) >> 8;
    FUN_001ee590(piVar3[7],piVar3[10],(short)piVar3[0xe] + 8);
    lVar2 = FUN_001c3840(param_1);
    if (lVar2 < -1) {
      return lVar2;
    }
    piVar3[0x12] = piVar3[0x12] + uVar4;
    *(undefined1 *)((int)piVar3 + 0xd) = 0x18;
  }
  return 0;
}

