FUNCTION FUN_005b58e0 @ 0x005b58e0  size=80
CALLERS (0): 
CALLEES (2): FUN_005c0370@0x005c0370, FUN_005c0f00@0x005c0f00
----------------------------------------------------------------

void FUN_005b58e0(void)

{
  int iVar1;
  ushort uStack_2;
  
  FUN_005c0f00(&uStack_2);
  iVar1 = (uStack_2 - 1) * 0x15c;
  FUN_005c0370(uStack_2,iVar1 + 0x6c0764,iVar1 + 0x6c0766,iVar1 + 0x6c0768,iVar1 + 0x6c076a,
               iVar1 + 0x6c076c);
  return;
}



================================================================