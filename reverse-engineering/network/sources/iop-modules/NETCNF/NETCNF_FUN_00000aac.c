FUNCTION FUN_00000aac @ 0x00000aac size=120
CALLERS (0): 
CALLEES (3): FUN_00009650@0x00009650, FUN_00009640@0x00009640, FUN_00008050@0x00008050

int FUN_00000aac(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_00008050();
  iVar3 = iVar1;
  if (iVar1 == 0) {
    iVar2 = FUN_00009650(param_1);
    iVar3 = -0x13;
    if (iVar2 + 1U <= param_3) {
      FUN_00009640(param_2,param_1);
      iVar3 = iVar1;
    }
  }
  return iVar3;
}


================================================================