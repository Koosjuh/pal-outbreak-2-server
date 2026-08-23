FUNCTION FUN_0000c174 @ 0x0000c174 size=148
CALLERS (1): FUN_0000d5a8@0x0000d5a8
CALLEES (0): 

undefined4 FUN_0000c174(int param_1,int param_2)

{
  ushort uVar1;
  
  if (param_2 == 0) {
    *(undefined2 *)(param_1 + 0xc) = 0xc023;
    *(ushort *)(param_1 + 4) = *(ushort *)(param_1 + 4) | 8;
  }
  else if (param_2 == 1) {
    *(undefined1 *)(param_1 + 0x19) = 0;
    *(ushort *)(param_1 + 4) = *(ushort *)(param_1 + 4) & 0xfff7;
  }
  else {
    if (param_2 == 2) {
      uVar1 = *(ushort *)(param_1 + 4);
      *(undefined2 *)(param_1 + 0xc) = 0xc223;
      *(undefined1 *)(param_1 + 0x18) = 5;
      *(undefined1 *)(param_1 + 0x19) = 0;
    }
    else {
      if (param_2 != 4) {
        return 1;
      }
      uVar1 = *(ushort *)(param_1 + 4);
      *(undefined2 *)(param_1 + 0xc) = 0xc223;
      *(undefined1 *)(param_1 + 0x18) = 5;
      *(undefined1 *)(param_1 + 0x19) = 1;
    }
    *(ushort *)(param_1 + 4) = uVar1 | 8;
  }
  return 0;
}


================================================================