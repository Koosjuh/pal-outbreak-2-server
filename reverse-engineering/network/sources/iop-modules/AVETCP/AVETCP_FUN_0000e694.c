FUNCTION FUN_0000e694 @ 0x0000e694 size=164
CALLERS (0): 
CALLEES (3): FUN_000125c0@0x000125c0, FUN_00014e24@0x00014e24, FUN_0000e14c@0x0000e14c

undefined4 FUN_0000e694(short param_1,undefined4 param_2,undefined4 param_3,short param_4)

{
  if ((DAT_00016178 & 0x80) != 0) {
    FUN_00014e24("ave-tcp: atNdimHandleRcvdPacket: called.\n");
  }
  FUN_0000e14c(&DAT_000185a0,(int)param_4,(int)param_1,param_3);
  if ((DAT_00016178 & 0x80) != 0) {
    FUN_00014e24("ave-tcp: atNdimHandleRcvdPacket: AT_tcp_que_regist\n");
  }
  FUN_000125c0();
  return 0;
}


================================================================