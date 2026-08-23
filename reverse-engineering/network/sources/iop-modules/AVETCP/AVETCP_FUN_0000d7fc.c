FUNCTION FUN_0000d7fc @ 0x0000d7fc size=136
CALLERS (1): FUN_00010130@0x00010130
CALLEES (1): FUN_0000e08c@0x0000e08c

undefined4 FUN_0000d7fc(short param_1,undefined4 *param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  
  sVar1 = FUN_0000e08c((int)param_1);
  uVar2 = 0xfffffffc;
  if (sVar1 == 0) {
    iVar3 = DAT_00016180 + param_1 * 0x17c;
    *param_2 = *(undefined4 *)(iVar3 + 0x158);
    *(undefined2 *)(param_2 + 1) = *(undefined2 *)(iVar3 + 0x144);
    uVar2 = 0;
    *(undefined2 *)((int)param_2 + 6) = *(undefined2 *)(iVar3 + 0x146);
  }
  return uVar2;
}


================================================================