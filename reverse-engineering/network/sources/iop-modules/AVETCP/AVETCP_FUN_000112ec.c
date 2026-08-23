FUNCTION FUN_000112ec @ 0x000112ec size=188
CALLERS (1): FUN_00000744@0x00000744
CALLEES (2): FUN_0000ec30@0x0000ec30, FUN_0000f580@0x0000f580

undefined4 FUN_000112ec(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = *param_1;
  uVar1 = uVar4;
  iVar2 = DAT_00017e04;
  iVar3 = DAT_00017e00;
  if (((DAT_00017e00 == 0) && (DAT_00017e04 == 0)) && (DAT_00017e08 == 0)) {
    uVar1 = param_1[1];
    iVar2 = 0;
    iVar3 = 0;
  }
  uVar1 = FUN_0000f580(uVar1,iVar2,iVar3);
  iVar2 = FUN_0000ec30(uVar4,uVar1,param_1[1],*(undefined2 *)(param_1 + 2),0,0);
  uVar1 = 0;
  if (iVar2 << 0x10 < 0) {
    uVar1 = 0xfffffff0;
  }
  return uVar1;
}


================================================================