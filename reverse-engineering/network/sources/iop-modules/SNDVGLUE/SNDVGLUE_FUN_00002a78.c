FUNCTION FUN_00002a78 @ 0x00002a78 size=140
CALLERS (1): FUN_00000a80@0x00000a80
CALLEES (0): 

void FUN_00002a78(uint param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 < 2) {
    uVar1 = param_2[1];
    uVar2 = param_2[2];
    uVar3 = param_2[3];
    *(undefined4 *)(&DAT_0000db80 + param_1 * 0x1c) = *param_2;
    (&DAT_0000db84)[param_1 * 7] = uVar1;
    (&DAT_0000db88)[param_1 * 7] = uVar2;
    (&DAT_0000db8c)[param_1 * 7] = uVar3;
    uVar1 = param_2[5];
    uVar2 = param_2[6];
    (&DAT_0000db90)[param_1 * 7] = param_2[4];
    (&DAT_0000db94)[param_1 * 7] = uVar1;
    *(undefined4 *)(&DAT_0000db98 + param_1 * 0xe) = uVar2;
  }
  return;
}


================================================================