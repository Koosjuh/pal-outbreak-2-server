FUNCTION FUN_00002428 @ 0x00002428 size=280
CALLERS (2): FUN_00002d38@0x00002d38, FUN_00002540@0x00002540
CALLEES (1): FUN_00003d74@0x00003d74

undefined4 FUN_00002428(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  char *pcVar5;
  
  DAT_000045ec = (undefined *)0x0;
  if (*(undefined4 **)(PTR_DAT_000045e0 + 0x18) == (undefined4 *)0x0) {
    uVar2 = 1;
  }
  else {
    piVar3 = (int *)**(undefined4 **)(PTR_DAT_000045e0 + 0x18);
    uVar2 = 2;
    if ((piVar3 != (int *)0x0) && (uVar2 = 3, *piVar3 == 0)) {
      piVar4 = (int *)piVar3[5];
      if (piVar4 == (int *)0x0) {
        uVar2 = 4;
      }
      else {
        uVar2 = 5;
        if (*piVar4 == 2) {
          piVar3 = (int *)piVar3[6];
          uVar2 = 6;
          if (piVar3 != (int *)0x0) {
            if (*(char *)((int)piVar4 + 0x12e) == '\0') {
              uVar2 = 7;
            }
            else if ((*piVar3 == 1) || (uVar2 = 8, *piVar3 == 3)) {
              DAT_000045ec = &DAT_000053c8;
              FUN_00003d74(&DAT_000053c8,0x28);
              puVar1 = DAT_000045ec;
              pcVar5 = "<auto-nic>";
              if (*piVar3 == 1) {
                pcVar5 = "<auto-eth>";
              }
              *(char **)(DAT_000045ec + 8) = pcVar5;
              *(undefined **)(puVar1 + 0x24) = &DAT_000053f0;
              uVar2 = 0;
              DAT_000053f4 = piVar3;
              *(undefined4 *)(*(int *)(puVar1 + 0x24) + 8) = 0;
            }
          }
        }
      }
    }
  }
  return uVar2;
}


================================================================