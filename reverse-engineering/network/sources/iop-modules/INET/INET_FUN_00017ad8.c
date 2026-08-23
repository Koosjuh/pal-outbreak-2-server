FUNCTION FUN_00017ad8 @ 0x00017ad8 size=284
CALLERS (19): FUN_00014380@0x00014380, FUN_000000c4@0x000000c4, FUN_0000d658@0x0000d658, FUN_00003780@0x00003780, FUN_00007abc@0x00007abc, FUN_000045a4@0x000045a4, FUN_00006cd0@0x00006cd0, FUN_00015c18@0x00015c18, FUN_00006d98@0x00006d98, FUN_00015a28@0x00015a28, FUN_00003e54@0x00003e54, FUN_000044dc@0x000044dc, FUN_000043a8@0x000043a8, FUN_0000ec64@0x0000ec64, FUN_00006d5c@0x00006d5c, FUN_00004b68@0x00004b68, FUN_00001108@0x00001108, FUN_00000344@0x00000344, FUN_0001442c@0x0001442c
CALLEES (3): FUN_00011d90@0x00011d90, FUN_0000d8cc@0x0000d8cc, FUN_0000a60c@0x0000a60c

undefined4 * FUN_00017ad8(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = param_3 >> 0x1f;
  if (iVar3 < 0) {
    FUN_00011d90("timeout: delta=%d\n",param_2,param_3,iVar3);
    puVar2 = (undefined4 *)0x0;
  }
  else {
    if (DAT_0001e424 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)FUN_0000a60c(0x18);
      if (puVar2 == (undefined4 *)0x0) {
        if ((DAT_0001b850 & 1) == 0) {
          return (undefined4 *)0x0;
        }
        FUN_00011d90("timeout: no space\n");
        return (undefined4 *)0x0;
      }
    }
    else {
      puVar2 = DAT_0001e424;
      DAT_0001e424 = (undefined4 *)*DAT_0001e424;
    }
    puVar2[2] = param_3;
    puVar2[3] = iVar3;
    puVar2[4] = param_1;
    puVar2[5] = param_2;
    puVar2[1] = DAT_0001e42c;
    puVar1 = puVar2;
    if (DAT_0001e42c != (undefined4 *)0x0) {
      *DAT_0001e42c = puVar2;
      puVar1 = DAT_0001e428;
    }
    DAT_0001e428 = puVar1;
    *puVar2 = 0;
    DAT_0001e42c = puVar2;
    FUN_0000d8cc();
  }
  return puVar2;
}


================================================================