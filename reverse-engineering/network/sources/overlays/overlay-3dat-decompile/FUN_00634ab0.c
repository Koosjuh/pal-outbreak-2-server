FUNCTION FUN_00634ab0 @ 0x00634ab0  size=1408
CALLERS (9): FUN_005faa60@0x005faa60, FUN_0062adb0@0x0062adb0, FUN_00625190@0x00625190, FUN_00614ad0@0x00614ad0, FUN_005dc2b0@0x005dc2b0, FUN_005f4be0@0x005f4be0, FUN_005b45f0@0x005b45f0, FUN_0062d430@0x0062d430, FUN_005f97c0@0x005f97c0
CALLEES (21): FUN_00635030@0x00635030, FUN_00630f20@0x00630f20, FUN_00635ab0@0x00635ab0, FUN_00636f90@0x00636f90, FUN_00635ed0@0x00635ed0, FUN_00633350@0x00633350, FUN_006371f0@0x006371f0, FUN_00635cb0@0x00635cb0, FUN_00637da0@0x00637da0, FUN_00630010@0x00630010, FUN_006352e0@0x006352e0, FUN_00635c60@0x00635c60, ...
----------------------------------------------------------------

undefined1 FUN_00634ab0(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  char cVar1;
  int iVar2;
  ushort uVar3;
  short sVar4;
  ulong uVar5;
  char acStack_100 [256];
  
  *(short *)(iRam00715da8 + 0x18) = *(short *)(iRam00715da8 + 0x18) + 1;
  *(int *)(iRam00715da8 + 0x44) = *(int *)(iRam00715da8 + 0x44) + -1;
  *(char *)(iRam00715da8 + 0x28) = *(char *)(iRam00715da8 + 0x28) + '\x01';
  uVar3 = FUN_00634a50(param_2);
  uVar3 = (ushort)param_2 | uVar3;
  uVar5 = FUN_00634a50(param_3);
  param_3 = param_3 | uVar5;
  if ('\0' < cRam00715b68) {
    cRam00715b68 = cRam00715b68 + -1;
    return 0;
  }
  cRam00715b68 = 0;
  if (cRam00715b70 != '\0') {
    func_0x00106b60(iRam00715da8 + 0x49c,0,10);
    *(char *)(iRam00715da8 + 0x49c) = cRam00715b70;
    *(char *)(iRam00715da8 + 0x49e) = cRam00715b70;
    cRam00715b70 = '\0';
  }
  *(undefined4 *)(iRam00715da8 + 0x248) = 0xffffffff;
  FUN_00630010();
  sVar4 = FUN_00634970(uVar3,(short)param_3);
  uVar5 = (ulong)sVar4;
  if ((uVar5 != 0) && (*(char *)(iRam00715da8 + 0x30) == '\0')) {
    FUN_006371f0();
    FUN_00634970(0,0);
    func_0x001b0140(1);
    return 0;
  }
  if (((uVar5 & 0xf000f) != 0) && ((*(byte *)(iRam00715da8 + 0x4a) & 1) == 0)) {
    FUN_00635030(uVar5,uVar3);
    *(byte *)(iRam00715da8 + 0x4a) = *(byte *)(iRam00715da8 + 0x4a) & 0xfe;
    *(undefined4 *)(iRam00715da8 + 0x248) = 0;
  }
  if ((uVar5 & 0x10) == 0) {
    if ((param_3 & 0x8000) == 0) {
      if ((uVar5 & 0x200) == 0) {
        if ((param_3 & 0x100) == 0) {
          if ((param_3 & 0x20) == 0) {
            if (*(char *)(iRam00715da8 + 0x2f) != '\x01') {
              if ((uVar5 & 0x400) != 0) {
                FUN_00635f80(0);
              }
              if ((uVar5 & 0x800) == 0) {
                if ((uVar5 & 0x80) != 0) {
                  FUN_00635940();
                }
              }
              else {
                FUN_00635c60();
              }
            }
          }
          else {
            FUN_00635ed0(1);
          }
        }
        else {
          FUN_00630f20();
        }
      }
      else {
        FUN_00635cb0(0);
      }
    }
    else {
      FUN_00635ed0();
    }
    goto LAB_00634edc;
  }
  iVar2 = *(int *)(iRam00715da8 + 8);
  if (*(char *)(iRam00715da8 + 0x2f) != '\x01') {
    if ((*(char *)(iRam00715da8 + 0x30) == '\x01') && (*(char *)(iRam00715da8 + 0x26) == '\x01')) {
      *(undefined4 *)(iRam00715da8 + 0x248) = 5;
      goto LAB_00634edc;
    }
    if (*(short *)(iVar2 + 4) == 0) {
      *(undefined4 *)(iRam00715da8 + 0x248) = 5;
      goto LAB_00634edc;
    }
    cVar1 = *(char *)(iVar2 + 2);
    if (cVar1 == '\x04') {
      FUN_00631ff0();
      acStack_100[0] = '\0';
      FUN_00634460(acStack_100,0,*(undefined1 *)(iVar2 + 3));
      if (acStack_100[0] != '\0') {
        FUN_00637da0(acStack_100,0x715bb0);
        sVar4 = FUN_006320f0(iRam00715da8 + 0x4c,0x715bb0,*(undefined2 *)(iRam00715da8 + 0x2a),
                             *(undefined2 *)(iRam00715da8 + 0x3a));
        *(short *)(iRam00715da8 + 0x2a) = *(short *)(iRam00715da8 + 0x2a) + sVar4;
      }
      goto LAB_00634edc;
    }
    if (cVar1 == '\x03') {
      FUN_00635ab0();
      if ((*(byte *)(iRam00715da8 + 0x4a) & 1) != 0) {
        FUN_00635ed0();
      }
      goto LAB_00634edc;
    }
    if (cVar1 == '\x02') {
      cVar1 = *(char *)(iVar2 + 3);
      if (cVar1 == '\x03') {
        FUN_00635ed0();
      }
      else if (cVar1 == '\x01') {
        if (*(char *)(iRam00715da8 + 0x2f) == '\x02') {
          FUN_00630f20();
        }
      }
      else if (cVar1 == '\0') {
        FUN_00635cb0();
      }
      goto LAB_00634edc;
    }
    if (cVar1 == '\x01') {
      FUN_00636f90(iVar2);
      goto LAB_00634edc;
    }
    if (cVar1 == '\0') goto LAB_00634edc;
  }
  FUN_006352e0(iVar2);
  *(undefined1 *)(iRam00715da8 + 0x28) = 0;
LAB_00634edc:
  if (*(char *)(iRam00715da8 + 0x32) != '\0') {
    if (*(char *)(iRam00715da8 + 0x32) == '\x01') {
      FUN_00632c00(iRam00715da8 + 0x4c,0x715bb0);
      cVar1 = *(char *)(iRam00715da8 + 0x1d);
      if (((cVar1 != '\x01') && (cVar1 != '\x05')) && (cVar1 != '\x02')) {
        FUN_00632ce0(0x715bb0);
      }
      func_0x00109eb8(param_1,0x715bb0);
    }
    if (*(char *)(iRam00715da8 + 0x1d) == '\v') {
      *(undefined1 *)(iRam00715da8 + 0x28) = 0;
      *(undefined2 *)(iRam00715da8 + 0x2c) = 0;
      *(undefined4 *)(iRam00715da8 + 0x3c) = 0;
      *(undefined2 *)(iRam00715da8 + 0x2a) = 0;
      *(undefined2 *)(iRam00715da8 + 0x4c) = 0;
      if (*(char *)(iRam00715da8 + 0x32) != -1) {
        *(undefined1 *)(iRam00715da8 + 0x32) = 0;
        FUN_00633350();
      }
    }
    else {
      func_0x001f26e0(0,0,0);
      func_0x001f3458(0);
    }
  }
  if (*(int *)(iRam00715da8 + 0x248) != -1) {
    func_0x001b0140();
  }
  return *(undefined1 *)(iRam00715da8 + 0x32);
}



================================================================