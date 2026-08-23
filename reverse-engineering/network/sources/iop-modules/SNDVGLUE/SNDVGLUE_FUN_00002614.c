FUNCTION FUN_00002614 @ 0x00002614 size=272
CALLERS (1): FUN_00001804@0x00001804
CALLEES (1): FUN_0000810c@0x0000810c

undefined4 FUN_00002614(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((&DAT_00009718)[param_1] == 0) {
    uVar1 = 0xffffffff;
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_000083f0);
      FUN_0000810c("mdmifSend id %d unregisterd\n",param_1);
      uVar1 = 0xffffffff;
    }
  }
  else {
    iVar2 = *(int *)((&DAT_00009718)[param_1] + 0x44);
    if (iVar2 < param_3) {
      param_3 = iVar2;
    }
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_000083f0);
      FUN_0000810c("mdmifSend snd_len %d len %d\n",*(undefined4 *)((&DAT_00009718)[param_1] + 0x44),
                   param_3);
    }
    uVar1 = (**(code **)((&DAT_00009718)[param_1] + 0x54))
                      (*(undefined4 *)((&DAT_00009718)[param_1] + 0x38),param_2,param_3);
  }
  return uVar1;
}


================================================================