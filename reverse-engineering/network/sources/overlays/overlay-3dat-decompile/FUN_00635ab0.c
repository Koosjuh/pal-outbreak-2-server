FUNCTION FUN_00635ab0 @ 0x00635ab0  size=220
CALLERS (4): FUN_00630c90@0x00630c90, FUN_00634ab0@0x00634ab0, FUN_00635940@0x00635940, FUN_006313a0@0x006313a0
CALLEES (4): FUN_00637da0@0x00637da0, FUN_00637140@0x00637140, FUN_00631620@0x00631620, FUN_006320f0@0x006320f0
----------------------------------------------------------------

void FUN_00635ab0(void)

{
  int iVar1;
  short sVar2;
  undefined1 auStack_300 [512];
  undefined1 auStack_100 [256];
  
  if (*(char *)(iRam00715da8 + 0x25) != DAT_0069240b) {
    FUN_00637140();
    if (*(int *)(iRam00715da8 + 0xc) != 0) {
      if ((*(byte *)(iRam00715da8 + 0x4a) & 1) != 0) {
        FUN_00631620();
      }
      iVar1 = *(int *)(*(int *)(iRam00715da8 + 0xc) + 0x20);
      if (iVar1 == 0) {
        *(undefined4 *)(iRam00715da8 + 0x248) = 5;
      }
      else {
        func_0x0010a4f0(auStack_100,iVar1,0xfa);
        FUN_00637da0(auStack_100,auStack_300);
        sVar2 = FUN_006320f0(iRam00715da8 + 0x4c,auStack_300,*(undefined2 *)(iRam00715da8 + 0x2a),
                             *(undefined2 *)(iRam00715da8 + 0x3a));
        *(short *)(iRam00715da8 + 0x2a) = *(short *)(iRam00715da8 + 0x2a) + sVar2;
        *(undefined4 *)(iRam00715da8 + 0x248) = 1;
      }
    }
  }
  return;
}



================================================================