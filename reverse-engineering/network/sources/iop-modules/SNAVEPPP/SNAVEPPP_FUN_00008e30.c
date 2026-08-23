FUNCTION FUN_00008e30 @ 0x00008e30 size=168
CALLERS (7): FUN_0000985c@0x0000985c, FUN_00009044@0x00009044, FUN_000097c0@0x000097c0, FUN_000096d8@0x000096d8, FUN_0000a7ac@0x0000a7ac, FUN_0000a624@0x0000a624, FUN_0000a40c@0x0000a40c
CALLEES (0): 

undefined * FUN_00008e30(undefined1 param_1)

{
  switch(param_1) {
  case 0:
    return PTR_s_Closed_00012e80;
  case 1:
    return PTR_s_Listen_00012e84;
  case 2:
    return PTR_s_Req_Sent_00012e88;
  case 3:
    return PTR_s_Ack_Rcvd_00012e8c;
  case 4:
    return PTR_s_Ack_Sent_00012e90;
  case 5:
    return PTR_s_Opened_00012e94;
  case 6:
    return PTR_s_Term_Sent_00012e98;
  default:
    return PTR_DAT_00012e9c;
  }
}


================================================================