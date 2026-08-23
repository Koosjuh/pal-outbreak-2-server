FUNCTION FUN_0060f480 @ 0x0060f480  size=340
CALLERS (1): FUN_0060e250@0x0060e250
CALLEES (0): 
----------------------------------------------------------------

void FUN_0060f480(byte *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  ushort uVar3;
  short sVar4;
  
  iVar2 = 0;
  while( true ) {
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    if (bVar1 < 0x80) {
      if (0xfe < iVar2) break;
      *param_1 = bVar1;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
      iVar2 = iVar2 + 1;
    }
    else {
      if (0xfc < iVar2) break;
      uVar3 = (ushort)bVar1 * 0x100 + (ushort)param_2[1];
      param_2 = param_2 + 2;
      if ((uVar3 < 0x829f) || (0x82dd < uVar3)) {
        if ((uVar3 < 0x82de) || (0x82f1 < uVar3)) {
          if ((uVar3 < 0x8340) || (0x835e < uVar3)) {
            if ((uVar3 < 0x835f) || (0x837e < uVar3)) {
              if ((uVar3 < 0x8380) || (sVar4 = uVar3 + 0x20, 0x8396 < uVar3)) {
                sVar4 = -0x7c44;
              }
            }
            else {
              sVar4 = uVar3 + 0x21;
            }
          }
          else {
            sVar4 = uVar3 - 0x9f;
          }
        }
        else {
          sVar4 = uVar3 - 0x5e;
        }
      }
      else {
        sVar4 = uVar3 - 0x11e;
      }
      *param_1 = 0xe3;
      iVar2 = iVar2 + 3;
      param_1[1] = (byte)((ushort)sVar4 >> 8);
      param_1[2] = (byte)sVar4;
      param_1 = param_1 + 3;
    }
  }
  *param_1 = 0;
  return;
}



================================================================