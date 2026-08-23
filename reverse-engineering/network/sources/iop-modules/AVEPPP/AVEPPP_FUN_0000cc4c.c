FUNCTION FUN_0000cc4c @ 0x0000cc4c size=504
CALLERS (0): 
CALLEES (6): FUN_000006b0@0x000006b0, FUN_0000c4b0@0x0000c4b0, FUN_0000c5a0@0x0000c5a0, FUN_00009044@0x00009044, FUN_0000c298@0x0000c298, FUN_00008fac@0x00008fac

uint FUN_0000cc4c(int param_1,int param_2,undefined4 param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  undefined4 local_res8 [2];
  byte local_38;
  byte local_37;
  undefined4 local_30 [2];
  
  iVar3 = (int)*(short *)(param_2 + 2);
  iVar2 = *(int *)(param_1 + 0x30);
  local_30[0] = 0;
  *(undefined2 *)(iVar2 + 0x50) = 0;
  local_res8[0] = param_3;
  local_30[0] = FUN_000006b0(1);
  sVar4 = 2;
  if (*(char *)(iVar2 + 0x4d) != '\0') {
    *(undefined2 *)(iVar2 + 0x58) = 0;
    *(ushort *)(iVar2 + 0x50) = *(ushort *)(iVar2 + 0x50) | 8;
  }
  if (0 < iVar3) {
    sVar4 = 2;
    do {
      sVar1 = FUN_00008fac(&local_38,local_res8);
      if (sVar1 == -1) break;
      iVar3 = iVar3 - (uint)local_37;
      if ((iVar3 < 0) ||
         (sVar1 = FUN_0000c5a0(local_res8,iVar2,iVar2 + 0x34,&local_38,1), sVar1 == -1)) {
        return 0xffffffff;
      }
      if (sVar4 <= sVar1) {
        if (sVar4 < sVar1) {
          local_30[0] = 0;
          sVar4 = sVar1;
        }
        if ((sVar1 != 4) && (local_38 < 9)) {
          *(ushort *)(iVar2 + 0x50) = *(ushort *)(iVar2 + 0x50) | (ushort)(1 << (local_38 & 0x1f));
        }
        FUN_0000c298(local_30,iVar2 + 0x50,local_38,local_37,local_res8);
      }
    } while (0 < iVar3);
  }
  if (sVar4 == 3) {
    if (*(char *)(param_1 + 6) == '\0') {
      sVar4 = 4;
    }
    else {
      FUN_0000c4b0(local_30,iVar2 + 0x50,
                   (int)(short)(*(ushort *)(iVar2 + 0x38) & ~*(ushort *)(iVar2 + 0x50)));
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + -1;
    }
  }
  FUN_00009044(param_1,(int)sVar4,*(undefined1 *)(param_2 + 1),local_30[0]);
  return (uint)(sVar4 != 2);
}


================================================================