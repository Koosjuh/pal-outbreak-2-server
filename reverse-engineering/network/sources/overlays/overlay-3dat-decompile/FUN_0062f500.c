FUNCTION FUN_0062f500 @ 0x0062f500  size=168
CALLERS (1): FUN_0062d730@0x0062d730
CALLEES (1): FUN_00618ba0@0x00618ba0
----------------------------------------------------------------

void FUN_0062f500(undefined4 param_1)

{
  short sVar1;
  undefined1 *puVar2;
  long lVar3;
  int iVar4;
  
  lVar3 = FUN_00618ba0();
  puVar2 = (undefined1 *)lVar3;
  if (lVar3 != 0) {
    *puVar2 = 1;
    puVar2[1] = 1;
    *(code **)(puVar2 + 0xc) = FUN_0062f5b0;
    *(undefined2 *)(puVar2 + 0x22) = 0x121;
    iVar4 = 0;
    *(undefined4 *)(puVar2 + 0x10) = param_1;
    *(undefined4 *)(puVar2 + 0x34) = 0xffffffe1;
    do {
      puVar2 = (undefined1 *)FUN_00618ba0();
      *puVar2 = 1;
      sVar1 = (short)iVar4;
      puVar2[1] = 1;
      puVar2[2] = (char)iVar4;
      puVar2[3] = 0;
      iVar4 = iVar4 + 1;
      *(short *)(puVar2 + 0x22) = sVar1 + 0xd9;
      *(code **)(puVar2 + 0xc) = FUN_0062f710;
      *(undefined4 *)(puVar2 + 0x10) = param_1;
      *(undefined4 *)(puVar2 + 0x34) = 0xffffffe1;
    } while (iVar4 < 2);
  }
  return;
}



================================================================