FUNCTION FUN_005ae770 @ 0x005ae770  size=300
CALLERS (1): FUN_005acab0@0x005acab0
CALLEES (5): FUN_005b9110@0x005b9110, FUN_005ae8a0@0x005ae8a0, FUN_005aeae0@0x005aeae0, FUN_005b1d10@0x005b1d10, FUN_005ae9b0@0x005ae9b0
----------------------------------------------------------------

undefined4 FUN_005ae770(undefined8 param_1)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  pcVar3 = (char *)param_1;
  if (pcVar3[0x5196] == '\0') {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    if (pcVar3[0x45a] != '\0') {
      cVar1 = *pcVar3;
      if (cVar1 == '\0') {
        uVar2 = 0;
      }
      else if (cVar1 == '\x06') {
        uVar2 = 0;
      }
      else if (cVar1 == '\a') {
        uVar2 = 0;
      }
      else if (cVar1 == '\x05') {
        uVar2 = 0;
      }
      else {
        uVar2 = 0;
        if ((cVar1 != '\f') && (uVar2 = 0, pcVar3[0x455] == '\0')) {
          if (pcVar3[0x42c] == '\x01') {
            FUN_005b1d10();
            FUN_005b9110(0x4c);
          }
          cVar1 = pcVar3[0x5197];
          if (cVar1 == '\x02') {
            FUN_005aeae0(param_1);
          }
          else if (cVar1 == '\x01') {
            FUN_005ae9b0(param_1);
          }
          else {
            if (cVar1 != '\0') {
              return 1;
            }
            FUN_005ae8a0(param_1);
          }
          uVar2 = 1;
        }
      }
    }
  }
  return uVar2;
}



================================================================