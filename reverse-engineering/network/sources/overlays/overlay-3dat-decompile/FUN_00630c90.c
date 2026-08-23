FUNCTION FUN_00630c90 @ 0x00630c90  size=428
CALLERS (1): FUN_006300a0@0x006300a0
CALLEES (10): FUN_00635ab0@0x00635ab0, FUN_00636f90@0x00636f90, FUN_00631a30@0x00631a30, FUN_00635ed0@0x00635ed0, FUN_00637da0@0x00637da0, FUN_00637140@0x00637140, FUN_00634460@0x00634460, FUN_006320f0@0x006320f0, FUN_00632330@0x00632330, FUN_00634160@0x00634160
----------------------------------------------------------------

void FUN_00630c90(void)

{
  bool bVar1;
  bool bVar2;
  undefined2 uVar3;
  short sVar4;
  long lVar5;
  char acStack_100 [256];
  
  bVar2 = false;
  if (*(char *)(iRam00715da8 + 0x36) == '\0') {
    lVar5 = FUN_00631a30();
    bVar1 = true;
    if (lVar5 == 1) {
      if (*(short *)(*(int *)(iRam00715da8 + 8) + 4) == 0) {
        *(undefined4 *)(iRam00715da8 + 0x248) = 5;
        return;
      }
      if (*(char *)(*(int *)(iRam00715da8 + 8) + 2) == '\x01') {
        FUN_00636f90();
        bVar1 = true;
      }
      else {
        bVar1 = bVar2;
        if (*(char *)(iRam00715da8 + 0x1f) == '\x04') {
          acStack_100[0] = '\0';
          FUN_00634460(acStack_100,iRam00715da8 + 0x2a,
                       *(undefined1 *)(*(int *)(iRam00715da8 + 8) + 3));
          if (acStack_100[0] != '\0') {
            uVar3 = FUN_00634160(iRam00715da8 + 0x4c);
            *(undefined2 *)(iRam00715da8 + 0x2a) = uVar3;
            FUN_00637da0(acStack_100,0x715bb0);
            sVar4 = FUN_006320f0(iRam00715da8 + 0x4c,0x715bb0,*(undefined2 *)(iRam00715da8 + 0x2a),
                                 *(undefined2 *)(iRam00715da8 + 0x3a));
            *(short *)(iRam00715da8 + 0x2a) = *(short *)(iRam00715da8 + 0x2a) + sVar4;
          }
        }
        else {
          FUN_00637140();
          if ((*(char *)(*(int *)(iRam00715da8 + 8) + 2) == '\x02') &&
             (*(char *)(*(int *)(iRam00715da8 + 8) + 3) == '\x03')) {
            FUN_00635ed0();
            bVar1 = true;
          }
          else {
            FUN_00635ab0();
            if ((*(byte *)(iRam00715da8 + 0x4a) & 1) != 0) {
              *(undefined1 *)(iRam00715da8 + 0x32) = 1;
            }
          }
        }
      }
    }
    else {
      FUN_00635ed0();
    }
  }
  else {
    FUN_00632330();
    bVar1 = true;
  }
  if (!bVar1) {
    *(undefined4 *)(iRam00715da8 + 0x248) = 1;
  }
  return;
}



================================================================