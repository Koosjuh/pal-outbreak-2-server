FUNCTION FUN_000115f0 @ 0x000115f0 size=80
CALLERS (1): FUN_00003840@0x00003840
CALLEES (1): FUN_00000200@0x00000200

undefined4
FUN_000115f0(int param_1,undefined4 param_2,undefined2 param_3,int param_4,ushort param_5)

{
  if (param_4 != 0) {
    FUN_00000200(param_4,(int)(short)(param_5 | 0x80),param_1,(int)*(short *)(param_1 + 4),param_2,
                 param_3);
  }
  return 0;
}


================================================================