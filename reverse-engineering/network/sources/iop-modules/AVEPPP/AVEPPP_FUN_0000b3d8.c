FUNCTION FUN_0000b3d8 @ 0x0000b3d8 size=500
CALLERS (0): 
CALLEES (5): FUN_0000abec@0x0000abec, FUN_0000a9c0@0x0000a9c0, FUN_00009044@0x00009044, FUN_0000ad1c@0x0000ad1c, FUN_00008fac@0x00008fac

uint FUN_0000b3d8(int param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  undefined4 local_res8 [2];
  byte local_38;
  byte local_37;
  undefined4 local_30 [2];
  
  iVar5 = (int)*(short *)(param_2 + 2);
  iVar4 = *(int *)(param_1 + 0x30);
  sVar6 = 2;
  local_30[0] = 0;
  *(undefined2 *)(iVar4 + 0x74) = 0;
  local_res8[0] = param_3;
  if (0 < iVar5) {
    sVar6 = 2;
    do {
      sVar2 = FUN_00008fac(&local_38,local_res8);
      if (sVar2 == -1) break;
      iVar5 = iVar5 - (uint)local_37;
      if ((iVar5 < 0) ||
         (sVar2 = FUN_0000ad1c(local_res8,iVar4,iVar4 + 0x4c,&local_38,1), sVar2 == -1)) {
        return 0xffffffff;
      }
      if (sVar6 <= sVar2) {
        if (sVar6 < sVar2) {
          local_30[0] = 0;
          sVar6 = sVar2;
        }
        if (sVar2 != 4) {
          uVar3 = (uint)local_38;
          if (uVar3 < 8) {
LAB_0000b4e4:
            uVar1 = (ushort)(1 << (uVar3 & 0x1f));
          }
          else {
            if ((uVar3 + 0x80 & 0xff) < 0x10) {
              uVar3 = local_38 - 0x78;
              goto LAB_0000b4e4;
            }
            uVar1 = 1;
          }
          *(ushort *)(iVar4 + 0x74) = *(ushort *)(iVar4 + 0x74) | uVar1;
        }
        FUN_0000a9c0(local_30,iVar4 + 0x74,local_38,local_37,local_res8);
      }
    } while (0 < iVar5);
  }
  if (sVar6 == 3) {
    if (*(char *)(param_1 + 6) == '\0') {
      sVar6 = 4;
    }
    else {
      FUN_0000abec(local_30,iVar4 + 0x74,
                   (int)(short)(*(ushort *)(iVar4 + 0x50) & ~*(ushort *)(iVar4 + 0x74)));
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + -1;
    }
  }
  FUN_00009044(param_1,(int)sVar6,*(undefined1 *)(param_2 + 1),local_30[0]);
  return (uint)(sVar6 != 2);
}


================================================================