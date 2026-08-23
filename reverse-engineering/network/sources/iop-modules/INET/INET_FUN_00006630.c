FUNCTION FUN_00006630 @ 0x00006630 size=404
CALLERS (3): FUN_00006b10@0x00006b10, FUN_00006bd0@0x00006bd0, FUN_00006c2c@0x00006c2c
CALLEES (4): FUN_0000709c@0x0000709c, FUN_00009e60@0x00009e60, FUN_00009f28@0x00009f28, FUN_00011d90@0x00011d90

void FUN_00006630(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  
  iVar5 = 0;
  if (param_1 != 0) {
    iVar5 = *(int *)(param_1 + 0x70);
  }
  if (iVar5 != 0) {
    iVar2 = FUN_00009e60(0,8);
    if (iVar2 == 0) {
      if ((DAT_0001b850 & 1) != 0) {
        FUN_00011d90("# ERR # %s:%d: %s\n",s_igmp_c_0001b700,0x28,"igmp_snd - no space for header");
      }
    }
    else {
      puVar4 = *(undefined1 **)(iVar2 + 0x14);
      *puVar4 = (char)param_2;
      puVar4[1] = 0;
      *(undefined4 *)(puVar4 + 4) = *(undefined4 *)(param_3 + 8);
      uVar3 = *(undefined4 *)(puVar4 + 4);
      puVar4[4] = (char)((uint)uVar3 >> 0x18);
      puVar4[5] = (char)((uint)uVar3 >> 0x10);
      puVar4[6] = (char)((uint)uVar3 >> 8);
      puVar4[7] = (char)uVar3;
      *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + 8;
      *(undefined2 *)(puVar4 + 2) = 0;
      uVar1 = FUN_00009f28(0,iVar2);
      *(ushort *)(puVar4 + 2) = ~uVar1;
      uVar3 = 0xe0000002;
      if (param_2 != 0x17) {
        uVar3 = *(undefined4 *)(param_3 + 8);
      }
      FUN_0000709c(param_1,iVar5,uVar3,2,1,0,iVar2,DAT_0001b6fc);
    }
  }
  return;
}


================================================================