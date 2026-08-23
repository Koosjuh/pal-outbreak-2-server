FUNCTION FUN_005f5ec0 @ 0x005f5ec0  size=192
CALLERS (2): FUN_005fe620@0x005fe620, FUN_005f76f0@0x005f76f0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005f5ec0(int param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  *(undefined1 *)(param_1 + 1) = 0;
  iVar3 = 0;
  *(undefined1 *)(param_1 + 0xe) = 0;
  *(undefined1 *)(param_1 + 0xf) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined1 *)(param_1 + 0x11) = 0;
  iVar2 = 0;
  do {
    iVar2 = (iVar2 + iVar3) * 0x10;
    if ((*(uint *)(iVar2 + 0x70a17c) & 0x80) != 0) {
      iVar5 = 0;
      iVar4 = 0x695d60;
      do {
        lVar1 = func_0x0010a338(iVar4 + 0x14,iVar2 + 0x70a164,0x10);
        if (lVar1 == 0) {
          *(uint *)(iVar4 + 0x2c) = *(uint *)(iVar2 + 0x70a17c) & 0x7f;
        }
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 0x30;
      } while (iVar5 < 100);
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar3 * 2;
  } while (iVar3 < 100);
  return;
}



================================================================