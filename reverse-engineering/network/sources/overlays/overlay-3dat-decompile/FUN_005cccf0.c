FUNCTION FUN_005cccf0 @ 0x005cccf0  size=320
CALLERS (1): FUN_005c9c50@0x005c9c50
CALLEES (2): FUN_005dedf0@0x005dedf0, FUN_005d76b0@0x005d76b0
----------------------------------------------------------------

void FUN_005cccf0(void)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  undefined1 auStack_4 [4];
  
  cVar2 = '\0';
  for (uVar3 = 0; uVar3 < 500; uVar3 = uVar3 + 1 & 0xffff) {
    pcVar1 = *(char **)(iRam00701068 + uVar3 * 4 + 0x5ffc0);
    if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) break;
    if (pcVar1[2] == '\r') {
      if (*(char *)(iRam00701070 + 0x2d) == '\x14') {
        pcVar1[5] = '\x03';
      }
      else if (**(char **)(pcVar1 + 100) == '\0') {
        pcVar1[5] = '\x02';
      }
      else {
        cVar2 = cVar2 + '\x01';
        FUN_005dedf0(auStack_4);
        FUN_005d76b0(auStack_4);
        *(undefined1 *)(*(int *)(iRam00701068 + uVar3 * 4 + 0x5ffc0) + 5) = 1;
        *(char *)(iRam00701070 + 0x2d) = *(char *)(iRam00701070 + 0x2d) + '\x01';
      }
    }
  }
  if (cVar2 == '\0') {
    *(undefined1 *)(iRam00701070 + 0x2e) = 10;
  }
  else {
    *(undefined1 *)(iRam00701070 + 0x2e) = 8;
  }
  return;
}



================================================================