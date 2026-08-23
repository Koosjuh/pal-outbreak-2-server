FUNCTION FUN_00002124 @ 0x00002124 size=320
CALLERS (1): FUN_00001804@0x00001804
CALLEES (1): FUN_0000810c@0x0000810c

undefined4 FUN_00002124(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (&DAT_00009718)[param_1];
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_000083f0);
      FUN_0000810c("mdmifStopDevice id %d unregisterd\n",param_1);
      uVar2 = 0xffffffff;
    }
  }
  else {
    uVar2 = (**(code **)(iVar1 + 0x4c))(*(undefined4 *)(iVar1 + 0x38),0);
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_000083f0);
      FUN_0000810c("mdmifStopDevice stop() = %d\n",uVar2);
    }
    *(undefined4 *)((&DAT_00009718)[param_1] + 0x5c) = 0;
    *(undefined4 *)((&DAT_00009718)[param_1] + 100) = 0;
    uVar2 = 0;
    if (*(int *)((&DAT_00009718)[param_1] + 0x60) != 0) {
      *(undefined4 *)((&DAT_00009718)[param_1] + 0x60) = 0;
      (&DAT_00009718)[param_1] = 0;
      DAT_000096e0 = 1;
      DAT_000096e4 = DAT_000096e4 + -1;
      uVar2 = 0;
    }
  }
  return uVar2;
}


================================================================