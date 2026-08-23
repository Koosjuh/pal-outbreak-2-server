FUNCTION FUN_000034a8 @ 0x000034a8 size=148
CALLERS (1): FUN_00010060@0x00010060
CALLEES (2): FUN_0000eecc@0x0000eecc, FUN_0001168c@0x0001168c

undefined4 FUN_000034a8(short param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (int)param_1;
  if (((iVar2 < (int)(uint)DAT_0001617e) && (-1 < iVar2)) &&
     (iVar3 = iVar2 * 0x30 + DAT_000161a0, *(short *)(iVar3 + 8) != 0)) {
    FUN_0000eecc(iVar3);
    FUN_0001168c(iVar2,*(undefined4 *)(iVar3 + 0x28),2,0xff);
    uVar1 = 0;
    *(undefined2 *)(iVar3 + 8) = 0;
  }
  else {
    uVar1 = 0xfffffffc;
  }
  return uVar1;
}


================================================================