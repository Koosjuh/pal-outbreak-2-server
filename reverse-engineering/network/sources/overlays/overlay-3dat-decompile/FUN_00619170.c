FUNCTION FUN_00619170 @ 0x00619170  size=172
CALLERS (1): FUN_00618c90@0x00618c90
CALLEES (1): FUN_006381e0@0x006381e0
----------------------------------------------------------------

void FUN_00619170(void)

{
  char *pcVar1;
  short sStack_10;
  short sStack_e;
  short sStack_c;
  short sStack_a;
  undefined4 uStack_8;
  
  pcVar1 = PTR_DAT_0066fe64;
  while( true ) {
    if ((*(ushort *)(pcVar1 + 2) & 0x2000) == 0) {
      func_0x001a7b70(0x5e,0x32);
      sStack_10 = *(short *)(pcVar1 + 4);
    }
    else {
      func_0x001a7b70(0x5e,0x12);
      sStack_10 = *(short *)(pcVar1 + 4);
    }
    sStack_e = *(short *)(pcVar1 + 6);
    sStack_c = sStack_10 + *(short *)(pcVar1 + 8);
    sStack_a = sStack_e + *(short *)(pcVar1 + 10);
    uStack_8 = 0xff000000;
    FUN_006381e0(&sStack_10,0xffffffffffffffe2);
    if (*pcVar1 == '\0') break;
    pcVar1 = pcVar1 + 0x14;
  }
  return;
}



================================================================