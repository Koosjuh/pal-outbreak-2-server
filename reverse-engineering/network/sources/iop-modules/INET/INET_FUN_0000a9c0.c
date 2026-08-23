FUNCTION FUN_0000a9c0 @ 0x0000a9c0 size=1124
CALLERS (41): FUN_00008d64@0x00008d64, FUN_00004290@0x00004290, FUN_000038a4@0x000038a4, FUN_00010fec@0x00010fec, FUN_0000a494@0x0000a494, FUN_0000df10@0x0000df10, FUN_00005f48@0x00005f48, FUN_00007abc@0x00007abc, FUN_00010418@0x00010418, FUN_00019204@0x00019204, FUN_0000fb40@0x0000fb40, FUN_0000f280@0x0000f280, FUN_0000b220@0x0000b220, FUN_00004078@0x00004078, FUN_0000e1c8@0x0000e1c8, FUN_00016e2c@0x00016e2c, FUN_0000b800@0x0000b800, FUN_0000f304@0x0000f304, FUN_0000057c@0x0000057c, FUN_0001104c@0x0001104c, FUN_00018de4@0x00018de4, FUN_00009f70@0x00009f70, FUN_00011184@0x00011184, FUN_0001442c@0x0001442c, FUN_00016368@0x00016368, FUN_00003f0c@0x00003f0c, FUN_00010dd4@0x00010dd4, FUN_00004130@0x00004130, FUN_0000709c@0x0000709c, FUN_0000f874@0x0000f874, FUN_00010cc0@0x00010cc0, FUN_0000797c@0x0000797c, FUN_0000b9bc@0x0000b9bc, FUN_00013264@0x00013264, FUN_0000a104@0x0000a104, FUN_00009e60@0x00009e60, FUN_0000b5c4@0x0000b5c4, FUN_00019444@0x00019444, FUN_00010f00@0x00010f00, FUN_0000f130@0x0000f130, FUN_00011124@0x00011124
CALLEES (1): FUN_000199dc@0x000199dc

