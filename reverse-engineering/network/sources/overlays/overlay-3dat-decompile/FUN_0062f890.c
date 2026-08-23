FUNCTION FUN_0062f890 @ 0x0062f890  size=256
CALLERS (1): FUN_0062e5b0@0x0062e5b0
CALLEES (1): FUN_00618ba0@0x00618ba0
----------------------------------------------------------------

void FUN_0062f890(void)

{
  undefined1 *puVar1;
  long lVar2;
  int iVar3;
  undefined4 uStack_8;
  undefined2 uStack_4;
  
  uStack_8 = DAT_0066af78;
  uStack_4 = DAT_0066af7c;
  if (cRam006c5c45 == '\0') {
    cRam006c5c45 = '\x01';
    for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
      lVar2 = FUN_00618ba0();
      puVar1 = (undefined1 *)lVar2;
      if (lVar2 == 0) {
        return;
      }
      *puVar1 = 1;
      puVar1[1] = 1;
      *(code **)(puVar1 + 0xc) = FUN_0062f990;
      *(undefined2 *)(puVar1 + 0x22) = *(undefined2 *)((int)&uStack_8 + iVar3 * 2);
      *(undefined2 *)(puVar1 + 0x26) = *(undefined2 *)(&DAT_0066af68 + iVar3 * 4);
      *(undefined2 *)(puVar1 + 0x28) = *(undefined2 *)(&DAT_0066af6a + iVar3 * 4);
      puVar1[3] = (char)iVar3;
    }
    for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {
      lVar2 = FUN_00618ba0();
      puVar1 = (undefined1 *)lVar2;
      if (lVar2 == 0) {
        return;
      }
      *puVar1 = 1;
      puVar1[1] = 1;
      *(code **)(puVar1 + 0xc) = FUN_0062fa80;
      puVar1[3] = (char)iVar3;
    }
  }
  return;
}



================================================================