FUNCTION FUN_005f4040 @ 0x005f4040  size=404
CALLERS (1): FUN_005f3ff0@0x005f3ff0
CALLEES (4): FUN_005de2a0@0x005de2a0, FUN_00606a20@0x00606a20, FUN_005ac610@0x005ac610, FUN_006386f0@0x006386f0
----------------------------------------------------------------

void FUN_005f4040(int param_1)

{
  char cVar1;
  long lVar2;
  
  cVar1 = *(char *)(param_1 + 9);
  if (cVar1 == '\x02') {
    lVar2 = FUN_00606a20();
    if (lVar2 != 0) {
      *(char *)(param_1 + 8) = *(char *)(param_1 + 8) + '\x01';
      *(undefined1 *)(param_1 + 9) = 0;
      uRam0035b746 = 100;
      uRam0035b748 = (undefined2)lVar2;
      FUN_005ac610();
    }
  }
  else {
    if (cVar1 != '\x01') {
      if (cVar1 != '\0') {
        return;
      }
      *(undefined1 *)(param_1 + 9) = 1;
      uRam0034357a = 0xffff;
      func_0x00106b60(0x874500,0,0xa28);
      FUN_005de2a0(iRam003435bc + 0x2ff000);
      func_0x00106b60(uRam003435fc,0,uRam00343600);
      puRam00715298 = (undefined1 *)0x7152e0;
      func_0x00106b60(0x7152e0,0,0x19c);
      *(undefined4 *)(puRam00715298 + 0x108) = 1;
      *puRam00715298 = 0x25;
      puRam00715298[1] = 2;
      func_0x001841d0();
      uRam00343639 = 1;
    }
    func_0x001af970(4,0x5f4220);
    func_0x001ad290();
    if (iRam00337dd0 == 0) {
      func_0x007de660();
      iRam00337dd0 = 1;
    }
    FUN_006386f0();
    func_0x007de630();
    *(char *)(param_1 + 9) = *(char *)(param_1 + 9) + '\x01';
  }
  return;
}



================================================================