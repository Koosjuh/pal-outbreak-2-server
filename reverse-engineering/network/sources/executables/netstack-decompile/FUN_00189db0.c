
/* WARNING: Removing unreachable block (ram,0x00189eb0) */
/* WARNING: Removing unreachable block (ram,0x00189eb8) */
/* WARNING: Removing unreachable block (ram,0x00189ec0) */

undefined4 FUN_00189db0(undefined8 param_1,undefined8 param_2)

{
  short sVar1;
  undefined8 uVar2;
  int *piVar3;
  long lVar4;
  undefined4 *puVar5;
  
  uVar2 = thunk_FUN_00197ad0(param_2,param_2,0);
  sVar1 = *(short *)((int)uVar2 + 2);
  lVar4 = 0;
  while( true ) {
    puVar5 = (undefined4 *)param_1;
    if (sVar1 <= lVar4) break;
    piVar3 = puVar5 + (int)lVar4;
    *(short *)(*piVar3 + 0xc2) = sVar1;
    *(undefined2 *)(*piVar3 + 0x180) = 0xffff;
    *(undefined2 *)(*piVar3 + 0x182) = 0xffff;
    *(undefined4 *)(*piVar3 + 0xcc) = 0;
    *(undefined4 *)(*piVar3 + 0xd0) = 0;
    *(undefined4 *)(*piVar3 + 0xd4) = 0;
    *(undefined4 *)(*piVar3 + 0xd8) = 0;
    *(undefined4 *)(*piVar3 + 0x178) = 0;
    *(undefined4 *)(*piVar3 + 0x17c) = 0;
    FUN_00186320(*piVar3 + 0x40);
    lVar4 = (long)((int)lVar4 + 1);
  }
  lVar4 = 0;
  while( true ) {
    if (sVar1 <= lVar4) break;
    FUN_0018a400(puVar5[(int)lVar4],uVar2,lVar4);
    lVar4 = (long)((int)lVar4 + 1);
  }
  FUN_00189f00(param_1,*puVar5,0);
  FUN_0018a0b0(*puVar5);
  return 1;
}

