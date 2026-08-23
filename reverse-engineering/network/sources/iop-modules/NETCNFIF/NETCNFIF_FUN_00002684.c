FUNCTION FUN_00002684 @ 0x00002684 size=100
CALLERS (0): 
CALLEES (1): FUN_0000283c@0x0000283c

undefined4 FUN_00002684(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_00006448 = param_1;
  iVar1 = FUN_0000283c(&DAT_00006420,0xe,0,&DAT_00006448,0x40,&DAT_00006448,0x40,0,0);
  uVar2 = 0xffffffff;
  if (-1 < iVar1) {
    uVar2 = DAT_00006448;
  }
  return uVar2;
}


================================================================