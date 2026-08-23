FUNCTION FUN_00636190 @ 0x00636190  size=332
CALLERS (1): FUN_006345e0@0x006345e0
CALLEES (0): 
----------------------------------------------------------------

void FUN_00636190(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 + 4;
  (&PTR_DAT_00692224)[iVar2 * 5] =
       *(undefined **)(&DAT_006921c0 + *(int *)(*(int *)(iRam00715da8 + 0x10) + 0x20) * 0x10);
  (&PTR_DAT_00692228)[iVar2 * 5] =
       *(undefined **)(&DAT_006921c4 + *(int *)(*(int *)(iRam00715da8 + 0x10) + 0x20) * 0x10);
  iVar1 = *(int *)(iRam00715da8 + 0x10);
  if (*(int *)(iVar1 + 0x20) == 2) {
    *(undefined4 *)(&DAT_0069222c + iVar2 * 0x14) =
         *(undefined4 *)(*(int *)(iVar1 + 0x24) + *(char *)(iRam00715da8 + 0x34) * 4);
  }
  else {
    *(undefined4 *)(&DAT_0069222c + iVar2 * 0x14) = *(undefined4 *)(iVar1 + 0x24);
  }
  param_1 = param_1 + 5;
  (&PTR_DAT_00692224)[param_1 * 5] =
       *(undefined **)(&DAT_006921f0 + *(int *)(*(int *)(iRam00715da8 + 0x10) + 0x28) * 0x10);
  (&PTR_DAT_00692228)[param_1 * 5] =
       *(undefined **)(&DAT_006921f4 + *(int *)(*(int *)(iRam00715da8 + 0x10) + 0x28) * 0x10);
  iVar1 = *(int *)(*(int *)(iRam00715da8 + 0x10) + 0x2c);
  if (iVar1 != 0) {
    *(undefined4 *)(&DAT_0069222c + param_1 * 0x14) =
         *(undefined4 *)(iVar1 + *(char *)(iRam00715da8 + 0x34) * 4);
  }
  return;
}



================================================================