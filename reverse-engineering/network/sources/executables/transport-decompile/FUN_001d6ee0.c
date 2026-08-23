
void FUN_001d6ee0(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  
  FUN_001d507c(param_1,*(undefined4 *)(param_1 + 0x500),*(undefined2 *)(param_1 + 0x504));
  uVar1 = *(int *)(param_1 + 0x88) + 0x128;
  *(uint *)(param_1 + 0x88) =
       *(int *)(param_1 + 0x88) << 0x18 | (*(uint *)(param_1 + 0x88) & 0xff00) << 8 |
       (int)(*(uint *)(param_1 + 0x88) & 0xff0000) >> 8 | *(uint *)(param_1 + 0x88) >> 0x18;
  iVar2 = FUN_001d533c(param_1);
  if (((iVar2 != 0) && (iVar3 = FUN_001ed74c(iVar2,param_1 + 0x84,uVar1), iVar3 == 0)) &&
     (lVar5 = FUN_001ed2c0(iVar2,0xe), lVar5 != 0)) {
    FUN_001eabc0(iVar2 + uVar1 + 0x3c);
    FUN_001eac0c(iVar2 + uVar1 + 0x3c,0x4d52,*(undefined4 *)(param_1 + 0x518));
    FUN_001eac0c(iVar2 + uVar1 + 0x3c,0x4c43,*(undefined4 *)(param_1 + 0x510));
    uVar4 = FUN_001ead70(iVar2 + uVar1 + 0x3c);
    FUN_001eaddc(iVar2 + uVar1 + 0x3c);
    FUN_001e180c(param_1,iVar2,0x3000,(uVar1 & 0xffff) + (uVar4 & 0xffff) & 0xffff,1,0);
  }
  return;
}

