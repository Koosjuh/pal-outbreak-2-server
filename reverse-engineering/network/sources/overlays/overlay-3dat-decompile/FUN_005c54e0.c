FUNCTION FUN_005c54e0 @ 0x005c54e0  size=292
CALLERS (0): 
CALLEES (2): FUN_005c5460@0x005c5460, FUN_005c51a0@0x005c51a0
----------------------------------------------------------------

void FUN_005c54e0(char *param_1,undefined8 param_2)

{
  int iVar1;
  uint uVar2;
  
  if (*param_1 == '\0') {
    iVar1 = (int)param_2;
    if ((*(uint *)(iVar1 + 0x18) & 0x80000) != 0) {
      for (uVar2 = 0; (int)uVar2 < 0x1e; uVar2 = uVar2 + 1) {
        if (*(int *)(uVar2 * 0x24 + 0x6fee8c) == *(int *)(iVar1 + 0x20)) {
          if ((*(uint *)(iVar1 + 0x18) & 0x40000000) != 0) {
            return;
          }
          FUN_005c51a0(param_2,uVar2 & 0xffff);
          FUN_005c5460(uVar2 + 1 & 0xffff);
          return;
        }
      }
      for (uVar2 = 0; (int)uVar2 < 0x1e; uVar2 = uVar2 + 1) {
        if (*(int *)(uVar2 * 0x24 + 0x6fee8c) == 0) {
          *(undefined4 *)(uVar2 * 0x24 + 0x6fee8c) = *(undefined4 *)(iVar1 + 0x20);
          FUN_005c51a0(param_2,uVar2 & 0xffff);
          FUN_005c5460(uVar2 + 1 & 0xffff);
          return;
        }
      }
    }
  }
  return;
}



================================================================