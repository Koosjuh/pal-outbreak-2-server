FUNCTION FUN_00617c30 @ 0x00617c30  size=876
CALLERS (0): 
CALLEES (6): FUN_005af2e0@0x005af2e0, FUN_00618c20@0x00618c20, FUN_0062fea0@0x0062fea0, FUN_005af2c0@0x005af2c0, FUN_00617fa0@0x00617fa0, FUN_005fe4b0@0x005fe4b0
----------------------------------------------------------------

void FUN_00617c30(undefined8 param_1)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  int iVar6;
  ulong unaff_s2;
  int unaff_s3_lo;
  undefined2 *puVar7;
  undefined1 auStack_40 [64];
  
  iVar6 = (int)param_1;
  cVar1 = *(char *)(iVar6 + 4);
  if (cVar1 == '\x02') {
    FUN_00618c20();
    return;
  }
  if (cVar1 != '\x01') {
    if (cVar1 != '\0') {
      return;
    }
    *(undefined1 *)(iVar6 + 4) = 1;
    if ((long)(ulong)bRam006c5520 <= (long)*(char *)(iVar6 + 3)) {
      *(undefined1 *)(iVar6 + 1) = 0;
      FUN_00618c20();
      return;
    }
    *(undefined2 *)(iVar6 + 0x26) =
         *(undefined2 *)(&DAT_00654270 + (*(char *)(iVar6 + 3) * 8 + (bRam006c5520 - 1) * 2) * 2);
    *(short *)(iVar6 + 0x26) = (short)(int)((float)(int)*(short *)(iVar6 + 0x26) * 1.25);
    *(undefined2 *)(iVar6 + 0x28) =
         *(undefined2 *)(&DAT_00654272 + (*(char *)(iVar6 + 3) * 8 + (bRam006c5520 - 1) * 2) * 2);
  }
  if (bRam006c5520 == 4) {
    unaff_s3_lo = 0x654340;
    unaff_s2 = (ulong)((*(byte *)(iVar6 + 3) & 1) != 0) ^ 1;
  }
  else if (bRam006c5520 == 3) {
    unaff_s3_lo = 0x654300;
    unaff_s2 = (ulong)(*(char *)(iVar6 + 3) == '\x02');
  }
  else if (bRam006c5520 == 2) {
    unaff_s3_lo = 0x6542d0;
    unaff_s2 = (ulong)(*(char *)(iVar6 + 3) == '\0');
  }
  else if (bRam006c5520 == 1) {
    unaff_s2 = 0;
    unaff_s3_lo = 0x6542b0;
  }
  else {
    FUN_00618c20(param_1);
  }
  cVar1 = *(char *)(iVar6 + 3);
  iVar3 = (int)cVar1;
  puVar7 = (undefined2 *)(unaff_s3_lo + (cVar1 * 4 + iVar3) * 4);
  iVar3 = ((cVar1 * 0x10 - iVar3) * 4 - iVar3) * 0x10;
  FUN_005af2e0(0x1c);
  FUN_005af2c0(0);
  if (*(short *)(iVar3 + 0x6c6e5a) == 0) {
    uVar4 = func_0x001b6950(*(undefined2 *)(iVar3 + 0x6c6e58));
    func_0x00109728(auStack_40,0x654390,uVar4,(&PTR_DAT_0068ae30)[*(short *)(iVar3 + 0x6c6e5c)]);
    uVar2 = *puVar7;
  }
  else {
    lVar5 = FUN_005fe4b0(*(undefined2 *)(iVar3 + 0x6c6e58));
    if (lVar5 < 0) {
      func_0x00109728(auStack_40,0x654398);
    }
    else {
      lVar5 = func_0x001b68b0(lVar5);
      if (lVar5 == 0) {
        func_0x00109728(auStack_40,0x654398);
      }
      else {
        func_0x00109728(auStack_40,0x6543a0,lVar5);
      }
    }
    uVar2 = *puVar7;
  }
  FUN_00617fa0(auStack_40,uVar2,puVar7[1],unaff_s2,0x1c);
  FUN_005af2e0(0x10);
  FUN_00617fa0((*(char *)(iVar6 + 3) * 0x3c - (int)*(char *)(iVar6 + 3)) * 0x10 + 0x6c6d7c,puVar7[4]
               ,puVar7[5],unaff_s2,0x10);
  uVar4 = FUN_0062fea0(0x6a);
  func_0x00109728(auStack_40,0x6543a0,uVar4);
  FUN_00617fa0(auStack_40,puVar7[6],puVar7[7],unaff_s2,0x10);
  func_0x00109728(auStack_40,0x6543a8,*(undefined4 *)(iVar3 + 0x6c6d94));
  FUN_00617fa0(auStack_40,puVar7[8],puVar7[9],unaff_s2,0x10);
  return;
}



================================================================