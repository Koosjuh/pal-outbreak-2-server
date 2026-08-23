FUNCTION FUN_0000d39c @ 0x0000d39c size=144
CALLERS (3): FUN_00010060@0x00010060, FUN_0000fb74@0x0000fb74, FUN_0000fa8c@0x0000fa8c
CALLEES (2): FUN_0000d42c@0x0000d42c, FUN_0000e08c@0x0000e08c

undefined4 FUN_0000d39c(short param_1)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = (int)param_1;
  sVar1 = FUN_0000e08c(iVar4);
  uVar2 = 0xfffffffc;
  if (sVar1 == 0) {
    iVar3 = DAT_00016180 + iVar4 * 0x17c;
    if (*(short *)(iVar3 + 0x13a) == -1) {
      uVar2 = 0xfffffff1;
    }
    else {
      *(byte *)(iVar3 + 0x13f) = *(byte *)(iVar3 + 0x13f) | 0x80;
      *(byte *)(iVar3 + 0x13e) = *(byte *)(iVar3 + 0x13e) | 0xc;
      FUN_0000d42c(iVar4);
      uVar2 = 0;
    }
  }
  return uVar2;
}


================================================================