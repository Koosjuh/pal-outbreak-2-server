FUNCTION FUN_0060da80 @ 0x0060da80  size=528
CALLERS (1): FUN_0060dea0@0x0060dea0
CALLEES (0): 
----------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x0060dba8) */
/* WARNING: Removing unreachable block (ram,0x0060dbb0) */
/* WARNING: Removing unreachable block (ram,0x0060daa8) */
/* WARNING: Removing unreachable block (ram,0x0060dab0) */

void FUN_0060da80(int param_1,undefined1 *param_2,int param_3,int param_4,uint param_5,uint param_6)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  
  if (param_4 == 8) {
    iVar3 = 0;
    if ((param_5 & 3) != 0) {
      iVar3 = 4 - (param_5 & 3);
    }
    iVar7 = 0;
    while (iVar7 < *(int *)(param_1 + 8)) {
      if (iVar7 < (int)(param_6 & 0xffff)) {
        iVar6 = 0;
        while( true ) {
          if (*(int *)(param_1 + 4) <= iVar6) goto LAB_0060dc74;
          iVar4 = param_3 + iVar6;
          if ((int)(param_5 & 0xffff) <= iVar6) break;
          iVar6 = iVar6 + 1;
          *param_2 = *(undefined1 *)
                      (iVar4 + (iVar3 + (param_5 & 0xffff)) * (((param_6 & 0xffff) - 1) - iVar7));
          param_2 = param_2 + 1;
        }
        iVar4 = *(int *)(param_1 + 4);
        for (; iVar6 < iVar4; iVar6 = iVar6 + 1) {
          *param_2 = 0;
          param_2 = param_2 + 1;
          iVar4 = *(int *)(param_1 + 4);
        }
LAB_0060dc74:
        iVar7 = iVar7 + 1;
      }
      else {
        for (iVar6 = 0; iVar6 < *(int *)(param_1 + 4); iVar6 = iVar6 + 1) {
          *param_2 = 0;
          param_2 = param_2 + 1;
        }
        iVar7 = iVar7 + 1;
      }
    }
  }
  else if (param_4 == 0x18) {
    iVar3 = 0;
    while (iVar3 < *(int *)(param_1 + 8)) {
      if (iVar3 < (int)(param_6 & 0xffff)) {
        for (iVar7 = 0; iVar7 < *(int *)(param_1 + 4); iVar7 = iVar7 + 1) {
          if (iVar7 < (int)(param_5 & 0xffff)) {
            puVar5 = (undefined1 *)
                     (param_3 + iVar7 * 3 +
                     ((param_5 & 3) + (param_5 & 0xffff) * 3) * (((param_6 & 0xffff) - 1) - iVar3));
            uVar1 = *puVar5;
            uVar2 = puVar5[1];
            *param_2 = puVar5[2];
            param_2[1] = uVar2;
            param_2[2] = uVar1;
          }
          else {
            *param_2 = 0;
            param_2[1] = 0;
            param_2[2] = 0;
          }
          param_2 = param_2 + 3;
        }
        iVar3 = iVar3 + 1;
      }
      else {
        for (iVar7 = 0; iVar7 < *(int *)(param_1 + 4); iVar7 = iVar7 + 1) {
          *param_2 = 0;
          param_2[1] = 0;
          param_2[2] = 0;
          param_2 = param_2 + 3;
        }
        iVar3 = iVar3 + 1;
      }
    }
  }
  return;
}



================================================================