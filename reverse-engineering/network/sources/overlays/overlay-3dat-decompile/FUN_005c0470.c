FUNCTION FUN_005c0470 @ 0x005c0470  size=116
CALLERS (2): FUN_005f99c0@0x005f99c0, FUN_0062de90@0x0062de90
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005c0470(undefined1 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  
  iVar3 = 0x25;
  puVar4 = (undefined1 *)0x6cc01a;
  do {
    iVar3 = iVar3 + -1;
    uVar1 = param_1[1];
    *puVar4 = *param_1;
    param_1 = param_1 + 2;
    puVar4[1] = uVar1;
    puVar4 = puVar4 + 2;
  } while (0 < iVar3);
  uVar2 = 0xffffffff;
  if (cRam006cba7c == '\0') {
    cRam006cba7c = '\x01';
    pcRam006cba58 = FUN_005c3490;
    uVar2 = 0;
    uRam006cba78 = 0;
    uRam006cba5c = param_2;
  }
  return uVar2;
}



================================================================