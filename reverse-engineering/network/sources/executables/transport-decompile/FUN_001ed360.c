
bool FUN_001ed360(undefined8 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_001ebca8(param_1);
  iVar2 = FUN_001ebd04(param_1);
  return iVar1 + (param_2 & 0xffff) <= iVar2 - 0x2cU;
}

