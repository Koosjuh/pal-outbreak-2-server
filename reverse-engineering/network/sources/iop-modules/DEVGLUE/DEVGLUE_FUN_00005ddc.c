FUNCTION FUN_00005ddc @ 0x00005ddc size=400
CALLERS (1): FUN_0000678c@0x0000678c
CALLEES (3): FUN_0000803c@0x0000803c, FUN_00008044@0x00008044, FUN_0000810c@0x0000810c

undefined2 * FUN_00005ddc(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  ushort local_28;
  ushort local_26 [3];
  
  puVar4 = (undefined2 *)0x0;
  do {
    if ((param_2 & 0xffff) == 0) {
LAB_00005f1c:
      if ((DAT_00009710 & 2) != 0) {
        FUN_0000810c("[session address] %08x\n",puVar4);
      }
      return puVar4;
    }
    FUN_00008044(&local_28,param_1,2);
    local_28 = local_28 << 8 | local_28 >> 8;
    if (local_28 == 0) goto LAB_00005f1c;
    FUN_00008044(local_26,param_1 + 2,2);
    local_26[0] = local_26[0] << 8 | local_26[0] >> 8;
    if (local_28 == 0x103) {
      puVar4 = (undefined2 *)0x0;
      if (local_26[0] != 8) goto LAB_00005f1c;
      iVar2 = 0;
      iVar3 = 0;
      do {
        puVar4 = &DAT_0000de90 + (iVar2 >> 0x10) * 0x70a;
        iVar2 = FUN_0000803c(param_1 + 4,&DAT_0000dec2 + (iVar2 >> 0x10) * 0xe14,8);
        iVar1 = iVar3 + 1;
        if (iVar2 == 0) break;
        iVar2 = iVar1 * 0x10000;
        iVar3 = iVar1;
      } while (iVar1 * 0x10000 < 1);
      if (0 < iVar3 << 0x10) {
        puVar4 = (undefined2 *)0x0;
        goto LAB_00005f1c;
      }
    }
    param_1 = param_1 + local_26[0] + 4;
    param_2 = (param_2 - 4) - (uint)local_26[0];
  } while( true );
}


================================================================