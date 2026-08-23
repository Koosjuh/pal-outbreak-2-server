FUNCTION FUN_0000075c @ 0x0000075c size=296
CALLERS (20): FUN_00004550@0x00004550, FUN_0000f9f4@0x0000f9f4, FUN_00006aec@0x00006aec, FUN_0000b5cc@0x0000b5cc, FUN_0000d108@0x0000d108, FUN_00008f3c@0x00008f3c, FUN_00003bb4@0x00003bb4, FUN_00008fac@0x00008fac, FUN_0000c298@0x0000c298, FUN_0000ce44@0x0000ce44, FUN_0000b8d0@0x0000b8d0, FUN_0000c5a0@0x0000c5a0, FUN_0000ad1c@0x0000ad1c, FUN_0000dcfc@0x0000dcfc, FUN_0000efbc@0x0000efbc, FUN_000067bc@0x000067bc, FUN_0000e730@0x0000e730, FUN_0000a9c0@0x0000a9c0, FUN_000002f8@0x000002f8, FUN_0000dfdc@0x0000dfdc
CALLEES (1): FUN_00010b3c@0x00010b3c

int FUN_0000075c(undefined4 *param_1,undefined1 *param_2,ushort param_3)

{
  int iVar1;
  short sVar2;
  ushort uVar3;
  int *piVar4;
  short sVar5;
  
  sVar5 = 0;
  iVar1 = 0;
  if (param_1 != (undefined4 *)0x0) {
    while ((param_3 != 0 && (piVar4 = (int *)*param_1, piVar4 != (int *)0x0))) {
      uVar3 = *(ushort *)(piVar4 + 1);
      if (param_3 < *(ushort *)(piVar4 + 1)) {
        uVar3 = param_3;
      }
      if (param_2 != (undefined1 *)0x0) {
        if (uVar3 == 1) {
          *param_2 = *(undefined1 *)*piVar4;
        }
        else if (1 < (short)uVar3) {
          FUN_00010b3c(param_2,*piVar4);
        }
        param_2 = param_2 + (short)uVar3;
      }
      sVar5 = sVar5 + uVar3;
      param_3 = param_3 - uVar3;
      sVar2 = (short)piVar4[1] - uVar3;
      *(short *)(piVar4 + 1) = sVar2;
      *piVar4 = *piVar4 + (int)(short)uVar3;
      if (sVar2 == 0) {
        param_3 = 0;
      }
    }
    iVar1 = (int)sVar5;
  }
  return iVar1;
}


================================================================