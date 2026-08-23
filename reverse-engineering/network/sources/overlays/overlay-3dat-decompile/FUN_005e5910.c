FUNCTION FUN_005e5910 @ 0x005e5910  size=1336
CALLERS (1): FUN_005e2760@0x005e2760
CALLEES (1): FUN_005ddb40@0x005ddb40
----------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x005e5d9c) */
/* WARNING: Removing unreachable block (ram,0x005e5a70) */
/* WARNING: Removing unreachable block (ram,0x005e59b4) */
/* WARNING: Removing unreachable block (ram,0x005e5af0) */
/* WARNING: Removing unreachable block (ram,0x005e5df8) */
/* WARNING: Removing unreachable block (ram,0x005e5b28) */
/* WARNING: Removing unreachable block (ram,0x005e5b54) */
/* WARNING: Removing unreachable block (ram,0x005e5b80) */

void FUN_005e5910(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  uVar2 = 0;
  iVar1 = (param_2 & 0xff) * 2;
  fVar6 = 0.0;
  fVar7 = *(float *)(param_1 + 0x38) - (float)*(int *)(iRam00701070 + 8);
  do {
    fVar3 = (fVar7 + (float)*(ushort *)(iVar1 + iRam00701068 + 0x68e50)) -
            (*(float *)(param_1 + 0x44) +
            (*(float *)(param_1 + 0x38) - (float)*(int *)(iRam00701070 + 8)));
    if ((0.0 < fVar3) && (fVar6 = fVar3, fVar3 == 0.0)) {
      return;
    }
    fVar3 = 0.0;
    for (fVar8 = *(float *)(param_1 + 0x34) - (float)*(int *)(iRam00701070 + 4);
        (fVar4 = (fVar8 + (float)*(ushort *)(iVar1 + iRam00701068 + 0x68e28)) -
                 (*(float *)(param_1 + 0x40) +
                 (*(float *)(param_1 + 0x34) - (float)*(int *)(iRam00701070 + 4))), fVar4 <= 0.0 ||
        (fVar3 = fVar4, fVar4 != 0.0));
        fVar8 = fVar8 + (float)*(ushort *)(iVar1 + iRam00701068 + 0x68e28)) {
      fVar4 = (float)*(ushort *)(iVar1 + iRam00701068 + 0x68e28);
      fVar5 = (float)*(ushort *)(iVar1 + iRam00701068 + 0x68e50);
      if (((fVar3 != 0.0) && (fVar3 != 1.0)) || ((fVar6 != 0.0 && (fVar6 != 1.0)))) {
        if (((fVar3 == 0.0) && (fVar3 != 1.0)) || ((fVar6 != 0.0 && (fVar6 != 1.0)))) {
          if (((fVar3 == 0.0) || (fVar3 == 1.0)) && ((fVar6 != 0.0 && (fVar6 != 1.0)))) {
            fVar5 = fVar5 - fVar6;
          }
          else {
            fVar4 = fVar4 - fVar3;
            fVar5 = fVar5 - fVar6;
          }
        }
        else {
          fVar4 = fVar4 - fVar3;
        }
      }
      FUN_005ddb40(0xffffffffffffffff,*(undefined4 *)((param_2 & 0xff) * 4 + iRam00701068 + 0x68dd8)
                   ,(int)fVar8,(int)fVar7,(int)fVar4,(int)fVar5,0,0);
      uVar2 = uVar2 + 1 & 0xff;
      if (0x200 < uVar2) {
        return;
      }
      if (0.0 < fVar3) break;
    }
    if (0.0 < fVar6) {
      return;
    }
    fVar7 = fVar7 + (float)*(ushort *)(iVar1 + iRam00701068 + 0x68e50);
  } while( true );
}



================================================================