FUNCTION FUN_000074ac @ 0x000074ac size=260
CALLERS (3): FUN_0000678c@0x0000678c, FUN_00005798@0x00005798, FUN_00006c1c@0x00006c1c
CALLEES (4): FUN_00007394@0x00007394, FUN_000072d8@0x000072d8, FUN_000075b0@0x000075b0, FUN_0000746c@0x0000746c

int FUN_000074ac(undefined2 *param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  
  switch(*param_1) {
  case 0:
  case 1:
    uVar1 = FUN_000072d8(param_1);
    if ((int)((uint)uVar1 << 0x10) < 0) goto LAB_00007598;
    uVar2 = 9;
    puVar3 = param_1 + 0xb;
    goto LAB_00007570;
  case 2:
  case 3:
    uVar1 = FUN_00007394(param_1);
    if ((int)((uint)uVar1 << 0x10) < 0) goto LAB_00007598;
    uVar2 = 0x19;
    break;
  default:
    return -1;
  case 5:
    uVar1 = 0xffff;
    if ((param_1[1] == 0) || (uVar1 = FUN_0000746c(param_1), (int)((uint)uVar1 << 0x10) < 0))
    goto LAB_00007598;
    uVar2 = 0xa7;
  }
  puVar3 = *(undefined2 **)(param_1 + 0x10);
LAB_00007570:
  uVar1 = FUN_000075b0(param_1 + 0x11d,puVar3,param_1 + 8,"emEFP_Recv\n",uVar2,param_1[1],uVar1);
  param_1[0x412] = uVar1;
LAB_00007598:
  return (int)(short)uVar1;
}


================================================================