FUNCTION FUN_00005af8 @ 0x00005af8 size=284
CALLERS (0): 
CALLEES (3): FUN_00009638@0x00009638, FUN_00004fb0@0x00004fb0, FUN_000045bc@0x000045bc

undefined4 FUN_00005af8(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  pcVar4 = *(char **)(param_1 + 0x844);
  cVar1 = *pcVar4;
  if (cVar1 == '-') {
    pcVar4 = pcVar4 + 1;
  }
  iVar2 = FUN_00009638("dialing_type_string",pcVar4);
  if (iVar2 == 0) {
    uVar3 = 0;
    if ((cVar1 != '-') && (uVar3 = 0, 1 < *(int *)(param_1 + 0x840))) {
      iVar2 = FUN_000045bc(param_1,*(undefined4 *)(param_1 + 0x848));
      *param_2 = iVar2;
      if (iVar2 != 0) {
        if (*(int *)(param_1 + 0x840) < 3) {
          return 0;
        }
        iVar2 = FUN_000045bc(param_1,*(undefined4 *)(param_1 + 0x84c));
        param_2[1] = iVar2;
        if (iVar2 != 0) {
          if (*(int *)(param_1 + 0x840) < 4) {
            return 0;
          }
          iVar2 = FUN_000045bc(param_1,*(undefined4 *)(param_1 + 0x850));
          param_2[2] = iVar2;
          if (iVar2 == 0) {
            return 0xffffffff;
          }
          return 0;
        }
      }
      uVar3 = 0xffffffff;
    }
  }
  else {
    uVar3 = FUN_00004fb0(param_1,&DAT_0000af58,param_2,param_2 + 7);
  }
  return uVar3;
}


================================================================