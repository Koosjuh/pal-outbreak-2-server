meta:
  id: pal_app_frame
  title: PAL Outbreak File #2 — application frame (0x6XXX)
  endian: be
  license: CC0-1.0
doc: |
  The application-layer frame the PAL client speaks — the same 0x6XXX command protocol as the
  JP Bioserver (only the transport differs). Header verified from the EE decompile FUN_001c3880
  (see the packet-class comment in server/snap_server.js).

  Layering note: this is the INNER app frame. The SN@P UDP-9090 reliable transport (type/len/token/
  id/ack — see docs/specs/L1-snap-transport-spec.md) wraps it separately; spec that as
  pal_snap_transport.ksy when we start wire-format / multiplayer work.

  OPEN (validate against a real capture before trusting for long frames): the payload length is a
  10-bit field split across byte0 (low 2 bits) + byte1 — established by the area-select length fix
  (`reply[0] |= (bodyLen>>8)&3`). byte0's upper 6 bits are treated as flags of unknown purpose.
seq:
  - id: len_hi
    type: u1
    doc: low 2 bits = high bits of payload length; upper 6 bits = flags (purpose TBD)
  - id: len_lo
    type: u1
  - id: direction
    type: u1
    enum: dir
    doc: 01 client-query, 02 server-tell, 10 server-broadcast
  - id: cmd
    type: u2
    doc: command 0x6XXX (BE u16)
  - id: pid
    type: u1
    doc: pid / sub-param
  - id: err
    type: u1
    doc: error flag — 0xFF makes every EE handler take the error path
  - id: param
    type: u1
    doc: padding / param
  - id: payload
    size: len_payload
instances:
  len_payload:
    value: '((len_hi & 0x03) << 8) | len_lo'
    doc: 10-bit payload length (byte0 low-2-bits as high, byte1 as low)
enums:
  dir:
    0x01: client_query
    0x02: server_tell
    0x10: server_broadcast
