FUNCTION FUN_0000ae24 @ 0x0000ae24 size=240
CALLERS (25): FUN_00012170@0x00012170, FUN_00004b68@0x00004b68, FUN_00008d64@0x00008d64, FUN_000038a4@0x000038a4, FUN_0000bfe0@0x0000bfe0, FUN_0000b100@0x0000b100, FUN_0000df10@0x0000df10, FUN_00010418@0x00010418, FUN_000114dc@0x000114dc, FUN_0000e1c8@0x0000e1c8, FUN_00016e2c@0x00016e2c, FUN_00017d38@0x00017d38, FUN_00017da0@0x00017da0, FUN_0001104c@0x0001104c, FUN_00010dd4@0x00010dd4, FUN_00005c7c@0x00005c7c, FUN_0000f874@0x0000f874, FUN_0000b9bc@0x0000b9bc, FUN_00000994@0x00000994, FUN_000043a8@0x000043a8, FUN_00019444@0x00019444, FUN_00000160@0x00000160, FUN_00012ac8@0x00012ac8, FUN_0000f130@0x0000f130, FUN_00017d10@0x00017d10
CALLEES (0): 

void FUN_0000ae24(undefined4 *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if ((int)param_2 < 4) goto LAB_0000af04;
  if (((uint)param_1 & 1) != 0) {
    *(undefined1 *)param_1 = 0;
    param_1 = (undefined4 *)((int)param_1 + 1);
    param_2 = param_2 - 1;
  }
  if (((uint)param_1 & 2) != 0) {
    *(undefined1 *)param_1 = 0;
    *(undefined1 *)((int)param_1 + 1) = 0;
    param_1 = (undefined4 *)((int)param_1 + 2);
    param_2 = param_2 - 2;
  }
  uVar2 = (int)param_2 >> 2 & 3;
  iVar4 = (int)param_2 >> 4;
  if (uVar2 == 2) {
LAB_0000aea8:
    *param_1 = 0;
    param_1 = param_1 + 1;
LAB_0000aeb0:
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  else if (uVar2 < 3) {
    if (uVar2 == 1) goto LAB_0000aeb0;
  }
  else if (uVar2 == 3) {
    *param_1 = 0;
    param_1 = param_1 + 1;
    goto LAB_0000aea8;
  }
  if (0 < iVar4) {
    puVar3 = param_1 + 3;
    do {
      iVar4 = iVar4 + -1;
      *param_1 = 0;
      puVar3[-2] = 0;
      puVar3[-1] = 0;
      *puVar3 = 0;
      puVar3 = puVar3 + 4;
      param_1 = param_1 + 4;
    } while (0 < iVar4);
  }
  param_2 = param_2 & 3;
LAB_0000af04:
  while (bVar1 = 0 < (int)param_2, param_2 = param_2 - 1, bVar1) {
    *(undefined1 *)param_1 = 0;
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  return;
}


================================================================