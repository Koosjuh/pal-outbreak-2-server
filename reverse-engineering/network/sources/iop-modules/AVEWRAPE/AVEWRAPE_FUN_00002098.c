FUNCTION FUN_00002098 @ 0x00002098 size=1140
CALLERS (0): 
CALLEES (66): FUN_00001a78@0x00001a78, FUN_00001100@0x00001100, FUN_00002064@0x00002064, FUN_00001744@0x00001744, FUN_000016c4@0x000016c4, FUN_000004e8@0x000004e8, FUN_00000c8c@0x00000c8c, FUN_00000208@0x00000208, FUN_00000168@0x00000168, FUN_00000724@0x00000724, FUN_00001820@0x00001820, FUN_000019a8@0x000019a8, FUN_000002a4@0x000002a4, FUN_00001780@0x00001780, FUN_00002030@0x00002030, FUN_00000930@0x00000930, FUN_00000b74@0x00000b74, FUN_0000150c@0x0000150c, FUN_00000264@0x00000264, FUN_00000c38@0x00000c38, FUN_00000834@0x00000834, FUN_0000159c@0x0000159c, FUN_00000d9c@0x00000d9c, FUN_000009c0@0x000009c0, FUN_00000304@0x00000304, FUN_0000019c@0x0000019c, FUN_00000ea4@0x00000ea4, FUN_000013b8@0x000013b8, FUN_00000630@0x00000630, FUN_000014c4@0x000014c4, FUN_0000097c@0x0000097c, FUN_00001ad4@0x00001ad4, FUN_000015d8@0x000015d8, FUN_000006a4@0x000006a4, FUN_0000113c@0x0000113c, FUN_0000122c@0x0000122c, FUN_000010b8@0x000010b8, FUN_00001bcc@0x00001bcc, FUN_000003d8@0x000003d8, FUN_00000448@0x00000448, FUN_00000564@0x00000564, FUN_00000364@0x00000364, FUN_00000e54@0x00000e54, FUN_000012cc@0x000012cc, FUN_00001a24@0x00001a24, FUN_000005ec@0x000005ec, FUN_00001c00@0x00001c00, FUN_0000131c@0x0000131c, FUN_00001560@0x00001560, FUN_0000146c@0x0000146c, FUN_000017d0@0x000017d0, FUN_00001184@0x00001184, FUN_00001648@0x00001648, FUN_000000a8@0x000000a8, FUN_000007dc@0x000007dc, FUN_00001898@0x00001898, FUN_000013f4@0x000013f4, FUN_00001ec0@0x00001ec0, FUN_00002918@0x00002918, FUN_00000b18@0x00000b18, FUN_000018d4@0x000018d4, FUN_000011d8@0x000011d8, FUN_00001370@0x00001370, FUN_00001430@0x00001430, FUN_000005a8@0x000005a8, FUN_00000bf4@0x00000bf4

int FUN_00002098(undefined4 param_1,int param_2)

{
  switch(param_1) {
  case 0:
    FUN_0000019c(param_2);
    break;
  case 1:
    FUN_00000208(param_2);
    break;
  case 2:
    FUN_00000264(param_2);
    break;
  case 3:
    FUN_000002a4(param_2);
    break;
  case 4:
    FUN_00000304(param_2);
    break;
  case 5:
    FUN_000000a8(param_2);
    break;
  case 6:
    FUN_00000168(param_2);
    break;
  case 7:
    FUN_00000364(param_2);
    break;
  case 8:
    FUN_000003d8(param_2);
    break;
  case 9:
    FUN_00000448(param_2);
    break;
  case 10:
    FUN_000004e8(param_2);
    break;
  case 0xb:
    FUN_00000564(param_2);
    break;
  case 0xc:
    FUN_000005a8(param_2);
    break;
  case 0xd:
    FUN_000005ec(param_2);
    break;
  case 0xe:
    FUN_00000630(param_2);
    break;
  case 0xf:
    FUN_000006a4(param_2);
    break;
  case 0x10:
    FUN_00000724(param_2);
    break;
  default:
    FUN_00002918("ave_wrap: !!FATAL ERROR!! Undefined function called -> %d\n",param_1);
    *(undefined4 *)(param_2 + 0x18) = 0xffffd8f1;
    break;
  case 0x13:
    FUN_000007dc(param_2);
    break;
  case 0x14:
    FUN_00000834(param_2);
    break;
  case 0x15:
    FUN_00000930(param_2);
    break;
  case 0x16:
    FUN_0000097c(param_2);
    break;
  case 0x1e:
    FUN_00000c38(param_2);
    break;
  case 0x1f:
    FUN_00000c8c(param_2);
    break;
  case 0x21:
    FUN_00000d9c(param_2);
    break;
  case 0x22:
    FUN_00000e54(param_2);
    break;
  case 0x23:
    FUN_00000ea4(param_2);
    break;
  case 0x24:
    FUN_000010b8(param_2);
    break;
  case 0x25:
    FUN_00001100(param_2);
    break;
  case 0x26:
    FUN_0000113c(param_2);
    break;
  case 0x27:
    FUN_00001184(param_2);
    break;
  case 0x28:
    FUN_000011d8(param_2);
    break;
  case 0x29:
    FUN_0000122c(param_2);
    break;
  case 0x2a:
    FUN_000012cc(param_2);
    break;
  case 0x2b:
    FUN_0000131c(param_2);
    break;
  case 0x2c:
    FUN_00001370(param_2);
    break;
  case 0x2d:
    FUN_000013b8(param_2);
    break;
  case 0x2e:
    FUN_000013f4(param_2);
    break;
  case 0x2f:
    FUN_00001430(param_2);
    break;
  case 0x30:
    FUN_0000146c(param_2);
    break;
  case 0x31:
    FUN_000014c4(param_2);
    break;
  case 0x32:
    FUN_0000150c(param_2);
    break;
  case 0x33:
    FUN_00001560(param_2);
    break;
  case 0x34:
    FUN_0000159c(param_2);
    break;
  case 0x35:
    FUN_000015d8(param_2);
    break;
  case 0x36:
    FUN_00001648(param_2);
    break;
  case 0x37:
    FUN_000016c4(param_2);
    break;
  case 0x38:
    FUN_00001744(param_2);
    break;
  case 0x39:
    FUN_00001780(param_2);
    break;
  case 0x3a:
    FUN_000017d0(param_2);
    break;
  case 0x3b:
    FUN_00001820(param_2);
    break;
  case 0x3c:
    FUN_00001898(param_2);
    break;
  case 0x3d:
    FUN_000018d4(param_2);
    break;
  case 0x3e:
    FUN_000019a8(param_2);
    break;
  case 0x3f:
    FUN_00001a24(param_2);
    break;
  case 0x40:
    FUN_00001a78(param_2);
    break;
  case 0x41:
    FUN_00001ad4(param_2);
    break;
  case 0x46:
    FUN_00001bcc(param_2);
    break;
  case 0x47:
    FUN_00001c00(param_2);
    break;
  case 0x48:
    FUN_00001ec0(param_2);
    break;
  case 0x49:
    FUN_00002030(param_2);
    break;
  case 0x4a:
    FUN_00002064(param_2);
    break;
  case 0x51:
    FUN_00000b18(param_2);
    break;
  case 0x52:
    FUN_00000bf4(param_2);
    break;
  case 0x53:
    FUN_00000b74(param_2);
    break;
  case 0x54:
    FUN_000009c0(param_2);
  }
  return param_2;
}


================================================================