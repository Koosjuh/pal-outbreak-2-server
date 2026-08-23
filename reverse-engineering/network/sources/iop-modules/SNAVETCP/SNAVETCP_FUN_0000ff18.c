FUNCTION FUN_0000ff18 @ 0x0000ff18 size=328
CALLERS (3): FUN_00007000@0x00007000, FUN_0000decc@0x0000decc, FUN_0000cc3c@0x0000cc3c
CALLEES (4): FUN_00000100@0x00000100, FUN_0000ce24@0x0000ce24, FUN_000120e0@0x000120e0, FUN_0000cdb4@0x0000cdb4

undefined4
FUN_0000ff18(short param_1,int param_2,short param_3,undefined4 param_4,undefined2 param_5,
            undefined2 param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == 0) {
    iVar3 = (int)param_1;
    iVar2 = iVar3 * 0x14;
    if ((&DAT_00017e50)[iVar3 * 5] != -1) {
      *(short *)(&DAT_00017e42 + iVar2) = param_3;
      *(undefined2 *)(&DAT_00017e44 + iVar2) = 1;
      *(undefined4 *)(&DAT_00017e48 + iVar2) = param_4;
      *(undefined2 *)(&DAT_00017e4c + iVar2) = param_5;
      *(undefined2 *)(&DAT_00017e4e + iVar2) = param_6;
      *(short *)(&DAT_00017e40 + iVar2) = param_1;
      FUN_000120e0((&DAT_00017e50)[iVar3 * 5]);
    }
  }
  else {
    iVar3 = (int)param_3;
    if (-1 < iVar3) {
      FUN_0000cdb4(iVar3);
    }
    uVar1 = FUN_00000100((int)param_1,param_2,iVar3,param_4,param_5,param_6);
    FUN_0000ce24((int)param_1,uVar1);
  }
  return 0;
}


================================================================