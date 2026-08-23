FUNCTION FUN_005af840 @ 0x005af840  size=500
CALLERS (1): FUN_005ad030@0x005ad030
CALLEES (2): FUN_005ba7c0@0x005ba7c0, FUN_00618ba0@0x00618ba0
----------------------------------------------------------------

void FUN_005af840(void)

{
  undefined1 *puVar1;
  long lVar2;
  int iVar3;
  
  lVar2 = FUN_00618ba0();
  if (lVar2 != 0) {
    puVar1 = (undefined1 *)lVar2;
    *puVar1 = 1;
    puVar1[1] = 1;
    *(undefined1 **)(puVar1 + 0xc) = &LAB_005b0840;
    *(undefined4 *)(puVar1 + 0x30) = 1;
    lVar2 = FUN_00618ba0();
    if (lVar2 != 0) {
      puVar1 = (undefined1 *)lVar2;
      *puVar1 = 1;
      puVar1[1] = 1;
      *(code **)(puVar1 + 0xc) = FUN_005afa40;
      *(undefined4 *)(puVar1 + 0x30) = 1;
      for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {
        lVar2 = FUN_00618ba0();
        if (lVar2 == 0) {
          return;
        }
        puVar1 = (undefined1 *)lVar2;
        *puVar1 = 1;
        puVar1[1] = 1;
        *(code **)(puVar1 + 0xc) = FUN_005b0210;
        puVar1[3] = (char)iVar3;
      }
      for (iVar3 = 0; iVar3 < (int)(uint)uRam006c45fa; iVar3 = iVar3 + 1) {
        lVar2 = FUN_00618ba0();
        if (lVar2 == 0) {
          return;
        }
        puVar1 = (undefined1 *)lVar2;
        *puVar1 = 1;
        puVar1[1] = 1;
        *(code **)(puVar1 + 0xc) = FUN_005b0550;
        puVar1[3] = (char)iVar3;
        *(undefined2 *)(puVar1 + 0x22) = 0x135;
      }
      lVar2 = FUN_00618ba0();
      if (lVar2 != 0) {
        puVar1 = (undefined1 *)lVar2;
        *puVar1 = 1;
        puVar1[1] = 1;
        *(undefined1 **)(puVar1 + 0xc) = &LAB_005afe40;
        for (iVar3 = 0; iVar3 < (int)(uint)uRam006c45fa; iVar3 = iVar3 + 1) {
          lVar2 = FUN_00618ba0();
          if (lVar2 == 0) {
            return;
          }
          puVar1 = (undefined1 *)lVar2;
          *puVar1 = 1;
          puVar1[1] = 1;
          *(code **)(puVar1 + 0xc) = FUN_005affb0;
          puVar1[3] = (char)iVar3;
          puVar1[0x38] = 0;
          if (iVar3 < 5) {
            *(undefined2 *)(puVar1 + 0x22) = 0x131;
          }
          else {
            *(undefined2 *)(puVar1 + 0x22) = 0x132;
          }
        }
        lVar2 = FUN_00618ba0();
        if (lVar2 != 0) {
          puVar1 = (undefined1 *)lVar2;
          *puVar1 = 1;
          puVar1[1] = 1;
          *(undefined1 **)(puVar1 + 0xc) = &LAB_005afe80;
          lVar2 = FUN_00618ba0();
          if (lVar2 != 0) {
            puVar1 = (undefined1 *)lVar2;
            *puVar1 = 1;
            puVar1[1] = 1;
            puVar1[3] = 1;
            *(undefined1 **)(puVar1 + 0xc) = &LAB_005afe80;
            lVar2 = FUN_00618ba0();
            if (lVar2 != 0) {
              puVar1 = (undefined1 *)lVar2;
              *puVar1 = 1;
              puVar1[1] = 1;
              *(undefined2 *)(puVar1 + 0x22) = 0x25;
              *(code **)(puVar1 + 0xc) = FUN_005b08f0;
              FUN_005ba7c0();
            }
          }
        }
      }
    }
  }
  return;
}



================================================================