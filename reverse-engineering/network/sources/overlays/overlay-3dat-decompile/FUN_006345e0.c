FUNCTION FUN_006345e0 @ 0x006345e0  size=668
CALLERS (9): FUN_005dc1e0@0x005dc1e0, FUN_005faa60@0x005faa60, FUN_0062adb0@0x0062adb0, FUN_00625190@0x00625190, FUN_0062d3d0@0x0062d3d0, FUN_005f4be0@0x005f4be0, FUN_005b45f0@0x005b45f0, FUN_006149f0@0x006149f0, FUN_005f97c0@0x005f97c0
CALLEES (15): FUN_00634880@0x00634880, FUN_00637210@0x00637210, FUN_006362e0@0x006362e0, FUN_00633350@0x00633350, FUN_006371f0@0x006371f0, FUN_00634540@0x00634540, FUN_00637da0@0x00637da0, FUN_00634890@0x00634890, FUN_00634470@0x00634470, FUN_00637250@0x00637250, FUN_00637230@0x00637230, FUN_00637710@0x00637710, ...
----------------------------------------------------------------

void FUN_006345e0(int param_1,undefined8 param_2,ushort param_3,long param_4)

{
  undefined2 uVar1;
  
  *(int *)(iRam00715da8 + 0x10) = param_1 * 0x30 + 0x690b90;
  FUN_00637250();
  FUN_00637210();
  if (0xfa < param_3) {
    param_3 = 0xfa;
  }
  *(ushort *)(iRam00715da8 + 0x3a) = param_3;
  FUN_00634880();
  uRam00715b68 = 1;
  cRam00715b70 = *(char *)(iRam00715da8 + 0x49c);
  if ((((cRam00715b70 == 'X') || (cRam00715b70 == '*')) || (cRam00715b70 == ')')) ||
     (cRam00715b70 == '(')) {
    cRam00715b70 = '\0';
  }
  *(undefined1 *)(iRam00715da8 + 0x1e) = *(undefined1 *)(*(int *)(iRam00715da8 + 0x10) + 0x1d);
  *(undefined1 *)(iRam00715da8 + 0x35) = 0;
  *(undefined1 *)(iRam00715da8 + 0x4a) = 0;
  *(undefined2 *)(iRam00715da8 + 0x48) = 0;
  *(undefined1 *)(iRam00715da8 + 0x36) = 0;
  FUN_00634890(param_2);
  FUN_00637710();
  FUN_00636190(0);
  FUN_00636190(8);
  FUN_006362e0();
  *(undefined1 *)(iRam00715da8 + 0x24) = 1;
  *(undefined1 *)(iRam00715da8 + 0x25) = 0;
  FUN_00634470();
  *(undefined1 *)(iRam00715da8 + 0x2f) = 0;
  *(undefined1 *)(iRam00715da8 + 0x32) = 0;
  *(undefined1 *)(iRam00715da8 + 0x36) = 0;
  *(undefined1 *)(iRam00715da8 + 0x26) = 0;
  *(undefined1 *)(iRam00715da8 + 0x27) = 1;
  *(undefined1 *)(iRam00715da8 + 0x28) = 0;
  *(undefined2 *)(iRam00715da8 + 0x2c) = 0;
  *(undefined4 *)(iRam00715da8 + 0x3c) = 0;
  if (param_4 == 0) {
    *(undefined2 *)(iRam00715da8 + 0x2a) = 0;
    *(undefined2 *)(iRam00715da8 + 0x4c) = 0;
  }
  else {
    FUN_00637da0(param_4,iRam00715da8 + 0x4c);
    uVar1 = FUN_00634160(iRam00715da8 + 0x4c);
    *(undefined2 *)(iRam00715da8 + 0x2a) = uVar1;
  }
  FUN_00634970(0,0);
  FUN_006371f0();
  FUN_00637230();
  FUN_00633350();
  func_0x00106b60(iRam00715da8 + 0x49c,0,10);
  func_0x001f26e0(0,10,4);
  func_0x00106b60(0x715b90,0,4);
  uRam00715b80 = 0xffff;
  FUN_00634540(0);
  return;
}



================================================================