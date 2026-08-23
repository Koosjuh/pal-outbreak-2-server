FUNCTION FUN_0061f4b0 @ 0x0061f4b0  size=336
CALLERS (19): FUN_006205c0@0x006205c0, FUN_00627400@0x00627400, FUN_00624850@0x00624850, FUN_00620d60@0x00620d60, FUN_00626e70@0x00626e70, FUN_00626900@0x00626900, FUN_0061fd70@0x0061fd70, FUN_00622f40@0x00622f40, FUN_00623800@0x00623800, FUN_00622d60@0x00622d60, FUN_00627540@0x00627540, FUN_00625190@0x00625190, ...
CALLEES (0): 
----------------------------------------------------------------

void FUN_0061f4b0(char param_1)

{
  switch(param_1) {
  case '\x01':
  case '\x02':
  case '\x03':
  case '\x04':
  case '\x05':
  case '\x06':
  case '\a':
  case '\b':
  case '\t':
  case '\n':
  case '\v':
  case '\f':
  case '\r':
  case '\x0e':
  case '\x0f':
  case '\x10':
  case '\x11':
  case '\x12':
  case '\x13':
  case '\x14':
  case '\x15':
  case '\x16':
  case '\x17':
  case '\x18':
  case '\x19':
  case '\x1a':
  case '\x1b':
  case '\x1c':
  case '\x1d':
  case '\x1e':
  case ' ':
  case '!':
  case '\"':
  case '#':
  case '$':
  case '%':
  case '&':
  case '\'':
  case '(':
  case '9':
  case ':':
  case ';':
  case '<':
  case '=':
  case '>':
  case '?':
  case 'Q':
  case 'R':
  case 'S':
  case 'T':
  case 'U':
  case 'V':
  case 'W':
  case 'X':
  case 'Y':
  case 'Z':
  case '[':
  case '\\':
  case ']':
  case '^':
  case '_':
  case '`':
  case 'a':
  case 'b':
  case 'c':
  case 'd':
  case 'e':
  case 'f':
  case 'g':
  case 'h':
  case 'i':
  case 'j':
  case 'k':
  case 'l':
  case 'm':
  case 'n':
  case 'o':
  case 'p':
  case 'q':
  case 'r':
  case 's':
  case 't':
  case 'u':
  case 'v':
  case 'w':
  case 'x':
  case 'y':
  case 'z':
  case '{':
  case '|':
  case '}':
  case '~':
  case '\x7f':
  case -0x80:
  case -0x7f:
  case -0x7e:
  case -0x7d:
  case -0x7c:
  case -0x7b:
  case -0x7a:
  case -0x79:
  case -0x78:
  case -0x77:
  case -0x76:
  case -0x75:
  case -0x74:
  case -0x73:
  case -0x72:
  case -0x71:
  case -0x70:
  case -0x6f:
  case -0x6e:
  case -0x6d:
  case -0x6c:
  case -0x6b:
  case -0x6a:
  case -0x69:
  case -0x68:
  case -0x61:
  case -0x60:
  case -0x5f:
  case -0x5e:
  case -0x5d:
  case -0x5c:
  case -0x5b:
  case -0x5a:
  case -0x58:
  case -0x57:
  case -0x56:
  case -0x55:
  case -0x53:
  case -0x52:
    if (cRam00715313 < '\b') {
      *(char *)(cRam00715313 + 0x715330) = param_1;
      *(undefined1 *)(cRam00715313 + 0x715338) = 0;
      cRam00715313 = cRam00715313 + '\x01';
    }
    break;
  case '\x1f':
  case ')':
  case '*':
  case '+':
  case ',':
  case '-':
  case '.':
  case '/':
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case -0x67:
  case -0x66:
  case -0x65:
  case -100:
    if (cRam00715312 < '\b') {
      *(char *)(cRam00715312 + 0x715320) = param_1;
      *(undefined1 *)(cRam00715312 + 0x715328) = 0;
      cRam00715312 = cRam00715312 + '\x01';
    }
    break;
  case '@':
  case 'A':
  case 'B':
  case 'C':
  case 'D':
  case 'E':
  case 'F':
  case 'G':
  case 'H':
  case 'I':
  case 'J':
  case 'K':
  case 'L':
  case 'M':
  case 'N':
  case 'O':
  case 'P':
  case -0x4f:
  case -0x4e:
  case -0x4d:
  case -0x4c:
  case -0x4b:
  case -0x4a:
    if (cRam00715313 < '\b') {
      *(char *)(cRam00715313 + 0x715330) = param_1;
      if ((param_1 == -0x4c) || (param_1 == '@')) {
        *(undefined1 *)(cRam00715313 + 0x715338) = 5;
      }
      else {
        *(undefined1 *)(cRam00715313 + 0x715338) = 4;
      }
      cRam00715313 = cRam00715313 + '\x01';
    }
  }
  return;
}



================================================================