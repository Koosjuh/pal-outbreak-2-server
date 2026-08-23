FUNCTION FUN_00000064 @ 0x00000064 size=648
CALLERS (1): FUN_0000035c@0x0000035c
CALLEES (11): FUN_0000295c@0x0000295c, FUN_00000000@0x00000000, FUN_00002808@0x00002808, FUN_00002920@0x00002920, FUN_00002908@0x00002908, FUN_000027d4@0x000027d4, FUN_000027dc@0x000027dc, FUN_000028e0@0x000028e0, FUN_00002928@0x00002928, FUN_0000294c@0x0000294c, FUN_00002800@0x00002800

undefined4 FUN_00000064(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  int local_28;
  
  iVar6 = 0x7b;
  iVar5 = 0x2000;
joined_r0x00000090:
  do {
    param_1 = param_1 + -1;
    if (param_1 < 1) {
      FUN_000027d4(&DAT_00003444);
      iVar2 = FUN_00002800(0x390);
      FUN_000027dc(DAT_00003444);
      if (iVar2 != 0) {
        return 1;
      }
      local_38 = 0x2000000;
      local_30 = 0xa7c;
      local_34 = 0;
      local_2c = iVar5;
      local_28 = iVar6;
      DAT_00003440 = FUN_0000294c(&local_38);
      if (DAT_00003440 < 1) {
        FUN_000027d4(&DAT_00003444);
        FUN_00002808(0x390);
        FUN_000027dc(DAT_00003444);
        return 1;
      }
      FUN_0000295c(DAT_00003440,0);
      return 2;
    }
    param_2 = param_2 + 1;
    iVar2 = FUN_00002920("thpri=",*param_2,6);
    if (iVar2 == 0) {
      iVar2 = *param_2;
      pcVar4 = (char *)(iVar2 + 6);
      uVar3 = FUN_000028e0((int)*(char *)(iVar2 + 6));
      if (((uVar3 & 4) == 0) || (iVar6 = FUN_00002928(pcVar4,0,10), 0x72 < iVar6 - 9U))
      goto LAB_00000208;
      if (*(char *)(iVar2 + 6) == '\0') goto joined_r0x00000090;
      do {
        uVar3 = FUN_000028e0((int)*pcVar4);
        if ((uVar3 & 4) == 0) goto LAB_000001dc;
        pcVar4 = pcVar4 + 1;
        cVar1 = '\0';
      } while (*pcVar4 != '\0');
    }
    else {
      iVar5 = FUN_00002920("thstack=",*param_2,8);
      if (iVar5 != 0) {
        FUN_00002920("-help",*param_2,5);
        goto LAB_00000208;
      }
      iVar2 = *param_2;
      pcVar4 = (char *)(iVar2 + 8);
      uVar3 = FUN_000028e0((int)*(char *)(iVar2 + 8));
      if ((uVar3 & 4) == 0) goto LAB_00000208;
      iVar5 = FUN_00002928(pcVar4,0,10);
      cVar1 = *(char *)(iVar2 + 8);
      while ((cVar1 != '\0' && (uVar3 = FUN_000028e0((int)*pcVar4), (uVar3 & 4) != 0))) {
        pcVar4 = pcVar4 + 1;
        cVar1 = *pcVar4;
      }
      iVar2 = FUN_00002908(pcVar4,&PTR_DAT_00002a9c);
      if (iVar2 == 0) {
        iVar5 = iVar5 << 10;
        goto joined_r0x00000090;
      }
LAB_000001dc:
      cVar1 = *pcVar4;
    }
    if (cVar1 != '\0') {
LAB_00000208:
      FUN_00000000();
      return 1;
    }
  } while( true );
}


================================================================