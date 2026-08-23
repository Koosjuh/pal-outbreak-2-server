FUNCTION FUN_0000decc @ 0x0000decc size=280
CALLERS (1): FUN_00010c8c@0x00010c8c
CALLEES (5): FUN_00011d48@0x00011d48, FUN_0000ff18@0x0000ff18, FUN_0000e08c@0x0000e08c, FUN_000105ec@0x000105ec, FUN_00010bc0@0x00010bc0

undefined4 FUN_0000decc(short param_1,uint param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = (int)param_1;
  sVar1 = FUN_0000e08c(iVar3);
  if (sVar1 == 0) {
    iVar4 = DAT_00016180 + iVar3 * 0x17c;
    uVar2 = 0xfffffff3;
    if ((param_2 & 0xfff8) == 0) {
      if (*(short *)(iVar4 + 0x13a) == 1) {
        if ((param_2 & 4) != 0) {
          FUN_0000ff18(iVar3,*(undefined4 *)(iVar4 + 0x164),0xfffffff2,0,0,0);
          return 0;
        }
      }
      else {
        if ((param_2 & 1) != 0) {
          FUN_00011d48(iVar4 + 0x14,0,0x98);
          FUN_000105ec(iVar3,*(undefined4 *)(iVar4 + 0xd0),0xfffffff2);
        }
        if ((param_2 & 2) != 0) {
          FUN_00011d48(iVar4 + 0xc0,0,8);
          FUN_00010bc0(iVar3,*(undefined4 *)(iVar4 + 0xd4),0xfffffff2,0);
        }
      }
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xfffffffc;
  }
  return uVar2;
}


================================================================