FUNCTION FUN_000017dc @ 0x000017dc size=80
CALLERS (1): FUN_00001a20@0x00001a20
CALLEES (0): 

undefined4 FUN_000017dc(char *param_1)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  
  cVar2 = *param_1;
  uVar3 = 0;
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    if ((cVar2 != '.') && (cVar2 != '0')) {
      uVar3 = 1;
    }
    param_1 = param_1 + 1;
    cVar2 = *param_1;
    cVar1 = *param_1;
  }
  return uVar3;
}


================================================================