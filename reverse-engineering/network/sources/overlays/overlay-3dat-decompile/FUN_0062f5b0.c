FUNCTION FUN_0062f5b0 @ 0x0062f5b0  size=352
CALLERS (0): 
CALLEES (6): FUN_005af2e0@0x005af2e0, FUN_0062fea0@0x0062fea0, FUN_00618c20@0x00618c20, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0, FUN_005fe4b0@0x005fe4b0
----------------------------------------------------------------

void FUN_0062f5b0(int param_1)

{
  char cVar1;
  undefined8 uVar2;
  long lVar3;
  int iVar4;
  undefined1 auStack_80 [128];
  
  if (**(char **)(param_1 + 0x10) == '\0') {
    FUN_00618c20();
  }
  else {
    FUN_005af2e0(0x12);
    FUN_005af2c0(0);
    uVar2 = FUN_0062fea0(0x5e);
    FUN_005af1e0(0x93,0xb0,3,uVar2);
    iVar4 = sRam006c4b94 * 4;
    if (*(char *)(iVar4 + 0x6c4baa) == '\0') {
      lVar3 = func_0x001b6950(*(undefined1 *)(iVar4 + 0x6c4bac));
      if (lVar3 != 0) {
        cVar1 = *(char *)(sRam006c4b94 * 4 + 0x6c4bab);
        if (cVar1 == '\0') {
          FUN_005af1e0(0x11c,0xc4,3);
        }
        else {
          func_0x00109728(auStack_80,0x66af60,lVar3,(&PTR_DAT_0068ae30)[cVar1]);
          FUN_005af1e0(0x11c,0xc4,3,auStack_80);
        }
      }
    }
    else {
      FUN_005fe4b0(*(undefined1 *)(iVar4 + 0x6c4bac));
      lVar3 = func_0x001b68b0();
      if (lVar3 != 0) {
        FUN_005af1e0(0x11c,0xc4,3,lVar3);
      }
    }
  }
  return;
}



================================================================