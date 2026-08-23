FUNCTION FUN_0062e440 @ 0x0062e440  size=360
CALLERS (1): FUN_0062e3c0@0x0062e3c0
CALLEES (6): FUN_005af120@0x005af120, FUN_005c0a00@0x005c0a00, FUN_005b6900@0x005b6900, FUN_005b68e0@0x005b68e0, FUN_005c44a0@0x005c44a0, FUN_005bffa0@0x005bffa0
----------------------------------------------------------------

void FUN_0062e440(undefined8 param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = uRam006c4600;
  iVar3 = (int)param_1;
  switch(*(char *)(iVar3 + 0x10)) {
  case '\0':
    FUN_005b68e0();
    FUN_005c0a00(uVar1,0x62f1e0);
    *(undefined1 *)(iVar3 + 0x4b7) = 0;
    *(char *)(iVar3 + 0x10) = *(char *)(iVar3 + 0x10) + '\x01';
  case '\x01':
    FUN_005b6900();
    break;
  case '\x02':
    FUN_005b68e0();
    FUN_005bffa0(uVar1,0x62f2b0);
    *(char *)(iVar3 + 0x10) = *(char *)(iVar3 + 0x10) + '\x01';
    break;
  case '\x03':
    FUN_005b6900();
    break;
  case '\x04':
    *(char *)(iVar3 + 0x10) = *(char *)(iVar3 + 0x10) + '\x01';
    break;
  case '\x05':
    FUN_005b68e0();
    *(undefined1 *)(iVar3 + 0x42b) = 0x17;
    *(char *)(iVar3 + 0x10) = *(char *)(iVar3 + 0x10) + '\x01';
    FUN_005c44a0(1,0x62f360);
    break;
  case '\x06':
    FUN_005b6900();
    break;
  case '\a':
    if (*(char *)(iVar3 + 0x97e) == '\0') {
      *(char *)(iVar3 + 0xf) = *(char *)(iVar3 + 0xf) + '\x01';
    }
    else {
      uVar2 = 0x708;
      if (cRam0034356c == '\0') {
        uVar2 = 0xe10;
      }
      *(undefined4 *)(iVar3 + 0x98c) = uVar2;
      *(char *)(iVar3 + 0xf) = *(char *)(iVar3 + 0xf) + '\x01';
    }
    *(undefined1 *)(iVar3 + 0x10) = 0;
    *(undefined1 *)(iVar3 + 0x45a) = 1;
    FUN_005af120(param_1);
  }
  return;
}



================================================================