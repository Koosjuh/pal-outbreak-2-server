FUNCTION FUN_006331a0 @ 0x006331a0  size=108
CALLERS (1): FUN_00632d20@0x00632d20
CALLEES (1): FUN_00633210@0x00633210
----------------------------------------------------------------

bool FUN_006331a0(undefined8 param_1)

{
  bool bVar1;
  long lVar2;
  byte abStack_4 [4];
  
  if (*(char *)param_1 == '\0') {
    bVar1 = true;
  }
  else {
    func_0x001af430(param_1,abStack_4);
    if ((&DAT_0068ef90)[abStack_4[0]] == '\0') {
      bVar1 = true;
    }
    else {
      lVar2 = FUN_00633210(param_1,0x68b6e0);
      bVar1 = lVar2 != 0;
    }
  }
  return bVar1;
}



================================================================