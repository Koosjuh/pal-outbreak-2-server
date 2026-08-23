
/* WARNING: Removing unreachable block (ram,0x00189ca4) */
/* WARNING: Removing unreachable block (ram,0x00189cac) */
/* WARNING: Removing unreachable block (ram,0x00189cb4) */

undefined4 FUN_00189bb0(undefined8 param_1,undefined8 param_2)

{
  short sVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  
  uVar2 = thunk_FUN_00197ad0(param_2,param_2,0);
  sVar1 = *(short *)((int)uVar2 + 2);
  lVar4 = 0;
  while( true ) {
    if (sVar1 <= lVar4) break;
    iVar3 = (int)param_1 + (int)lVar4 * 400;
    *(short *)(iVar3 + 0xc2) = sVar1;
    *(undefined2 *)(iVar3 + 0x180) = 0xffff;
    *(undefined2 *)(iVar3 + 0x182) = 0xffff;
    *(undefined4 *)(iVar3 + 0xcc) = 0;
    *(undefined4 *)(iVar3 + 0xd0) = 0;
    *(undefined4 *)(iVar3 + 0xd4) = 0;
    *(undefined4 *)(iVar3 + 0xd8) = 0;
    *(undefined4 *)(iVar3 + 0x178) = 0;
    *(undefined4 *)(iVar3 + 0x17c) = 0;
    FUN_00186320(iVar3 + 0x40);
    lVar4 = (long)((int)lVar4 + 1);
  }
  for (lVar4 = 0; lVar4 < sVar1; lVar4 = (long)((int)lVar4 + 1)) {
    FUN_0018a400((int)param_1 + (int)lVar4 * 400,uVar2,lVar4);
  }
  FUN_00189cf0(param_1,param_1,0);
  FUN_0018a0b0(param_1);
  return 1;
}

