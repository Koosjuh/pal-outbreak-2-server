FUNCTION FUN_005e82c0 @ 0x005e82c0  size=228
CALLERS (3): FUN_005e9750@0x005e9750, FUN_005e8e40@0x005e8e40, FUN_005e9540@0x005e9540
CALLEES (0): 
----------------------------------------------------------------

void FUN_005e82c0(char *param_1)

{
  undefined *puVar1;
  int iVar2;
  char *pcVar3;
  undefined8 uVar4;
  long lVar5;
  char *pcVar6;
  
LAB_005e8370:
  do {
    pcVar3 = (char *)func_0x0010a700(param_1,0x6484f8);
    if (pcVar3 == (char *)0x0) {
      return;
    }
    param_1 = pcVar3 + 1;
    iVar2 = 0;
    while( true ) {
      if (8 < iVar2) goto LAB_005e8370;
      puVar1 = (&PTR_DAT_006484c0)[iVar2];
      uVar4 = func_0x0010a050(puVar1);
      lVar5 = func_0x0010a338(pcVar3 + 1,puVar1,uVar4);
      if (lVar5 == 0) break;
      iVar2 = iVar2 + 1;
    }
    *pcVar3 = *(char *)(iVar2 + 0x6484e8);
    iVar2 = func_0x0010a050(puVar1);
    pcVar6 = pcVar3 + iVar2;
    do {
      pcVar6 = pcVar6 + 1;
      pcVar3 = pcVar3 + 1;
      *pcVar3 = *pcVar6;
    } while (*pcVar6 != '\0');
  } while( true );
}



================================================================