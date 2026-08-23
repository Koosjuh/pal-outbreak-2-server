FUNCTION FUN_00001804 @ 0x00001804 size=332
CALLERS (0): 
CALLEES (11): FUN_00002724@0x00002724, FUN_0000819c@0x0000819c, FUN_000081bc@0x000081bc, FUN_00002124@0x00002124, FUN_00002614@0x00002614, FUN_000016e0@0x000016e0, FUN_00002360@0x00002360, FUN_00001778@0x00001778, FUN_000014d4@0x000014d4, FUN_0000810c@0x0000810c, FUN_00001d54@0x00001d54

void FUN_00001804(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 local_18;
  int local_14;
  
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_00008380);
    FUN_0000810c("modem(%d) event thread start\n",param_1);
  }
  iVar1 = FUN_00001d54(param_1);
  if (iVar1 == 0) {
    while( true ) {
      uVar2 = FUN_00002360(param_1);
      if ((int)uVar2 < 0) break;
      if (((uVar2 & 1) != 0) && (iVar1 = FUN_00002724(param_1,&DAT_0000d980,0x200), 0 < iVar1)) {
        FUN_000014d4(&DAT_0000d958,&DAT_0000d980,iVar1);
      }
      FUN_000016e0(&DAT_0000d940,&local_18,&local_14);
      if ((0 < local_14) && (iVar1 = FUN_00002614(param_1,local_18), -1 < iVar1)) {
        local_14 = iVar1;
        FUN_00001778(&DAT_0000d940,iVar1);
      }
      FUN_000081bc(10000);
    }
  }
  FUN_00002124(param_1);
  if ((DAT_00009710 & 1) != 0) {
    FUN_0000810c(&PTR_DAT_00008380);
    FUN_0000810c("modem(%d) event thread terminate\n",param_1);
  }
  FUN_0000819c();
  return;
}


================================================================