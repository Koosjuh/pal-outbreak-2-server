FUNCTION FUN_005bf0e0 @ 0x005bf0e0  size=72
CALLERS (5): FUN_005bfd80@0x005bfd80, FUN_005c0e30@0x005c0e30, FUN_005c04f0@0x005c04f0, FUN_005bfa70@0x005bfa70, FUN_005c0400@0x005c0400
CALLEES (0): 
----------------------------------------------------------------

void FUN_005bf0e0(char param_1,undefined1 param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  
  uVar1 = uRam006ce5c4;
  uVar2 = uRam006ce5c5;
  uVar3 = param_2;
  if (((param_1 != '\x02') && (uVar2 = param_2, uVar3 = uRam006ce5c6, param_1 != '\x01')) &&
     (uVar1 = param_2, uVar2 = uRam006ce5c5, param_1 != '\0')) {
    uVar1 = uRam006ce5c4;
  }
  uRam006ce5c6 = uVar3;
  uRam006ce5c5 = uVar2;
  uRam006ce5c4 = uVar1;
  return;
}



================================================================