FUNCTION FUN_00001bb4 @ 0x00001bb4 size=96
CALLERS (0): 
CALLEES (4): FUN_000009cc@0x000009cc, FUN_00010aac@0x00010aac, FUN_00000990@0x00000990, FUN_00000ac0@0x00000ac0

undefined * FUN_00001bb4(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 auStack_68 [88];
  
  uVar1 = FUN_00010aac();
  FUN_00000990(auStack_68);
  FUN_000009cc(auStack_68,param_1,uVar1);
  FUN_00000ac0(&DAT_00012f40,auStack_68);
  return &DAT_00012f40;
}


================================================================