FUNCTION FUN_00000318 @ 0x00000318 size=484
CALLERS (0): 
CALLEES (8): FUN_00002190@0x00002190, FUN_00002240@0x00002240, FUN_00002164@0x00002164, FUN_00002238@0x00002238, FUN_00001938@0x00001938, FUN_000002e8@0x000002e8, FUN_00002188@0x00002188, FUN_0000159c@0x0000159c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00000318(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  DAT_00002660 = 1;
  iVar1 = FUN_00002190(*param_2,0x2f);
  DAT_000026a8 = iVar1 + 1;
  if (iVar1 == 0) {
    DAT_000026a8 = *param_2;
  }
  param_1 = param_1 + -1;
  while( true ) {
    if ((param_1 < 1) || (*(char *)param_2[1] != '-')) {
      iVar2 = 0xf;
      iVar1 = 0x3c;
      do {
        *(undefined4 *)((int)&DAT_00002668 + iVar1) = 0;
        iVar2 = iVar2 + -1;
        iVar1 = iVar1 + -4;
      } while (-1 < iVar2);
      if ((_DAT_bf80146e & 0xf0) == 0x20) {
        DAT_000025c8 = 0;
        FUN_00002164("dev9: CXD9566 detected.\n");
        iVar1 = FUN_0000159c(&DAT_00002660);
      }
      else if ((_DAT_bf80146e & 0xf0) == 0x30) {
        DAT_000025c8 = 1;
        FUN_00002164("dev9: CXD9611 detected.\n");
        iVar1 = FUN_00001938(&DAT_00002660);
      }
      else {
        iVar1 = 1;
        FUN_00002164("dev9: unknown dev9 hardware.\n");
      }
      if (iVar1 == 0) {
        FUN_00002240("dev9x");
        iVar2 = FUN_00002238(&PTR_s_dev9x_0000263c);
        if (iVar2 != 0) {
          iVar1 = 1;
        }
      }
      return iVar1;
    }
    iVar1 = FUN_00002188(&DAT_000022f8);
    if ((iVar1 != 0) || (param_2 = param_2 + 2, param_1 + -1 < 1)) break;
    iVar1 = FUN_00002188("SA_THFIFO",*param_2);
    if (iVar1 == 0) {
      DAT_00002660 = 0;
    }
    param_1 = param_1 + -2;
  }
  iVar1 = FUN_000002e8();
  return iVar1;
}


================================================================