FUNCTION FUN_0000de60 @ 0x0000de60 size=108
CALLERS (1): FUN_0000f870@0x0000f870
CALLEES (1): FUN_0000e08c@0x0000e08c

undefined4 FUN_0000de60(short param_1,undefined4 param_2)

{
  short sVar1;
  undefined4 uVar2;
  
  sVar1 = FUN_0000e08c((int)param_1);
  uVar2 = 0xfffffffc;
  if (sVar1 == 0) {
    uVar2 = 0;
    *(undefined4 *)(param_1 * 0x17c + DAT_00016180 + 0x168) = param_2;
  }
  return uVar2;
}


================================================================