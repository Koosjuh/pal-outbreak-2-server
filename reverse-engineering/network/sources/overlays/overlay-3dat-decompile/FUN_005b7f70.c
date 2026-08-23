FUNCTION FUN_005b7f70 @ 0x005b7f70  size=84
CALLERS (1): FUN_005b76f0@0x005b76f0
CALLEES (1): FUN_005b7f00@0x005b7f00
----------------------------------------------------------------

uint FUN_005b7f70(int param_1,long param_2)

{
  uint uVar1;
  long extraout_a2;
  int extraout_a3_lo;
  int extraout_t0_lo;
  uint uVar2;
  int extraout_t1_lo;
  
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      uVar1 = FUN_005b7f00(param_1);
      uVar2 = extraout_t0_lo + 1U & 0xff;
      param_1 = extraout_t1_lo + (uVar1 & 0xff);
    } while ((long)((long)(int)(extraout_a3_lo + (uVar1 & 0xff)) & 0xffffU) < extraout_a2);
  }
  return uVar2;
}



================================================================