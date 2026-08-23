FUNCTION FUN_0000574c @ 0x0000574c size=388
CALLERS (0): 
CALLEES (4): FUN_00009638@0x00009638, FUN_00009720@0x00009720, FUN_0000497c@0x0000497c, FUN_00004fb0@0x00004fb0

undefined4 FUN_0000574c(int param_1)

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
  iVar2 = FUN_00009638("interface",pcVar4);
  if (iVar2 == 0) {
    if (cVar1 == '-') {
      return 0;
    }
    if (*(int *)(param_1 + 0x840) < 3) {
      FUN_00009720("netcnf: \"%s\" line %d: ",*(undefined4 *)(param_1 + 0x38),
                   *(undefined4 *)(param_1 + 0x3c));
      FUN_00009720("ac=%d",*(undefined4 *)(param_1 + 0x840));
      FUN_00009720(&DAT_00009a7c);
      *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
      return 0xffffffff;
    }
    uVar3 = 0;
    if (3 < *(int *)(param_1 + 0x840)) {
      uVar3 = *(undefined4 *)(param_1 + 0x850);
    }
    iVar2 = FUN_0000497c(param_1,*(undefined4 *)(param_1 + 0x848),*(undefined4 *)(param_1 + 0x84c),
                         uVar3);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
  }
  else {
    iVar2 = FUN_00009638("zero_prefix",pcVar4);
    if (iVar2 != 0) {
      uVar3 = FUN_00004fb0(param_1,&DAT_0000ab80,*(int *)(param_1 + 0x18),
                           *(int *)(param_1 + 0x18) + 0x24);
      return uVar3;
    }
    FUN_00009720("netcnf: \"%s\" line %d: ",*(undefined4 *)(param_1 + 0x38),
                 *(undefined4 *)(param_1 + 0x3c));
    FUN_00009720("obsoleted keyword (%s)",pcVar4);
    FUN_00009720(&DAT_00009a7c);
    *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
  }
  return 0;
}


================================================================