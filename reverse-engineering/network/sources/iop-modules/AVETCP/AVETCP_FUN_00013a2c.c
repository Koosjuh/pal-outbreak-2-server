FUNCTION FUN_00013a2c @ 0x00013a2c size=92
CALLERS (1): FUN_00014818@0x00014818
CALLEES (0): 

void FUN_00013a2c(byte *param_1,byte *param_2)

{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  
  uVar2 = 0;
  sVar3 = 0;
  do {
    bVar1 = uVar2 == 0;
    uVar2 = uVar2 - 1;
    if (bVar1) {
      uVar2 = (ushort)*param_2;
      if (uVar2 == 0) {
        *param_1 = 0;
        return;
      }
      if (sVar3 != 0) {
        *param_1 = 0x2e;
        goto LAB_00013a7c;
      }
    }
    else {
      *param_1 = *param_2;
LAB_00013a7c:
      param_1 = param_1 + 1;
    }
    param_2 = param_2 + 1;
    sVar3 = sVar3 + 1;
  } while( true );
}


================================================================