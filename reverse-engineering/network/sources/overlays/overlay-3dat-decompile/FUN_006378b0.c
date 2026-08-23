FUNCTION FUN_006378b0 @ 0x006378b0  size=184
CALLERS (2): FUN_00636f90@0x00636f90, FUN_00635f80@0x00635f80
CALLEES (5): FUN_00631ff0@0x00631ff0, FUN_00637da0@0x00637da0, FUN_006343c0@0x006343c0, FUN_006320f0@0x006320f0, FUN_00634160@0x00634160
----------------------------------------------------------------

void FUN_006378b0(void)

{
  undefined2 uVar1;
  short sVar2;
  long lVar3;
  char acStack_100 [256];
  
  FUN_00631ff0();
  acStack_100[0] = '\0';
  lVar3 = FUN_006343c0(acStack_100,iRam00715da8 + 0x2a);
  if (lVar3 < 0) {
    *(byte *)(iRam00715da8 + 0x35) = *(byte *)(iRam00715da8 + 0x35) | 0xf;
  }
  uVar1 = FUN_00634160(iRam00715da8 + 0x4c);
  *(undefined2 *)(iRam00715da8 + 0x2a) = uVar1;
  if (acStack_100[0] != '\0') {
    FUN_00637da0(acStack_100,0x715bb0);
    sVar2 = FUN_006320f0(iRam00715da8 + 0x4c,0x715bb0,*(undefined2 *)(iRam00715da8 + 0x2a),
                         *(undefined2 *)(iRam00715da8 + 0x3a));
    *(short *)(iRam00715da8 + 0x2a) = *(short *)(iRam00715da8 + 0x2a) + sVar2;
  }
  return;
}



================================================================