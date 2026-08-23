FUNCTION FUN_006343c0 @ 0x006343c0  size=156
CALLERS (1): FUN_006378b0@0x006378b0
CALLEES (1): FUN_00634a40@0x00634a40
----------------------------------------------------------------

undefined4 FUN_006343c0(char *param_1,short *param_2)

{
  char *pcVar1;
  short sVar2;
  
  sVar2 = 0;
  for (pcVar1 = (&PTR_DAT_00690cd0)[bRam00715b60]; *pcVar1 != '\0'; pcVar1 = pcVar1 + 2) {
    *param_1 = *pcVar1;
    sVar2 = sVar2 + 2;
    param_1[1] = pcVar1[1];
    param_1 = param_1 + 2;
  }
  *param_1 = '\0';
  *param_2 = sVar2;
  bRam00715b60 = bRam00715b60 + 1;
  if (0xe < bRam00715b60) {
    bRam00715b60 = 0;
  }
  FUN_00634a40(0);
  return 0xffffffff;
}



================================================================