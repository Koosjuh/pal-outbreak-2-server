FUNCTION FUN_005e2760 @ 0x005e2760  size=2060
CALLERS (1): FUN_005daf30@0x005daf30
CALLEES (5): FUN_005e1a30@0x005e1a30, FUN_005e5910@0x005e5910, FUN_005e0440@0x005e0440, FUN_005e0510@0x005e0510, FUN_005e19b0@0x005e19b0
----------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x005e2d90) */
/* WARNING: Removing unreachable block (ram,0x005e2d04) */
/* WARNING: Removing unreachable block (ram,0x005e2c60) */
/* WARNING: Removing unreachable block (ram,0x005e2bd8) */
/* WARNING: Removing unreachable block (ram,0x005e2b54) */
/* WARNING: Removing unreachable block (ram,0x005e2ad8) */
/* WARNING: Removing unreachable block (ram,0x005e2a5c) */
/* WARNING: Removing unreachable block (ram,0x005e29c4) */
/* WARNING: Removing unreachable block (ram,0x005e2a10) */
/* WARNING: Removing unreachable block (ram,0x005e2920) */
/* WARNING: Removing unreachable block (ram,0x005e2a88) */
/* WARNING: Removing unreachable block (ram,0x005e2b04) */
/* WARNING: Removing unreachable block (ram,0x005e2b80) */
/* WARNING: Removing unreachable block (ram,0x005e2c04) */
/* WARNING: Removing unreachable block (ram,0x005e2cb0) */
/* WARNING: Removing unreachable block (ram,0x005e2d3c) */
/* WARNING: Removing unreachable block (ram,0x005e2dbc) */
/* WARNING: Removing unreachable block (ram,0x005e2970) */

