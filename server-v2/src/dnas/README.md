# V2 DNAS Evidence Boundary

This implementation targets PAL `SLES_533.19`, not every DNAS title or every
possible PAL application.

The strict request forms in `application-codec.js` are a fail-closed
implementation boundary:

- `/eu-gw/v2.5_i-connect`: 308 bytes, query at `+0x00`, game ID at `+0x2c`
- `/eu-gw/v2.5_others`: 184 bytes, query at `+0x00`, game ID at `+0x1b`
- `/eu-gw/v2.5_others`: 44 bytes, query at `+0x00`, game ID at `+0x1b`

These forms are verified by repeated SLES_533.19 runtime sessions and locked by
captured-body fixtures. They are not claimed to exhaust DNAS variants.

If the target client emits another path, length, or layout, V2 must reject and
record it. Add support only after a capture and decoded-client/response-path
trace establishes the new form. Do not restore V1's seven-offset search as a
generic fallback.

The response transform is supported by accepted V1 runtime behavior and the
legacy PHP-derived reference implementation. Its independent DNAS280
reconstruction remains open, so its provenance is classified `Medium` even
though the tested bytes are deterministic.
