FUNCTION FUN_000041a0 @ 0x000041a0 size=944
CALLERS (1): FUN_00010108@0x00010108
CALLEES (5): FUN_00004550@0x00004550, FUN_00010bc8@0x00010bc8, FUN_00000710@0x00000710, FUN_00010bd8@0x00010bd8, FUN_0000071c@0x0000071c

undefined4 FUN_000041a0(void)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  ushort uVar6;
  ushort local_20 [4];
  
  if (DAT_00012ef8 == 0) {
    if (DAT_000133f8 == (byte *)0x0) {
      DAT_000132e0 = 0xffff;
      DAT_000132f0 = (int *)0x0;
      DAT_000132e4 = 0;
      DAT_000133f8 = &DAT_000132f8;
      DAT_000133fc = &DAT_000132f8;
    }
    while( true ) {
      while( true ) {
        if (DAT_000133f8 == DAT_000133fc) {
          iVar3 = FUN_00010bc8(0x100,&DAT_000132f8,local_20);
          if ((iVar3 != 0) || (local_20[0] == 0)) {
            if (DAT_00012ecc == 3) goto LAB_0000450c;
            goto LAB_000044f8;
          }
          DAT_000133f8 = &DAT_000132f8;
          DAT_000133fc = &DAT_000132f8 + local_20[0];
        }
        uVar5 = (uint)*DAT_000133f8;
        DAT_000133f8 = DAT_000133f8 + 1;
        if (uVar5 == 0x7e) break;
        if (uVar5 == 0x7d) {
          DAT_000132e4 = DAT_000132e4 | 1;
        }
        else {
          if (DAT_000132f0 == (int *)0x0) {
            DAT_000132f0 = &DAT_00019abc;
            DAT_00019ac0 = 0;
            DAT_000132e4 = 0;
            DAT_000132e0 = 0xffff;
            DAT_00019abc = (int)&DAT_00019abc + (DAT_00016fc0 + 0x83U & 0xfffffffc);
          }
          if ((DAT_000132e4 & 1) != 0) {
            DAT_000132e4 = DAT_000132e4 & 0xfffffffe;
            uVar5 = uVar5 ^ 0x20;
          }
          uVar6 = *(ushort *)(DAT_000132f0 + 1);
          if (uVar6 < 0x800) {
            iVar3 = *DAT_000132f0;
            *(ushort *)(DAT_000132f0 + 1) = uVar6 + 1;
            *(char *)(iVar3 + (uint)uVar6) = (char)uVar5;
            DAT_000132e0 = *(ushort *)(&DAT_00010c90 + ((uVar5 ^ DAT_000132e0) & 0xff) * 2) ^
                           DAT_000132e0 >> 8;
          }
        }
      }
      if (((DAT_000132f0 != (int *)0x0) && (*(ushort *)(DAT_000132f0 + 1) < 0x800)) &&
         (DAT_000132e0 == 0xf0b8)) break;
      DAT_000132f0 = (int *)0x0;
    }
    sVar2 = FUN_00000710();
    FUN_0000071c(&DAT_000132f0,sVar2 + -2);
    FUN_00004550(DAT_000132f0);
    DAT_000132f0 = (int *)0x0;
    uVar4 = 1;
  }
  else {
    do {
      DAT_000132f0 = &DAT_00019abc;
      DAT_00019ac0 = 0;
      DAT_00019abc = (int)&DAT_00019abc + (DAT_00016fc0 + 0x83U & 0xfffffffc);
      iVar3 = FUN_00010bc8(0x5d6,DAT_00019abc,&DAT_00019ac0);
      if ((iVar3 != 0) || ((short)DAT_000132f0[1] == 0)) break;
      bVar1 = *(byte *)*DAT_000132f0;
      uVar6 = (ushort)bVar1;
      if ((bVar1 & 1) == 0) {
        uVar6 = CONCAT11(bVar1,((byte *)*DAT_000132f0)[1]);
      }
      FUN_00004550();
    } while (((uVar6 == 0x21) || (uVar6 == 0x2d)) || (uVar6 == 0x2f));
LAB_000044f8:
    uVar4 = 0;
    if (DAT_00012ecc == 4) {
LAB_0000450c:
      sVar2 = FUN_00010bd8();
      uVar4 = 0;
      if (sVar2 == 0) {
        DAT_00012ecc = 5;
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}


================================================================