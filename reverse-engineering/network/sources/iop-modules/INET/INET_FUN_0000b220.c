FUNCTION FUN_0000b220 @ 0x0000b220 size=676
CALLERS (1): FUN_00007e28@0x00007e28
CALLEES (4): FUN_00009e60@0x00009e60, FUN_0000d8cc@0x0000d8cc, FUN_0000a9c0@0x0000a9c0, FUN_000100c4@0x000100c4

undefined4 FUN_0000b220(undefined4 param_1,int param_2,int param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar5 = *(int *)(param_3 + 0x14) - *(int *)(param_3 + 0x10);
  iVar8 = iVar5 + 0x14;
  iVar7 = DAT_0001b984;
  do {
    if (iVar7 == 0) {
      return 0;
    }
    if ((*(int *)(iVar7 + 0xc) == 1) &&
       (((*(uint *)(iVar7 + 0x14) == 0 || (*(uint *)(iVar7 + 0x14) == (uint)*(byte *)(param_2 + 9)))
        && (*(int *)(iVar7 + 0x1c) + iVar8 <= *(int *)(iVar7 + 0x18))))) {
      puVar3 = (undefined4 *)FUN_00009e60(0,iVar8);
      if (puVar3 == (undefined4 *)0x0) {
        return 0;
      }
      FUN_0000a9c0(param_2,puVar3[5],0x14);
      uVar1 = *(ushort *)(puVar3[5] + 2);
      *(ushort *)(puVar3[5] + 2) = uVar1 << 8 | uVar1 >> 8;
      uVar1 = *(ushort *)(puVar3[5] + 4);
      *(ushort *)(puVar3[5] + 4) = uVar1 << 8 | uVar1 >> 8;
      uVar1 = *(ushort *)(puVar3[5] + 6);
      *(ushort *)(puVar3[5] + 6) = uVar1 << 8 | uVar1 >> 8;
      iVar6 = puVar3[5];
      uVar2 = *(undefined4 *)(iVar6 + 0xc);
      *(char *)(iVar6 + 0xc) = (char)((uint)uVar2 >> 0x18);
      *(char *)(iVar6 + 0xd) = (char)((uint)uVar2 >> 0x10);
      *(char *)(iVar6 + 0xe) = (char)((uint)uVar2 >> 8);
      *(char *)(iVar6 + 0xf) = (char)uVar2;
      iVar6 = puVar3[5];
      uVar2 = *(undefined4 *)(iVar6 + 0x10);
      *(char *)(iVar6 + 0x10) = (char)((uint)uVar2 >> 0x18);
      *(char *)(iVar6 + 0x11) = (char)((uint)uVar2 >> 0x10);
      *(char *)(iVar6 + 0x12) = (char)((uint)uVar2 >> 8);
      *(char *)(iVar6 + 0x13) = (char)uVar2;
      iVar6 = puVar3[5];
      puVar3[5] = iVar6 + 0x14;
      FUN_0000a9c0(*(undefined4 *)(param_3 + 0x10),iVar6 + 0x14,iVar5);
      puVar3[5] = puVar3[5] + iVar5;
      puVar4 = *(undefined4 **)(iVar7 + 0x24);
      puVar3[1] = puVar4;
      if (puVar4 == (undefined4 *)0x0) {
        *(undefined4 **)(iVar7 + 0x20) = puVar3;
      }
      else {
        *puVar4 = puVar3;
      }
      *puVar3 = 0;
      *(undefined4 **)(iVar7 + 0x24) = puVar3;
      *(int *)(iVar7 + 0x1c) = *(int *)(iVar7 + 0x1c) + iVar8;
      FUN_0000d8cc(iVar7 + 0x28);
      FUN_000100c4();
    }
    iVar7 = *(int *)(iVar7 + 4);
  } while( true );
}


================================================================