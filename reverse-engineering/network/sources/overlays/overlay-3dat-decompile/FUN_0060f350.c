FUNCTION FUN_0060f350 @ 0x0060f350  size=300
CALLERS (1): FUN_0060e440@0x0060e440
CALLEES (0): 
----------------------------------------------------------------

void FUN_0060f350(byte *param_1,byte *param_2)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  
  while( true ) {
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    if (bVar1 < 0x80) {
      *param_1 = bVar1;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
    else {
      uVar2 = (ushort)param_2[1] * 0x100 + (ushort)param_2[2];
      param_2 = param_2 + 3;
      if ((uVar2 < 0x8181) || (0x81bf < uVar2)) {
        if ((uVar2 < 0x8280) || (0x8293 < uVar2)) {
          if ((uVar2 < 0x82a1) || (0x82bf < uVar2)) {
            if ((uVar2 < 0x8380) || (0x839f < uVar2)) {
              if ((uVar2 < 0x83a0) || (sVar3 = uVar2 - 0x20, 0x83b6 < uVar2)) {
                sVar3 = -0x7ea5;
              }
            }
            else {
              sVar3 = uVar2 - 0x21;
            }
          }
          else {
            sVar3 = uVar2 + 0x9f;
          }
        }
        else {
          sVar3 = uVar2 + 0x5e;
        }
      }
      else {
        sVar3 = uVar2 + 0x11e;
      }
      *param_1 = (byte)((ushort)sVar3 >> 8);
      param_1[1] = (byte)sVar3;
      param_1 = param_1 + 2;
    }
  }
  *param_1 = 0;
  return;
}



================================================================