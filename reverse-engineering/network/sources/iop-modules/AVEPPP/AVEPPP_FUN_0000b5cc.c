FUNCTION FUN_0000b5cc @ 0x0000b5cc size=316
CALLERS (0): 
CALLEES (3): FUN_00000710@0x00000710, FUN_0000acc8@0x0000acc8, FUN_0000075c@0x0000075c

undefined4 FUN_0000b5cc(int param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  short sVar2;
  undefined4 uVar3;
  ushort uVar4;
  ushort uVar5;
  undefined4 local_res8 [2];
  undefined4 local_28 [2];
  
  bVar1 = false;
  if (*(char *)(param_2 + 1) == *(char *)(param_1 + 1)) {
    local_res8[0] = param_3;
    local_28[0] = FUN_0000acc8(param_1);
    sVar2 = FUN_00000710();
    if (*(short *)(param_2 + 2) == sVar2) {
      do {
        sVar2 = FUN_0000075c(local_28,&DAT_00013624,1);
        uVar4 = 0xffff;
        if (sVar2 == 1) {
          uVar4 = (ushort)DAT_00013624;
        }
        if (uVar4 == 0xffff) goto LAB_0000b6c0;
        sVar2 = FUN_0000075c(local_res8,&DAT_00013624,1);
        uVar5 = 0xffff;
        if (sVar2 == 1) {
          uVar5 = (ushort)DAT_00013624;
        }
      } while ((uVar5 != 0xffff) && (uVar5 == uVar4));
    }
    bVar1 = true;
LAB_0000b6c0:
    uVar3 = 0xffffffff;
    if (!bVar1) {
      uVar3 = 0;
      *(char *)(param_1 + 0xb) = *(char *)(param_1 + 0xb) + '\x01';
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


================================================================