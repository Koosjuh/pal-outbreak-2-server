FUNCTION FUN_00601ac0 @ 0x00601ac0  size=308
CALLERS (1): FUN_00601c00@0x00601c00
CALLEES (1): FUN_0062fea0@0x0062fea0
----------------------------------------------------------------

void FUN_00601ac0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char *pcVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  undefined1 auStack_40 [64];
  
  pcVar1 = (char *)FUN_0062fea0(0x45);
  do {
    cVar3 = *pcVar1;
    while( true ) {
      if (cVar3 == '\0') {
        return;
      }
      lVar2 = func_0x00109be0(pcVar1,0x25);
      if (lVar2 == 0) break;
      iVar4 = (int)lVar2;
      func_0x0010a188(param_1,pcVar1,iVar4 - (int)pcVar1);
      if (*(char *)(iVar4 + 1) == '2') {
        func_0x00109728(auStack_40,0x649d48,param_3);
        func_0x0010a188(param_1,auStack_40,2);
      }
      else if (*(char *)(iVar4 + 1) == '1') {
        func_0x00109728(auStack_40,0x649d48,param_2);
        func_0x0010a188(param_1,auStack_40,2);
      }
      else {
        func_0x00109728(auStack_40,0x649d50);
        func_0x0010a188(param_1,auStack_40,2);
      }
      pcVar1 = (char *)(iVar4 + 2);
      cVar3 = *pcVar1;
    }
    func_0x0010a188(param_1,pcVar1,1);
    pcVar1 = pcVar1 + 1;
  } while( true );
}



================================================================