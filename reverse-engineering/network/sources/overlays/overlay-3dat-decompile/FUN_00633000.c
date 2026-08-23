FUNCTION FUN_00633000 @ 0x00633000  size=412
CALLERS (1): FUN_00632d20@0x00632d20
CALLEES (0): 
----------------------------------------------------------------

void FUN_00633000(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  uint uStack_4;
  
  iVar7 = 0;
  while( true ) {
    if (param_3 < iVar7) break;
    iVar2 = func_0x001af430(param_2 + iVar7,&uStack_4);
    iVar6 = 0;
    if ((int)uStack_4 < 0x100) {
      uVar3 = (undefined1)*(undefined2 *)(&DAT_0068f090 + (uStack_4 & 0xff) * 2);
      if (iVar2 == 1) {
        *(undefined1 *)(param_1 + iVar7) = uVar3;
      }
      else {
        *(undefined1 *)(param_1 + iVar7) =
             (char)((ushort)*(undefined2 *)(&DAT_0068f090 + (uStack_4 & 0xff) * 2) >> 8);
        ((undefined1 *)(param_1 + iVar7))[1] = uVar3;
      }
      cVar1 = *(char *)(param_1 + iVar7);
    }
    else {
      while( true ) {
        pcVar5 = (char *)(param_2 + iVar7 + iVar6);
        if (iVar2 <= iVar6) break;
        pcVar4 = (char *)(param_1 + iVar7) + iVar6;
        iVar6 = iVar6 + 1;
        *pcVar4 = *pcVar5;
      }
      cVar1 = *(char *)(param_1 + iVar7);
    }
    pcVar5 = (char *)(param_1 + iVar7);
    if (cVar1 == '@') {
      *pcVar5 = 'A';
    }
    if (*pcVar5 == '$') {
      *pcVar5 = 'S';
    }
    if (*pcVar5 == '5') {
      *pcVar5 = 'S';
    }
    if (*pcVar5 == '<') {
      *pcVar5 = 'C';
    }
    if (*pcVar5 == '(') {
      *pcVar5 = 'C';
    }
    if (*pcVar5 == '!') {
      *pcVar5 = 'I';
    }
    if (*pcVar5 == '1') {
      *pcVar5 = 'I';
    }
    if (*pcVar5 == '2') {
      *pcVar5 = 'Z';
    }
    if (*pcVar5 == '0') {
      *pcVar5 = 'O';
    }
    iVar7 = iVar7 + iVar2;
  }
  return;
}



================================================================