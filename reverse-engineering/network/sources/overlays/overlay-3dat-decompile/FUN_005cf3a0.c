FUNCTION FUN_005cf3a0 @ 0x005cf3a0  size=584
CALLERS (2): FUN_005cfb20@0x005cfb20, FUN_005cab10@0x005cab10
CALLEES (2): FUN_005cebc0@0x005cebc0, FUN_0061e720@0x0061e720
----------------------------------------------------------------

bool FUN_005cf3a0(undefined8 param_1,long param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  long lVar4;
  int iVar5;
  
  iVar5 = ((uint)param_1 & 0xffff) * 4 + iRam00701068;
  pcVar2 = *(char **)(iVar5 + 0x5ffc0);
  cVar1 = pcVar2[2];
  if (cVar1 != '\x02') {
    if ((((cVar1 != '\f') && (cVar1 != '\v')) && (cVar1 != '\a')) &&
       (((cVar1 != '\x06' && (cVar1 != '\x05')) && ((cVar1 != '\x04' && (cVar1 != '\x03')))))) {
      if (cVar1 != '\b') {
        if ((cVar1 == '\x12') || (cVar1 == '\x11')) {
          if (**(char **)(pcVar2 + 0x60) != '\0') {
            *(undefined1 *)(iRam00701068 + 0x68e88) = 1;
            if (param_2 != 0) {
              FUN_0061e720();
            }
            lVar4 = FUN_005cebc0(param_1,param_2);
            if (lVar4 != 0) {
              return true;
            }
          }
          return false;
        }
        if (cVar1 != '\r') {
          return false;
        }
        if ((*pcVar2 == '\x05') || (*pcVar2 == '\x03')) {
          *(undefined1 *)(iRam00701068 + 0x68e88) = 1;
          if (param_2 != 0) {
            FUN_0061e720();
          }
          lVar4 = FUN_005cebc0(param_1,param_2);
          if (lVar4 != 0) {
            return true;
          }
        }
        return false;
      }
      if (*pcVar2 != '\v') {
        return false;
      }
    }
    *(undefined1 *)(iRam00701068 + 0x68e88) = 1;
    if (param_2 != 0) {
      FUN_0061e720();
    }
    lVar4 = FUN_005cebc0(param_1,param_2);
    return lVar4 != 0;
  }
  pcVar3 = *(char **)(iVar5 + 0x5ffbc);
  if (((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) &&
     (lVar4 = func_0x00109d70(*(undefined4 *)(pcVar3 + 0x60),*(undefined4 *)(pcVar2 + 0x60)),
     lVar4 == 0)) {
    return false;
  }
  *(undefined1 *)(iRam00701068 + 0x68e88) = 1;
  if (param_2 != 0) {
    FUN_0061e720();
  }
  lVar4 = FUN_005cebc0(param_1,param_2);
  if (lVar4 != 0) {
    return true;
  }
  return false;
}



================================================================