FUNCTION FUN_00011e5c @ 0x00011e5c size=200
CALLERS (0): 
CALLEES (0): 

undefined4 FUN_00011e5c(undefined4 *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = (int *)DAT_0001b85c;
  if (DAT_0001b880 == (undefined4 *)0x0) {
    DAT_0001b880 = param_1;
    param_1[5] = FUN_00011e2c;
    for (; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
      if ((piVar4[0x12] & 0x200U) != 0) {
        iVar3 = piVar4[0x6d];
        piVar4[0x6d] = 0;
        while (bVar1 = 0 < iVar3, iVar3 = iVar3 + -1, bVar1) {
          (*(code *)*DAT_0001b880)(piVar4);
        }
      }
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffe0a;
  }
  return uVar2;
}


================================================================