FUNCTION FUN_0000cb4c @ 0x0000cb4c size=648
CALLERS (1): FUN_0000cdd4@0x0000cdd4
CALLEES (4): FUN_00011d90@0x00011d90, FUN_0000c444@0x0000c444, FUN_00018cd0@0x00018cd0, FUN_000032fc@0x000032fc

undefined4 FUN_0000cb4c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = 0xfffffdfc;
  iVar4 = 0;
  piVar1 = (int *)FUN_00018cd0(0,0xffffffff,param_2,0x35);
  *(int **)(param_1 + 0x81c) = piVar1;
  if ((int)piVar1 < 0) {
    if ((DAT_0001b850 & 1) != 0) {
      FUN_00011d90("# ERR # %s:%d: %s\n","resolv.c",0x14d,"resolv - udp_create\n");
    }
  }
  else {
    iVar4 = *piVar1;
    iVar2 = (**(code **)(iVar4 + 4))(piVar1,param_3);
    if (iVar2 < 0) {
      if ((DAT_0001b850 & 1) != 0) {
        FUN_00011d90("# ERR # %s:%d: %s\n","resolv.c",0x150,"resolv - udp_open\n");
      }
    }
    else {
      iVar2 = (**(code **)(iVar4 + 0x10))
                        (*(undefined4 *)(param_1 + 0x81c),param_1 + 0xc,
                         *(undefined4 *)(param_1 + 0x80c),0,param_3);
      iVar3 = param_1 + 0x20c;
      if (*(int *)(param_1 + 0x80c) == iVar2) {
        iVar2 = (**(code **)(iVar4 + 0xc))(*(undefined4 *)(param_1 + 0x81c),iVar3,0x200,0,param_3);
        *(int *)(param_1 + 0x810) = iVar2;
        if (iVar2 < 0) {
          if (iVar2 == -0x1f5) {
            uVar5 = 0xfffffe0b;
          }
          if ((DAT_0001b850 & 1) != 0) {
            FUN_00011d90("# ERR # %s:%d: %s\n","resolv.c",0x157,"resolv - udp_recv\n");
          }
        }
        else {
          if ((DAT_0001b850 & 4) != 0) {
            FUN_00011d90("resolv-ans:\n");
            FUN_000032fc(iVar3,*(undefined4 *)(param_1 + 0x810));
          }
          uVar5 = FUN_0000c444(*(undefined4 *)(param_1 + 0x818),iVar3,
                               *(undefined4 *)(param_1 + 0x810),param_1 + 0x40c,param_1 + 0x60c,
                               *(undefined4 *)(param_1 + 0x814),*(undefined4 *)(param_1 + 0x820));
          if ((DAT_0001b850 & 4) != 0) {
            FUN_00011d90("res_get_answer() -> %d\n",uVar5);
          }
        }
      }
      else if ((DAT_0001b850 & 1) != 0) {
        FUN_00011d90("# ERR # %s:%d: %s\n","resolv.c",0x152,"resolv - udp_send\n");
      }
    }
  }
  if (iVar4 != 0) {
    (**(code **)(iVar4 + 8))(*(undefined4 *)(param_1 + 0x81c),0xffffffff);
  }
  return uVar5;
}


================================================================