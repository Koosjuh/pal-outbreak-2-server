FUNCTION FUN_00002b0c @ 0x00002b0c size=160
CALLERS (0): 
CALLEES (1): FUN_0000810c@0x0000810c

void FUN_00002b0c(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar1 = (&DAT_00009718)[iVar3];
    if ((iVar1 != 0) &&
       (uVar2 = (**(code **)(iVar1 + 0x4c))(*(undefined4 *)(iVar1 + 0x38),0),
       (DAT_00009710 & 1) != 0)) {
      FUN_0000810c(&PTR_DAT_000083f0);
      FUN_0000810c("mdmifTerm device[%d] stop() = %d\n",iVar3,uVar2);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  return;
}


================================================================