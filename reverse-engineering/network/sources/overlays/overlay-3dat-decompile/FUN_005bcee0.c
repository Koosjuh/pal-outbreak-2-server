FUNCTION FUN_005bcee0 @ 0x005bcee0  size=232
CALLERS (0): 
CALLEES (2): FUN_005bdc70@0x005bdc70, FUN_005bcc30@0x005bcc30
----------------------------------------------------------------

void FUN_005bcee0(char *param_1)

{
  undefined1 uStack_10;
  undefined1 uStack_f;
  
  FUN_005bcc30();
  if (*param_1 == '\0') {
    func_0x00109eb8(0x6cc440,0x639e78);
    func_0x0010a4f0(0x6cc450,0x86f820,0x10);
    uStack_f = 2;
    uStack_10 = 0;
    (*pcRam006cb96c)(&uStack_10,&uStack_10);
    FUN_005bdc70();
  }
  else if (*param_1 == '\'') {
    func_0x00109eb8(0x6cc440,0x639e78);
    func_0x0010a4f0(0x6cc450,0x86f820,0x10);
    uStack_f = 2;
    uStack_10 = 0;
    (*pcRam006cb96c)(&uStack_10,&uStack_10);
    FUN_005bdc70();
  }
  return;
}



================================================================