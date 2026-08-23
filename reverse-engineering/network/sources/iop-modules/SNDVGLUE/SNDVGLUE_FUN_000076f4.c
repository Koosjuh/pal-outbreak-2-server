FUNCTION FUN_000076f4 @ 0x000076f4 size=260
CALLERS (1): FUN_00006c1c@0x00006c1c
CALLEES (4): FUN_000075b0@0x000075b0, FUN_00008044@0x00008044, FUN_00006b50@0x00006b50, FUN_0000746c@0x0000746c

void FUN_000076f4(int param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  undefined2 local_18;
  undefined2 local_16 [3];
  
  local_18 = 0x21c0;
  FUN_00008044(param_1 + 0x24e,&local_18,2);
  *(undefined1 *)(param_1 + 0x250) = 5;
  *(undefined1 *)(param_1 + 0x251) = 1;
  local_16[0] = 0x400;
  FUN_00008044(param_1 + 0x252,local_16,2);
  iVar3 = param_1 + 0x23a;
  uVar1 = FUN_000075b0(iVar3,*(undefined4 *)(param_1 + 0x20),param_1 + 0x10,"mEFP_Recv\n",0,
                       *(undefined2 *)(param_1 + 2),6);
  *(undefined2 *)(param_1 + 0x824) = uVar1;
  FUN_00006b50(iVar3,uVar1);
  uVar2 = FUN_0000746c(param_1);
  if (-1 < (int)((uint)uVar2 << 0x10)) {
    uVar1 = FUN_000075b0(iVar3,*(undefined4 *)(param_1 + 0x20),param_1 + 0x10,"emEFP_Recv\n",0xa7,
                         *(undefined2 *)(param_1 + 2),uVar2);
    *(undefined2 *)(param_1 + 0x824) = uVar1;
    FUN_00006b50(iVar3,uVar1);
  }
  return;
}


================================================================