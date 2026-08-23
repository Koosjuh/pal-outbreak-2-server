FUNCTION FUN_00629200 @ 0x00629200  size=304
CALLERS (1): FUN_00628e10@0x00628e10
CALLEES (4): FUN_005b1460@0x005b1460, FUN_0062a5c0@0x0062a5c0, FUN_005b1420@0x005b1420, FUN_005b0f00@0x005b0f00
----------------------------------------------------------------

undefined4 FUN_00629200(undefined8 param_1,char *param_2)

{
  short sVar1;
  long lVar2;
  int iVar3;
  
  FUN_005b0f00(param_2 + 0xc,2,3);
  lVar2 = FUN_005b1420();
  if (lVar2 == 0) {
    lVar2 = FUN_005b1460();
    if (lVar2 != 0) {
      func_0x001b0140(2);
      *param_2 = '\0';
      param_2[1] = '\0';
    }
  }
  else {
    sVar1 = *(short *)(param_2 + 0xc);
    if (sVar1 == 2) {
      *param_2 = '\b';
      param_2[1] = '\0';
      param_2[2] = '\0';
    }
    else if (sVar1 == 1) {
      *param_2 = *param_2 + '\x01';
      param_2[0x14] = '\x01';
      param_2[4] = '\b';
      param_2[5] = '\0';
      func_0x001b0140();
      iVar3 = (int)param_1;
      func_0x00106b60(iVar3 + 0x1044,0,0x25);
      func_0x00106b60(iVar3 + 0x1069,0,0x25);
      func_0x00106b60(iVar3 + 0x108e,0,0x25);
      func_0x00109eb8(iVar3 + 0x1045,iVar3 + 0xefb);
      func_0x00109eb8(iVar3 + 0x1055,iVar3 + 0xf0b);
      FUN_0062a5c0(param_1);
    }
    else if (sVar1 == 0) {
      *param_2 = '\a';
      param_2[1] = '\0';
      param_2[2] = '\0';
    }
  }
  return 0xffffffff;
}



================================================================