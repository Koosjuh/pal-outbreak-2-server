FUNCTION FUN_000020bc @ 0x000020bc size=456
CALLERS (1): FUN_00002284@0x00002284
CALLEES (5): FUN_00002734@0x00002734, FUN_00002910@0x00002910, FUN_00002900@0x00002900, FUN_00001c64@0x00001c64, FUN_00001b0c@0x00001b0c

int FUN_000020bc(int param_1,char *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((*param_2 == '\0') || (param_2[0x100] == '\0')) {
    return -100;
  }
  if (*(int *)(param_1 + 0x18) == 0) {
    iVar1 = FUN_00002734(param_1,0x2c,2);
    *(int *)(param_1 + 0x18) = iVar1;
    if (iVar1 != 0) goto LAB_0000212c;
LAB_00002190:
    iVar3 = -2;
  }
  else {
LAB_0000212c:
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 8) = 3;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x10) = 0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x14) = 0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x20) = 0xffffffff;
    puVar2 = (undefined4 *)**(undefined4 **)(param_1 + 0x18);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)FUN_00002734(param_1,0x28,2);
      if (puVar2 == (undefined4 *)0x0) goto LAB_00002190;
      puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x18) + 4);
      puVar2[1] = puVar4;
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = *(undefined4 **)(param_1 + 0x18);
      }
      *puVar4 = puVar2;
      *puVar2 = 0;
      *(undefined4 **)(*(int *)(param_1 + 0x18) + 4) = puVar2;
    }
    FUN_00002910(&DAT_00006270,param_2);
    FUN_00002900(&DAT_00006270,&DAT_000033e0);
    FUN_00002900(&DAT_00006270,param_2 + 0x100);
    iVar1 = 0;
    puVar2[2] = &DAT_00006270;
    puVar2[3] = param_2;
    puVar2[4] = param_2 + 0x100;
    while( true ) {
      *(undefined4 *)(param_1 + 0x1c) = 0;
      iVar1 = iVar1 + 1;
      iVar3 = FUN_00001c64(param_1,param_2,iVar1);
      if ((iVar3 < 0) && (iVar3 != -100)) break;
      iVar3 = FUN_00001b0c(param_1,iVar1);
      if (iVar3 < 0) {
        return iVar3;
      }
      if (1 < iVar1) {
        return iVar3;
      }
    }
  }
  return iVar3;
}


================================================================