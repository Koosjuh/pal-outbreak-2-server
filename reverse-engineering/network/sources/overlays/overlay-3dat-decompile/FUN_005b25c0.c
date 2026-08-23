FUNCTION FUN_005b25c0 @ 0x005b25c0  size=1004
CALLERS (1): FUN_005b24e0@0x005b24e0
CALLEES (13): FUN_005ba7b0@0x005ba7b0, FUN_005af2f0@0x005af2f0, FUN_005bb440@0x005bb440, FUN_005b68e0@0x005b68e0, FUN_005f4b70@0x005f4b70, FUN_005b8cf0@0x005b8cf0, FUN_005bd6e0@0x005bd6e0, FUN_005af310@0x005af310, FUN_005bdf70@0x005bdf70, FUN_005b6950@0x005b6950, FUN_005b6900@0x005b6900, FUN_00618b60@0x00618b60, ...
----------------------------------------------------------------

void FUN_005b25c0(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  int iVar3;
  undefined1 uStack_80;
  undefined1 uStack_7f;
  undefined1 uStack_7e;
  undefined1 auStack_7c [16];
  undefined2 uStack_6c;
  undefined2 uStack_6a;
  ushort uStack_68;
  undefined2 uStack_66;
  undefined2 uStack_64;
  undefined2 uStack_62;
  undefined2 uStack_60;
  undefined2 uStack_5e;
  undefined1 uStack_50;
  undefined1 uStack_4f;
  undefined1 auStack_4e [11];
  undefined1 auStack_43 [19];
  undefined4 uStack_30;
  undefined2 uStack_8;
  ushort uStack_6;
  undefined2 uStack_4;
  undefined2 uStack_2;
  
  uStack_2 = 0;
  uStack_4 = 0;
  uStack_6 = 0;
  uStack_8 = 0;
  iVar3 = (int)param_1;
  cVar1 = *(char *)(iVar3 + 0xf);
  if (cVar1 == '\x03') {
    FUN_005b6900();
  }
  else if (cVar1 == '\x02') {
    lVar2 = FUN_005af310();
    if (lVar2 != 0) {
      func_0x00106b60(&uStack_50,0,0x40);
      *(char *)(iVar3 + 0xf) = *(char *)(iVar3 + 0xf) + '\x01';
      FUN_005b68e0();
      uStack_50 = 1;
      uStack_30 = 0x702140;
      uStack_4f = 0;
      func_0x0010a4f0(auStack_4e,0x8710f1,10);
      func_0x0010a4f0(auStack_43,0x8710e0,0x10);
      FUN_005bd2e0(&uStack_50,0x5b6070);
    }
  }
  else if (cVar1 == '\x01') {
    FUN_00618b60();
    FUN_005b8cf0(0x51);
    FUN_005af2f0(0,10);
    FUN_005ba7b0();
    *(char *)(iVar3 + 0xf) = *(char *)(iVar3 + 0xf) + '\x01';
  }
  else if (cVar1 == '\0') {
    FUN_005bb440();
    func_0x00106b60(iVar3 + 0x51a2,0,0x31c);
    func_0x00106b60(iVar3 + 0x5190,0,6);
    func_0x00106b60(iVar3 + 0x4092,0,0x1004);
    FUN_005bdf70(1,0x5b5370);
    FUN_005bdf70(2,0x5b53b0);
    FUN_005bdf70(5,0x5b53f0);
    FUN_005bdf70(3,0x5b5520);
    FUN_005bdf70(4,0x5b5690);
    FUN_005bdf70(6,0x5b56e0);
    FUN_005bdf70(7,0x5b5710);
    FUN_005bdf70(8,0x5b5760);
    FUN_005bdf70(0xf,0x5b57a0);
    FUN_005bdf70(0x15,0x5b57e0);
    FUN_005bdf70(0x14,0x5b57e0);
    FUN_005bdf70(0x18,0x5b5820);
    FUN_005bdf70(0x1a,0x5b5860);
    FUN_005bdf70(0x19,0x5b58a0);
    FUN_005bdf70(0x1d,0x5b58e0);
    FUN_005bdf70(0x1e,0x5b5930);
    FUN_005bdf70(0x29,0x5b5970);
    FUN_005bdf70(9,0x5b59b0);
    FUN_005bdf70(10,0x5b5a00);
    FUN_005bdf70(0xb,0x5b5a50);
    FUN_005bdf70(0x1f,0x5b5ac0);
    FUN_005bdf70(0x20,0x5b5d20);
    FUN_005bdf70(0x21,0x5b5f60);
    FUN_005bdf70(0x23,0x5b6450);
    FUN_005bdf70(0x24,0x5b6460);
    FUN_005bdf70(0x25,0x5b6570);
    FUN_005bdf70(0xc,0x5b5fb0);
    FUN_005bdf70(0x2b,0x5b6030);
    *(char *)(iVar3 + 0xf) = *(char *)(iVar3 + 0xf) + '\x01';
    *(undefined4 *)(iVar3 + 0x550) = 1;
    *(undefined4 *)(iVar3 + 0x554) = 0;
    *(undefined1 *)(iVar3 + 0x45a) = 1;
    func_0x00106b60(&uStack_80,0,0x24);
    func_0x001bf2e0(&uStack_2,&uStack_4,&uStack_6,&uStack_8);
    uStack_7f = 1;
    uStack_7e = 5;
    uStack_80 = 0;
    if (cRam00343571 != '\0') {
      uStack_6 = uStack_6 | 4;
    }
    func_0x0010a4f0(auStack_7c,0x245e38,10);
    uStack_64 = 0;
    uStack_62 = 0;
    uStack_6c = uStack_2;
    uStack_6a = uStack_4;
    uStack_68 = uStack_6;
    uStack_66 = uStack_8;
    uStack_60 = 0;
    uStack_5e = 0;
    FUN_005bd6e0(&uStack_80);
    FUN_005b6950(param_1);
    FUN_005f4b70();
  }
  return;
}



================================================================