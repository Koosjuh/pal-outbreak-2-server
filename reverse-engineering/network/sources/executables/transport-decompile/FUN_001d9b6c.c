
void FUN_001d9b6c(int param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined8 uVar3;
  long lVar4;
  uint auStack_b0 [2];
  undefined1 auStack_a8 [136];
  int iStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  
  *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_1 + 0x4fc);
  iStack_20 = param_2 + 0x3c;
  uVar3 = FUN_0010a050(param_1 + 0x4d4);
  puVar2 = (uint *)FUN_001e5538(iStack_20,param_1 + 0x4d4,
                                (*(ushort *)(param_2 + 0x2c) & 0x3ff) - 0x10,uVar3,0x114);
  *puVar2 = *puVar2 << 0x18 | (*puVar2 & 0xff00) << 8 | (*puVar2 & 0xff0000) >> 8 | *puVar2 >> 0x18;
  puVar2[1] = puVar2[1] << 0x18 | (puVar2[1] & 0xff00) << 8 | (puVar2[1] & 0xff0000) >> 8 |
              puVar2[1] >> 0x18;
  puVar2[0x22] = puVar2[0x22] << 0x18 | (puVar2[0x22] & 0xff00) << 8 |
                 (puVar2[0x22] & 0xff0000) >> 8 | puVar2[0x22] >> 0x18;
  puVar2[0x23] = puVar2[0x23] << 0x18 | (puVar2[0x23] & 0xff00) << 8 |
                 (puVar2[0x23] & 0xff0000) >> 8 | puVar2[0x23] >> 0x18;
  FUN_001d507c(param_1,0,(short)*puVar2);
  uVar3 = FUN_0010a050(param_1 + 0x484);
  FUN_001ea8e8(puVar2 + 0x25,puVar2[0x22],param_1 + 0x484,uVar3,puVar2 + 2,puVar2[1]);
  iStack_1c = FUN_001d533c(param_1);
  if (iStack_1c == 0) {
    DAT_0025b790 = 0x65;
  }
  else {
    iStack_20 = FUN_001ed2c0(iStack_1c,0x88);
    if (iStack_20 == 0) {
      FUN_001ec9e0(*(undefined4 *)(param_1 + 0x520),iStack_1c);
      DAT_0025b790 = 0x65;
    }
    else {
      FUN_001069a8(auStack_a8,puVar2 + 0x25,puVar2[0x23]);
      uVar1 = puVar2[0x23];
      auStack_b0[0] =
           uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000) >> 8 | uVar1 >> 0x18;
      uVar3 = FUN_0010a050(param_1 + 0x4d4);
      uStack_18 = FUN_001e56c8(iStack_20,auStack_b0,0x88,param_1 + 0x4d4,uVar3);
      lVar4 = FUN_001e180c(param_1,iStack_1c,0xb000,(undefined2)uStack_18,0x41,0);
      if (lVar4 == 0) {
        FUN_00109eb8(param_1 + 0x484,param_1 + 0x4d4);
      }
      else {
        DAT_0025b790 = 0x66;
      }
    }
  }
  return;
}

