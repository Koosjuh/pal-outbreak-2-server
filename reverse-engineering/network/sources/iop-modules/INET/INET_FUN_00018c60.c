FUNCTION FUN_00018c60 @ 0x00018c60 size=112
CALLERS (1): FUN_00018cd0@0x00018cd0
CALLEES (0): 

ushort FUN_00018c60(void)

{
  int iVar1;
  ushort uVar2;
  
  uVar2 = DAT_0001b9c0;
  do {
    DAT_0001b9c0 = uVar2;
    iVar1 = DAT_0001b9b8;
    if (DAT_0001b9c0 < 5000) {
      DAT_0001b9c0 = 5000;
    }
    while( true ) {
      uVar2 = DAT_0001b9c0;
      if (iVar1 == 0) {
        DAT_0001b9c0 = DAT_0001b9c0 + 1;
        return uVar2;
      }
      uVar2 = DAT_0001b9c0 + 1;
      if (DAT_0001b9c0 == *(ushort *)(iVar1 + 0x1e)) break;
      iVar1 = *(int *)(iVar1 + 4);
    }
  } while( true );
}


================================================================