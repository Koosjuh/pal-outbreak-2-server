FUNCTION FUN_000008e8 @ 0x000008e8 size=568
CALLERS (1): FUN_00000b9c@0x00000b9c
CALLEES (1): FUN_000021e0@0x000021e0

undefined4 FUN_000008e8(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_000026f8 < 0) {
    uVar1 = 0xfffffffe;
  }
  else {
    DAT_b000002c = 0xe1;
    FUN_000021e0(1);
    DAT_b000002e = 0x80;
    iVar3 = 0;
    FUN_000021e0(1);
    do {
      DAT_b000002e = 0xa0;
      FUN_000021e0(1);
      DAT_b000002e = 0xe0;
      iVar3 = iVar3 + 1;
      FUN_000021e0(1);
    } while (iVar3 < 2);
    iVar3 = 0;
    do {
      DAT_b000002e = 0x80;
      FUN_000021e0(1);
      DAT_b000002e = 0xc0;
      iVar3 = iVar3 + 1;
      FUN_000021e0(1);
    } while (iVar3 < 7);
    DAT_b000002e = 0xc0;
    FUN_000021e0(1);
    if ((DAT_b000002e & 0x10) == 0) {
      FUN_000021e0(1);
      DAT_b000002e = 0x80;
      FUN_000021e0(1);
      iVar4 = 0;
      iVar3 = 2;
      do {
        *(undefined2 *)((int)&DAT_000026f8 + iVar3) = 0;
        uVar2 = 0xf;
        do {
          DAT_b000002e = 0xc0;
          FUN_000021e0(1);
          if ((DAT_b000002e & 0x10) != 0) {
            *(ushort *)((int)&DAT_000026f8 + iVar3) =
                 *(ushort *)((int)&DAT_000026f8 + iVar3) | (ushort)(1 << (uVar2 & 0x1f));
          }
          DAT_b000002e = 0x80;
          FUN_000021e0(1);
          uVar2 = uVar2 - 1;
        } while (-1 < (int)uVar2);
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 2;
      } while (iVar4 < 4);
      DAT_b000002e = 0;
      FUN_000021e0(1);
      uVar1 = 0;
      DAT_000026f8 = 1;
    }
    else {
      FUN_000021e0(1);
      DAT_b000002e = 0;
      FUN_000021e0(1);
      uVar1 = 0xffffffff;
      DAT_000026f8 = 0;
    }
  }
  DAT_b000002c = 1;
  return uVar1;
}


================================================================