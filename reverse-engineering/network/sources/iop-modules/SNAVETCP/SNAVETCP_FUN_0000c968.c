FUNCTION FUN_0000c968 @ 0x0000c968 size=184
CALLERS (1): FUN_0000c704@0x0000c704
CALLEES (1): FUN_0000becc@0x0000becc

void FUN_0000c968(short param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00016180 + param_1 * 0x17c;
  *(undefined2 *)(iVar2 + 0x138) = 1;
  *(undefined2 *)(iVar2 + 300) = 0x218;
  *(undefined2 *)(iVar2 + 0x11a) = 0x18;
  *(undefined2 *)(iVar2 + 0x120) = 0xc;
  *(undefined2 *)(iVar2 + 0x13a) = 0;
  *(undefined1 *)(iVar2 + 0x16f) = 0;
  *(undefined1 *)(iVar2 + 0x13f) = 0;
  *(undefined1 *)(iVar2 + 0x13e) = 0;
  *(undefined2 *)(iVar2 + 0x118) = 0;
  *(undefined2 *)(iVar2 + 0x10e) = 0xffff;
  *(undefined2 *)(iVar2 + 0x13c) = 0xffff;
  FUN_0000becc(iVar2);
  iVar1 = (int)DAT_00015740;
  *(undefined1 *)(iVar2 + 0x170) = 0x78;
  *(undefined1 *)(iVar2 + 0x16e) = 0;
  *(undefined2 *)(iVar2 + 0x15c) = 0;
  *(undefined4 *)(iVar2 + 0x160) = 0;
  *(undefined4 *)(iVar2 + 0x168) = 0;
  *(undefined4 *)(iVar2 + 0x130) = 0;
  *(undefined2 *)(iVar2 + 0x174) = 0;
  *(int *)(iVar2 + 0x178) = iVar1;
  return;
}


================================================================