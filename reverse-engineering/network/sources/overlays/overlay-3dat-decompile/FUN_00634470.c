FUNCTION FUN_00634470 @ 0x00634470  size=204
CALLERS (5): FUN_00635030@0x00635030, FUN_006375d0@0x006375d0, FUN_006345e0@0x006345e0, FUN_00631910@0x00631910, FUN_00637140@0x00637140
CALLEES (0): 
----------------------------------------------------------------

undefined1 FUN_00634470(void)

{
  *(undefined1 *)((int)piRam00715da8 + 0x2e) =
       *(undefined1 *)
        (*(int *)(*piRam00715da8 + 8) +
        (uint)*(byte *)(piRam00715da8 + 9) * 4 + (uint)*(byte *)((int)piRam00715da8 + 0x25));
  piRam00715da8[1] = *(int *)(*piRam00715da8 + 4) + *(char *)((int)piRam00715da8 + 0x2e) * 8;
  piRam00715da8[2] = *(int *)*piRam00715da8 + *(char *)((int)piRam00715da8 + 0x2e) * 6;
  if (*(int *)(*piRam00715da8 + 0xc) == 0) {
    piRam00715da8[3] = 0;
  }
  else {
    piRam00715da8[3] =
         *(int *)(*piRam00715da8 + 0xc) +
         (char)(&DAT_00692404)[*(char *)((int)piRam00715da8 + 0x2e)] * 0x24;
  }
  return *(undefined1 *)((int)piRam00715da8 + 0x2e);
}



================================================================