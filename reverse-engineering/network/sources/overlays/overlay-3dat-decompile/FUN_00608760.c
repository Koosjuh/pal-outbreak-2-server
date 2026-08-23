FUNCTION FUN_00608760 @ 0x00608760  size=216
CALLERS (1): FUN_005f4480@0x005f4480
CALLEES (0): 
----------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void FUN_00608760(void)

{
  if (cRam006c5037 == '\0') {
    bRam00337de1 = bRam00337de1 & 0xfd;
  }
  else {
    bRam00337de1 = bRam00337de1 | 2;
  }
  if (cRam006c503a == '\0') {
    bRam00337de1 = bRam00337de1 & 0xf7;
  }
  else {
    bRam00337de1 = bRam00337de1 | 8;
  }
  if (cRam006c503b == '\0') {
    bRam00337de1 = bRam00337de1 & 0xfe;
  }
  else {
    bRam00337de1 = bRam00337de1 | 1;
  }
  uRam00337e04 = uRam006c5039;
  uRam00337e07 = uRam006c503f;
  uRam00337e03 = uRam006c503e;
  uRam00337e05 = uRam006c503d;
  uRam00337e06 = uRam006c503c;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



================================================================