FUNCTION FUN_0000daec @ 0x0000daec size=136
CALLERS (0): 
CALLEES (2): FUN_0000a79c@0x0000a79c, FUN_00008bf0@0x00008bf0

int FUN_0000daec(short param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_00016180 + param_1 * 0x17c;
  if ((*(short *)(iVar3 + 0x13a) < 6) || (iVar2 = -10, (*(byte *)(iVar3 + 0x13e) & 8) == 0)) {
    FUN_00008bf0(param_2,iVar3);
    sVar1 = FUN_0000a79c(iVar3);
    iVar2 = (int)sVar1;
  }
  return iVar2;
}


================================================================