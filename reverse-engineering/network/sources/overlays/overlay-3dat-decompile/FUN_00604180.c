FUNCTION FUN_00604180 @ 0x00604180  size=1508
CALLERS (1): FUN_00603e40@0x00603e40
CALLEES (14): FUN_00604940@0x00604940, FUN_00604a80@0x00604a80, FUN_005b1190@0x005b1190, FUN_005af3e0@0x005af3e0, FUN_005b8da0@0x005b8da0, FUN_005b8cf0@0x005b8cf0, FUN_0061ded0@0x0061ded0, FUN_006278e0@0x006278e0, FUN_005b9110@0x005b9110, FUN_005b14b0@0x005b14b0, FUN_005af400@0x005af400, FUN_005b09b0@0x005b09b0, ...
----------------------------------------------------------------

undefined4 FUN_00604180(char *param_1)

{
  char cVar1;
  bool bVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  char *pcVar6;
  
  pcVar6 = param_1 + 0x900;
  switch(param_1[0x900]) {
  case '\0':
    if (param_1[0x901] == '\x01') {
      if (param_1[0x905] != '\0') {
        FUN_005b1190(param_1 + 0x908,param_1 + 0x907,param_1[0x905],7,2);
        param_1[0x909] =
             (char)*(undefined4 *)(((int)param_1[0x907] + (int)param_1[0x908]) * 0x38 + 0x70b4d0);
        if (((param_1[0x909] == '\0') || (param_1[0x909] == '\x01')) &&
           (lVar4 = FUN_005b09b0(param_1 + 0x909,1,1), lVar4 != 0)) {
          if (param_1[0x909] == '\0') {
            *(undefined4 *)(((int)param_1[0x907] + (int)param_1[0x908]) * 0x38 + 0x70b4d0) = 0;
            *(short *)(param_1 + 0x914) = *(short *)(param_1 + 0x914) + 1;
            func_0x001b0140(0);
          }
          else if ((char)*(short *)(param_1 + 0x914) < '\x01') {
            func_0x001b0140(5);
          }
          else {
            *(short *)(param_1 + 0x914) = *(short *)(param_1 + 0x914) + -1;
            *(undefined4 *)(((int)param_1[0x907] + (int)param_1[0x908]) * 0x38 + 0x70b4d0) = 1;
            func_0x001b0140(0);
          }
        }
      }
      lVar4 = FUN_005b14b0(0x200);
      if (lVar4 != 0) {
        *pcVar6 = *pcVar6 + '\x01';
        param_1[0x901] = '\0';
        func_0x001b0140(2);
      }
    }
    else {
      if (param_1[0x901] != '\0') {
        return 0xffffffff;
      }
      param_1[0x901] = '\x01';
      param_1[0x907] = '\0';
      param_1[0x908] = '\0';
      param_1[0x909] = '\0';
      param_1[0x90c] = '\0';
    }
    break;
  case '\x01':
    cVar1 = param_1[0x901];
    if (cVar1 == '\x04') {
      *(int *)(param_1 + 0x918) = *(int *)(param_1 + 0x918) + -1;
      if (*(int *)(param_1 + 0x918) < 0) {
        if (param_1[0x43c] == '\0') {
          *pcVar6 = *pcVar6 + '\x01';
          param_1[0x901] = '\0';
        }
        else {
          *pcVar6 = '\0';
          param_1[0x901] = '\0';
        }
      }
    }
    else if (cVar1 == '\x03') {
      *(int *)(param_1 + 0x918) = *(int *)(param_1 + 0x918) + -1;
      if (*(int *)(param_1 + 0x918) < 0) {
        param_1[0x901] = param_1[0x901] + '\x01';
        param_1[0x43f] = '\0';
        param_1[0x918] = '\x06';
        param_1[0x919] = '\0';
        param_1[0x91a] = '\0';
        param_1[0x91b] = '\0';
        FUN_005b9110(3);
      }
    }
    else if (cVar1 == '\x02') {
      FUN_005b09b0(param_1 + 0x43c,1);
      lVar4 = FUN_005b14b0(0x10);
      if (lVar4 == 0) {
        lVar4 = FUN_005b14b0(0x200);
        if (lVar4 != 0) {
          func_0x001b0140(2);
          *pcVar6 = '\0';
          param_1[0x901] = '\0';
          FUN_005b9110(3);
        }
      }
      else {
        param_1[0x901] = param_1[0x901] + '\x01';
        param_1[0x43f] = '\x01';
        param_1[0x918] = '\b';
        param_1[0x919] = '\0';
        param_1[0x91a] = '\0';
        param_1[0x91b] = '\0';
        func_0x001b0140();
      }
    }
    else if (cVar1 == '\x01') {
      *(int *)(param_1 + 0x918) = *(int *)(param_1 + 0x918) + -1;
      if (*(int *)(param_1 + 0x918) < 0) {
        param_1[0x901] = param_1[0x901] + '\x01';
      }
    }
    else if (cVar1 == '\0') {
      lVar4 = FUN_00604940();
      if (lVar4 == 2) {
        *pcVar6 = '\x02';
        param_1[0x901] = '\0';
      }
      else if (lVar4 == 1) {
        param_1[0x901] = param_1[0x901] + '\x01';
        param_1[0x43c] = '\x01';
        param_1[0x918] = '\x10';
        param_1[0x919] = '\0';
        param_1[0x91a] = '\0';
        param_1[0x91b] = '\0';
        FUN_005b8da0(3,param_1 + 0x43c);
      }
      else if (lVar4 == 0) {
        *pcVar6 = '\x05';
        param_1[0x901] = '\0';
      }
    }
    break;
  case '\x02':
    bVar2 = false;
    for (lVar4 = 0; lVar4 < param_1[0x905]; lVar4 = (long)((int)lVar4 + 1)) {
      iVar5 = (int)lVar4 * 0x38;
      if (((*(int *)(iVar5 + 0x70b4d0) != 0) &&
          (lVar3 = FUN_006049b0(0x694700,iVar5 + 0x70b4b0,iVar5 + 0x70b4c0), lVar3 != -1)) &&
         (bVar2 = true, *param_1 == '\f')) {
        FUN_00604a80(0x694700,iVar5 + 0x70b4c0);
      }
    }
    if (bVar2) {
      *pcVar6 = '\x03';
      param_1[0x901] = '\0';
      param_1[0x45a] = '\0';
      FUN_005af3c0();
    }
    else {
      *pcVar6 = '\x05';
    }
    break;
  case '\x03':
    cVar1 = param_1[0x901];
    if (cVar1 == '\x03') {
      *pcVar6 = '\x05';
      param_1[0x901] = '\0';
      param_1[0x45a] = '\x01';
      FUN_006278e0(0x694700);
    }
    else if (cVar1 == '\x02') {
      lVar4 = FUN_0061ded0();
      if (lVar4 != 0) {
        param_1[0x901] = param_1[0x901] + '\x01';
        if (lVar4 < 0) {
          FUN_005af400();
        }
        else {
          FUN_005af3e0();
        }
      }
    }
    else {
      if (cVar1 != '\x01') {
        if (cVar1 != '\0') {
          return 0xffffffff;
        }
        param_1[0x901] = '\x01';
      }
      param_1[0x901] = param_1[0x901] + '\x01';
    }
    break;
  case '\x04':
    cVar1 = param_1[0x901];
    if (cVar1 == '\x02') {
      *(int *)(param_1 + 0x918) = *(int *)(param_1 + 0x918) + -1;
      if (*(int *)(param_1 + 0x918) < 0) {
        *pcVar6 = '\x05';
        param_1[0x901] = '\0';
      }
    }
    else if (cVar1 == '\x01') {
      *(int *)(param_1 + 0x918) = *(int *)(param_1 + 0x918) + -1;
      if (*(int *)(param_1 + 0x918) < 0) {
        param_1[0x901] = param_1[0x901] + '\x01';
        param_1[0x918] = '\x06';
        param_1[0x919] = '\0';
        param_1[0x91a] = '\0';
        param_1[0x91b] = '\0';
        FUN_005b9110(0x4c);
      }
    }
    else if (cVar1 == '\0') {
      param_1[0x901] = '\x01';
      param_1[0x918] = 'L';
      param_1[0x919] = '\0';
      param_1[0x91a] = '\0';
      param_1[0x91b] = '\0';
      FUN_005b8cf0(0x75);
    }
    break;
  case '\x05':
    param_1[0x45a] = '\x01';
    return 0;
  }
  return 0xffffffff;
}



================================================================