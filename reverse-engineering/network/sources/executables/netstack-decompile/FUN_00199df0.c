
undefined4 FUN_00199df0(uint *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  uVar3 = FUN_00199f70(param_2,param_3);
  if (*(int *)uVar3 == 4) {
    lVar4 = FUN_0019a350(uVar3,0xf0000,0);
    if (lVar4 == 0) {
      uVar1 = 0xffffffff;
    }
    else {
      iVar2 = (int)lVar4;
      *param_1 = *(uint *)(iVar2 + 0xc);
      if ((*param_1 & 0xffff0000) == 0x10000) {
        uVar1 = 0;
        *param_1 = *(uint *)(iVar2 + 0xc);
        param_1[1] = *(uint *)(iVar2 + 0x10);
        param_1[2] = *(uint *)(iVar2 + 0x14);
        param_1[3] = *(uint *)(iVar2 + 0x18);
        param_1[4] = *(uint *)(iVar2 + 0x1c);
        param_1[5] = *(uint *)(iVar2 + 0x20);
        param_1[6] = *(uint *)(iVar2 + 0x24);
        param_1[7] = *(uint *)(iVar2 + 0x28);
        param_1[8] = *(uint *)(iVar2 + 0x2c);
        param_1[9] = *(uint *)(iVar2 + 0x30);
        param_1[10] = *(uint *)(iVar2 + 0x34);
        param_1[0xb] = *(uint *)(iVar2 + 0x38);
        param_1[0xc] = *(uint *)(iVar2 + 0x3c);
        param_1[0xd] = *(uint *)(iVar2 + 0x40);
        param_1[0xe] = *(uint *)(iVar2 + 0x44);
        param_1[0xf] = *(uint *)(iVar2 + 0x48);
        param_1[0x10] = *(uint *)(iVar2 + 0x4c);
        param_1[0x11] = *(uint *)(iVar2 + 0x50);
      }
      else {
        uVar1 = 0xfffffffe;
      }
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

