-- pal_snap.lua — Wireshark dissector for the PAL Outbreak File #2 SN@P transport (UDP 9090).
-- Grounded in docs/specs/L1-snap-transport-spec.md §1.1 (Confirmed): wire+0x00 u16 = flags|len
-- (low 10 bits = payload length incl the 16-byte header, excl the 4-byte trailer), +0x04 token,
-- +0x08 id/seq, +0x0c ack, +0x10 body, trailer `ba 47 66 11`.
--
-- Install: copy to %APPDATA%\Wireshark\plugins  (or: outbreak-tools MCP tool `install_lua_dissector`).
-- STARTER: header is grounded; body opcode/fields get refined with the multiplayer/wire goal
-- (validate against tests/results/*.pcap). The 0x6XXX app frame (TCP 10127) is a separate follow-up.

local snap = Proto("palsnap", "PAL SN@P transport (Outbreak F2)")
local f_flags   = ProtoField.uint16("palsnap.flags",   "flags (upper 6 bits)", base.HEX)
local f_len     = ProtoField.uint16("palsnap.len",     "payload_len (hdr+body, excl trailer)", base.DEC)
local f_rel     = ProtoField.bool  ("palsnap.reliable","reliable (flag 0x8000)")
local f_rsvd    = ProtoField.bytes ("palsnap.rsvd",    "reserved (+0x02)")
local f_token   = ProtoField.bytes ("palsnap.token",   "session token (+0x04)")
local f_id      = ProtoField.uint32("palsnap.id",      "msg id/seq (+0x08)", base.DEC)
local f_ack     = ProtoField.uint32("palsnap.ack",     "ack (+0x0c)", base.DEC)
local f_op      = ProtoField.uint8 ("palsnap.op",      "opcode? (body[0])", base.HEX)
local f_body    = ProtoField.bytes ("palsnap.body",    "body")
local f_trailer = ProtoField.bytes ("palsnap.trailer", "trailer (ba 47 66 11)")
snap.fields = { f_flags, f_len, f_rel, f_rsvd, f_token, f_id, f_ack, f_op, f_body, f_trailer }

function snap.dissector(buf, pkt, tree)
  if buf:len() < 16 then return 0 end
  pkt.cols.protocol = "PAL-SN@P"
  local t = tree:add(snap, buf(0))
  local flagslen = buf(0, 2):uint()
  local len = bit.band(flagslen, 0x03ff)
  t:add(f_flags, buf(0, 2), bit.rshift(flagslen, 10))
  t:add(f_len,   buf(0, 2), len)
  t:add(f_rel,   buf(0, 2), (bit.band(flagslen, 0x8000) ~= 0) and 1 or 0)
  t:add(f_rsvd,  buf(2, 2))
  t:add(f_token, buf(4, 4))
  t:add(f_id,    buf(8, 4))
  t:add(f_ack,   buf(12, 4))
  local body_len = len - 16
  if body_len > 0 and buf:len() >= 16 + body_len then
    t:add(f_op,   buf(16, 1))
    t:add(f_body, buf(16, body_len))
    if buf:len() >= 16 + body_len + 4 then t:add(f_trailer, buf(16 + body_len, 4)) end
  end
  pkt.cols.info = string.format("SN@P len=%d id=%d ack=%d op=0x%02x", len,
                                buf(8,4):uint(), buf(12,4):uint(), (body_len>0) and buf(16,1):uint() or 0)
  return buf:len()
end

DissectorTable.get("udp.port"):add(9090, snap)
