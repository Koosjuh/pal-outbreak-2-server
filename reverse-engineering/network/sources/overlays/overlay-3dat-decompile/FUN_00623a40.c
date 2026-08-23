FUNCTION FUN_00623a40 @ 0x00623a40  size=200
CALLERS (1): FUN_00622f40@0x00622f40
CALLEES (0): 
----------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void FUN_00623a40(undefined4 param_1)

{
  *(undefined1 *)(iRam00715298 + 0xd) = 0;
  *(undefined1 *)(iRam00715298 + 0x79) = 0;
  *(undefined1 *)(iRam00715298 + 0x160) = 0;
  *(undefined1 *)(iRam00715298 + 0x161) = 0;
  *(undefined1 *)(iRam00715298 + 0x162) = 0;
  *(undefined1 *)(iRam00715298 + 0x163) = 0;
  *(undefined4 *)(iRam00715298 + 0x164) = 0;
  *(undefined4 *)(iRam00715298 + 0x168) = param_1;
  *(int *)(iRam00715298 + 0x170) = iRam003435bc + 0x2ff000;
  *(int *)(iRam00715298 + 0x174) = iRam003435bc + 0x31f000;
  *(int *)(iRam00715298 + 0x178) = iRam003435bc + 0x33f000;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



================================================================