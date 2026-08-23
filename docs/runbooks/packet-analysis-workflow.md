# Packet Analysis Workflow

## Goal

Analyze client/server behavior without inventing protocol meaning.

## Workflow

1. Capture traffic.
2. Record platform, client version, network setup, and server commit hash.
3. Store the PCAP under `docs/evidence/pcaps/`.
4. Store matching server logs under `docs/evidence/logs/`.
5. Identify packet boundaries and direction.
6. Label unknown fields as `unknown_*`.
7. Compare real PS2 behavior against emulator behavior.
8. Document confirmed facts separately from hypotheses.
9. Update open questions and blocking issues.
