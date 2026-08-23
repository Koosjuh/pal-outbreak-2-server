FUNCTION FUN_005d6810 @ 0x005d6810  size=36
CALLERS (4): FUN_005d71e0@0x005d71e0, FUN_005d6920@0x005d6920, FUN_005d8840@0x005d8840, FUN_005d72d0@0x005d72d0
CALLEES (0): 
----------------------------------------------------------------

int * FUN_005d6810(undefined8 param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)*param_2;
  piVar2 = param_2;
  if ((piVar1 != (int *)0x0) && (piVar2 = piVar1, piVar1[0x41] == 0)) {
    piVar2 = param_2;
  }
  return piVar2;
}



================================================================