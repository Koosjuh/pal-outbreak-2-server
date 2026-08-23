FUNCTION FUN_000183f0 @ 0x000183f0 size=636
CALLERS (1): FUN_0001866c@0x0001866c
CALLEES (6): FUN_0000a7e0@0x0000a7e0, FUN_00011d90@0x00011d90, FUN_0000d8cc@0x0000d8cc, FUN_0000a60c@0x0000a60c, FUN_00009eec@0x00009eec, FUN_000100c4@0x000100c4

undefined4
FUN_000183f0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5,
            undefined2 param_6,int param_7)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = *(int *)(param_7 + 0x14) - *(int *)(param_7 + 0x10);
  if (*(int *)(param_2 + 0x20) < iVar4) {
    if ((DAT_0001b850 & 1) != 0) {
      FUN_00011d90("# ERR # %s:%d: %s\n",s_udp_c_0001b930,0xbc,"udp_recv_one - too big");
    }
  }
  else {
    if (*(int *)(param_2 + 0x20) < *(int *)(param_2 + 0x24) + iVar4) {
      do {
        piVar5 = *(int **)(param_2 + 0x28);
        if (piVar5 == (int *)0x0) break;
        iVar4 = *piVar5;
        *(int *)(param_2 + 0x28) = iVar4;
        if (iVar4 == 0) {
          *(undefined4 *)(param_2 + 0x2c) = 0;
        }
        else {
          *(undefined4 *)(*piVar5 + 4) = 0;
        }
        *(int *)(param_2 + 0x24) =
             *(int *)(param_2 + 0x24) - (*(int *)(piVar5[5] + 0x14) - *(int *)(piVar5[5] + 0x10));
        FUN_00009eec(piVar5[5]);
        FUN_0000a7e0(piVar5);
        *(int *)(*(int *)(param_1 + 0x1a0) + 0x44) = *(int *)(*(int *)(param_1 + 0x1a0) + 0x44) + 1;
      } while (*(int *)(param_2 + 0x20) <
               *(int *)(param_2 + 0x24) + (*(int *)(param_7 + 0x14) - *(int *)(param_7 + 0x10)));
      if ((*(int *)(param_2 + 0x20) <
           *(int *)(param_2 + 0x24) + (*(int *)(param_7 + 0x14) - *(int *)(param_7 + 0x10))) &&
         (*(int *)(param_2 + 0x28) == 0)) {
        *(undefined4 *)(param_2 + 0x24) = 0;
      }
    }
    puVar1 = (undefined4 *)FUN_0000a60c(0x18);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[2] = param_3;
      puVar1[3] = param_4;
      *(undefined2 *)(puVar1 + 4) = param_5;
      puVar1[5] = param_7;
      *(undefined2 *)((int)puVar1 + 0x12) = param_6;
      puVar2 = *(undefined4 **)(param_2 + 0x2c);
      puVar1[1] = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        *(undefined4 **)(param_2 + 0x28) = puVar1;
      }
      else {
        *puVar2 = puVar1;
      }
      *puVar1 = 0;
      *(undefined4 **)(param_2 + 0x2c) = puVar1;
      *(int *)(param_2 + 0x24) =
           *(int *)(param_2 + 0x24) + (*(int *)(param_7 + 0x14) - *(int *)(param_7 + 0x10));
      FUN_0000d8cc(param_2 + 0x34);
      FUN_000100c4();
      return 0;
    }
    if ((DAT_0001b850 & 1) != 0) {
      FUN_00011d90("# ERR # %s:%d: %s\n",s_udp_c_0001b930,0xc9,"udp_recv_one - no space");
    }
  }
  *(int *)(*(int *)(param_1 + 0x1a0) + 0x44) = *(int *)(*(int *)(param_1 + 0x1a0) + 0x44) + 1;
  uVar3 = FUN_00009eec(param_7);
  return uVar3;
}


================================================================