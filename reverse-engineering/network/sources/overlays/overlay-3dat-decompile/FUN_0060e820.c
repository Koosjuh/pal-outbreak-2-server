FUNCTION FUN_0060e820 @ 0x0060e820  size=400
CALLERS (2): FUN_00610580@0x00610580, FUN_00610830@0x00610830
CALLEES (3): FUN_0060e250@0x0060e250, FUN_0060e590@0x0060e590, FUN_0060f0f0@0x0060f0f0
----------------------------------------------------------------

int FUN_0060e820(undefined8 param_1,int param_2,int param_3)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_28c0 [3584];
  undefined1 auStack_1ac0 [256];
  undefined1 auStack_19c0 [1088];
  undefined1 auStack_1580 [512];
  undefined1 auStack_1380 [2304];
  undefined1 auStack_a80 [256];
  undefined1 auStack_980 [1824];
  char cStack_260;
  char cStack_25b;
  undefined1 auStack_210 [524];
  int iStack_4;
  
  auStack_210[0] = 0;
  FUN_0060e250(param_1,auStack_1580,auStack_210);
  FUN_0060e590(param_1,auStack_28c0);
  iVar3 = 0;
  do {
    if (param_3 <= iVar3) {
      return -1;
    }
    iVar1 = *(int *)(param_2 + 0x10);
    if (iVar1 != 0) {
      lVar2 = func_0x00109d70(iVar1 + 0xe00,auStack_1ac0);
      if ((((lVar2 == 0) && (lVar2 = func_0x00109d70(iVar1 + 0xf00,auStack_19c0), lVar2 == 0)) &&
          (*(char *)(iVar1 + 0x1320) == cStack_260)) &&
         ((lVar2 = func_0x00109d70(iVar1 + 0x200,auStack_1380), lVar2 == 0 &&
          (*(char *)(iVar1 + 0x1325) == cStack_25b)))) {
        lVar2 = func_0x00109d70(iVar1 + 0xb00,auStack_a80);
        if (lVar2 == 0) {
          lVar2 = func_0x00109d70(iVar1 + 0xc00,auStack_980);
          if (lVar2 == 0) {
            iStack_4 = 0;
            FUN_0060f0f0(iVar1 + 0x300,&iStack_4);
            iVar4 = (int)param_1;
            if (iStack_4 == *(int *)(iVar4 + 0x60c)) {
              iStack_4 = 0;
              FUN_0060f0f0(iVar1 + 0x400,&iStack_4);
              if (iStack_4 == *(int *)(iVar4 + 0x610)) {
                iStack_4 = 0;
                FUN_0060f0f0(iVar1 + 0x500,&iStack_4);
                if (iStack_4 == *(int *)(iVar4 + 0x614)) {
                  iStack_4 = 0;
                  FUN_0060f0f0(iVar1 + 0x600,&iStack_4);
                  if (iStack_4 == *(int *)(iVar4 + 0x618)) {
                    iStack_4 = 0;
                    FUN_0060f0f0(iVar1 + 0x700,&iStack_4);
                    if (iStack_4 == *(int *)(iVar4 + 0x61c)) {
                      return iVar3;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    param_2 = param_2 + 0x14;
    iVar3 = iVar3 + 1;
  } while( true );
}



================================================================