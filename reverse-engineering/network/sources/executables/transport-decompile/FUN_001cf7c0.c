
void FUN_001cf7c0(uint param_1,ulong param_2,char param_3,undefined8 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_3 == '\x01') {
    FUN_001cbc20((param_1 & 0xff) * 8 + 0x1600);
  }
  else {
    FUN_001cbc20((param_1 & 0xff) * 8 + 0x1400);
  }
  FUN_001cf360();
  uVar3 = 2;
  if (param_3 == '\x01') {
    uVar3 = 3;
  }
  iVar1 = (param_1 & 0xff) * 0x1468;
  uVar2 = FUN_001ab460(0x20,uVar3 | ((uint)param_2 & 0xff) << 0x10);
  *(undefined4 *)(iVar1 + 0x460d08) = uVar2;
  *(int *)(iVar1 + 0x460500) = iVar1 + 0x460d20;
  *(int *)(iVar1 + 0x460504) = iVar1 + 0x460f20;
  *(int *)(iVar1 + 0x460d18) = iVar1 + 0x461120;
  if (param_3 != '\x01') {
    param_4 = 0xff;
  }
  FUN_001ce070((int *)(iVar1 + 0x460500),param_2 & 0xff,param_2 & 0xff,3,0,(char)param_4);
  if (param_3 == '\x01') {
    FUN_001cf6a0(param_4,param_2);
  }
  return;
}

