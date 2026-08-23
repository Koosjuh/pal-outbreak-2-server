FUNCTION FUN_0062d430 @ 0x0062d430  size=172
CALLERS (1): FUN_0062d380@0x0062d380
CALLEES (3): FUN_00637180@0x00637180, FUN_00604860@0x00604860, FUN_00634ab0@0x00634ab0
----------------------------------------------------------------

undefined4 FUN_0062d430(int param_1,undefined8 param_2,int param_3)

{
  char cVar1;
  
  cVar1 = FUN_00634ab0(param_3 + 0x11,uRam006c4610,uRam006c4618 | uRam006c4620);
  if (cVar1 != -1) {
    if (cVar1 != '\x01') {
      return 0;
    }
    FUN_00604860(0x694700,0x32,param_3 + 0x11);
    func_0x00106b60(param_1 + 0x12c2,0,0x19e);
  }
  FUN_00637180();
  return 1;
}



================================================================