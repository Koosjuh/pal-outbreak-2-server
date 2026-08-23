# Reproduce Real PS2 Test

## Required Setup

- Real PS2
- PAL Resident Evil Outbreak File #2, SLES_533.19
- Network capture point
- Current Pi server build and runtime environment

## Pi Runtime

The server runs on the Pi at `192.0.2.121`. Before testing, verify runtime
state with `docs/runbooks/pi-deployment.md`: file hashes, active service,
effective systemd environment, and recent journal.

## Steps

1. Verify Pi runtime.
2. Start packet capture.
3. Record deploy-git ref and Pi runtime hashes.
4. Boot PAL client.
5. Attempt lobby connection.
6. Record selected lobby.
7. Record result and exact error.
8. Save PCAP and Pi journal/server logs.
9. Update docs/current-status.md and docs/test-plan.md.
