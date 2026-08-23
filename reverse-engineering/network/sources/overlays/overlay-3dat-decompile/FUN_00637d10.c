FUNCTION FUN_00637d10 @ 0x00637d10  size=132
CALLERS (10): FUN_00634280@0x00634280, FUN_00630750@0x00630750, FUN_006340d0@0x006340d0, FUN_00634010@0x00634010, FUN_00633fa0@0x00633fa0, FUN_006341d0@0x006341d0, FUN_006320f0@0x006320f0, FUN_00634310@0x00634310, FUN_00634160@0x00634160, FUN_00632c00@0x00632c00
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_00637d10(ulong param_1,byte *param_2)

{
  undefined4 uVar1;
  byte bVar2;
  uint uVar3;
  
  bVar2 = (byte)param_1;
  if (param_1 < 0x80) {
    *param_2 = bVar2;
    uVar1 = 1;
    param_2[1] = 0;
  }
  else {
    uVar3 = (uint)param_1;
    if (param_1 < 0x800) {
      *param_2 = (byte)(uVar3 >> 6) & 0x1f | 0xc0;
      uVar1 = 2;
      param_2[1] = bVar2 & 0x3f | 0x80;
      param_2[2] = 0;
    }
    else {
      *param_2 = (byte)(uVar3 >> 0xc) & 0x1f | 0xe0;
      param_2[1] = (byte)(uVar3 >> 6) & 0x3f | 0x80;
      param_2[2] = bVar2 & 0x3f | 0x80;
      uVar1 = 3;
      param_2[3] = 0;
    }
  }
  return uVar1;
}



================================================================