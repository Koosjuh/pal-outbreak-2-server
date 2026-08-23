FUNCTION FUN_0000a9f8 @ 0x0000a9f8 size=300
CALLERS (1): FUN_00007000@0x00007000
CALLEES (3): FUN_000010a8@0x000010a8, FUN_0000acf0@0x0000acf0, FUN_00011d00@0x00011d00

undefined4 FUN_0000a9f8(int param_1,char *param_2,int param_3,int param_4)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  short local_28 [4];
  
  for (; ((0 < param_3 << 0x10 && (cVar1 = *param_2, cVar1 != '\0')) &&
         ((uVar6 = 1, cVar1 == '\x01' || (uVar6 = (uint)(byte)param_2[1], uVar6 != 0))));
      param_2 = param_2 + uVar6) {
    iVar5 = param_3 - uVar6;
    if ((cVar1 == '\x02') && (iVar5 = param_3 - uVar6, uVar6 == 4)) {
      if ((*(byte *)(param_4 + 0xd) & 2) != 0) {
        FUN_00011d00(local_28,param_2 + 2,2);
        uVar2 = FUN_000010a8((int)local_28[0]);
        uVar3 = FUN_0000acf0(param_1);
        if (uVar2 < uVar3) {
          uVar4 = FUN_000010a8((int)local_28[0]);
          *(undefined2 *)(param_1 + 300) = uVar4;
        }
        else {
          uVar4 = FUN_0000acf0(param_1);
          *(undefined2 *)(param_1 + 300) = uVar4;
        }
      }
      iVar5 = param_3 + -4;
    }
    param_3 = iVar5;
  }
  return 0;
}


================================================================