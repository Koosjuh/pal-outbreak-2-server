FUNCTION FUN_0000ce44 @ 0x0000ce44 size=292
CALLERS (0): 
CALLEES (3): FUN_0000c54c@0x0000c54c, FUN_0000075c@0x0000075c, FUN_00000710@0x00000710

undefined4 FUN_0000ce44(int param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  short sVar2;
  undefined4 uVar3;
  ushort uVar4;
  ushort uVar5;
  undefined4 local_res8 [2];
  undefined4 local_20 [2];
  
  bVar1 = false;
  if (*(char *)(param_2 + 1) == *(char *)(param_1 + 1)) {
    local_res8[0] = param_3;
    local_20[0] = FUN_0000c54c();
    sVar2 = FUN_00000710();
    if (*(short *)(param_2 + 2) == sVar2) {
      do {
        sVar2 = FUN_0000075c(local_20,&DAT_00013674,1);
        uVar4 = 0xffff;
        if (sVar2 == 1) {
          uVar4 = (ushort)DAT_00013674;
        }
        if (uVar4 == 0xffff) goto LAB_0000cf38;
        sVar2 = FUN_0000075c(local_res8,&DAT_00013674,1);
        uVar5 = 0xffff;
        if (sVar2 == 1) {
          uVar5 = (ushort)DAT_00013674;
        }
      } while ((uVar5 != 0xffff) && (uVar5 == uVar4));
    }
    bVar1 = true;
LAB_0000cf38:
    uVar3 = 0xffffffff;
    if (!bVar1) {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


================================================================