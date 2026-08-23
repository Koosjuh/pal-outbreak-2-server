# Reproduce Emulator Test

## Required Setup

- Emulator name and version
- PAL Resident Evil Outbreak File #2, SLES_533.19
- Network configuration details
- Current Pi server build and runtime environment
- Wireshark/tshark or dumpcap available
- PINE sampler available when runtime memory evidence is needed

## Mandatory Harness

Start emulator tests through the capture harness by default:

```powershell
node tests/capture.mjs --case GT-003 --platform emulator --idle <seconds> --watch <watch-file> --force
```

For the current Pi-server bridged setup, the server is expected at
`192.0.2.121` and the emulator config should capture traffic involving that
Pi host. Do not start PCSX2 manually for a protocol test unless you also capture
equivalent PCAP, Pi journal/server logs, PINE samples when relevant, DEV9/PCSX2
logs when relevant, and run metadata.

## Steps

1. Verify Pi runtime with `docs/runbooks/pi-deployment.md`.
2. Check disk space for `tests/results`.
3. Start the harness.
4. Confirm packet capture started.
5. Confirm PINE sampler is reading before sign-in when a watch file is used.
6. Boot PAL client in emulator.
7. Attempt lobby connection.
8. Record selected lobby.
9. Record result and exact error.
10. Save PCAP, Pi journal/server logs, PINE samples, DEV9/PCSX2 logs if relevant, and metadata.
11. Compare against real PS2 behavior.
12. Update docs/current-status.md and docs/test-plan.md.
