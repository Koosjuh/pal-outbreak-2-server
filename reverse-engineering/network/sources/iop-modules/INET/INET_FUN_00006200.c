FUNCTION FUN_00006200 @ 0x00006200 size=212
CALLERS (7): FUN_0000db2c@0x0000db2c, FUN_0001866c@0x0001866c, FUN_000038a4@0x000038a4, FUN_00013264@0x00013264, FUN_00015430@0x00015430, FUN_00018170@0x00018170, FUN_00018de4@0x00018de4
CALLEES (1): FUN_00009f28@0x00009f28

undefined2 FUN_00006200(uint param_1,uint param_2,uint param_3,int param_4)

{
  undefined2 uVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = ((param_2 << 0x18 | (param_2 & 0xff00) << 8) >> 0x10) +
          (param_2 >> 8 & 0xff00 | param_2 >> 0x18) +
          ((param_3 << 0x18 | (param_3 & 0xff00) << 8) >> 0x10) +
          (param_3 >> 8 & 0xff00 | param_3 >> 0x18) +
          ((param_1 & 0xff) << 8 | (param_1 & 0xffff) >> 8);
  for (piVar2 = (int *)param_4; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
    iVar3 = iVar3 + ((piVar2[5] - piVar2[4]) * 0x100 & 0xff00U |
                    (uint)(piVar2[5] - piVar2[4]) >> 8 & 0xff);
  }
  uVar1 = FUN_00009f28(iVar3,param_4);
  return uVar1;
}


================================================================