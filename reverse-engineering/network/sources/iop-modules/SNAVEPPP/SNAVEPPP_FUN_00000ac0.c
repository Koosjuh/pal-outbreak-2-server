FUNCTION FUN_00000ac0 @ 0x00000ac0 size=160
CALLERS (3): FUN_00006aec@0x00006aec, FUN_00001bb4@0x00001bb4, FUN_000067bc@0x000067bc
CALLEES (3): FUN_000009cc@0x000009cc, FUN_00001b8c@0x00001b8c, FUN_00001ab4@0x00001ab4

void FUN_00000ac0(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_18 [8];
  
  FUN_00001ab4(auStack_18,param_2 + 0x10,8);
  uVar2 = *(uint *)(param_2 + 0x10) >> 3 & 0x3f;
  iVar1 = 0x38;
  if (0x37 < uVar2) {
    iVar1 = 0x78;
  }
  FUN_000009cc(param_2,&DAT_00010e90,iVar1 - uVar2);
  FUN_000009cc(param_2,auStack_18,8);
  FUN_00001ab4(param_1,param_2,0x10);
  FUN_00001b8c(param_2,0,0x58);
  return;
}


================================================================