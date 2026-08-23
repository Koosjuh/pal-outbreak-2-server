FUNCTION FUN_00618e30 @ 0x00618e30  size=828
CALLERS (2): FUN_00619220@0x00619220, FUN_00618c90@0x00618c90
CALLEES (2): FUN_006381e0@0x006381e0, FUN_00637f90@0x00637f90
----------------------------------------------------------------

void FUN_00618e30(int param_1)

{
  char cVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  ushort uVar6;
  ushort uVar7;
  short sVar8;
  short sVar9;
  char *pcVar10;
  short sStack_30;
  short sStack_2e;
  short sStack_2c;
  short sStack_2a;
  uint uStack_28;
  short sStack_24;
  short sStack_22;
  short sStack_20;
  short sStack_1e;
  short sStack_10;
  short sStack_e;
  short sStack_c;
  short sStack_a;
  uint uStack_8;
  undefined4 uStack_4;
  
  pcVar10 = (&PTR_DAT_0066fdd0)[*(ushort *)(param_1 + 0x22)];
  do {
    if ((*(ushort *)(pcVar10 + 2) & 0x2000) == 0) {
      func_0x001a7b70(0x5e,0x32);
      uVar6 = *(ushort *)(pcVar10 + 2);
    }
    else {
      func_0x001a7b70(0x5e,0x12);
      uVar6 = *(ushort *)(pcVar10 + 2);
    }
    uVar7 = uVar6 ^ *(ushort *)(param_1 + 0x24);
    if ((uVar7 & 0x400) == 0) {
      sVar2 = *(short *)(pcVar10 + 0x12);
      sVar8 = *(short *)(pcVar10 + 0xe);
      sVar9 = *(short *)(pcVar10 + 0xc);
      sVar3 = *(short *)(pcVar10 + 0x10);
    }
    else {
      sVar3 = *(short *)(param_1 + 0x44);
      sVar2 = *(short *)(param_1 + 0x46);
      sVar8 = *(short *)(param_1 + 0x42);
      sVar9 = *(short *)(param_1 + 0x40);
    }
    if ((uVar7 & 0x200) == 0) {
      sVar4 = *(short *)(pcVar10 + 10);
      sVar5 = *(short *)(pcVar10 + 8);
    }
    else {
      sVar5 = *(short *)(param_1 + 0x3c);
      sVar4 = *(short *)(param_1 + 0x3e);
    }
    if ((uVar6 & 0x800) == 0) {
      uStack_4 = func_0x001cbcb0((byte)pcVar10[1] + 0x4000);
      func_0x00194050(1,&uStack_4);
      func_0x001a7b70(4,uStack_4);
      sStack_30 = *(short *)(param_1 + 0x26) + *(short *)(pcVar10 + 4);
      sStack_2e = *(short *)(param_1 + 0x28) + *(short *)(pcVar10 + 6);
      if ((*(ushort *)(param_1 + 0x24) & 0x80) == 0) {
        uStack_28 = (uint)((ulong)((long)*(int *)(param_1 + 0x2c) << 0x28) >> 0x28) | 0xff000000;
      }
      else {
        uStack_28 = *(uint *)(param_1 + 0x2c);
      }
      uVar6 = *(ushort *)(param_1 + 0x24) ^ *(ushort *)(pcVar10 + 2);
      if ((uVar6 & 0x4000) == 0) {
        sStack_20 = sVar9 + sVar3 + -1;
        sStack_24 = sVar9;
      }
      else {
        sStack_24 = sVar9 + sVar3 + -1;
        sStack_20 = sVar9;
      }
      if ((uVar6 & 0x8000) == 0) {
        sStack_1e = sVar8 + sVar2 + -1;
        sStack_22 = sVar8;
      }
      else {
        sStack_22 = sVar8 + sVar2 + -1;
        sStack_1e = sVar8;
      }
      sStack_2c = sVar5;
      sStack_2a = sVar4;
      if ((*(ushort *)(pcVar10 + 2) & 0x1000) == 0) {
        func_0x001a7b70(0x6c,1);
        FUN_00637f90(&sStack_30,*(undefined4 *)(param_1 + 0x34));
        goto LAB_0061912c;
      }
      func_0x001a7b70(0x6c,0);
      func_0x0018aa50(&sStack_30);
      cVar1 = *pcVar10;
    }
    else {
      func_0x001a7b70(0x6c,1);
      sStack_10 = *(short *)(param_1 + 0x26) + *(short *)(pcVar10 + 4);
      sStack_e = *(short *)(param_1 + 0x28) + *(short *)(pcVar10 + 6);
      sStack_c = sStack_10 + sVar5;
      sStack_a = sStack_e + sVar4;
      if ((*(ushort *)(pcVar10 + 2) & 0x100) == 0) {
        uStack_8 = *(uint *)(param_1 + 0x2c);
      }
      else {
        uStack_8 = (int)*(short *)(pcVar10 + 0x10) |
                   (int)*(short *)(pcVar10 + 0xe) << 8 |
                   (int)*(short *)(pcVar10 + 0x12) << 0x18 | (int)*(short *)(pcVar10 + 0xc) << 0x10;
      }
      FUN_006381e0(&sStack_10,*(undefined4 *)(param_1 + 0x34));
LAB_0061912c:
      cVar1 = *pcVar10;
    }
    if (cVar1 == '\0') {
      return;
    }
    pcVar10 = pcVar10 + 0x14;
  } while( true );
}



================================================================