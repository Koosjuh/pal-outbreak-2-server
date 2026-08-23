FUNCTION FUN_000009e4 @ 0x000009e4 size=100
CALLERS (0): 
CALLEES (3): FUN_00003c4c@0x00003c4c, FUN_000095cc@0x000095cc, FUN_000095d4@0x000095d4

undefined4 FUN_000009e4(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_000095d4(DAT_0000afe0);
  uVar1 = FUN_00003c4c(param_1);
  FUN_000095cc(DAT_0000afe0);
  return uVar1;
}


================================================================