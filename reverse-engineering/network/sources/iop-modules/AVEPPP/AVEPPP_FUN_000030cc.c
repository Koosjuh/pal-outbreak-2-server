FUNCTION FUN_000030cc @ 0x000030cc size=200
CALLERS (1): FUN_00003084@0x00003084
CALLEES (5): FUN_0001073c@0x0001073c, FUN_00010b3c@0x00010b3c, FUN_00010b7c@0x00010b7c, FUN_0000402c@0x0000402c, FUN_00010764@0x00010764

undefined4 FUN_000030cc(int param_1,short param_2)

{
  undefined4 uVar1;
  
  FUN_0001073c();
  if (DAT_00012ecc == 4) {
    uVar1 = 0;
    DAT_00018210 = param_2 + -0xe;
    DAT_0001820c = (int)&DAT_0001820c + (DAT_00016fc0 + 0x83U & 0xfffffffc);
    FUN_00010b3c(DAT_0001820c,param_1 + 0xe,DAT_00018210);
    FUN_00010b7c(0,param_1,0);
    FUN_0000402c(&DAT_0001820c);
  }
  else {
    FUN_00010b7c(0,param_1,0);
    uVar1 = 0xffffffff;
  }
  FUN_00010764();
  return uVar1;
}


================================================================