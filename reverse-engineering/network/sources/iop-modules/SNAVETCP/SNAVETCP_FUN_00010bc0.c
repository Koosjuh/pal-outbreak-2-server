FUNCTION FUN_00010bc0 @ 0x00010bc0 size=204
CALLERS (6): FUN_0000a264@0x0000a264, FUN_0000a1d0@0x0000a1d0, FUN_0000c428@0x0000c428, FUN_00007000@0x00007000, FUN_0000decc@0x0000decc, FUN_00009c90@0x00009c90
CALLEES (3): FUN_000120e0@0x000120e0, FUN_0000019c@0x0000019c, FUN_0000de28@0x0000de28

undefined4 FUN_00010bc0(short param_1,int param_2,short param_3,short param_4)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == 0) {
    iVar2 = (int)param_1;
    iVar3 = iVar2 * 0xc;
    if ((&DAT_00017f48)[iVar2 * 3] != -1) {
      *(short *)(&DAT_00017f42 + iVar3) = param_3;
      *(undefined2 *)(&DAT_00017f44 + iVar3) = 0;
      *(short *)(&DAT_00017f40 + iVar3) = param_1;
      FUN_000120e0((&DAT_00017f48)[iVar2 * 3]);
    }
  }
  else {
    iVar2 = -8;
    if (param_3 != 0) {
      iVar2 = (int)param_3;
    }
    uVar1 = FUN_0000019c((int)param_1,param_2,iVar2,(int)param_4);
    FUN_0000de28((int)param_1,uVar1);
  }
  return 0;
}


================================================================