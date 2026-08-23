FUNCTION FUN_000029f8 @ 0x000029f8 size=400
CALLERS (2): FUN_0000df10@0x0000df10, FUN_0000ec64@0x0000ec64
CALLEES (4): FUN_00001574@0x00001574, FUN_000027d8@0x000027d8, FUN_00002428@0x00002428, FUN_00011d90@0x00011d90

void FUN_000029f8(undefined4 param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  iVar6 = param_2[4];
  for (piVar3 = param_2; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
    iVar5 = iVar5 + (piVar3[5] - piVar3[4]);
  }
  FUN_00011d90("%<TIME> %s ",param_1);
  iVar4 = param_2[5];
  iVar2 = param_2[4];
  if ((DAT_0001b850 & 2) != 0) {
    FUN_00001574(iVar6);
    FUN_00011d90(&DAT_0001b4bc);
    FUN_00001574(iVar6 + 6);
    FUN_00011d90(&DAT_0001b45c);
  }
  iVar4 = (iVar4 - iVar2) + -0xe;
  iVar2 = iVar6 + 0xe;
  if (iVar4 < 1) {
    param_2 = (int *)*param_2;
    iVar2 = param_2[4];
    iVar4 = param_2[5] - iVar2;
  }
  uVar1 = *(ushort *)(iVar6 + 0xc) << 8 | *(ushort *)(iVar6 + 0xc) >> 8;
  if (uVar1 == 0x806) {
LAB_00002b38:
    FUN_000027d8(uVar1,iVar2);
  }
  else {
    if (uVar1 < 0x807) {
      if (uVar1 == 0x800) {
        FUN_00002428(iVar2,param_2,iVar4,iVar5 + -0xe);
        goto LAB_00002b5c;
      }
    }
    else if (uVar1 == 0x8035) goto LAB_00002b38;
    FUN_00011d90("0x%x %dB",uVar1,iVar5 + -0xe);
  }
LAB_00002b5c:
  FUN_00011d90(&DAT_0001b460);
  return;
}


================================================================