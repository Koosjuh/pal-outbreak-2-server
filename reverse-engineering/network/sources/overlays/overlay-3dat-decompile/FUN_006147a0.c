FUNCTION FUN_006147a0 @ 0x006147a0  size=180
CALLERS (7): FUN_00612ca0@0x00612ca0, FUN_00613e70@0x00613e70, FUN_00613f40@0x00613f40, FUN_00614600@0x00614600, FUN_00613da0@0x00613da0, FUN_00613fb0@0x00613fb0, FUN_00612fd0@0x00612fd0
CALLEES (0): 
----------------------------------------------------------------

undefined2 FUN_006147a0(byte *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar3 = 0;
  for (iVar4 = 0; iVar4 < 0x200; iVar4 = iVar4 + 1) {
    bVar1 = *param_1;
    if (bVar1 == 0) break;
    if (bVar1 < 0xf0) {
      if (bVar1 < 0xe0) {
        if (bVar1 < 0xc0) {
          iVar2 = iVar2 + 1;
        }
        else {
          param_1 = param_1 + 1;
          iVar2 = iVar2 + 1;
        }
      }
      else {
        param_1 = param_1 + 2;
        iVar3 = iVar3 + 1;
      }
    }
    else {
      param_1 = param_1 + 3;
      iVar3 = iVar3 + 1;
    }
    param_1 = param_1 + 1;
  }
  iVar2 = param_2 * iVar2;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 1;
  }
  iVar2 = (0x280 - param_2 * iVar3) - (iVar2 >> 1);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 1;
  }
  return (short)(iVar2 >> 1);
}



================================================================
FUNCTION thunk_EXT_FUN_001ae3e0 @ 0x00614860  size=8
CALLERS (1): FUN_00613600@0x00613600
CALLEES (0): 
----------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thunk_EXT_FUN_001ae3e0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



================================================================