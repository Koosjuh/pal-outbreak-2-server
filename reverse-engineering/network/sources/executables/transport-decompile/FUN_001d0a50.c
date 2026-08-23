
void FUN_001d0a50(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)param_1;
  uVar1 = *puVar3;
  uVar2 = puVar3[1];
  uRam00528200 = (char)uVar1;
  uRam00528201 = (char)uVar2;
  FUN_001d06d0(param_1,0x528200,puVar3 + 2,param_2,param_3);
  uRam005262b0 = (char)uVar1;
  uRam005262b1 = (char)uVar2;
  FUN_001d06d0(param_1,0x5262b0,puVar3 + 0x2a,param_2,param_3);
  return;
}

