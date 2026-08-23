FUNCTION FUN_00014238 @ 0x00014238 size=332
CALLERS (1): FUN_00014c40@0x00014c40
CALLEES (4): FUN_0001285c@0x0001285c, FUN_00014e24@0x00014e24, FUN_0001388c@0x0001388c, FUN_00013710@0x00013710

int FUN_00014238(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  if ((DAT_00016178 & 0x40) != 0) {
    FUN_00014e24("DNS_GetTicket() host %s\n",param_1);
  }
  if (param_2 == 0) {
    if ((DAT_00016178 & 0x40) == 0) {
      return -1;
    }
    pcVar3 = "DNS_GetTicket() error %d ticket_area is null.\n";
  }
  else {
    iVar1 = FUN_00013710(param_2);
    if (iVar1 < 0) {
      if ((DAT_00016178 & 0x40) == 0) {
        return -1;
      }
      pcVar3 = "DNS_GetTicket() error %d can\'t get ticket id.\n";
    }
    else {
      iVar4 = (int)(short)iVar1;
      iVar2 = FUN_0001388c(0,0x3500,0,iVar4);
      if (iVar2 == 0) {
        FUN_0001285c((&DAT_00016fa0)[iVar1] + 0x818,param_1);
        if ((DAT_00016178 & 0x40) == 0) {
          return iVar4;
        }
        FUN_00014e24("DNS_GetTicket() return ticket_id %d\n",iVar1);
        return iVar4;
      }
      if ((DAT_00016178 & 0x40) == 0) {
        return -1;
      }
      pcVar3 = "DNS_GetTicket() error %d adns_udp_open error.\n";
    }
  }
  FUN_00014e24(pcVar3,0xffffffff);
  return -1;
}


================================================================