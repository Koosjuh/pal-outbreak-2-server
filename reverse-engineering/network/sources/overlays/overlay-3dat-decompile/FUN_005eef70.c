FUNCTION FUN_005eef70 @ 0x005eef70  size=208
CALLERS (20): FUN_005eee00@0x005eee00, FUN_005e8720@0x005e8720, FUN_005e9910@0x005e9910, FUN_005e8d10@0x005e8d10, FUN_005e8d30@0x005e8d30, FUN_005ea120@0x005ea120, FUN_005e9d50@0x005e9d50, FUN_005e9d90@0x005e9d90, FUN_005e9a10@0x005e9a10, FUN_005e86c0@0x005e86c0, FUN_005e86f0@0x005e86f0, FUN_005e9d20@0x005e9d20, ...
CALLEES (4): FUN_005ec170@0x005ec170, FUN_005f3ac0@0x005f3ac0, FUN_005eeca0@0x005eeca0, FUN_005eea60@0x005eea60
----------------------------------------------------------------

void FUN_005eef70(undefined8 param_1)

{
  int iStack_4;
  
  if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
    iStack_4 = iRam007012a0 + (uint)*(ushort *)(iRam007012a0 + 0x188) * 4 + 0x1540;
    FUN_005eea60(param_1,&iStack_4);
    FUN_005eeca0(iStack_4);
    *(undefined2 *)(iRam007012a0 + 0xd8bc) = *(undefined2 *)(iRam007012a0 + 0xd8c0);
    *(undefined2 *)(iRam007012a0 + 0xd8be) = *(undefined2 *)(iRam007012a0 + 0xd8c2);
    FUN_005ec170(iRam007012a0 + 0xd8bc);
    *(undefined4 *)(iRam007012a0 + 4) = 0;
    *(undefined1 *)param_1 = 0;
  }
  else {
    FUN_005f3ac0();
  }
  return;
}



================================================================