FUNCTION FUN_0001388c @ 0x0001388c size=216
CALLERS (1): FUN_00014238@0x00014238
CALLEES (2): FUN_00011d48@0x00011d48, FUN_000008d4@0x000008d4

undefined4 FUN_0001388c(undefined4 param_1,undefined2 param_2,undefined2 param_3,short param_4)

{
  undefined4 uVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_38;
  undefined2 local_34;
  undefined2 local_32;
  code *local_20;
  
  uVar3 = 0xffffffff;
  if (param_4 != -1) {
    FUN_00011d48(&local_38,0,0x1c);
    local_20 = FUN_000137cc;
    local_38 = param_1;
    local_34 = param_2;
    local_32 = param_3;
    sVar2 = FUN_000008d4(&LAB_00004120,&local_38,0);
    uVar1 = DAT_00017bb4;
    uVar3 = 0xffffffff;
    if (((int)sVar2 & 0x8000U) == 0) {
      iVar4 = (&DAT_00016fa0)[param_4];
      uVar3 = 0;
      *(short *)(iVar4 + 2) = sVar2;
      *(undefined4 *)(iVar4 + 4) = 0;
      *(undefined4 *)(iVar4 + 8) = param_1;
      *(undefined2 *)(iVar4 + 0xc) = param_2;
      *(undefined4 *)(iVar4 + 0x814) = 0;
      *(undefined4 *)(iVar4 + 0xc18) = 0;
      *(undefined4 *)(iVar4 + 0xc1c) = 0;
      *(undefined4 *)(iVar4 + 0xc20) = uVar1;
    }
  }
  return uVar3;
}


================================================================