FUNCTION FUN_00005354 @ 0x00005354 size=440
CALLERS (1): FUN_00000850@0x00000850
CALLEES (1): FUN_0000810c@0x0000810c

int FUN_00005354(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  uint local_18 [2];
  
  iVar1 = (&DAT_00009720)[param_1];
  if (iVar1 == 0) {
    iVar2 = -1;
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_00008c20);
      FUN_0000810c("netdevifGetNegoMode id %d unregisterd\n",param_1);
      iVar2 = -1;
    }
  }
  else {
    iVar1 = (**(code **)(iVar1 + 0x6c))(*(undefined4 *)(iVar1 + 0x44),0x80020000,local_18,4);
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_00008c20);
      FUN_0000810c("id %d sceInetNDCC_GET_NEGO_MODE val %d ret %d\n",param_1,local_18[0],iVar1);
    }
    iVar2 = -1;
    if (-1 < iVar1) {
      *param_2 = 0;
      if ((local_18[0] & 1) != 0) {
        *param_2 = 1;
      }
      if ((local_18[0] & 2) != 0) {
        *param_2 = *param_2 | 2;
      }
      if ((local_18[0] & 4) != 0) {
        *param_2 = *param_2 | 4;
      }
      if ((local_18[0] & 8) != 0) {
        *param_2 = *param_2 | 8;
      }
      if ((local_18[0] & 0x40) != 0) {
        *param_2 = *param_2 | 0x40;
      }
      iVar2 = iVar1;
      if ((local_18[0] & 0x80) != 0) {
        *param_2 = *param_2 | 0x80;
      }
    }
  }
  return iVar2;
}


================================================================