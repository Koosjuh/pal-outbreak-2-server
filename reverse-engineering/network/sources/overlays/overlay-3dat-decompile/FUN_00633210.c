FUNCTION FUN_00633210 @ 0x00633210  size=136
CALLERS (1): FUN_006331a0@0x006331a0
CALLEES (1): FUN_006332a0@0x006332a0
----------------------------------------------------------------

undefined4 FUN_00633210(undefined8 param_1,char *param_2)

{
  undefined8 uVar1;
  long lVar2;
  undefined1 auStack_100 [256];
  
  uVar1 = func_0x0010a050();
  while( true ) {
    if (*param_2 == '\0') {
      return 0;
    }
    lVar2 = FUN_006332a0(param_2,auStack_100,uVar1);
    if ((lVar2 != -1) && (lVar2 = func_0x0010a338(param_1,auStack_100,lVar2), lVar2 == 0)) break;
    param_2 = param_2 + 0x10;
  }
  return 1;
}



================================================================