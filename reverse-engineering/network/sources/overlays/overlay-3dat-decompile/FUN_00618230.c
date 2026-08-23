FUNCTION FUN_00618230 @ 0x00618230  size=556
CALLERS (4): FUN_006120a0@0x006120a0, FUN_006101d0@0x006101d0, FUN_00610830@0x00610830, FUN_00612020@0x00612020
CALLEES (0): 
----------------------------------------------------------------

uint FUN_00618230(char *param_1)

{
  char cVar1;
  ulong uVar2;
  long lVar3;
  
  cVar1 = *param_1;
  if (cVar1 == '\x02') {
    func_0x001f4630();
    lVar3 = func_0x001f5630(0);
    if (param_1[2] == 0) {
      if (lVar3 == 0) {
        return (uint)(byte)param_1[3];
      }
      *param_1 = '\0';
    }
    else {
      if (lVar3 != 0) {
        return (uint)(byte)(param_1[3] | param_1[2]);
      }
      *param_1 = '\0';
    }
  }
  else if (cVar1 == '\x01') {
    func_0x001f4630();
    uVar2 = func_0x001f5620();
    if (uVar2 != 0xffffffffffffffff) {
      if (uVar2 == 0xffffffffffffff00) {
        func_0x001f46e0();
        *param_1 = '\x02';
        return (uint)(byte)(param_1[3] | param_1[2]);
      }
      if (uVar2 != 0xffffffffffffff02) {
        if (((uVar2 != 0) && (uVar2 != 0xffffffffffffff03)) && (uVar2 != 0xffffffffffffff05)) {
          uVar2 = uVar2 & 0xff;
          if ((uVar2 == 4) || (uVar2 == 3)) {
            param_1[2] = param_1[2] | 2;
          }
          else if (uVar2 == 2) {
            param_1[2] = param_1[2] | 2;
            param_1[3] = param_1[3] | 2;
          }
          func_0x001f46e0();
          *param_1 = '\x02';
          return (uint)(byte)(param_1[3] | param_1[2]);
        }
        func_0x001f46e0();
        param_1[2] = param_1[2] | 2;
        *param_1 = '\x02';
        return (uint)(byte)(param_1[3] | param_1[2]);
      }
      func_0x001f46e0();
      param_1[2] = param_1[2] | 2;
      param_1[3] = param_1[3] | 2;
      *param_1 = '\x02';
      return (uint)(byte)(param_1[3] | param_1[2]);
    }
  }
  else {
    if (cVar1 != '\0') {
      return 0xffffffff;
    }
    *param_1 = '\x01';
    param_1[4] = '\0';
    param_1[2] = '\0';
    param_1[3] = '\0';
    func_0x001f45e0();
    func_0x001f4980(0,iRam003435bc + 0x2ff000,1);
  }
  return 0xffffffff;
}



================================================================