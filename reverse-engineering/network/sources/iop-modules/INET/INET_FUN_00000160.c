FUNCTION FUN_00000160 @ 0x00000160 size=216
CALLERS (1): FUN_0000029c@0x0000029c
CALLEES (4): FUN_0000ae24@0x0000ae24, FUN_00000000@0x00000000, FUN_0000a60c@0x0000a60c, FUN_00011d90@0x00011d90

int * FUN_00000160(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  DAT_0001b958 = DAT_0001b958 + 1;
  if (0x100 < DAT_0001b958) {
    FUN_00000000(DAT_0001b954);
  }
  piVar2 = (int *)FUN_0000a60c(0x30);
  if (piVar2 == (int *)0x0) {
    if ((DAT_0001b850 & 1) != 0) {
      FUN_00011d90("# ERR # %s:%d: %s\n",s_arp_c_0001b3f8,0x5c,"arp_add - no space");
    }
  }
  else {
    FUN_0000ae24(piVar2,0x30);
    piVar2[4] = param_2;
    *piVar2 = (int)DAT_0001b950;
    piVar1 = piVar2;
    if (DAT_0001b950 != (int *)0x0) {
      DAT_0001b950[1] = (int)piVar2;
      piVar1 = DAT_0001b954;
    }
    DAT_0001b954 = piVar1;
    piVar2[1] = 0;
    DAT_0001b950 = piVar2;
    piVar2[0xb] = param_1;
  }
  return piVar2;
}


================================================================