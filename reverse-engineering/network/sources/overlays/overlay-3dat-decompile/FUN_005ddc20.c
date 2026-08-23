FUNCTION FUN_005ddc20 @ 0x005ddc20  size=480
CALLERS (10): FUN_005e3a80@0x005e3a80, FUN_005e5200@0x005e5200, FUN_005e5650@0x005e5650, FUN_005dd660@0x005dd660, FUN_005e2fa0@0x005e2fa0, FUN_005e2060@0x005e2060, FUN_005dbca0@0x005dbca0, FUN_005e4f10@0x005e4f10, FUN_005dc010@0x005dc010, FUN_005e4b00@0x005e4b00
CALLEES (0): 
----------------------------------------------------------------

void FUN_005ddc20(float param_1,float param_2,undefined8 param_3,uint param_4,undefined8 param_5,
                 uint param_6,char *param_7)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char acStack_100 [256];
  
  if ((*param_7 != '\0') && (param_7 != (char *)0x6433a0)) {
    func_0x001af030();
    func_0x001af020(1);
    param_6 = param_6 & 0xff;
    func_0x001af060(param_6,param_6);
    func_0x001af0b0(0);
    func_0x001af0c0((int)((param_4 & 0xff0000) >> 0x10) >> 1 |
                    ((int)((param_4 & 0xff00) >> 8) >> 1) << 8 |
                    ((int)(param_4 & 0xff) >> 1) << 0x10 | 0x80000000U);
    iVar4 = (int)param_2;
    if ((0x10 < (int)(iVar4 + param_6)) && (iVar4 < iRam0028a450 + -0x10)) {
      func_0x001af080((short)(int)param_1,(short)iVar4);
      lVar1 = func_0x00109be0(param_7,0x25);
      if (lVar1 == 0) {
        func_0x0010a050(param_7);
        func_0x001af190(param_7);
        func_0x001af040();
      }
      else {
        uVar2 = 0;
        while (uVar2 < 0xff) {
          if (*param_7 == '\0') {
            acStack_100[uVar2] = '\0';
            goto LAB_005dddb4;
          }
          acStack_100[uVar2] = *param_7;
          uVar3 = uVar2 + 1;
          if (*param_7 == '%') {
            acStack_100[uVar2 + 1] = '%';
            uVar3 = uVar2 + 2;
          }
          param_7 = param_7 + 1;
          uVar2 = uVar3;
        }
        acStack_100[0xff] = 0;
LAB_005dddb4:
        func_0x001af190(acStack_100);
        func_0x001af040();
      }
    }
  }
  return;
}



================================================================