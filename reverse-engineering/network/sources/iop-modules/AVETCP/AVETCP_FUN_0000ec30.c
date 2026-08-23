FUNCTION FUN_0000ec30 @ 0x0000ec30 size=396
CALLERS (3): FUN_0000f09c@0x0000f09c, FUN_000112ec@0x000112ec, FUN_000049c4@0x000049c4
CALLEES (0): 

undefined4
FUN_0000ec30(uint param_1,uint param_2,uint param_3,undefined2 param_4,char param_5,ushort param_6)

{
  undefined2 uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  bool bVar5;
  
  bVar5 = false;
  puVar3 = &DAT_00018350;
  iVar4 = 0;
  if (DAT_0001619a != 0) {
    iVar2 = 0;
    do {
      iVar2 = iVar2 >> 0x10;
      if (((&DAT_00018350)[iVar2 * 7] == param_1) && (((&DAT_0001835e)[iVar2 * 0xe] & 1) != 0)) {
        if ((((param_1 != 0) || (param_2 != 0)) || (param_3 != 0)) || (param_5 != '\x01')) {
          return 0xffffffff;
        }
      }
      else if ((!bVar5) && ((&DAT_0001835e)[iVar2 * 0xe] == 0)) {
        puVar3 = &DAT_00018350 + (short)iVar4 * 7;
        bVar5 = true;
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar4 * 0x10000;
    } while (iVar4 * 0x10000 >> 0x10 < (int)(uint)DAT_0001619a);
  }
  if (!bVar5) {
    return 0xffffffff;
  }
  puVar3[1] = param_2;
  if (param_5 == '\x02') {
    *(ushort *)((int)puVar3 + 0xe) = param_6 | 1;
    if ((param_6 & 4) != 0) {
      puVar3[1] = 0xffffffff;
    }
  }
  else {
    if (param_5 == '\x01') {
      uVar1 = 9;
    }
    else {
      if ((param_5 != '\x03') && ((param_1 & ~param_2) != 0)) {
        *(undefined2 *)((int)puVar3 + 0xe) = 0xf;
        puVar3[1] = 0xffffffff;
        goto LAB_0000ed90;
      }
      uVar1 = 0xb;
    }
    *(undefined2 *)((int)puVar3 + 0xe) = uVar1;
  }
LAB_0000ed90:
  puVar3[5] = 0;
  puVar3[4] = 0;
  *(undefined1 *)(puVar3 + 6) = 0;
  *(char *)((int)puVar3 + 0x19) = param_5;
  *puVar3 = param_1;
  *(undefined2 *)(puVar3 + 3) = param_4;
  puVar3[2] = param_3;
  return 0;
}


================================================================