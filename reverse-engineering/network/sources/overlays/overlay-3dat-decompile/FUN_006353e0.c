FUNCTION FUN_006353e0 @ 0x006353e0  size=288
CALLERS (1): FUN_006352e0@0x006352e0
CALLEES (5): FUN_00631ff0@0x00631ff0, FUN_00634970@0x00634970, FUN_006343b0@0x006343b0, FUN_00635900@0x00635900, FUN_006320f0@0x006320f0
----------------------------------------------------------------

void FUN_006353e0(int param_1)

{
  short sVar1;
  long lVar2;
  undefined2 uStack_4;
  undefined2 uStack_2;
  
  lVar2 = FUN_00635900();
  if (lVar2 == 0) {
    return;
  }
  lVar2 = FUN_006343b0();
  if (lVar2 == 0) {
    if (*(short *)(iRam00715da8 + 0x260) != 0) {
      FUN_00631ff0();
      FUN_00634970(0,0);
    }
  }
  else if (*(short *)(param_1 + 4) == 0x20) {
    if (*(char *)(iRam00715da8 + 0x2f) == '\x01') {
LAB_006354cc:
      FUN_00631ff0();
      FUN_00634970(0,0);
      *(undefined4 *)(iRam00715da8 + 0x248) = 1;
      return;
    }
    if (*(short *)(iRam00715da8 + 0x260) != 0) {
      return;
    }
  }
  else if (*(char *)(iRam00715da8 + 0x2f) != '\0') goto LAB_006354cc;
  uStack_4 = *(undefined2 *)(param_1 + 4);
  uStack_2 = 0;
  sVar1 = FUN_006320f0(iRam00715da8 + 0x4c,&uStack_4,*(undefined2 *)(iRam00715da8 + 0x2a),
                       *(undefined2 *)(iRam00715da8 + 0x3a));
  *(short *)(iRam00715da8 + 0x2a) = *(short *)(iRam00715da8 + 0x2a) + sVar1;
  *(undefined4 *)(iRam00715da8 + 0x248) = 1;
  return;
}



================================================================