void FUN_005e2760(undefined8 param_1)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  pcVar3 = (char *)param_1;
  cVar1 = pcVar3[2];
  if (cVar1 == '\r') {
    if (pcVar3[5] != '\x02') {
      return;
    }
    if (*pcVar3 != '\x04') {
      return;
    }
  }
  else if ((cVar1 != '\x0f') && (cVar1 != '\x10')) {
    return;
  }
  fVar7 = *(float *)(pcVar3 + 0x34);
  if (fVar7 <= (float)((*(int *)(iRam00701070 + 4) + 0x280) - (int)*(short *)(iRam00701070 + 0x20)))
  {
    fVar5 = (float)*(int *)(iRam00701070 + 4);
    if (fVar5 - *(float *)(pcVar3 + 0x40) <= fVar7) {
      fVar6 = *(float *)(pcVar3 + 0x38);
      fVar4 = (float)*(int *)(iRam00701070 + 8);
      if ((fVar4 - *(float *)(pcVar3 + 0x44) <= fVar6) &&
         (fVar6 <= (float)(*(int *)(iRam00701070 + 8) + 0x1ac))) {
        fVar7 = fVar7 - fVar5;
        fVar6 = fVar6 - fVar4;
        fVar5 = fVar7 + *(float *)(pcVar3 + 0x40);
        fVar4 = fVar6 + *(float *)(pcVar3 + 0x44);
        if (cVar1 == '\x0f') {
          if (-1 < (int)*(uint *)(pcVar3 + 0x58)) {
            FUN_005e0440(fVar7,fVar6,fVar5,fVar4,*(uint *)(pcVar3 + 0x58) | 0xff000000);
          }
          if (pcVar3[0x5d] != '\0') {
            fVar8 = fVar6 + 1.0;
            fVar9 = fVar7 + 1.0;
            FUN_005e1a30(fVar9,fVar8,(fVar7 - 1.0) + *(float *)(pcVar3 + 0x40),fVar8,
                         0xffffffffff606060);
            FUN_005e19b0(fVar9,fVar8,fVar9,(fVar6 - 1.0) + *(float *)(pcVar3 + 0x44),
                         0xffffffffff606060);
            if (*(int *)(iRam00701070 + 0x14) == -1) {
              FUN_005e19b0(fVar5,fVar6,fVar5,fVar4,0xffffffffffd0d0d0);
              FUN_005e1a30(fVar7,fVar4,fVar5,fVar4,0xffffffffffd0d0d0);
            }
            else {
              fVar5 = (fVar7 - 1.0) + *(float *)(pcVar3 + 0x40);
              FUN_005e19b0(fVar5,fVar6 - 1.0,fVar5,(fVar6 - 1.0) + *(float *)(pcVar3 + 0x44));
              fVar5 = (fVar6 - 1.0) + *(float *)(pcVar3 + 0x44);
              FUN_005e1a30(fVar7 - 1.0,fVar5,(fVar7 - 1.0) + *(float *)(pcVar3 + 0x40),fVar5,
                           0xffffffffffffffff);
            }
          }
        }
        else if (cVar1 == '\x10') {
          if (pcVar3[5] == '\x02') {
            if (-1 < (int)*(uint *)(pcVar3 + 0x58)) {
              FUN_005e0440(fVar7,fVar6,fVar5,fVar4,*(uint *)(pcVar3 + 0x58) | 0xff000000);
            }
          }
          else if ((pcVar3[5] == '\x01') && (bVar2 = pcVar3[0x5d], bVar2 != 0)) {
            if ((int)*(uint *)(pcVar3 + 0x58) < 1) {
              if (*(int *)(iRam00701070 + 0x14) == -1) {
                FUN_005e0440(fVar7,fVar6,fVar7 + (float)bVar2,fVar4,0xffffffffffd0d0d0);
                FUN_005e0440(fVar7,fVar6,fVar5,fVar6 + (float)(byte)pcVar3[0x5d],0xffffffffffd0d0d0)
                ;
                bVar2 = pcVar3[0x5d];
              }
              else {
                FUN_005e0440(fVar7,fVar6,fVar7 + (float)bVar2,fVar4,0xffffffffffffffff);
                FUN_005e0440(fVar7,fVar6,fVar5,fVar6 + (float)(byte)pcVar3[0x5d],0xffffffffffffffff)
                ;
                bVar2 = pcVar3[0x5d];
              }
              FUN_005e0440(fVar5 - (float)bVar2,fVar6 + (float)bVar2,fVar5,fVar4,0xffffffffff606060)
              ;
              FUN_005e0440(fVar7 + (float)(byte)pcVar3[0x5d],fVar4 - (float)(byte)pcVar3[0x5d],fVar5
                           ,fVar4,0xffffffffff606060);
              fVar8 = fVar7 + (float)(byte)pcVar3[0x5d];
              FUN_005e0510(fVar7,fVar4,fVar8,fVar4,fVar8,fVar4 - (float)(byte)pcVar3[0x5d],
                           0xffffffffff606060);
              fVar7 = fVar6 + (float)(byte)pcVar3[0x5d];
              FUN_005e0510(fVar5,fVar6,fVar5,fVar7,fVar5 - (float)(byte)pcVar3[0x5d],fVar7,
                           0xffffffffff606060);
            }
            else {
              FUN_005e0440(fVar7,fVar6,fVar7 + (float)bVar2,fVar4,
                           *(uint *)(pcVar3 + 0x58) | 0xff000000);
              FUN_005e0440(fVar7,fVar6,fVar5,fVar6 + (float)(byte)pcVar3[0x5d],
                           *(uint *)(pcVar3 + 0x58) | 0xff000000);
              FUN_005e0440((fVar5 - (float)(byte)pcVar3[0x5d]) - 1.0,
                           fVar6 + (float)(byte)pcVar3[0x5d],fVar5,fVar4,
                           *(uint *)(pcVar3 + 0x58) | 0xff000000);
              FUN_005e0440(fVar7 + (float)(byte)pcVar3[0x5d],
                           (fVar4 - (float)(byte)pcVar3[0x5d]) - 1.0,fVar5,fVar4,
                           *(uint *)(pcVar3 + 0x58) | 0xff000000);
            }
          }
        }
        else if (cVar1 == '\r') {
          FUN_005e5910(param_1,pcVar3[0x5f]);
        }
      }
    }
  }
  return;
}



================================================================