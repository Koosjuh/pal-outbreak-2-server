FUNCTION FUN_00014384 @ 0x00014384 size=96
CALLERS (1): FUN_00014c70@0x00014c70
CALLEES (2): FUN_00014e24@0x00014e24, FUN_00013964@0x00013964

void FUN_00014384(short param_1)

{
  if ((DAT_00016178 & 0x40) != 0) {
    FUN_00014e24("DNS_ReleaseTicket() ticket_id %d\n",(int)param_1);
  }
  if (param_1 != -1) {
    FUN_00013964();
  }
  return;
}


================================================================