FUNCTION FUN_006355a0 @ 0x006355a0  size=852
CALLERS (1): FUN_006352e0@0x006352e0
CALLEES (3): FUN_00634880@0x00634880, FUN_00631ff0@0x00631ff0, FUN_006320f0@0x006320f0
----------------------------------------------------------------

void FUN_006355a0(short param_1)

{
  bool bVar1;
  bool bVar2;
  short sVar3;
  short asStack_4 [2];
  
  bVar1 = false;
  asStack_4[1] = 0;
  bVar2 = bVar1;
  if (cRam00715b78 == '\x04') {
    if (param_1 == 0x75) {
      asStack_4[0] = 0xfc;
    }
    else if (param_1 == 0x55) {
      asStack_4[0] = 0xdc;
    }
    else if (param_1 == 0x6f) {
      asStack_4[0] = 0xf6;
    }
    else if (param_1 == 0x4f) {
      asStack_4[0] = 0xd6;
    }
    else if (param_1 == 0x61) {
      asStack_4[0] = 0xe4;
    }
    else if (param_1 == 0x41) {
      asStack_4[0] = 0xc4;
    }
    else {
      bVar2 = true;
    }
  }
  else if (cRam00715b78 == '\x03') {
    if (param_1 == 0x6e) {
      asStack_4[0] = 0xf1;
    }
    else if (param_1 == 0x4e) {
      asStack_4[0] = 0xd1;
    }
    else {
      bVar2 = true;
    }
  }
  else {
    bVar2 = true;
    if (cRam00715b78 == '\x02') {
      if (param_1 == 0x65) {
        asStack_4[0] = 0xe9;
        bVar2 = bVar1;
      }
      else if (param_1 == 0x45) {
        asStack_4[0] = 0xc9;
        bVar2 = bVar1;
      }
      else {
        bVar2 = true;
      }
    }
    else if (cRam00715b78 == '\x01') {
      if (param_1 == 0x75) {
        asStack_4[0] = 0xf9;
        bVar2 = bVar1;
      }
      else if (param_1 == 0x55) {
        asStack_4[0] = 0xd9;
        bVar2 = bVar1;
      }
      else if (param_1 == 0x65) {
        asStack_4[0] = 0xe8;
        bVar2 = bVar1;
      }
      else if (param_1 == 0x45) {
        asStack_4[0] = 200;
        bVar2 = bVar1;
      }
      else if (param_1 == 0x61) {
        asStack_4[0] = 0xe0;
        bVar2 = bVar1;
      }
      else if (param_1 == 0x41) {
        asStack_4[0] = 0xc0;
        bVar2 = bVar1;
      }
      else {
        bVar2 = true;
      }
    }
    else if (cRam00715b78 == '\0') {
      if (param_1 == 0x75) {
        asStack_4[0] = 0xfb;
        bVar2 = bVar1;
      }
      else if (param_1 == 0x55) {
        asStack_4[0] = 0xdb;
        bVar2 = bVar1;
      }
      else if (param_1 == 0x6f) {
        asStack_4[0] = 0xf4;
        bVar2 = bVar1;
      }
      else if (param_1 == 0x4f) {
        asStack_4[0] = 0xd4;
        bVar2 = bVar1;
      }
      else if (param_1 == 0x69) {
        asStack_4[0] = 0xee;
        bVar2 = bVar1;
      }
      else if (param_1 == 0x49) {
        asStack_4[0] = 0xce;
        bVar2 = bVar1;
      }
      else if (param_1 == 0x65) {
        asStack_4[0] = 0xea;
        bVar2 = bVar1;
      }
      else if (param_1 == 0x45) {
        asStack_4[0] = 0xca;
        bVar2 = bVar1;
      }
      else if (param_1 == 0x61) {
        asStack_4[0] = 0xe2;
        bVar2 = bVar1;
      }
      else if (param_1 == 0x41) {
        asStack_4[0] = 0xc2;
        bVar2 = bVar1;
      }
    }
  }
  if (bVar2) {
    FUN_00631ff0();
    asStack_4[0] = param_1;
  }
  sVar3 = FUN_006320f0(iRam00715da8 + 0x4c,asStack_4,*(undefined2 *)(iRam00715da8 + 0x2a),
                       *(undefined2 *)(iRam00715da8 + 0x3a));
  func_0x00106b60(iRam00715da8 + 0x260,0,0xfa);
  *(short *)(iRam00715da8 + 0x2a) = *(short *)(iRam00715da8 + 0x2a) + sVar3;
  *(undefined2 *)(iRam00715da8 + 0x2c) = 0;
  FUN_00634880();
  *(undefined1 *)(iRam00715da8 + 0x2f) = 0;
  *(undefined4 *)(iRam00715da8 + 0x248) = 1;
  return;
}



================================================================