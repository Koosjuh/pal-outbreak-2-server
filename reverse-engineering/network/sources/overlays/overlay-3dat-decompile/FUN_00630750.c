FUNCTION FUN_00630750 @ 0x00630750  size=448
CALLERS (1): FUN_006352e0@0x006352e0
CALLEES (6): FUN_00630910@0x00630910, FUN_00631ff0@0x00631ff0, FUN_00637980@0x00637980, FUN_00637d10@0x00637d10, FUN_006320f0@0x006320f0, FUN_00635500@0x00635500
----------------------------------------------------------------

void FUN_00630750(short param_1)

{
  char cVar1;
  long lVar2;
  undefined1 auStack_8 [4];
  short asStack_4 [2];
  
  asStack_4[1] = 0;
  asStack_4[0] = param_1;
  FUN_00637d10(param_1,auStack_8);
  lVar2 = func_0x001af420(auStack_8);
  if (lVar2 == 2) {
    if ((*(char *)(iRam00715da8 + 0x1d) == '\b') && (lVar2 = FUN_00637980(asStack_4[0]), lVar2 != 0)
       ) {
      return;
    }
    if (((*(byte *)(iRam00715da8 + 0x33) & 2) != 0) && (asStack_4[0] == -0xfb)) {
      return;
    }
    if (asStack_4[0] != 0x20) {
      lVar2 = FUN_006320f0(iRam00715da8 + 0x4c,asStack_4,*(undefined2 *)(iRam00715da8 + 0x2a),
                           *(undefined2 *)(iRam00715da8 + 0x3a));
      *(short *)(iRam00715da8 + 0x2a) = *(short *)(iRam00715da8 + 0x2a) + (short)lVar2;
      goto LAB_006308e0;
    }
    if (*(short *)(iRam00715da8 + 0x260) != 0) {
      return;
    }
    if (*(char *)(iRam00715da8 + 0x4a4) != ',') {
      return;
    }
  }
  else {
    if (lVar2 != 1) goto LAB_006308e0;
    lVar2 = FUN_00630910(asStack_4[0]);
    if (lVar2 == 0) {
      return;
    }
    if (*(short *)(iRam00715da8 + 0x260) != 0) {
      FUN_00631ff0();
    }
    cVar1 = FUN_00635500(asStack_4[0]);
    if (-1 < cVar1) {
      *(undefined1 *)(iRam00715da8 + 0x2f) = 3;
      lVar2 = FUN_006320f0(iRam00715da8 + 0x260,asStack_4,*(undefined2 *)(iRam00715da8 + 0x2c),
                           *(undefined2 *)(iRam00715da8 + 0x3a));
      goto LAB_006308e0;
    }
  }
  lVar2 = FUN_006320f0(iRam00715da8 + 0x4c,asStack_4,*(undefined2 *)(iRam00715da8 + 0x2a),
                       *(undefined2 *)(iRam00715da8 + 0x3a));
  *(short *)(iRam00715da8 + 0x2a) = *(short *)(iRam00715da8 + 0x2a) + (short)lVar2;
LAB_006308e0:
  if (lVar2 != 0) {
    *(undefined1 *)(iRam00715da8 + 0x28) = 0;
  }
  *(undefined4 *)(iRam00715da8 + 0x248) = 1;
  return;
}



================================================================