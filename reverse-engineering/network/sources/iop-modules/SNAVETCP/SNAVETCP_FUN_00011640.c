FUNCTION FUN_00011640 @ 0x00011640 size=76
CALLERS (1): FUN_00005828@0x00005828
CALLEES (1): FUN_00000200@0x00000200

undefined4 FUN_00011640(int param_1,undefined4 param_2,int param_3,ushort param_4)

{
  if (param_3 != 0) {
    FUN_00000200(param_3,(int)(short)(param_4 | 0xc0),param_1,(int)*(short *)(param_1 + 4),param_2,0
                );
  }
  return 0;
}


================================================================