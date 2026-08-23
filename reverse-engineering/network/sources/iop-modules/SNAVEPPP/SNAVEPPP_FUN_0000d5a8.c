FUNCTION FUN_0000d5a8 @ 0x0000d5a8 size=240
CALLERS (1): FUN_00001d0c@0x00001d0c
CALLEES (10): FUN_0000d398@0x0000d398, FUN_0000c208@0x0000c208, FUN_0000c140@0x0000c140, FUN_000096d8@0x000096d8, FUN_0000a624@0x0000a624, FUN_000075dc@0x000075dc, FUN_0000c0f0@0x0000c0f0, FUN_0000c174@0x0000c174, FUN_0000c238@0x0000c238, FUN_0000c268@0x0000c268

undefined4 FUN_0000d5a8(int param_1,undefined4 *param_2)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  
  FUN_000096d8();
  FUN_000075dc(param_1);
  FUN_0000d398(param_1);
  if (**(char **)(param_1 + 0xc) != '\0') {
    iVar3 = *(int *)(param_1 + 0x30);
    FUN_0000c238(iVar3,(int)*(short *)(param_2 + 3));
    FUN_0000c0f0(iVar3,*param_2);
    uVar2 = *(ushort *)((int)param_2 + 6);
    if (((uVar2 & 0x80) == 0) && (uVar2 != 4)) {
      FUN_0000c174(iVar3 + 0x34,*(undefined2 *)((int)param_2 + 6));
      uVar2 = *(ushort *)((int)param_2 + 6);
      iVar1 = iVar3;
    }
    else {
      uVar2 = uVar2 & 0x7f;
      iVar1 = iVar3 + 0x34;
    }
    FUN_0000c174(iVar1,uVar2);
    FUN_0000c208(iVar3,param_2[2]);
    FUN_0000c268(iVar3,(int)*(short *)((int)param_2 + 0xe));
    FUN_0000c140(iVar3,(int)*(short *)(param_2 + 1));
    FUN_0000a624(param_1);
  }
  return 0;
}


================================================================