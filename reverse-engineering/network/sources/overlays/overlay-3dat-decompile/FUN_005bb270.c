FUNCTION FUN_005bb270 @ 0x005bb270  size=268
CALLERS (1): FUN_005bb380@0x005bb380
CALLEES (0): 
----------------------------------------------------------------

void FUN_005bb270(undefined2 param_1,undefined2 param_2,undefined8 param_3)

{
  long lVar1;
  undefined1 *puVar2;
  undefined1 auStack_120 [128];
  undefined1 auStack_a0 [128];
  undefined1 auStack_20 [16];
  undefined1 auStack_10 [16];
  
  puVar2 = auStack_120;
  auStack_a0[0] = 0;
  func_0x00109eb8(puVar2,param_3);
  lVar1 = func_0x0010a700(puVar2,0x639e50);
  if (lVar1 != 0) {
    *(undefined1 *)lVar1 = 0;
    func_0x00109ab0(auStack_a0,puVar2);
    func_0x00109ab0(auStack_a0,0x639e58);
    puVar2 = (undefined1 *)lVar1 + 2;
    func_0x00109eb8(auStack_20,0x639d58);
    if (cRam0034359d == '\0') {
      func_0x001b7650(auStack_20,auStack_10);
    }
    else {
      func_0x00109eb8(auStack_10,auStack_20);
    }
    func_0x00109ab0(auStack_a0,auStack_10);
    func_0x00109ab0(auStack_a0,0x639e60);
  }
  func_0x00109ab0(auStack_a0,puVar2);
  func_0x001b7310(param_1,param_2,auStack_a0,0);
  return;
}



================================================================