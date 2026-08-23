FUNCTION FUN_0000b5c4 @ 0x0000b5c4 size=572
CALLERS (0): 
CALLEES (4): FUN_0000709c@0x0000709c, FUN_00009e60@0x00009e60, FUN_0000e4e8@0x0000e4e8, FUN_0000a9c0@0x0000a9c0

uint FUN_0000b5c4(int param_1,int param_2,uint param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined1 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  undefined1 auStack_30 [2];
  ushort local_2e;
  ushort local_2c;
  ushort local_2a;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  
  iVar11 = 0;
  if (*(int *)(param_1 + 0xc) == 1) {
    uVar7 = 0xfffffe00;
    if (0x13 < param_3) {
      FUN_0000a9c0(param_2,auStack_30,0x14);
      uVar5 = _local_20;
      uVar9 = _local_24;
      local_2e = local_2e << 8 | local_2e >> 8;
      local_2c = local_2c << 8 | local_2c >> 8;
      local_2a = local_2a << 8 | local_2a >> 8;
      uVar4 = (uint)_local_24 >> 8;
      uVar3 = (uint)_local_24 >> 0x10;
      uVar7 = (uint)_local_24 >> 0x18;
      _local_24 = CONCAT13((char)uVar9,CONCAT12((char)uVar4,CONCAT11((char)uVar3,(char)uVar7)));
      uVar2 = (undefined1)((uint)_local_20 >> 8);
      uVar1 = (undefined1)((uint)_local_20 >> 0x10);
      uVar8 = (undefined1)((uint)_local_20 >> 0x18);
      _local_20 = CONCAT13((char)uVar5,CONCAT12(uVar2,CONCAT11(uVar1,uVar8)));
      iVar10 = CONCAT13((char)uVar5,CONCAT12(uVar2,CONCAT11(uVar1,uVar8)));
      if ((iVar10 == -1) || (iVar11 = FUN_0000e4e8(iVar10), iVar11 != 0)) {
        iVar6 = FUN_00009e60(param_2 + 0x14,param_3 - 0x14);
        uVar7 = 0xfffffe08;
        if (iVar6 != 0) {
          uVar9 = 0;
          if (iVar11 != 0) {
            uVar9 = *(undefined4 *)(iVar11 + 0x70);
          }
          FUN_0000709c(iVar11,uVar9,iVar10,local_27,local_28,0,iVar6,0);
          uVar7 = param_3;
        }
      }
      else {
        uVar7 = 0xfffffdfe;
      }
    }
  }
  else {
    uVar7 = 0xfffffe04;
  }
  return uVar7;
}


================================================================