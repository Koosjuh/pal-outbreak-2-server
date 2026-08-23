FUNCTION FUN_00635cb0 @ 0x00635cb0  size=540
CALLERS (2): FUN_00631030@0x00631030, FUN_00634ab0@0x00634ab0
CALLEES (5): FUN_00634880@0x00634880, FUN_00634970@0x00634970, FUN_00633fa0@0x00633fa0, FUN_006341d0@0x006341d0, FUN_00637e10@0x00637e10
----------------------------------------------------------------

void FUN_00635cb0(void)

{
  char cVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  
  if ((((*(char *)(iRam00715da8 + 0x1d) == '\f') || (*(char *)(iRam00715da8 + 0x1d) == '\r')) ||
      (*(short *)(iRam00715da8 + 0x260) != 0)) || (*(short *)(iRam00715da8 + 0x4c) != 0)) {
    if ((*(byte *)(iRam00715da8 + 0x4a) & 1) == 0) {
      cVar1 = *(char *)(iRam00715da8 + 0x2f);
      if (cVar1 == '\x03') {
        *(undefined1 *)(iRam00715da8 + 0x2f) = 0;
        *(undefined1 *)(iRam00715da8 + 0x26) = 0;
        *(undefined2 *)(iRam00715da8 + 0x260) = 0;
        *(undefined2 *)(iRam00715da8 + 0x2c) = 0;
        FUN_00634880();
      }
      else if (cVar1 == '\x01') {
        *(undefined1 *)(iRam00715da8 + 0x2f) = 0;
        *(undefined1 *)(iRam00715da8 + 0x26) = 0;
        if (*(char *)(iRam00715da8 + 0x36) != '\0') {
          *(undefined2 *)(iRam00715da8 + 0x2c) = 0;
          *(undefined2 *)(iRam00715da8 + 0x260) = 0;
        }
      }
      else if (cVar1 == '\0') {
        iVar5 = iRam00715da8 + 0x260;
        if (*(short *)(iRam00715da8 + 0x260) == 0) {
          sVar2 = *(short *)(iRam00715da8 + 0x2a);
          iVar5 = iRam00715da8 + 0x4c;
          if (sVar2 == 0) {
            return;
          }
          sVar3 = FUN_00633fa0(iVar5,sVar2);
          uVar4 = FUN_006341d0(iVar5,sVar2);
          *(undefined2 *)((uVar4 & 0xffff) * 2 + iVar5 + -2) = 0;
          FUN_00637e10(iVar5);
          *(short *)(iRam00715da8 + 0x2a) = *(short *)(iRam00715da8 + 0x2a) - sVar3;
          if (*(short *)(iRam00715da8 + 0x2a) < 1) {
            *(undefined2 *)(iRam00715da8 + 0x2a) = 0;
            FUN_00634970(0,0);
          }
        }
        else {
          sVar2 = *(short *)(iRam00715da8 + 0x2c);
          if (sVar2 == 0) {
            return;
          }
          FUN_00633fa0(iVar5,sVar2);
          uVar4 = FUN_006341d0(iVar5,sVar2);
          *(undefined2 *)((uVar4 & 0xffff) * 2 + iVar5 + -2) = 0;
          FUN_00637e10(iVar5);
        }
      }
      *(undefined1 *)(iRam00715da8 + 0x28) = 0;
      *(undefined4 *)(iRam00715da8 + 0x248) = 0;
    }
    else {
      *(undefined1 *)(iRam00715da8 + 0x32) = 0xff;
      *(undefined4 *)(iRam00715da8 + 0x248) = 2;
    }
  }
  else {
    *(undefined1 *)(iRam00715da8 + 0x32) = 1;
    *(undefined4 *)(iRam00715da8 + 0x248) = 2;
  }
  return;
}



================================================================