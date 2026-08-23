
void FUN_001ce740(ulong param_1,undefined2 param_2,undefined2 param_3)

{
  long lVar1;
  long lVar2;
  undefined1 *puVar3;
  undefined1 auStack_100 [3];
  undefined1 auStack_fd [253];
  
  lVar1 = FUN_001ce600(param_1,param_3);
  if ((lVar1 == 0) && (lVar1 = FUN_001ce5b0(), lVar1 != 0)) {
    FUN_00109728(auStack_100,0x24ca70,0x24ca90,param_1 & 0xffff,param_3);
    lVar2 = FUN_001cb360(auStack_fd,uRam0036b9c0,1,0);
    if (0 < lVar2) {
      puVar3 = (undefined1 *)lVar1;
      FUN_001d09e0(uRam0036b9c0,*(undefined4 *)(puVar3 + 4),lVar2,200,0);
      *puVar3 = 1;
      *(undefined2 *)(puVar3 + 2) = param_2;
      *(short *)(puVar3 + 8) = (short)param_1;
      *(undefined2 *)(puVar3 + 0xc) = param_3;
    }
  }
  return;
}

