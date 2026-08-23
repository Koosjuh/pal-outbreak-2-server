FUNCTION FUN_00017f30 @ 0x00017f30 size=284
CALLERS (2): FUN_0001866c@0x0001866c, FUN_00018cd0@0x00018cd0
CALLEES (2): FUN_00017da0@0x00017da0, FUN_00006ea8@0x00006ea8

int FUN_00017f30(int param_1,int param_2,short param_3,int param_4,short param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_0001b9b8;
  do {
    if (iVar2 == 0) {
      iVar2 = FUN_00017da0(param_2,param_3,param_4,param_5);
      return iVar2;
    }
    if ((((param_2 == *(int *)(iVar2 + 0x18)) || (*(int *)(iVar2 + 0x18) == 0)) &&
        ((param_3 == *(short *)(iVar2 + 0x1e) || (*(short *)(iVar2 + 0x1e) == 0)))) &&
       (((param_4 == *(int *)(iVar2 + 0x14) || (*(int *)(iVar2 + 0x14) == 0)) ||
        ((param_1 != 0 && (iVar1 = FUN_00006ea8(param_1), iVar1 != 0)))))) {
      if (param_5 == *(short *)(iVar2 + 0x1c)) {
        return iVar2;
      }
      if (*(short *)(iVar2 + 0x1c) == 0) {
        return iVar2;
      }
    }
    iVar2 = *(int *)(iVar2 + 4);
  } while( true );
}


================================================================