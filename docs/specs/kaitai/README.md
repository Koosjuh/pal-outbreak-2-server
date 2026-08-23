# Kaitai Struct wire specs

Executable, versioned specs of the PAL Outbreak File #2 wire formats. Each `.ksy` **fails loudly**
when framing is wrong (unlike prose notes) and generates parsers for the Node server + Python tooling.

## Specs
- `pal_app_frame.ksy` — the 0x6XXX **application** frame (verified from EE decompile `FUN_001c3880`;
  the same command protocol as the JP Bioserver). Has one flagged OPEN question (10-bit length).
- _(next)_ `pal_snap_transport.ksy` — the SN@P UDP-9090 reliable transport (type/len/token/id/ack).
  Add when we start wire-format / multiplayer work; validate against `tests/results/*.pcap`.

## Compiler
Downloaded to `vendor/kaitai/` (git-ignored — Java app, ~10 MB). Reinstall:
```
Invoke-WebRequest https://github.com/kaitai-io/kaitai_struct_compiler/releases/download/0.10/kaitai-struct-compiler-0.10.zip -OutFile ksc.zip
Expand-Archive ksc.zip vendor/kaitai
```
Needs a JRE (Temurin 21 present).

## Compile a spec (generated code is git-ignored — regenerate on demand)
```
vendor/kaitai/kaitai-struct-compiler-0.10/bin/kaitai-struct-compiler.bat \
  --target javascript docs/specs/kaitai/pal_app_frame.ksy --outdir docs/specs/kaitai/generated
```
Targets: `javascript` (Node server), `python` (tooling), etc. Running a generated JS parser needs the
runtime: `npm i kaitai-struct`.

## Workflow (per CLAUDE.md)
When a goal touches a wire format: encode the hypothesis as a `.ksy`, compile it, then **validate it
against a real capture** — if it doesn't parse the bytes, the framing hypothesis is wrong. Evidence,
not prose.
