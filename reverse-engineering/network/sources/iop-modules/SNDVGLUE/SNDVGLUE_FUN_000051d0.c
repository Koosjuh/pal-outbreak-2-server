FUNCTION FUN_000051d0 @ 0x000051d0 size=388
CALLERS (1): FUN_00000730@0x00000730
CALLEES (1): FUN_0000810c@0x0000810c

int FUN_000051d0(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint local_18 [2];
  
  if ((&DAT_00009720)[param_1] == 0) {
    iVar2 = -1;
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_00008c20);
      FUN_0000810c("netdevifSetNegoMode id %d unregisterd\n",param_1);
      iVar2 = -1;
    }
  }
  else {
    local_18[0] = (uint)((param_2 & 1) != 0);
    if ((param_2 & 2) != 0) {
      local_18[0] = local_18[0] | 2;
    }
    if ((param_2 & 4) != 0) {
      local_18[0] = local_18[0] | 4;
    }
    if ((param_2 & 8) != 0) {
      local_18[0] = local_18[0] | 8;
    }
    if ((param_2 & 0x40) != 0) {
      local_18[0] = local_18[0] | 0x40;
    }
    if ((param_2 & 0x80) != 0) {
      local_18[0] = local_18[0] | 0x80;
    }
    iVar1 = (**(code **)((&DAT_00009720)[param_1] + 0x6c))
                      (*(undefined4 *)((&DAT_00009720)[param_1] + 0x44),0x81020000,local_18,4);
    if ((DAT_00009710 & 1) != 0) {
      FUN_0000810c(&PTR_DAT_00008c20);
      FUN_0000810c("id %d sceInetNDCC_SET_NEGO_MODE val %d ret %d\n",param_1,local_18[0],iVar1);
    }
    iVar2 = -1;
    if (-1 < iVar1) {
      iVar2 = iVar1;
    }
  }
  return iVar2;
}


================================================================