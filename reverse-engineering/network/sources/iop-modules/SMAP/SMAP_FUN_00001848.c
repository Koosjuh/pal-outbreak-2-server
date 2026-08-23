FUNCTION FUN_00001848 @ 0x00001848 size=1320
CALLERS (0): 
CALLEES (3): FUN_00002ad4@0x00002ad4, FUN_00002b38@0x00002b38, FUN_00001684@0x00001684

uint FUN_00001848(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint local_20 [2];
  
  uVar1 = 0xfffffe00;
  puVar3 = (uint *)0x0;
  uVar2 = uVar1;
  if (param_2 == -0x7ffef000) {
    puVar3 = (uint *)(param_1 + 0x108);
  }
  else if (param_2 < -0x7ffeefff) {
    if (param_2 == -0x7ffefffa) {
      puVar3 = (uint *)(param_1 + 0xe0);
    }
    else if (param_2 < -0x7ffefff9) {
      if (param_2 == -0x7ffeffff) {
        puVar3 = (uint *)(param_1 + 0xcc);
      }
      else if (param_2 < -0x7ffefffe) {
        if (param_2 == -0x7fffff00) {
          uVar2 = 1;
        }
        else if (param_2 < -0x7ffffeff) {
          uVar2 = DAT_000031f8;
          if (param_2 != -0x80000000) {
            uVar2 = uVar1;
          }
        }
        else if (param_2 == -0x7fff0000) {
          puVar3 = (uint *)(param_1 + 200);
        }
      }
      else if (param_2 == -0x7ffefffd) {
        puVar3 = (uint *)(param_1 + 0xd4);
      }
      else if (param_2 < -0x7ffefffd) {
        puVar3 = (uint *)(param_1 + 0xd0);
      }
      else if (param_2 == -0x7ffefffc) {
        puVar3 = (uint *)(param_1 + 0xd8);
      }
      else if (param_2 == -0x7ffefffb) {
        puVar3 = (uint *)(param_1 + 0xdc);
      }
    }
    else if (param_2 == -0x7ffefff5) {
      puVar3 = (uint *)(param_1 + 0xf4);
    }
    else if (param_2 < -0x7ffefff4) {
      if (param_2 == -0x7ffefff8) {
        puVar3 = (uint *)(param_1 + 0xe8);
      }
      else if (param_2 < -0x7ffefff8) {
        puVar3 = (uint *)(param_1 + 0xe4);
      }
      else if (param_2 == -0x7ffefff7) {
        puVar3 = (uint *)(param_1 + 0xec);
      }
      else if (param_2 == -0x7ffefff6) {
        puVar3 = (uint *)(param_1 + 0xf0);
      }
    }
    else if (param_2 == -0x7ffefff3) {
      puVar3 = (uint *)(param_1 + 0xfc);
    }
    else if (param_2 < -0x7ffefff3) {
      puVar3 = (uint *)(param_1 + 0xf8);
    }
    else if (param_2 == -0x7ffefff2) {
      puVar3 = (uint *)(param_1 + 0x100);
    }
    else if (param_2 == -0x7ffefff1) {
      puVar3 = (uint *)(param_1 + 0x104);
    }
  }
  else if (param_2 == -0x7ffeeff7) {
    puVar3 = (uint *)(param_1 + 300);
  }
  else if (param_2 < -0x7ffeeff6) {
    if (param_2 == -0x7ffeeffc) {
      puVar3 = (uint *)(param_1 + 0x118);
    }
    else if (param_2 < -0x7ffeeffb) {
      if (param_2 == -0x7ffeeffe) {
        puVar3 = (uint *)(param_1 + 0x110);
      }
      else {
        puVar3 = (uint *)(param_1 + 0x114);
        if (param_2 < -0x7ffeeffd) {
          puVar3 = (uint *)(param_1 + 0x10c);
        }
      }
    }
    else if (param_2 == -0x7ffeeffa) {
      puVar3 = (uint *)(param_1 + 0x120);
    }
    else if (param_2 < -0x7ffeeffa) {
      puVar3 = (uint *)(param_1 + 0x11c);
    }
    else if (param_2 == -0x7ffeeff9) {
      puVar3 = (uint *)(param_1 + 0x124);
    }
    else if (param_2 == -0x7ffeeff8) {
      puVar3 = (uint *)(param_1 + 0x128);
    }
  }
  else if (param_2 == -0x7ffdffff) {
    uVar2 = 0;
    if (0 < *(int *)(param_1 + 0x38)) {
      uVar2 = *(uint *)(param_1 + 0x3c);
    }
  }
  else if (param_2 < -0x7ffdfffe) {
    if (param_2 == -0x7ffeeff5) {
      puVar3 = (uint *)(param_1 + 0x134);
    }
    else if (param_2 < -0x7ffeeff5) {
      puVar3 = (uint *)(param_1 + 0x130);
    }
    else if (param_2 == -0x7ffeeff4) {
      puVar3 = (uint *)(param_1 + 0x138);
    }
    else if (param_2 == -0x7ffe0000) {
      local_20[0] = (uint)(DAT_00003204 != 0) << 7;
      if ((DAT_0000320c & 0x400) != 0) {
        local_20[0] = local_20[0] | 0x40;
      }
      if ((DAT_0000320c & 0x100) != 0) {
        local_20[0] = local_20[0] | 8;
      }
      if ((DAT_0000320c & 0x80) != 0) {
        local_20[0] = local_20[0] | 4;
      }
      if ((DAT_0000320c & 0x40) != 0) {
        local_20[0] = local_20[0] | 2;
      }
      local_20[0] = DAT_0000320c >> 5 & 1 | local_20[0];
      puVar3 = local_20;
    }
  }
  else if (param_2 == -0x7f000000) {
    if ((param_3 != 0) && (param_4 == 4)) {
      FUN_00002ad4(param_3,local_20,4);
      uVar2 = 0xfffffe6d;
      if (local_20[0] - 9 < 0x73) {
        DAT_000031f8 = local_20[0];
        uVar2 = FUN_00002b38(*(undefined4 *)(param_1 + 0x24));
      }
    }
  }
  else if (param_2 < -0x7effffff) {
    if (param_2 == -0x7ffd0000) {
      uVar2 = *(uint *)(param_1 + 0x38);
    }
  }
  else if (param_2 == -0x7efe0000) {
    if ((param_3 != 0) && (param_4 == 4)) {
      FUN_00002ad4(param_3,local_20,4);
      DAT_0000320c = (local_20[0] & 0x40) << 4;
      DAT_00003204 = local_20[0] >> 7 & 1;
      if ((local_20[0] & 8) != 0) {
        DAT_0000320c = DAT_0000320c | 0x100;
      }
      if ((local_20[0] & 4) != 0) {
        DAT_0000320c = DAT_0000320c | 0x80;
      }
      if ((local_20[0] & 2) != 0) {
        DAT_0000320c = DAT_0000320c | 0x40;
      }
      if ((local_20[0] & 1) != 0) {
        DAT_0000320c = DAT_0000320c | 0x20;
      }
      uVar2 = 0;
    }
  }
  else if (param_2 == -0x7efc0000) {
    uVar2 = FUN_00001684(param_1,param_3,param_4);
  }
  if (((puVar3 != (uint *)0x0) && (param_3 != 0)) && (param_4 == 4)) {
    FUN_00002ad4(puVar3,param_3,4);
    uVar2 = 0;
  }
  return uVar2;
}


================================================================