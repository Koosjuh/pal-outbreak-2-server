FUNCTION FUN_0062fa80 @ 0x0062fa80  size=404
CALLERS (0): 
CALLEES (6): FUN_005af2e0@0x005af2e0, FUN_00618c20@0x00618c20, FUN_0062fc40@0x0062fc40, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0, FUN_0062fc20@0x0062fc20
----------------------------------------------------------------

void FUN_0062fa80(undefined8 param_1)

{
  int iVar1;
  undefined1 auStack_80 [128];
  
  if (cRam006c4fd5 == '\0') {
    iVar1 = (int)param_1;
    if (*(char *)(iVar1 + 4) != '\x01') {
      if (*(char *)(iVar1 + 4) != '\0') {
        return;
      }
      *(undefined1 *)(iVar1 + 4) = 1;
      *(undefined1 *)(iVar1 + 1) = 1;
      if (*(char *)(iVar1 + 3) == '\0') {
        FUN_0062fc20();
        *(undefined2 *)(iVar1 + 0x22) = 0x123;
      }
    }
    if (*(char *)(iVar1 + 3) == '\0') {
      FUN_0062fc40(param_1);
      if (uRam006c4fe6 < 4) {
        *(undefined1 *)(iVar1 + 1) = 1;
      }
      else {
        *(undefined1 *)(iVar1 + 1) = 0;
      }
      *(short *)(iVar1 + 0x26) = (sRam006c50ca + -1) * 0x46 + 0xba;
      *(undefined2 *)(iVar1 + 0x28) = 0x138;
      *(undefined2 *)(iVar1 + 0x22) = *(undefined2 *)(&DAT_0066af80 + (uint)uRam006c4fe6 * 2);
    }
    else {
      *(undefined2 *)(iVar1 + 0x22) = 0x11f;
      *(short *)(iVar1 + 0x26) = *(short *)(&DAT_0066af8e + sRam006c50ca * 2) + -0x10;
      *(undefined2 *)(iVar1 + 0x28) = 0x170;
      FUN_005af2e0(0x12);
      FUN_005af2c0(0);
      func_0x00109728(auStack_80,0x66afa0,uRam006c4fe6);
      FUN_005af1e0(*(undefined2 *)(&DAT_0066af8e + sRam006c50ca * 2),0x178,0,auStack_80);
    }
  }
  else {
    uRam006c5c45 = 0;
    FUN_00618c20();
  }
  return;
}



================================================================