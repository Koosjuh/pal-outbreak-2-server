FUNCTION FUN_005f9540 @ 0x005f9540  size=636
CALLERS (1): FUN_005f9150@0x005f9150
CALLEES (9): FUN_005fc850@0x005fc850, FUN_005b14b0@0x005b14b0, FUN_00618b60@0x00618b60, FUN_005f9bb0@0x005f9bb0, FUN_005f8c20@0x005f8c20, FUN_005f9d40@0x005f9d40, FUN_005f9e50@0x005f9e50, FUN_005f9f60@0x005f9f60, FUN_005b09b0@0x005b09b0
----------------------------------------------------------------

void FUN_005f9540(undefined8 param_1)

{
  char cVar1;
  undefined1 uVar2;
  long lVar3;
  int iVar4;
  
  iVar4 = (int)param_1;
  cVar1 = *(char *)(iVar4 + 0x10);
  if (cVar1 == '\x02') {
    lVar3 = FUN_005b14b0(0x220);
    if (lVar3 != 0) {
      *(undefined1 *)(iVar4 + 0x10) = 1;
      *(undefined1 *)(iVar4 + 0x11) = 0;
      FUN_00618b60();
      FUN_005fc850(2);
      func_0x001b0140(1);
    }
  }
  else if (cVar1 == '\x01') {
    lVar3 = FUN_005b14b0(0x10);
    if (lVar3 == 0) {
      lVar3 = FUN_005b14b0(0x200);
      if (lVar3 == 0) {
        uVar2 = *(undefined1 *)(iVar4 + 0x908);
        lVar3 = FUN_005b09b0(iVar4 + 0x908,10,2);
        if (lVar3 == 0) {
          lVar3 = FUN_005b14b0(0x20);
          if (lVar3 == 0) {
            cVar1 = *(char *)(iVar4 + 0x908);
            if ((cVar1 < '\x02') || ('\a' < cVar1)) {
              if (cVar1 == '\b') {
                FUN_005f9f60(param_1);
              }
              else if (cVar1 == '\t') {
                FUN_005b09b0(iVar4 + 4,(int)*(short *)(iVar4 + 10) - 1U & 0xff,1);
              }
            }
            else {
              FUN_005f9e50(cVar1 + -2);
            }
          }
          else {
            *(char *)(iVar4 + 0x10) = *(char *)(iVar4 + 0x10) + '\x01';
            *(undefined1 *)(iVar4 + 0x11) = 0;
            FUN_005fc850(3);
            func_0x001b0140(1);
          }
        }
        else {
          uVar2 = FUN_005f9bb0(*(undefined1 *)(iVar4 + 0x908),uVar2);
          *(undefined1 *)(iVar4 + 0x908) = uVar2;
          if (('\x01' < *(char *)(iVar4 + 0x908)) && (*(char *)(iVar4 + 0x908) != '\n')) {
            FUN_005f9d40();
          }
        }
      }
      else {
        func_0x001b0140(2);
        FUN_005f8c20(param_1,3);
      }
    }
    else {
      cVar1 = *(char *)(iVar4 + 0x908);
      if (((cVar1 == '\n') || (cVar1 == '\x01')) || (cVar1 == '\0')) {
        *(char *)(iVar4 + 0xf) = *(char *)(iVar4 + 0xf) + '\x01';
        *(undefined1 *)(iVar4 + 0x10) = 0;
        func_0x001b0140(1);
      }
    }
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(iVar4 + 0x10) = 1;
    if (cRam006970a0 == '\0') {
      func_0x00109eb8(0x6970b2,(bRam006c4600 - 1) * 0x15c + 0x6c0778);
      if (cRam006970a1 == '\0') {
        *(undefined1 *)(iVar4 + 0x908) = 2;
      }
      else {
        *(undefined1 *)(iVar4 + 0x908) = 1;
      }
    }
    uVar2 = FUN_005f9bb0(*(undefined1 *)(iVar4 + 0x908),0);
    *(undefined1 *)(iVar4 + 0x908) = uVar2;
  }
  return;
}



================================================================