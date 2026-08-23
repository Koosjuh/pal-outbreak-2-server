FUNCTION FUN_00006b50 @ 0x00006b50 size=116
CALLERS (5): FUN_00005798@0x00005798, FUN_00005888@0x00005888, FUN_00006c1c@0x00006c1c, FUN_0000678c@0x0000678c, FUN_000076f4@0x000076f4
CALLEES (2): FUN_00007b48@0x00007b48, FUN_00007d78@0x00007d78

int FUN_00006b50(int param_1,undefined2 param_2)

{
  short sVar1;
  
  if (((DAT_00009710 & 2) != 0) && (*(short *)(param_1 + 0xc) == 0x6388)) {
    FUN_00007d78("+--- send ------------------------------------+\n",param_1,param_2);
  }
  sVar1 = FUN_00007b48(param_1,param_2);
  return (int)sVar1;
}


================================================================