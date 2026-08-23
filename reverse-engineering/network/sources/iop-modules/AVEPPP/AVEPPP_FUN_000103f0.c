FUNCTION FUN_000103f0 @ 0x000103f0 size=332
CALLERS (0): 
CALLEES (7): FUN_000109c4@0x000109c4, FUN_00010c6c@0x00010c6c, FUN_00010c74@0x00010c74, FUN_00010c38@0x00010c38, FUN_00010c5c@0x00010c5c, FUN_00010c14@0x00010c14, FUN_00010c7c@0x00010c7c

undefined4 FUN_000103f0(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 1;
  DAT_00012efc = 0;
  DAT_00012ef8 = 0;
  if (1 < param_1) {
    do {
      param_2 = param_2 + 1;
      iVar1 = FUN_00010c74(*param_2,"debug",5);
      if (iVar1 == 0) {
        uVar2 = FUN_00010c6c(*param_2);
        if (uVar2 < 7) {
          DAT_00012efc = 1;
        }
        else {
          DAT_00012efc = FUN_00010c7c(*param_2 + 6,0,10);
        }
      }
      iVar1 = FUN_00010c5c(*param_2,"pppoe");
      if (iVar1 == 0) {
        DAT_00012ef8 = 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_1);
  }
  iVar4 = FUN_00010c14(0);
  uVar3 = 1;
  if (iVar4 == 0) {
    FUN_00010c38("AVE-PPP version 0x%04x (%s)\n",0x121,"2002/10/11");
    iVar4 = FUN_000109c4();
    uVar3 = 0;
    if (iVar4 << 0x10 < 0) {
      FUN_00010c38("AVE-PPP internal error. NO_RESIDENT_END\n");
      uVar3 = 1;
    }
  }
  return uVar3;
}


================================================================