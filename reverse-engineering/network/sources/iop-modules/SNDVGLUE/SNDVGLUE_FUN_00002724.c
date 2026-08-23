FUNCTION FUN_00002724 @ 0x00002724 size=284
CALLERS (1): FUN_00001804@0x00001804
CALLEES (1): FUN_0000810c@0x0000810c

undefined4 FUN_00002724(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if ((&DAT_00009718)[param_1] == 0) {
    uVar1 = 0xffffffff;
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_000083f0);
      FUN_0000810c("mdmifReceive id %d unregisterd\n",param_1);
      uVar1 = 0xffffffff;
    }
  }
  else {
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_000083f0);
      FUN_0000810c("mdmifReceive sceModemEFP_Recv\n");
    }
    uVar1 = (**(code **)((&DAT_00009718)[param_1] + 0x50))
                      (*(undefined4 *)((&DAT_00009718)[param_1] + 0x38),param_2,param_3);
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_000083f0);
      FUN_0000810c("mdmifReceive recv() ret %d\n",uVar1);
    }
  }
  return uVar1;
}


================================================================