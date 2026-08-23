FUNCTION FUN_000140cc @ 0x000140cc size=276
CALLERS (1): FUN_00014bec@0x00014bec
CALLEES (2): FUN_0001285c@0x0001285c, FUN_00014e24@0x00014e24

undefined4 FUN_000140cc(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  DAT_00016fa4 = 1;
  if ((DAT_00016178 & 0x40) != 0) {
    FUN_00014e24("DNS_Initialize() ticket max %d\n",1);
  }
  iVar3 = 0;
  if (0 < (int)((uint)DAT_00016fa4 << 0x10)) {
    iVar2 = 0;
    do {
      uVar1 = DAT_00016fa4;
      iVar3 = iVar3 + 1;
      *(undefined4 *)((int)&DAT_00016fa0 + iVar2) = 0;
      iVar2 = iVar3 * 4;
    } while (iVar3 < (short)uVar1);
  }
  DAT_00016fa8 = 0;
  if (param_1 != 0) {
    FUN_0001285c(&DAT_00016fa8,param_1);
  }
  DAT_00017bb0 = 0;
  if (param_2 != 0) {
    DAT_00017bb0 = 1;
    DAT_00017ba8 = param_2;
    if (param_3 != 0) {
      DAT_00017bb0 = 2;
      DAT_00017bac = param_3;
    }
  }
  DAT_00017bb4 = 0;
  return 0;
}


================================================================