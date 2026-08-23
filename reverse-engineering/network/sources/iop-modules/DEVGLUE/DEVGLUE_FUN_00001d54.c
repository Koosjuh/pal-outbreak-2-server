FUNCTION FUN_00001d54 @ 0x00001d54 size=976
CALLERS (1): FUN_00001804@0x00001804
CALLEES (5): FUN_000081f8@0x000081f8, FUN_000081bc@0x000081bc, FUN_00001c1c@0x00001c1c, FUN_00008208@0x00008208, FUN_0000810c@0x0000810c

undefined4 FUN_00001d54(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 local_20;
  uint local_1c;
  
  iVar1 = (&DAT_00009718)[param_1];
  if (iVar1 == 0) {
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_000083f0);
      FUN_0000810c("mdmifStartDevice id %d unregisterd\n",param_1);
    }
  }
  else {
    uVar2 = (**(code **)(iVar1 + 0x58))(*(undefined4 *)(iVar1 + 0x38),0xc0020000,&local_20,4);
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_000083f0);
      FUN_0000810c("mdmifStartDevice sceModemCC_GET_PARAM(%08x) ret %d\n",local_20,uVar2);
    }
    local_20 = FUN_00001c1c(&DAT_0000db80 + param_1 * 0x1c);
    uVar2 = (**(code **)((&DAT_00009718)[param_1] + 0x58))
                      (*(undefined4 *)((&DAT_00009718)[param_1] + 0x38),0xc1020000,&local_20,4);
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_000083f0);
      FUN_0000810c("mdmifStartDevice sceModemCC_SET_PARAM(%08x) ret %d\n",local_20,uVar2);
    }
    uVar2 = FUN_000081f8(*(undefined4 *)((&DAT_00009718)[param_1] + 0x3c),0);
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_000083f0);
      FUN_0000810c("mdmifStartDevice ClearEventFlag ret %d\n",uVar2);
    }
    uVar2 = (**(code **)((&DAT_00009718)[param_1] + 0x48))
                      (*(undefined4 *)((&DAT_00009718)[param_1] + 0x38),0);
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_000083f0);
      FUN_0000810c("mdmifStartDevice start() = %d\n",uVar2);
    }
    iVar1 = 0;
    do {
      local_1c = 0;
      iVar3 = FUN_00008208(*(undefined4 *)((&DAT_00009718)[param_1] + 0x3c),3,0x11,&local_1c);
      if (iVar3 == -0x1a5) {
        FUN_000081bc(100000);
      }
      else {
        if (iVar3 != 0) {
          if ((DAT_00009710 & 1) == 0) {
            return 0xffffffff;
          }
          FUN_0000810c(&PTR_DAT_000083f0);
          FUN_0000810c("mdmifStartDevice PollEventFlag ret %d\n",iVar3);
          return 0xffffffff;
        }
        if ((local_1c & 2) != 0) {
          if ((DAT_00009710 & 1) == 0) {
            return 0xffffffff;
          }
          FUN_0000810c(&PTR_DAT_000083f0);
          pcVar4 = "mdmifStartDevice PlugOut\n";
          goto LAB_000020fc;
        }
        if ((local_1c & 1) != 0) {
          if ((DAT_00009710 & 1) != 0) {
            FUN_0000810c(&PTR_DAT_000083f0);
            FUN_0000810c("mdmifStartDevice StartDone\n");
          }
          uVar2 = (**(code **)((&DAT_00009718)[param_1] + 0x58))
                            (*(undefined4 *)((&DAT_00009718)[param_1] + 0x38),0xc0000110,0,0);
          if ((DAT_00009710 & 1) != 0) {
            FUN_0000810c(&PTR_DAT_000083f0);
            FUN_0000810c("mdmifStartDevice sceModemCC_FLUSH_RXBUF ret %d\n",uVar2);
          }
          *(undefined4 *)((&DAT_00009718)[param_1] + 0x5c) = 1;
          return 0;
        }
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 200);
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_000083f0);
      pcVar4 = "mdmifStartDevice TimeOut\n";
LAB_000020fc:
      FUN_0000810c(pcVar4);
    }
  }
  return 0xffffffff;
}


================================================================