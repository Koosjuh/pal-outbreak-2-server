FUNCTION FUN_00015cfc @ 0x00015cfc size=112
CALLERS (1): FUN_00015d6c@0x00015d6c
CALLEES (0): 

ushort FUN_00015cfc(void)

{
  int iVar1;
  ushort uVar2;
  
  uVar2 = DAT_0001b9ac;
  do {
    DAT_0001b9ac = uVar2;
    iVar1 = DAT_0001b9a0;
    if (DAT_0001b9ac < 5000) {
      DAT_0001b9ac = 5000;
    }
    while( true ) {
      uVar2 = DAT_0001b9ac;
      if (iVar1 == 0) {
        DAT_0001b9ac = DAT_0001b9ac + 1;
        return uVar2;
      }
      uVar2 = DAT_0001b9ac + 1;
      if (DAT_0001b9ac == *(ushort *)(iVar1 + 0x1a)) break;
      iVar1 = *(int *)(iVar1 + 4);
    }
  } while( true );
}


================================================================