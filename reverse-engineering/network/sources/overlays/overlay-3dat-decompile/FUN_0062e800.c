FUNCTION FUN_0062e800 @ 0x0062e800  size=196
CALLERS (1): FUN_0062e3c0@0x0062e3c0
CALLEES (4): FUN_005b6900@0x005b6900, FUN_005c0750@0x005c0750, FUN_005b68e0@0x005b68e0, FUN_005aec20@0x005aec20
----------------------------------------------------------------

void FUN_0062e800(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x10);
  if (cVar1 == '\x02') {
    *(undefined1 *)(param_1 + 0x146b) = 0;
    uRam006c4fd5 = 1;
    uRam006c4b9e = 1;
    uRam006c5530 = 0x708;
    uRam006c4b9f = 0;
    uRam006c4ba0 = 0;
    uRam006c4ba1 = 0;
    FUN_005aec20();
  }
  else if (cVar1 == '\x01') {
    FUN_005b6900();
  }
  else if (cVar1 == '\0') {
    FUN_005b68e0();
    *(undefined1 *)(param_1 + 0x42b) = 0x19;
    FUN_005c0750(0x62f3f0);
    *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
  }
  return;
}



================================================================