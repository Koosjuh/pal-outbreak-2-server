FUNCTION FUN_0000cf80 @ 0x0000cf80 size=132
CALLERS (1): FUN_0000fb74@0x0000fb74
CALLEES (1): FUN_0000e08c@0x0000e08c

undefined4 FUN_0000cf80(short param_1,undefined4 param_2,undefined2 param_3)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  
  sVar1 = FUN_0000e08c((int)param_1);
  uVar2 = 0xfffffffc;
  if (sVar1 == 0) {
    uVar2 = 0;
    iVar3 = DAT_00016180 + param_1 * 0x17c;
    *(undefined4 *)(iVar3 + 0x158) = param_2;
    *(undefined2 *)(iVar3 + 0x146) = param_3;
    *(undefined2 *)(iVar3 + 0x13a) = 1;
  }
  return uVar2;
}


================================================================