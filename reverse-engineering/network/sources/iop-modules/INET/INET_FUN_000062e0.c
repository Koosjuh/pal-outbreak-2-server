FUNCTION FUN_000062e0 @ 0x000062e0 size=408
CALLERS (2): FUN_00007e28@0x00007e28, FUN_00006478@0x00006478
CALLEES (5): FUN_0000709c@0x0000709c, FUN_00009e60@0x00009e60, FUN_00009f28@0x00009f28, FUN_00009eec@0x00009eec, FUN_00011d90@0x00011d90

void FUN_000062e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,uint param_7,uint param_8,int *param_9)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_1 != 0) {
    iVar4 = *(int *)(param_1 + 0x70);
  }
  if (iVar4 != 0) {
    puVar2 = (undefined4 *)FUN_00009e60(0,8);
    if ((puVar2 != (undefined4 *)0x0) && (*param_9 == 0)) {
      puVar3 = (undefined1 *)puVar2[5];
      *(short *)(puVar3 + 4) = (short)param_7;
      *(short *)(puVar3 + 6) = (short)param_8;
      *(ushort *)(puVar3 + 4) = (ushort)((param_7 & 0xff) << 8) | (ushort)(param_7 >> 8) & 0xff;
      *puVar3 = param_5;
      puVar3[1] = param_6;
      *(ushort *)(puVar3 + 6) = (ushort)((param_8 & 0xff) << 8) | (ushort)(param_8 >> 8) & 0xff;
      *puVar2 = param_9;
      puVar2[5] = puVar2[5] + 8;
      param_9[1] = (int)puVar2;
      *(undefined2 *)(puVar3 + 2) = 0;
      uVar1 = FUN_00009f28(0,puVar2);
      *(ushort *)(puVar3 + 2) = ~uVar1;
      FUN_0000709c(param_1,iVar4,param_3,1,param_4,0,puVar2,0);
      return;
    }
    if ((DAT_0001b850 & 1) != 0) {
      FUN_00011d90("# ERR # %s:%d: %s\n",s_icmp_c_0001b6e0,0x1b,"icmp_snd - no space for header");
    }
  }
  FUN_00009eec(param_9);
  return;
}


================================================================