FUNCTION FUN_005bca90 @ 0x005bca90  size=408
CALLERS (0): 
CALLEES (5): FUN_005c7f20@0x005c7f20, FUN_005c7e30@0x005c7e30, FUN_005c4f40@0x005c4f40, FUN_005c4fd0@0x005c4fd0, FUN_005bdf90@0x005bdf90
----------------------------------------------------------------

void FUN_005bca90(char *param_1,int param_2)

{
  uint uVar1;
  undefined8 uVar2;
  undefined1 auStack_b0 [64];
  undefined1 auStack_70 [16];
  undefined1 auStack_60 [16];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined1 *puStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined1 *puStack_3c;
  undefined1 uStack_10;
  undefined1 uStack_f;
  
  uRam0086f7f8 = 0;
  if (*param_1 == '\0') {
    uRam006febb4 = *(undefined4 *)(param_2 + 4);
    func_0x00109eb8(0x6cc440,0x639e78);
    func_0x0010a4f0(0x6cc450,0x86f820,0x10);
    uStack_f = 2;
    uStack_10 = 0;
    (*pcRam006cb96c)(&uStack_10,&uStack_10);
    func_0x00106b60(&uStack_50,0,0x3c);
    uVar2 = FUN_005c4f40();
    func_0x00109eb8(auStack_60,uVar2);
    uVar2 = FUN_005c4fd0();
    func_0x00109eb8(auStack_70,uVar2);
    uStack_4c = 0x44;
    uStack_50 = 0x4e414d45;
    uStack_44 = 0x4e414d45;
    puStack_48 = auStack_60;
    puStack_3c = auStack_70;
    uStack_40 = 0x46;
    func_0x001e094c(uRam006febac,&uStack_50,10,0x5bc990);
  }
  else if (*param_1 == '\'') {
    func_0x00106b60(0x6fc5e8,0,0x300);
    if (*(uint *)(param_2 + 4) < 0x19) {
      uVar1 = *(uint *)(param_2 + 4) + 0x334 & 0xffff;
    }
    else {
      uVar1 = 0x332;
    }
    FUN_005c7e30(10);
    FUN_005c7f20(0xe);
    func_0x00109728(auStack_b0,0x639e68,uVar1);
    func_0x00109ab0(0x6fc5e8,auStack_b0);
    FUN_005bdf90(2,0);
  }
  return;
}



================================================================