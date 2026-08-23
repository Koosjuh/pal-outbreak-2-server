FUNCTION FUN_0000ce24 @ 0x0000ce24 size=100
CALLERS (1): FUN_0000ff18@0x0000ff18
CALLEES (1): FUN_0001168c@0x0001168c

undefined4 FUN_0000ce24(short param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_00016180 + param_1 * 0x17c;
  *(undefined4 *)(iVar1 + 0x164) = 0;
  if (param_2 != 0) {
    FUN_0001168c((int)param_1,*(undefined4 *)(iVar1 + 0x168),3,0xff);
    *(undefined2 *)(iVar1 + 0x138) = 0;
  }
  return 0;
}


================================================================