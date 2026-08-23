FUNCTION FUN_00003288 @ 0x00003288 size=164
CALLERS (0): 
CALLEES (2): FUN_00000148@0x00000148, FUN_00000104@0x00000104

undefined4 FUN_00003288(int param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  FUN_00000104();
  piVar1 = (int *)DAT_000046ec;
  do {
    if (piVar1 == (int *)0x0) {
LAB_00003300:
      FUN_00000148();
      return uVar2;
    }
    if (param_1 == piVar1[2]) {
      uVar2 = 0;
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = piVar1[4];
      }
      goto LAB_00003300;
    }
    piVar1 = (int *)*piVar1;
  } while( true );
}


================================================================