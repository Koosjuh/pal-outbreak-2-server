FUNCTION FUN_0062b500 @ 0x0062b500  size=288
CALLERS (1): FUN_0062b2c0@0x0062b2c0
CALLEES (1): FUN_0062b620@0x0062b620
----------------------------------------------------------------

void FUN_0062b500(char *param_1,char *param_2)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  
  bVar1 = false;
  do {
    if (bVar1) {
      return;
    }
    if (*param_1 == '<') {
      func_0x00106b60(0x715480,0,0x20);
      param_1 = (char *)FUN_0062b620(param_1);
      iVar2 = 0;
      while ((iVar2 < 0xb &&
             (lVar3 = func_0x0010a700(0x715480,(&PTR_s_DUMMY_0066ae10)[iVar2]), lVar3 == 0))) {
        iVar2 = iVar2 + 1;
      }
      switch(iVar2) {
      case 0:
      case 1:
      case 5:
      case 6:
      case 7:
        break;
      default:
        func_0x00109ab0(param_2,0x715480);
        iVar2 = func_0x001ae3e0(0x715480);
        param_2 = param_2 + iVar2;
        break;
      case 8:
        bVar1 = true;
      }
    }
    else {
      *param_2 = *param_1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
  } while( true );
}



================================================================