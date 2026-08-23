FUNCTION FUN_005b53f0 @ 0x005b53f0  size=292
CALLERS (0): 
CALLEES (2): FUN_005f50d0@0x005f50d0, FUN_005c4b90@0x005c4b90
----------------------------------------------------------------

void FUN_005b53f0(void)

{
  long lVar1;
  int iVar2;
  undefined1 auStack_130 [16];
  undefined1 auStack_120 [20];
  undefined1 auStack_10c [256];
  char cStack_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  
  FUN_005c4b90(auStack_130);
  if (cStack_c == '\0') {
LAB_005b54e8:
    FUN_005f50d0(auStack_130,auStack_120,auStack_10c,cStack_c,uStack_b,uStack_a,uStack_9);
  }
  else {
    if (cRam006c4b90 == '\x04') {
      if (cStack_c != '\x04') {
        return;
      }
    }
    else {
      if (cRam006c4b90 != '\f') {
        if ((cRam006c4b90 != '\x02') && (cRam006c4b90 != '\x0e')) {
          return;
        }
        if (cStack_c == '\x04') {
          return;
        }
        goto LAB_005b54e8;
      }
      if (cStack_c != '\f') {
        return;
      }
    }
    for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
      if ((*(char *)(iVar2 * 0x3b0 + 0x6c7c2c) != '\0') &&
         (lVar1 = func_0x00109d70(iVar2 * 0x3b0 + 0x6c7c3c,auStack_120), lVar1 == 0))
      goto LAB_005b54e8;
    }
  }
  return;
}



================================================================