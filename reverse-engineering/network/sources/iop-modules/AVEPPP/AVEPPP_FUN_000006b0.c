FUNCTION FUN_000006b0 @ 0x000006b0 size=96
CALLERS (8): FUN_0000acc8@0x0000acc8, FUN_00006590@0x00006590, FUN_0000db58@0x0000db58, FUN_0000cc4c@0x0000cc4c, FUN_0000abec@0x0000abec, FUN_0000a9c0@0x0000a9c0, FUN_0000c298@0x0000c298, FUN_0000c54c@0x0000c54c
CALLEES (0): 

undefined4 * FUN_000006b0(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00016fc0;
  if (1 < (param_1 & 0xffff)) {
    return (undefined4 *)0x0;
  }
  iVar2 = (param_1 & 0xffff) * 0x898;
  *(undefined2 *)(&DAT_00016fc8 + iVar2) = 0;
  *(undefined **)(&DAT_00016fc4 + iVar2) = &DAT_00016fc4 + iVar2 + (iVar1 + 0x83U & 0xfffffffc);
  return (undefined4 *)(&DAT_00016fc4 + iVar2);
}


================================================================