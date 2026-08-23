FUNCTION FUN_005d80c0 @ 0x005d80c0  size=228
CALLERS (1): FUN_005c8810@0x005c8810
CALLEES (3): FUN_005d7e00@0x005d7e00, FUN_005d7f80@0x005d7f80, FUN_005d7b60@0x005d7b60
----------------------------------------------------------------

void FUN_005d80c0(void)

{
  int iVar1;
  long lVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(iRam00701068 + 0x4f694);
LAB_005d80e0:
  do {
    puVar3 = (undefined4 *)*puVar3;
    while( true ) {
      if (puVar3 == (undefined4 *)0x0) {
        return;
      }
      iVar1 = puVar3[0x41];
      if (iVar1 == 0) {
        return;
      }
      if (iVar1 == 4) {
        lVar2 = func_0x01212a00();
        if (lVar2 != 0) {
          if (*(char *)((int)puVar3 + 0x10d) == '\x02') {
            FUN_005d7f80(puVar3);
          }
          else if (*(char *)((int)puVar3 + 0x10d) == '\x01') {
            FUN_005d7e00(puVar3);
          }
        }
        goto LAB_005d80e0;
      }
      if (iVar1 == 3) break;
      puVar3 = (undefined4 *)*puVar3;
    }
    (**(code **)(puVar3[0x46] + 100))();
    FUN_005d7b60(puVar3);
    if (puVar3[0x41] != 3) {
      return;
    }
  } while( true );
}



================================================================