FUNCTION FUN_005ec920 @ 0x005ec920  size=232
CALLERS (7): FUN_005ea190@0x005ea190, FUN_005eb990@0x005eb990, FUN_005eb9f0@0x005eb9f0, FUN_005e94c0@0x005e94c0, FUN_005eb300@0x005eb300, FUN_005eb350@0x005eb350, FUN_005e60c0@0x005e60c0
CALLEES (0): 
----------------------------------------------------------------

undefined1 FUN_005ec920(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  long lVar3;
  uint uVar4;
  undefined1 auStack_100 [256];
  
  uVar1 = func_0x0010a050();
  for (uVar4 = 0; uVar4 < (uVar1 & 0xffff); uVar4 = uVar4 + 1 & 0xffff) {
    auStack_100[uVar4] = (&DAT_006493b0)[*(byte *)(param_1 + uVar4)];
  }
  auStack_100[uVar4] = 0;
  uVar1 = 0;
  while( true ) {
    if ((param_3 >> 3 & 0xffff) <= uVar1) {
      return 0;
    }
    puVar2 = (undefined4 *)(param_2 + uVar1 * 8);
    lVar3 = func_0x0010a338(auStack_100,*puVar2,*(undefined1 *)(puVar2 + 1));
    if (lVar3 == 0) break;
    uVar1 = uVar1 + 1 & 0xffff;
  }
  return *(undefined1 *)(uVar1 * 8 + param_2 + 5);
}



================================================================