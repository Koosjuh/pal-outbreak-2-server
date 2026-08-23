FUNCTION FUN_00608b70 @ 0x00608b70  size=260
CALLERS (1): FUN_0060acb0@0x0060acb0
CALLEES (1): FUN_00608ab0@0x00608ab0
----------------------------------------------------------------

long FUN_00608b70(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  long lVar1;
  long lVar2;
  int iVar3;
  undefined1 *puVar4;
  
  iVar3 = (int)param_1;
  lVar1 = (**(code **)(iVar3 + 0x28))(*(undefined4 *)(iVar3 + 0x30),1,0x48);
  if (lVar1 != 0) {
    lVar2 = (**(code **)(iVar3 + 0x28))(*(undefined4 *)(iVar3 + 0x30),8,0x5a0);
    puVar4 = (undefined1 *)lVar1;
    *(int *)(puVar4 + 0x28) = (int)lVar2;
    if (lVar2 == 0) {
      (**(code **)(iVar3 + 0x2c))(*(undefined4 *)(iVar3 + 0x30),lVar1);
      lVar1 = 0;
    }
    else {
      lVar2 = (**(code **)(iVar3 + 0x28))(*(undefined4 *)(iVar3 + 0x30),1,param_3);
      *(int *)(puVar4 + 0x2c) = (int)lVar2;
      if (lVar2 == 0) {
        (**(code **)(iVar3 + 0x2c))(*(undefined4 *)(iVar3 + 0x30),*(undefined4 *)(puVar4 + 0x28));
        (**(code **)(iVar3 + 0x2c))(*(undefined4 *)(iVar3 + 0x30),lVar1);
        lVar1 = 0;
      }
      else {
        *(int *)(puVar4 + 0x30) = *(int *)(puVar4 + 0x2c) + (int)param_3;
        *(undefined4 *)(puVar4 + 0x3c) = param_2;
        *puVar4 = 0;
        FUN_00608ab0(lVar1,param_1,0);
      }
    }
  }
  return lVar1;
}



================================================================