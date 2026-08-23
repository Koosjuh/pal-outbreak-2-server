FUNCTION FUN_0000ec64 @ 0x0000ec64 size=1228
CALLERS (0): 
CALLEES (21): FUN_000029f8@0x000029f8, FUN_0000eab8@0x0000eab8, FUN_00005d28@0x00005d28, FUN_00011d90@0x00011d90, FUN_0000e848@0x0000e848, FUN_00019aa4@0x00019aa4, FUN_00001004@0x00001004, FUN_00017bf4@0x00017bf4, FUN_0000d41c@0x0000d41c, FUN_0000e870@0x0000e870, FUN_00005da4@0x00005da4, FUN_000016ec@0x000016ec, FUN_00017ad8@0x00017ad8, FUN_0000d3b4@0x0000d3b4, FUN_0000d3d4@0x0000d3d4, FUN_00002428@0x00002428, FUN_00009eec@0x00009eec, FUN_0000ebe0@0x0000ebe0, FUN_00007e28@0x00007e28, FUN_0000d390@0x0000d390, FUN_00019a18@0x00019a18

void FUN_0000ec64(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint local_28 [2];
  
  bVar1 = false;
  iVar5 = 0;
  uVar6 = *(uint *)(param_1 + 0x48) & 0x10;
  FUN_0000d3d4();
LAB_0000ec9c:
  do {
    FUN_0000d41c();
    iVar2 = FUN_00019aa4(*(undefined4 *)(param_1 + 0x4c),0xffffffff,0x11,local_28);
    if (iVar2 != 0) {
      return;
    }
    FUN_0000d3d4();
    if (((local_28[0] & 0x10000) != 0) && (!bVar1)) {
      *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xfffffeff;
      iVar2 = (**(code **)(param_1 + 0x60))(*(undefined4 *)(param_1 + 0x44),0);
      if (iVar2 < 0) {
        FUN_00011d90("%s_start -> %d\n",*(undefined4 *)(param_1 + 0x14),iVar2);
        goto LAB_0000ec9c;
      }
      bVar1 = true;
    }
    if ((local_28[0] & 0xa0030) == 0) goto LAB_0000ee0c;
    if ((local_28[0] & 0x30) != 0) {
      *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 0x100;
    }
    if (!bVar1) {
      FUN_0000e848();
      goto LAB_0000ee0c;
    }
    if (((local_28[0] & 0x80000) == 0) && (iVar2 = FUN_00005da4(param_1), iVar2 != 0)) {
      iVar5 = FUN_00017ad8(FUN_0000ec40,param_1,2000);
    }
    else if ((iVar5 == 0) || ((local_28[0] & 0x80000) != 0)) {
      iVar5 = 0;
      FUN_0000eab8(param_1);
      iVar2 = (**(code **)(param_1 + 100))(*(undefined4 *)(param_1 + 0x44),0);
      if (iVar2 < 0) {
        FUN_00011d90("%s_stop -> %d\n",*(undefined4 *)(param_1 + 0x14),iVar2);
      }
      FUN_0000ebe0(param_1);
      bVar1 = false;
LAB_0000ee0c:
      if ((local_28[0] & 0x40000) != 0) {
        FUN_0000e870(param_1);
      }
      if ((local_28[0] & 1) != 0) {
        if ((uVar6 == 0) ||
           ((((*(short *)(param_1 + 0x88) != DAT_0001b3e0 ||
              (*(short *)(param_1 + 0x8a) != DAT_0001b3e2)) ||
             (*(short *)(param_1 + 0x8c) != DAT_0001b3e4)) &&
            (((*(short *)(param_1 + 0x88) != DAT_0001b3e8 ||
              (*(short *)(param_1 + 0x8a) != DAT_0001b3ea)) ||
             (*(short *)(param_1 + 0x8c) != DAT_0001b3ec)))))) {
          if ((*(uint *)(param_1 + 0x48) & 0x20) == 0) {
            FUN_0000e870(param_1);
          }
          else {
            FUN_00005d28(param_1);
          }
        }
        else {
          FUN_00011d90("%s,StartDone -> invalid hw_addr\n",*(undefined4 *)(param_1 + 0x14));
        }
      }
      if ((local_28[0] & 2) != 0) {
        iVar5 = FUN_00017bf4(iVar5);
        FUN_0000eab8(param_1);
        iVar2 = (**(code **)(param_1 + 100))(*(undefined4 *)(param_1 + 0x44),0);
        if (iVar2 < 0) {
          FUN_00011d90("xxx_stop -> %d\n",iVar2);
        }
        FUN_0000ebe0(param_1);
        FUN_0000d41c();
        FUN_00019a18();
      }
      if ((local_28[0] & 4) != 0) {
LAB_0000ef80:
        uVar3 = FUN_0000d390();
        piVar4 = *(int **)(param_1 + 0x50);
        if (piVar4 != (int *)0x0) {
          iVar2 = *piVar4;
          *(int *)(param_1 + 0x50) = iVar2;
          if (iVar2 == 0) {
            *(undefined4 *)(param_1 + 0x54) = 0;
          }
          else {
            *(undefined4 *)(*piVar4 + 4) = 0;
          }
        }
        FUN_0000d3b4(uVar3);
        if (piVar4 != (int *)0x0) {
          piVar4[1] = 0;
          *piVar4 = 0;
          piVar4[3] = 0;
          piVar4[2] = 0;
          if (uVar6 != 0) break;
          if ((DAT_0001b850 & 0x10) != 0) {
            FUN_00011d90(&PTR_DAT_0001b884,param_1 + 8);
            FUN_00011d90("%<TIME> R ");
            FUN_00002428(0,piVar4,0,0);
            FUN_00011d90(&DAT_0001b88c);
          }
          if ((DAT_0001b850 & 0x80) != 0) {
            FUN_000016ec(0,piVar4[4],piVar4[5] - piVar4[4]);
          }
          uVar3 = FUN_00007e28(param_1,piVar4,1);
          goto LAB_0000f0fc;
        }
      }
    }
  } while( true );
  if ((DAT_0001b850 & 0x10) != 0) {
    FUN_00011d90(&PTR_DAT_0001b884,param_1 + 8);
    FUN_000029f8(&DAT_0001b89c,piVar4);
  }
  if ((DAT_0001b850 & 0x80) != 0) {
    FUN_000016ec(0,piVar4[4],piVar4[5] - piVar4[4]);
  }
  if ((((*(uint *)(param_1 + 0x48) & 0x200) == 0) || (DAT_0001b880 == 0)) ||
     (piVar4 = (int *)(**(code **)(DAT_0001b880 + 0x10))(param_1,piVar4), piVar4 != (int *)0x0)) {
    uVar3 = FUN_00001004(param_1,piVar4);
LAB_0000f0fc:
    FUN_00009eec(uVar3);
  }
  goto LAB_0000ef80;
}


================================================================