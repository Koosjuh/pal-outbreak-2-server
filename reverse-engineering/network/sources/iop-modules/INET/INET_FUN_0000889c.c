FUNCTION FUN_0000889c @ 0x0000889c size=40
CALLERS (1): FUN_00012170@0x00012170
CALLEES (0): 

void FUN_0000889c(void)

{
  if ((DAT_0001b95c & 1) == 0) {
    DAT_0001b9cc = 0;
    DAT_0001b9d0 = 0;
    DAT_0001b95c = DAT_0001b95c | 1;
  }
  return;
}


================================================================