void FUN_0000a9c0(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  int iVar10;
  undefined1 *puVar11;
  
  if (param_1 < param_2) {
    puVar6 = (undefined4 *)((int)param_1 + param_3);
    if (param_2 < puVar6) {
      param_2 = (undefined4 *)((int)param_2 + param_3);
      if ((int)param_3 < 4) goto joined_r0x0000ade4;
      if (((uint)puVar6 & 1) != 0) {
        param_2 = (undefined4 *)((int)param_2 + -1);
        puVar6 = (undefined4 *)((int)puVar6 + -1);
        param_3 = param_3 - 1;
        *(undefined1 *)param_2 = *(undefined1 *)puVar6;
      }
      if (((uint)puVar6 & 2) != 0) {
        puVar11 = (undefined1 *)((int)puVar6 + -1);
        puVar6 = (undefined4 *)((int)puVar6 + -2);
        param_3 = param_3 - 2;
        *(undefined1 *)((int)param_2 + -1) = *puVar11;
        param_2 = (undefined4 *)((int)param_2 + -2);
        *(undefined1 *)param_2 = *(undefined1 *)puVar6;
      }
      if (((uint)param_2 & 1) != 0) goto joined_r0x0000ade4;
      if (((uint)param_2 & 2) != 0) {
        uVar7 = (int)param_3 >> 1 & 3;
        iVar10 = (int)param_3 >> 3;
        if (uVar7 == 2) {
LAB_0000ad68:
          puVar6 = (undefined4 *)((int)puVar6 + -2);
          param_2 = (undefined4 *)((int)param_2 + -2);
          *(undefined2 *)param_2 = *(undefined2 *)puVar6;
LAB_0000ad78:
          puVar6 = (undefined4 *)((int)puVar6 + -2);
          param_2 = (undefined4 *)((int)param_2 + -2);
          *(undefined2 *)param_2 = *(undefined2 *)puVar6;
          puVar3 = param_2;
          puVar4 = puVar6;
        }
        else {
          puVar3 = param_2;
          puVar4 = puVar6;
          if (uVar7 < 3) {
            if (uVar7 == 1) goto LAB_0000ad78;
          }
          else if (uVar7 == 3) {
            puVar6 = (undefined4 *)((int)puVar6 + -2);
            param_2 = (undefined4 *)((int)param_2 + -2);
            *(undefined2 *)param_2 = *(undefined2 *)puVar6;
            goto LAB_0000ad68;
          }
        }
        for (; 0 < iVar10; iVar10 = iVar10 + -1) {
          puVar6 = puVar6 + -2;
          param_2 = param_2 + -2;
          *(undefined2 *)((int)puVar3 + -2) = *(undefined2 *)((int)puVar4 + -2);
          *(undefined2 *)(puVar3 + -1) = *(undefined2 *)(puVar4 + -1);
          *(undefined2 *)((int)puVar3 + -6) = *(undefined2 *)((int)puVar4 + -6);
          *(undefined2 *)(puVar3 + -2) = *(undefined2 *)(puVar4 + -2);
          puVar3 = puVar3 + -2;
          puVar4 = puVar4 + -2;
        }
        param_3 = param_3 & 1;
        goto joined_r0x0000ade4;
      }
      uVar7 = (int)param_3 >> 2 & 3;
      iVar10 = (int)param_3 >> 4;
      if (uVar7 == 2) {
LAB_0000aca8:
        puVar6 = puVar6 + -1;
        param_2 = param_2 + -1;
        *param_2 = *puVar6;
LAB_0000acb8:
        puVar6 = puVar6 + -1;
        param_2 = param_2 + -1;
        *param_2 = *puVar6;
        puVar3 = param_2;
        puVar4 = puVar6;
      }
      else {
        puVar3 = param_2;
        puVar4 = puVar6;
        if (uVar7 < 3) {
          if (uVar7 == 1) goto LAB_0000acb8;
        }
        else if (uVar7 == 3) {
          puVar6 = puVar6 + -1;
          param_2 = param_2 + -1;
          *param_2 = *puVar6;
          goto LAB_0000aca8;
        }
      }
      for (; 0 < iVar10; iVar10 = iVar10 + -1) {
        puVar6 = puVar6 + -4;
        param_2 = param_2 + -4;
        puVar3[-1] = puVar4[-1];
        puVar3[-2] = puVar4[-2];
        puVar3[-3] = puVar4[-3];
        puVar3[-4] = puVar4[-4];
        puVar3 = puVar3 + -4;
        puVar4 = puVar4 + -4;
      }
      param_3 = param_3 & 3;
joined_r0x0000ade4:
      for (; 0 < (int)param_3; param_3 = param_3 - 1) {
        param_2 = (undefined4 *)((int)param_2 + -1);
        puVar6 = (undefined4 *)((int)puVar6 + -1);
        *(undefined1 *)param_2 = *(undefined1 *)puVar6;
      }
      return;
    }
  }
  if ((int)param_3 < 4) goto joined_r0x0000abc0;
  if (((uint)param_1 & 1) != 0) {
    uVar1 = *(undefined1 *)param_1;
    param_1 = (undefined4 *)((int)param_1 + 1);
    param_3 = param_3 - 1;
    *(undefined1 *)param_2 = uVar1;
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  if (((uint)param_1 & 2) != 0) {
    puVar11 = (undefined1 *)((int)param_1 + 1);
    param_3 = param_3 - 2;
    *(undefined1 *)param_2 = *(undefined1 *)param_1;
    param_1 = (undefined4 *)((int)param_1 + 2);
    *(undefined1 *)((int)param_2 + 1) = *puVar11;
    param_2 = (undefined4 *)((int)param_2 + 2);
  }
  if (((uint)param_2 & 1) != 0) goto joined_r0x0000abc0;
  if (((uint)param_2 & 2) != 0) {
    uVar7 = (int)param_3 >> 1 & 3;
    iVar10 = (int)param_3 >> 3;
    if (uVar7 == 2) {
LAB_0000ab44:
      uVar2 = *(undefined2 *)param_1;
      param_1 = (undefined4 *)((int)param_1 + 2);
      *(undefined2 *)param_2 = uVar2;
      param_2 = (undefined4 *)((int)param_2 + 2);
LAB_0000ab54:
      uVar2 = *(undefined2 *)param_1;
      param_1 = (undefined4 *)((int)param_1 + 2);
      *(undefined2 *)param_2 = uVar2;
      param_2 = (undefined4 *)((int)param_2 + 2);
    }
    else if (uVar7 < 3) {
      if (uVar7 == 1) goto LAB_0000ab54;
    }
    else if (uVar7 == 3) {
      uVar2 = *(undefined2 *)param_1;
      param_1 = (undefined4 *)((int)param_1 + 2);
      *(undefined2 *)param_2 = uVar2;
      param_2 = (undefined4 *)((int)param_2 + 2);
      goto LAB_0000ab44;
    }
    if (0 < iVar10) {
      puVar9 = (undefined2 *)((int)param_2 + 6);
      puVar8 = (undefined2 *)((int)param_1 + 6);
      do {
        iVar10 = iVar10 + -1;
        uVar2 = *(undefined2 *)param_1;
        param_1 = param_1 + 2;
        *(undefined2 *)param_2 = uVar2;
        puVar9[-2] = puVar8[-2];
        param_2 = param_2 + 2;
        puVar9[-1] = puVar8[-1];
        uVar2 = *puVar8;
        puVar8 = puVar8 + 4;
        *puVar9 = uVar2;
        puVar9 = puVar9 + 4;
      } while (0 < iVar10);
    }
    param_3 = param_3 & 1;
    goto joined_r0x0000abc0;
  }
  uVar7 = (int)param_3 >> 2 & 3;
  if (uVar7 == 2) {
LAB_0000aab8:
    uVar5 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = uVar5;
    param_2 = param_2 + 1;
LAB_0000aac8:
    uVar5 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = uVar5;
    param_2 = param_2 + 1;
  }
  else if (uVar7 < 3) {
    if (uVar7 == 1) goto LAB_0000aac8;
  }
  else if (uVar7 == 3) {
    uVar5 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = uVar5;
    param_2 = param_2 + 1;
    goto LAB_0000aab8;
  }
  uVar7 = param_3 & 0xfffffff0;
  FUN_000199dc(param_2,param_1,uVar7);
  param_1 = (undefined4 *)((int)param_1 + uVar7);
  param_2 = (undefined4 *)((int)param_2 + uVar7);
  param_3 = param_3 & 3;
joined_r0x0000abc0:
  for (; 0 < (int)param_3; param_3 = param_3 - 1) {
    uVar1 = *(undefined1 *)param_1;
    param_1 = (undefined4 *)((int)param_1 + 1);
    *(undefined1 *)param_2 = uVar1;
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  return;
}


================================================================