#!/usr/bin/env python3
"""Local stdio MCP server for evidence-first Outbreak protocol analysis."""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import re
import shutil
import socket
import subprocess
import sys
import urllib.error
import urllib.request
from datetime import datetime, timezone
from pathlib import Path
from typing import Any


ROOT = Path(__file__).resolve().parents[2]
TOOL_DIR = Path(__file__).resolve().parent
SYMBOLS_PATH = TOOL_DIR / "symbols.json"
OPCODES_PATH = TOOL_DIR / "known_opcodes.json"
GRAPH_PATH = TOOL_DIR / "evidence_graph.json"
OPENAI_CONFIG_PATH = TOOL_DIR / "openai.json"
PINE_DEFAULT_HOST = "127.0.0.1"
PINE_DEFAULT_PORT = 28011

RUNTIME_FAILURES: dict[str, int] = {}
RUNTIME_DISABLED: set[str] = set()

CONFIDENCE_RANK = {
    "unknown": 0,
    "low": 1,
    "hypothesis": 1,
    "observation": 2,
    "inferred": 2,
    "correlation": 2,
    "medium": 3,
    "likely": 3,
    "strong": 4,
    "strong evidence": 4,
    "runtime-confirmed": 5,
    "runtime-confirmed mechanism": 5,
    "confirmed": 5,
    "high": 5,
}


class ToolError(Exception):
    pass


def normalize_hex_bytes(value: str) -> str:
    return re.sub(r"[^0-9a-fA-F]", "", value).lower()


def ascii_preview(data: bytes) -> str:
    return "".join(chr(b) if 0x20 <= b < 0x7F else "." for b in data)


def hex_dump(data: bytes, width: int = 16) -> str:
    rows = []
    for offset in range(0, len(data), width):
        chunk = data[offset : offset + width]
        hex_part = " ".join(f"{b:02x}" for b in chunk).ljust(width * 3 - 1)
        rows.append(f"{offset:04x}  {hex_part}  {ascii_preview(chunk)}")
    return "\n".join(rows)


def parse_opcode(value: str) -> int:
    text = str(value).strip().lower()
    if text.startswith("0x"):
        return int(text, 16)
    return int(text, 16)


def decode_snap_header(payload: bytes) -> dict[str, Any] | None:
    if len(payload) < 4:
        return None
    byte0 = payload[0]
    return {
        "type": byte0 >> 4,
        "length": ((byte0 & 0x0F) << 8) | payload[1],
        "opcode": f"0x{int.from_bytes(payload[2:4], 'big'):04x}",
    }


def infer_direction(src_port: int, dst_port: int, udp_port: int) -> str:
    if dst_port == udp_port and src_port != udp_port:
        return "client_to_server"
    if src_port == udp_port and dst_port != udp_port:
        return "server_to_client"
    if src_port == udp_port and dst_port == udp_port:
        return "unknown_udp_port_both"
    return "unknown"


def require_tshark() -> str:
    exe = shutil.which("tshark")
    if exe:
        return exe
    candidates = [
        Path(os.environ.get("ProgramFiles", r"C:\Program Files")) / "Wireshark" / "tshark.exe",
        Path(os.environ.get("ProgramFiles(x86)", r"C:\Program Files (x86)")) / "Wireshark" / "tshark.exe",
    ]
    for candidate in candidates:
        if candidate.exists():
            return str(candidate)
    raise ToolError(
        "tshark is required for pcap tools but was not found on PATH or in the standard "
        "Windows Wireshark install directories. Install Wireshark/tshark or add tshark.exe to PATH."
    )


def read_pcap_udp_packets(pcap_path: str, udp_port: int) -> list[dict[str, Any]]:
    tshark = require_tshark()
    path = Path(pcap_path)
    if not path.exists():
        raise ToolError(f"pcap_path does not exist: {pcap_path}")

    cmd = [
        tshark,
        "-r",
        str(path),
        "-Y",
        f"udp.port == {int(udp_port)}",
        "-T",
        "fields",
        "-E",
        "separator=|",
        "-E",
        "occurrence=f",
        "-e",
        "frame.number",
        "-e",
        "frame.time_epoch",
        "-e",
        "ip.src",
        "-e",
        "udp.srcport",
        "-e",
        "ip.dst",
        "-e",
        "udp.dstport",
        "-e",
        "udp.payload",
    ]
    proc = subprocess.run(cmd, capture_output=True, text=True)
    if proc.returncode != 0:
        raise ToolError(f"tshark failed: {proc.stderr.strip() or proc.stdout.strip()}")

    packets: list[dict[str, Any]] = []
    for line in proc.stdout.splitlines():
        if not line.strip():
            continue
        parts = line.split("|")
        while len(parts) < 7:
            parts.append("")
        number, timestamp, src, src_port, dst, dst_port, payload_hex = parts[:7]
        clean = normalize_hex_bytes(payload_hex)
        payload = bytes.fromhex(clean) if clean else b""
        try:
            sp = int(src_port)
            dp = int(dst_port)
        except ValueError:
            sp = dp = -1
        packets.append(
            {
                "packet_number": int(number) if number.isdigit() else number,
                "timestamp": timestamp,
                "src": f"{src}:{src_port}",
                "dst": f"{dst}:{dst_port}",
                "src_ip": src,
                "dst_ip": dst,
                "src_port": sp,
                "dst_port": dp,
                "direction": infer_direction(sp, dp, int(udp_port)),
                "payload": payload,
            }
        )
    return packets


def pcap_timeline(pcap_path: str, udp_port: int = 9090) -> dict[str, Any]:
    packets = read_pcap_udp_packets(pcap_path, udp_port)
    timeline = []
    for pkt in packets:
        payload = pkt["payload"]
        timeline.append(
            {
                "packet_number": pkt["packet_number"],
                "timestamp": pkt["timestamp"],
                "direction": pkt["direction"],
                "src": pkt["src"],
                "dst": pkt["dst"],
                "udp_payload_length": len(payload),
                "first_16_payload_bytes": payload[:16].hex(" "),
                "snap_header": decode_snap_header(payload),
                "body_offset": 16 if len(payload) >= 16 else None,
                "body_offset_note": "SN@P serialized body offset is treated as 0x10 when present",
                "ascii_preview": ascii_preview(payload[:64]),
                "sha256": hashlib.sha256(payload).hexdigest(),
            }
        )
    return {
        "pcap_path": pcap_path,
        "udp_port": udp_port,
        "packet_count": len(timeline),
        "timeline": timeline,
        "Verified": {"packet_count": len(timeline), "packet_facts": timeline},
        "Inferred": ["direction is inferred from the configured UDP port and packet source/destination ports"],
        "Unknown": ["opcode semantics are not proven by the timeline alone"],
        "Assumption": ["SN@P header decode uses byte0/type, byte0-byte1 length, and bytes2-3 opcode as specified for this project"],
    }


def extract_opcode_packets(pcap_path: str, opcode: str, udp_port: int = 9090) -> dict[str, Any]:
    target = parse_opcode(opcode)
    matches = []
    for pkt in read_pcap_udp_packets(pcap_path, udp_port):
        payload = pkt["payload"]
        header = decode_snap_header(payload)
        if not header or int(header["opcode"], 16) != target:
            continue
        matches.append(
            {
                "packet_number": pkt["packet_number"],
                "timestamp": pkt["timestamp"],
                "direction": pkt["direction"],
                "src": pkt["src"],
                "dst": pkt["dst"],
                "length": len(payload),
                "snap_header": header,
                "ascii_preview": ascii_preview(payload[:128]),
                "hex_dump": hex_dump(payload),
            }
        )
    return {
        "pcap_path": pcap_path,
        "udp_port": udp_port,
        "opcode": f"0x{target:04x}",
        "matches": matches,
        "Verified": {"match_count": len(matches), "matching_packets": matches},
        "Inferred": ["direction is inferred from the configured UDP port and packet source/destination ports"],
        "Unknown": ["matching an opcode does not prove handler semantics or client intent"],
        "Assumption": ["opcode is decoded from SN@P header bytes 2-3 big-endian"],
    }


HEX_ROW_RE = re.compile(r"0x([0-9a-fA-F]{4,8})[:\s]+(.+)$")


def parse_snapshot(path: str) -> dict[int, int]:
    p = Path(path)
    if not p.exists():
        raise ToolError(f"snapshot path does not exist: {path}")
    memory: dict[int, int] = {}
    text = p.read_text(encoding="utf-8", errors="replace")

    try:
        obj = json.loads(text)
    except json.JSONDecodeError:
        obj = None
    if isinstance(obj, dict):
        json_regions = []
        if isinstance(obj.get("regions"), list):
            json_regions.extend(obj.get("regions", []))
        if isinstance(obj.get("values"), list):
            json_regions.extend(obj.get("values", []))
        for region in json_regions:
            if not isinstance(region, dict):
                continue
            addr_value = region.get("addr") or region.get("address")
            if not addr_value:
                continue
            addr = int(str(addr_value), 0)
            data = bytes.fromhex(normalize_hex_bytes(str(region.get("hex") or region.get("bytes") or "")))
            for i, b in enumerate(data):
                memory[addr + i] = b
        if memory:
            return memory

    for line in text.splitlines():
        match = HEX_ROW_RE.search(line)
        if not match:
            continue
        addr = int(match.group(1), 16)
        right = match.group(2).split("|", 1)[0]
        tokens = re.findall(r"(?<![0-9a-fA-F])([0-9a-fA-F]{2})(?![0-9a-fA-F])", right)
        for i, tok in enumerate(tokens):
            memory[addr + i] = int(tok, 16)
    if not memory:
        raise ToolError(f"no hexdump bytes found in snapshot: {path}")
    return memory


def compare_snapshots(baseline_snapshot_path: str, state_snapshot_path: str) -> dict[str, Any]:
    before = parse_snapshot(baseline_snapshot_path)
    after = parse_snapshot(state_snapshot_path)
    all_offsets = sorted(set(before) | set(after))
    changed = [addr for addr in all_offsets if before.get(addr) != after.get(addr)]

    regions = []
    if changed:
        start = prev = changed[0]
        for addr in changed[1:]:
            if addr == prev + 1:
                prev = addr
                continue
            regions.append((start, prev))
            start = prev = addr
        regions.append((start, prev))

    changed_regions = []
    changed_offsets = []
    grouped_by_symbol: dict[str, dict[str, Any]] = {}
    high_value_changes = []
    for start, end in regions:
        before_bytes = bytes(before.get(a, 0) for a in range(start, end + 1))
        after_bytes = bytes(after.get(a, 0) for a in range(start, end + 1))
        known_symbols = symbols_overlapping(start, end)
        changed_regions.append(
            {
                "start": f"0x{start:08x}",
                "end": f"0x{end:08x}",
                "length": end - start + 1,
                "before": before_bytes.hex(" "),
                "after": after_bytes.hex(" "),
                "before_ascii": ascii_preview(before_bytes),
                "after_ascii": ascii_preview(after_bytes),
                "known_symbols": known_symbols,
            }
        )
        for sym in known_symbols:
            name = str(sym.get("symbol_name"))
            grouped_by_symbol.setdefault(
                name,
                {
                    "symbol": sym,
                    "changed_regions": [],
                    "changed_offsets": [],
                    "classification": sym.get("evidence_class", "Unknown"),
                },
            )["changed_regions"].append({"start": f"0x{start:08x}", "end": f"0x{end:08x}"})
            if find_symbol(name) and find_symbol(name).get("high_value"):
                high_value_changes.append({"symbol": name, "region": f"0x{start:08x}-0x{end:08x}", "classification": sym.get("evidence_class", "Unknown")})
        for addr in range(start, end + 1):
            if before.get(addr) != after.get(addr):
                offset_entry = {
                    "offset": f"0x{addr:08x}",
                    "before": None if addr not in before else f"0x{before[addr]:02x}",
                    "after": None if addr not in after else f"0x{after[addr]:02x}",
                    "nearby_symbols": symbols_near(addr),
                }
                changed_offsets.append(offset_entry)
                for sym in known_symbols:
                    grouped_by_symbol[str(sym.get("symbol_name"))]["changed_offsets"].append(offset_entry["offset"])

    markdown_summary = [
        "## Snapshot Comparison",
        "",
        f"- Verified: compared {len(before)} baseline bytes with {len(after)} state bytes.",
        f"- Verified: {len(changed_offsets)} changed offsets in {len(changed_regions)} changed regions.",
        f"- Inferred: {len(grouped_by_symbol)} changed symbol regions matched `symbols.json` ranges.",
        f"- Unknown: unchanged regions are suppressed; absence of a symbol match does not prove a field is irrelevant.",
    ]
    if high_value_changes:
        markdown_summary.append("- Inferred high-value changes: " + ", ".join(sorted({item["symbol"] for item in high_value_changes})))

    return {
        "baseline_snapshot_path": baseline_snapshot_path,
        "state_snapshot_path": state_snapshot_path,
        "summary": {
            "baseline_bytes": len(before),
            "state_bytes": len(after),
            "changed_offset_count": len(changed_offsets),
            "changed_region_count": len(changed_regions),
            "symbol_group_count": len(grouped_by_symbol),
            "high_value_change_count": len(high_value_changes),
        },
        "changed_regions": changed_regions,
        "changed_offsets": changed_offsets,
        "grouped_by_symbol": grouped_by_symbol,
        "high_value_changes": high_value_changes,
        "markdown_summary": "\n".join(markdown_summary),
        "Verified": {"changed_regions": changed_regions, "changed_offsets": changed_offsets},
        "Inferred": {"grouped_by_symbol": grouped_by_symbol, "high_value_changes": high_value_changes},
        "Unknown": ["unmapped changes have no known symbol in symbols.json", "unchanged regions are suppressed"],
        "Assumption": ["symbol grouping depends on current symbols.json ranges and confidence labels"],
    }


def load_symbols() -> list[dict[str, Any]]:
    try:
        data = json.loads(SYMBOLS_PATH.read_text(encoding="utf-8"))
    except FileNotFoundError:
        raise ToolError(f"symbols file missing: {SYMBOLS_PATH}")
    symbols = data.get("symbols", data if isinstance(data, list) else [])
    if not isinstance(symbols, list):
        raise ToolError("symbols.json must contain a top-level symbols array")
    return symbols


def confidence_rank(value: Any) -> int:
    return CONFIDENCE_RANK.get(str(value or "").strip().lower(), 0)


def evidence_class(sym: dict[str, Any]) -> str:
    return str(sym.get("evidence_class") or "Unknown")


def symbol_names(sym: dict[str, Any]) -> list[str]:
    return [str(sym.get("name", "")), *[str(alias) for alias in sym.get("aliases", [])]]


def symbol_address(sym: dict[str, Any]) -> int | None:
    addr = sym.get("address")
    if addr in (None, ""):
        return None
    try:
        return int(str(addr), 0)
    except ValueError:
        return None


def symbol_size(sym: dict[str, Any]) -> int:
    try:
        return int(sym.get("size") or 0)
    except (TypeError, ValueError):
        return 0


def symbol_to_response(sym: dict[str, Any]) -> dict[str, Any]:
    return {
        "symbol_name": sym.get("name"),
        "aliases": sym.get("aliases", []),
        "address": sym.get("address"),
        "size": sym.get("size"),
        "category": sym.get("category", "Unknown"),
        "confidence": sym.get("confidence", "Low"),
        "evidence_class": evidence_class(sym),
        "source_file": sym.get("source_file", str(SYMBOLS_PATH.relative_to(ROOT)).replace("\\", "/")),
        "notes": sym.get("notes", ""),
        "related_functions": sym.get("related_functions", []),
        "readers": sym.get("readers", []),
        "writers": sym.get("writers", []),
    }


def find_symbol(query: str) -> dict[str, Any] | None:
    query_l = str(query).strip().lower()
    query_addr = parse_address_query(query_l)
    symbols = load_symbols()
    if query_addr is not None:
        exact = []
        containing = []
        for sym in symbols:
            addr = symbol_address(sym)
            if addr is None:
                continue
            size = symbol_size(sym)
            if addr == query_addr:
                exact.append(sym)
            elif size and addr <= query_addr < addr + size:
                containing.append(sym)
        if exact:
            return sorted(exact, key=lambda s: confidence_rank(s.get("confidence")), reverse=True)[0]
        if containing:
            return sorted(containing, key=lambda s: (confidence_rank(s.get("confidence")), -symbol_size(s)), reverse=True)[0]
        return None

    for sym in symbols:
        if any(query_l == name.lower() for name in symbol_names(sym)):
            return sym
    for sym in symbols:
        if any(query_l in name.lower() for name in symbol_names(sym)):
            return sym
    return None


def symbols_near(address: int, distance: int = 0x40) -> list[dict[str, Any]]:
    out = []
    for sym in load_symbols():
        addr = symbol_address(sym)
        if addr is None:
            continue
        size = symbol_size(sym)
        start = addr
        end = addr + max(size, 1) - 1
        if start <= address <= end or abs(address - start) <= distance:
            out.append(
                {
                    "name": sym.get("name"),
                    "address": sym.get("address"),
                    "category": sym.get("category", "Unknown"),
                    "confidence": sym.get("confidence", "Low"),
                    "evidence_class": evidence_class(sym),
                    "distance": 0 if start <= address <= end else address - start,
                }
            )
    return sorted(out, key=lambda item: abs(int(item["distance"])))[:5]


def symbols_overlapping(start: int, end: int) -> list[dict[str, Any]]:
    matches = []
    for sym in load_symbols():
        addr = symbol_address(sym)
        if addr is None:
            continue
        size = max(symbol_size(sym), 1)
        sym_end = addr + size - 1
        if addr <= end and sym_end >= start:
            matches.append(symbol_to_response(sym))
    return sorted(matches, key=lambda item: item.get("address") or "")


def parse_address_query(value: str) -> int | None:
    text = str(value).strip().lower()
    if re.fullmatch(r"0x[0-9a-f]+", text):
        return int(text, 16)
    if re.fullmatch(r"[0-9a-f]{6,8}", text):
        return int(text, 16)
    return None


def resolve_symbol(name_or_address: str) -> dict[str, Any]:
    query = str(name_or_address).strip()
    query_addr = parse_address_query(query)
    best = find_symbol(query)

    if best is None:
        return {
            "symbol_name": query,
            "aliases": [],
            "address": f"0x{query_addr:08x}" if query_addr is not None else None,
            "size": None,
            "category": "Unknown",
            "confidence": "Low",
            "evidence_class": "Unknown",
            "source_file": str(SYMBOLS_PATH.relative_to(ROOT)).replace("\\", "/"),
            "notes": "No matching symbol. Treat as Unknown until resolved through symbols.json or Ghidra.",
            "related_functions": [],
            "readers": [],
            "writers": [],
        }

    return symbol_to_response(best)


def load_assumptions() -> list[str]:
    path = ROOT / "docs" / "protocol" / "ASSUMPTIONS.md"
    if not path.exists():
        return ["docs/protocol/ASSUMPTIONS.md is missing."]
    assumptions = []
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        if line.startswith("- "):
            assumptions.append(line[2:].strip())
    return assumptions or ["No active assumptions listed."]


def evidence_report(
    pcap_path: str,
    baseline_snapshot_path: str | None = None,
    state_snapshot_path: str | None = None,
    udp_port: int = 9090,
) -> str:
    facts: list[str] = []
    unknowns: list[str] = []
    inferences: list[str] = []

    try:
        timeline = pcap_timeline(pcap_path, udp_port)
        facts.append(f"Parsed {timeline['packet_count']} UDP packets on port {udp_port} from `{pcap_path}`.")
        op_counts: dict[str, int] = {}
        dirs: dict[str, int] = {}
        for item in timeline["timeline"]:
            dirs[item["direction"]] = dirs.get(item["direction"], 0) + 1
            header = item.get("snap_header") or {}
            opcode = header.get("opcode")
            if opcode:
                op_counts[opcode] = op_counts.get(opcode, 0) + 1
        if op_counts:
            facts.append("Observed SN@P opcodes: " + ", ".join(f"{k} x{v}" for k, v in sorted(op_counts.items())) + ".")
        if dirs:
            facts.append("Direction counts: " + ", ".join(f"{k} x{v}" for k, v in sorted(dirs.items())) + ".")
        unknowns.append("Opcode semantics are not proven by the pcap alone.")
    except ToolError as exc:
        facts.append(f"PCAP timeline unavailable: {exc}")
        unknowns.append("Packet facts remain unknown until tshark can parse the capture.")

    if baseline_snapshot_path and state_snapshot_path:
        diff = compare_snapshots(baseline_snapshot_path, state_snapshot_path)
        facts.append(
            "Snapshot diff found "
            f"{diff['summary']['changed_offset_count']} changed offsets across "
            f"{diff['summary']['changed_region_count']} regions."
        )
        if diff["summary"]["changed_offset_count"]:
            inferences.append("Changed memory regions are candidates for runtime state movement, not proof of protocol meaning.")
    else:
        unknowns.append("No baseline/state snapshot pair was provided, so memory deltas were not checked.")

    assumptions = load_assumptions()
    lines = [
        "# Evidence Report",
        "",
        "## Verified facts",
        *[f"- {item}" for item in facts],
        "",
        "## Unknowns",
        *[f"- {item}" for item in unknowns],
        "",
        "## Inferences",
        *([f"- {item}" for item in inferences] or ["- None."]),
        "",
        "## Active assumptions",
        *[f"- {item}" for item in assumptions],
        "",
        "## Recommended next observation",
        "- Identify the unanswered or mis-answered message in the packet timeline, then collect a matching baseline/state snapshot before changing server behavior.",
    ]
    return "\n".join(lines)


def symbol_audit(category: str | None = None, min_confidence: str | None = None) -> dict[str, Any]:
    symbols = load_symbols()
    if category:
        symbols = [s for s in symbols if str(s.get("category", "")).lower() == category.lower()]
    if min_confidence:
        minimum = confidence_rank(min_confidence)
        symbols = [s for s in symbols if confidence_rank(s.get("confidence")) >= minimum]

    names: dict[str, list[str]] = {}
    addresses: dict[str, list[str]] = {}
    alias_names = set()
    canonical_names = {str(s.get("name")) for s in symbols}
    missing_confidence = []
    duplicate_names = []
    duplicate_addresses = []
    aliases_pointing_unknown = []
    low_confidence_used_by_high_confidence_notes = []

    for sym in symbols:
        name = str(sym.get("name", ""))
        if not sym.get("confidence"):
            missing_confidence.append(symbol_to_response(sym))
        names.setdefault(name.lower(), []).append(name)
        for alias in sym.get("aliases", []):
            alias_names.add(str(alias).lower())
            names.setdefault(str(alias).lower(), []).append(name)
            if str(alias).startswith("@") and str(alias)[1:] not in canonical_names:
                aliases_pointing_unknown.append({"symbol": name, "alias": alias, "missing_target": str(alias)[1:]})
        addr = sym.get("address")
        if addr:
            addresses.setdefault(str(addr).lower(), []).append(name)

    for key, owners in names.items():
        if len(set(owners)) > 1:
            duplicate_names.append({"name_or_alias": key, "symbols": sorted(set(owners))})
    for addr, owners in addresses.items():
        if len(owners) > 1:
            duplicate_addresses.append({"address": addr, "symbols": owners})

    low_names = {str(s.get("name")) for s in symbols if confidence_rank(s.get("confidence")) <= 1}
    for sym in symbols:
        if confidence_rank(sym.get("confidence")) < 4:
            continue
        refs = [*sym.get("related_functions", []), *sym.get("readers", []), *sym.get("writers", [])]
        used = sorted(set(str(r) for r in refs if str(r) in low_names))
        if used:
            low_confidence_used_by_high_confidence_notes.append({"symbol": sym.get("name"), "low_confidence_refs": used})

    addressed = sorted(
        [(symbol_address(sym), sym.get("name"), sym.get("address")) for sym in symbols if symbol_address(sym) is not None],
        key=lambda item: item[0] or 0,
    )
    suspiciously_close = []
    for idx, (addr, name, addr_text) in enumerate(addressed):
        if addr is None:
            continue
        for other_addr, other_name, other_text in addressed[idx + 1 : idx + 8]:
            if other_addr is None:
                continue
            delta = other_addr - addr
            if delta > 0x100:
                break
            if delta > 0:
                suspiciously_close.append(
                    {
                        "address_a": addr_text,
                        "symbol_a": name,
                        "address_b": other_text,
                        "symbol_b": other_name,
                        "delta": f"0x{delta:x}",
                        "classification": "Inferred",
                        "notes": "Close addresses are not errors by themselves, but are typo-prone during manual analysis.",
                    }
                )

    return {
        "filters": {"category": category, "min_confidence": min_confidence},
        "summary": {
            "symbols_checked": len(symbols),
            "missing_confidence": len(missing_confidence),
            "duplicate_addresses": len(duplicate_addresses),
            "duplicate_names": len(duplicate_names),
            "aliases_pointing_unknown": len(aliases_pointing_unknown),
            "low_confidence_refs_from_high_confidence_symbols": len(low_confidence_used_by_high_confidence_notes),
            "suspiciously_close_addresses": len(suspiciously_close),
        },
        "Verified": {
            "symbols_checked": len(symbols),
            "missing_confidence": missing_confidence,
            "duplicate_addresses": duplicate_addresses,
            "duplicate_names": duplicate_names,
            "aliases_pointing_unknown": aliases_pointing_unknown,
        },
        "Inferred": {
            "low_confidence_symbols_used_by_high_confidence_notes": low_confidence_used_by_high_confidence_notes,
            "suspiciously_close_addresses": suspiciously_close,
        },
        "Unknown": [],
        "Assumption": ["Audit checks metadata consistency; it does not validate address correctness."],
    }


def memory_slice(memory: dict[int, int], address: int, size: int) -> bytes | None:
    if any((address + i) not in memory for i in range(size)):
        return None
    return bytes(memory[address + i] for i in range(size))


def decode_bytes(data: bytes, decoder: str | None) -> Any:
    if decoder == "u8":
        return data[0] if data else None
    if decoder == "u16le":
        return int.from_bytes(data[:2], "little") if len(data) >= 2 else None
    if decoder == "u32le":
        return int.from_bytes(data[:4], "little") if len(data) >= 4 else None
    if decoder == "u32le_ptr":
        return f"0x{int.from_bytes(data[:4], 'little'):08x}" if len(data) >= 4 else None
    if decoder == "ipv4_le":
        return ".".join(str(b) for b in data[:4]) if len(data) >= 4 else None
    if decoder == "ipv4_be":
        return ".".join(str(b) for b in reversed(data[:4])) if len(data) >= 4 else None
    if decoder == "ascii":
        return ascii_preview(data).rstrip(".")
    if decoder == "hex":
        return data.hex(" ")
    if decoder == "callback_table":
        entries = []
        for slot in range(0, min(len(data), 256), 4):
            value = int.from_bytes(data[slot : slot + 4], "little")
            if value:
                entries.append({"slot": f"0x{slot // 4:02x}", "value": f"0x{value:08x}", "symbol": resolve_symbol(f"0x{value:08x}")})
        return entries
    return data.hex(" ")


def decode_snapshot_symbols(snapshot_path: str) -> dict[str, Any]:
    memory = parse_snapshot(snapshot_path)
    decoded = []
    unknown = []
    for sym in load_symbols():
        addr = symbol_address(sym)
        size = symbol_size(sym)
        decoder = sym.get("decoder")
        if addr is None or size <= 0 or not decoder:
            continue
        data = memory_slice(memory, addr, size)
        entry_base = {
            "symbol_name": sym.get("name"),
            "address": sym.get("address"),
            "size": size,
            "confidence": sym.get("confidence", "Low"),
            "evidence_class": evidence_class(sym),
            "source_symbol_entry": symbol_to_response(sym),
        }
        if data is None:
            unknown.append({**entry_base, "raw_bytes": None, "decoded_value": None, "classification": "Unknown", "notes": "Bytes for this symbol were not present in the snapshot."})
            continue
        decoded.append(
            {
                **entry_base,
                "raw_bytes": data.hex(" "),
                "decoded_value": decode_bytes(data, str(decoder)),
                "classification": evidence_class(sym),
            }
        )
    return {
        "snapshot_path": snapshot_path,
        "summary": {
            "snapshot_bytes": len(memory),
            "decoded_symbols": len(decoded),
            "unknown_symbols_missing_bytes": len(unknown),
        },
        "Verified": [item for item in decoded if item["classification"] == "Verified"],
        "Inferred": [item for item in decoded if item["classification"] == "Inferred"],
        "Unknown": unknown + [item for item in decoded if item["classification"] == "Unknown"],
        "Assumption": [item for item in decoded if item["classification"] == "Assumption"],
        "decoded": decoded,
    }


def load_graph() -> list[dict[str, Any]]:
    try:
        data = json.loads(GRAPH_PATH.read_text(encoding="utf-8"))
    except FileNotFoundError:
        raise ToolError(f"evidence graph missing: {GRAPH_PATH}")
    entities = data.get("entities", [])
    if not isinstance(entities, list):
        raise ToolError("evidence_graph.json must contain an entities array")
    return entities


def query_evidence_graph(query: str) -> dict[str, Any]:
    q = str(query).strip().lower()
    matches = []
    for entity in load_graph():
        hay = " ".join([str(entity.get("id", "")), str(entity.get("summary", "")), *[str(n) for n in entity.get("names", [])]]).lower()
        if q in hay or hay in q:
            matches.append(entity)
    if not matches:
        sym = find_symbol(query)
        if sym:
            matches.append(
                {
                    "id": sym.get("name"),
                    "type": sym.get("category", "symbol"),
                    "names": symbol_names(sym),
                    "confidence": sym.get("confidence", "Low"),
                    "evidence_class": evidence_class(sym),
                    "summary": sym.get("notes", ""),
                    "related_opcodes": [],
                    "related_functions": sym.get("related_functions", []),
                    "related_memory_symbols": [sym.get("name")],
                    "related_evidence_files": [sym.get("source_file")],
                    "unknowns": ["No direct evidence graph entity matched; result was resolved through symbols.json."],
                    "assumptions": ["Symbol match does not prove runtime relevance."],
                }
            )
    return {
        "query": query,
        "matching_entities": matches,
        "summary": {"match_count": len(matches)},
        "Verified": [m for m in matches if m.get("evidence_class") == "Verified"],
        "Inferred": [m for m in matches if m.get("evidence_class") == "Inferred"],
        "Unknown": [m for m in matches if m.get("evidence_class") == "Unknown"],
        "Assumption": [m for m in matches if m.get("assumptions")],
    }


def utc_now() -> str:
    return datetime.now(timezone.utc).isoformat(timespec="seconds")


def source_meta(source: str, validation: str, reliability: str, confidence: str, notes: str | None = None) -> dict[str, Any]:
    meta: dict[str, Any] = {
        "source": source,
        "validation": validation,
        "reliability": reliability,
        "confidence": confidence,
    }
    if notes:
        meta["notes"] = notes
    return meta


def get_recent_commits(limit: int = 10) -> list[dict[str, Any]]:
    proc = subprocess.run(
        ["git", "log", f"-{int(limit)}", "--pretty=format:%h%x09%cs%x09%s"],
        cwd=ROOT,
        capture_output=True,
        text=True,
    )
    if proc.returncode != 0:
        return [{"Unknown": proc.stderr.strip() or proc.stdout.strip()}]
    commits = []
    for line in proc.stdout.splitlines():
        sha, date, subject = (line.split("\t", 2) + ["", ""])[:3]
        commits.append({"commit": sha, "date": date, "subject": subject})
    return commits


def validate_re_evidence(evidence: list[Any], platform: str = "Unknown", confidence: str = "Unknown", proposed_change: str | None = None) -> dict[str, Any]:
    missing = []
    if not evidence:
        missing.append("No evidence supplied.")
    if proposed_change:
        needed = ["exact packet number", "opcode", "expected client state transition", "rollback plan"]
        text = json.dumps(evidence).lower()
        missing.extend([item for item in needed if item not in text])
    return {
        "usable": bool(evidence) and not missing,
        "platform": platform,
        "confidence": confidence,
        "proposed_change": proposed_change,
        "missing_evidence": missing,
        "rules": [
            "Emulator-only success does not prove real PS2 success.",
            "Medium/Low confidence requires second_opinion before server code edits.",
        ],
    }


def ghidra_ps2_plugin_status() -> dict[str, Any]:
    roots = [ROOT / "vendor", ROOT / "tools", ROOT / "scripts", ROOT / "docs" / "reverse-engineering"]
    matches = []
    for root in roots:
        if not root.exists():
            continue
        for path in root.rglob("*"):
            if not path.is_file():
                continue
            name = path.name.lower()
            if any(token in name for token in ["r5900", "emotion", "ee", "ghidra_ps2", "ps2"]):
                matches.append(str(path.relative_to(ROOT)))
                if len(matches) >= 50:
                    break
        if len(matches) >= 50:
            break
    return {
        "ghidra_mcp_reachable": "Unknown",
        "current_program_appears_ps2_ee_r5900": "Unknown",
        "ps2_emotion_engine_processor_support_active": "Unknown",
        "plugin_support_files_present": bool(matches),
        "detected_files": matches,
        "manual_setup_needed": "Unknown until Ghidra MCP/program context is available." if matches else "Likely: no local support files detected by filename scan.",
        "notes": ["This tool does not modify Ghidra project files."],
    }


def tool_path_from_config(value: str, default: Path) -> Path:
    if not value:
        return default
    path = Path(value)
    if path.is_absolute():
        return path
    return ROOT / path


def read_openai_config() -> dict[str, Any]:
    if not OPENAI_CONFIG_PATH.exists():
        raise ToolError(f"OpenAI config is missing: {OPENAI_CONFIG_PATH}")
    try:
        with OPENAI_CONFIG_PATH.open("r", encoding="utf-8") as fh:
            return json.load(fh)
    except json.JSONDecodeError as exc:
        raise ToolError(f"OpenAI config is invalid JSON: {exc}") from exc


def append_jsonl(path: Path, entry: dict[str, Any]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("a", encoding="utf-8") as fh:
        fh.write(json.dumps(entry, separators=(",", ":"), ensure_ascii=False) + "\n")


def redact_secrets(text: str) -> str:
    return re.sub(r"sk-[A-Za-z0-9_\-]+", "sk-REDACTED", text)


def openai_log_paths(config: dict[str, Any]) -> tuple[Path, Path]:
    usage_log = tool_path_from_config(
        str(config.get("usage_log") or ""),
        TOOL_DIR / "logs" / "openai_usage.jsonl",
    )
    error_log = tool_path_from_config(
        str(config.get("error_log") or ""),
        TOOL_DIR / "logs" / "openai_errors.jsonl",
    )
    return usage_log, error_log


def estimate_tokens(text: str) -> int:
    return max(1, (len(text) + 3) // 4)


def openai_pricing(config: dict[str, Any]) -> tuple[float, float]:
    pricing = config.get("estimated_cost_per_1m_tokens") or {}
    input_cost = float(pricing.get("input_usd") or 0.15)
    output_cost = float(pricing.get("output_usd") or 0.60)
    return input_cost, output_cost


def estimate_openai_spend_usd(config: dict[str, Any], prompt: str) -> dict[str, Any]:
    max_output_tokens = int(config.get("max_output_tokens") or 600)
    input_tokens = estimate_tokens(prompt)
    input_per_1m, output_per_1m = openai_pricing(config)
    estimate = (input_tokens / 1_000_000 * input_per_1m) + (max_output_tokens / 1_000_000 * output_per_1m)
    return {
        "input_tokens_estimate": input_tokens,
        "max_output_tokens": max_output_tokens,
        "estimated_cost_usd": round(estimate, 8),
    }


def openai_usage_total(path: Path) -> float:
    if not path.exists():
        return 0.0
    total = 0.0
    with path.open("r", encoding="utf-8") as fh:
        for line in fh:
            line = line.strip()
            if not line:
                continue
            try:
                entry = json.loads(line)
            except json.JSONDecodeError:
                continue
            total += float(entry.get("estimated_cost_usd") or 0.0)
            total += float(entry.get("actual_cost_usd") or 0.0)
    return total


def get_openai_api_key() -> str | None:
    key = os.environ.get("OPENAI_API_KEY")
    if key:
        return key
    if os.name != "nt":
        return None
    try:
        import winreg

        with winreg.OpenKey(winreg.HKEY_CURRENT_USER, "Environment") as env_key:
            value, _ = winreg.QueryValueEx(env_key, "OPENAI_API_KEY")
            return value if value else None
    except OSError:
        return None


def second_opinion_refusal(reason: str, notes: list[str] | None = None) -> dict[str, Any]:
    return {
        "agreement": "InsufficientEvidence",
        "confidence": "Low",
        "unsupported_assumptions": [],
        "alternative_explanations": [],
        "missing_evidence": [],
        "recommended_next_observation": "Resolve the tool configuration issue, then rerun second_opinion with the same structured evidence.",
        "notes": [reason] + (notes or []),
        "source_metadata": source_meta("OpenAI", "refused", "Low", "Low"),
    }


def second_opinion_prompt(hypothesis: str, confidence: str, evidence: list[Any], question: str) -> str:
    payload = {
        "role": "evidence_review",
        "rules": [
            "Never invent evidence.",
            "Separate facts from assumptions.",
            "Challenge the hypothesis.",
            "Suggest one next observation.",
            "Never recommend protocol/server changes without supporting evidence.",
            "Return only strict JSON with the requested schema.",
        ],
        "schema": {
            "agreement": "Agree|Partial|Disagree|InsufficientEvidence",
            "confidence": "Low|Medium|High",
            "unsupported_assumptions": ["string"],
            "alternative_explanations": ["string"],
            "missing_evidence": ["string"],
            "recommended_next_observation": "string",
            "notes": ["string"],
        },
        "hypothesis": hypothesis,
        "hypothesis_confidence": confidence,
        "evidence": evidence,
        "question": question,
    }
    return json.dumps(payload, indent=2, ensure_ascii=False)


def extract_response_text(response: dict[str, Any]) -> str:
    if isinstance(response.get("output_text"), str):
        return response["output_text"]
    parts: list[str] = []
    for item in response.get("output") or []:
        for content in item.get("content") or []:
            text = content.get("text")
            if isinstance(text, str):
                parts.append(text)
    return "\n".join(parts)


def parse_second_opinion_json(text: str) -> dict[str, Any]:
    stripped = text.strip()
    if stripped.startswith("```"):
        stripped = re.sub(r"^```(?:json)?\s*", "", stripped)
        stripped = re.sub(r"\s*```$", "", stripped)
    try:
        data = json.loads(stripped)
    except json.JSONDecodeError as exc:
        raise ToolError(f"OpenAI response was not valid JSON: {exc}") from exc
    required = [
        "agreement",
        "confidence",
        "unsupported_assumptions",
        "alternative_explanations",
        "missing_evidence",
        "recommended_next_observation",
        "notes",
    ]
    missing = [key for key in required if key not in data]
    if missing:
        raise ToolError(f"OpenAI response JSON is missing required fields: {', '.join(missing)}")
    return data


def second_opinion(hypothesis: str, confidence: str, evidence: list[Any], question: str) -> dict[str, Any]:
    config = read_openai_config()
    usage_log, error_log = openai_log_paths(config)
    prompt = second_opinion_prompt(hypothesis, confidence, evidence, question)
    estimate = estimate_openai_spend_usd(config, prompt)
    base_log = {
        "timestamp": utc_now(),
        "tool": "second_opinion",
        "model": config.get("model", "gpt-5.4-mini"),
        **estimate,
    }

    if not bool(config.get("enabled", False)):
        append_jsonl(usage_log, {**base_log, "status": "refused_disabled"})
        return second_opinion_refusal("OpenAI consultation is disabled in tools/outbreak_mcp/openai.json.")

    api_key = get_openai_api_key()
    if not api_key:
        append_jsonl(usage_log, {**base_log, "status": "refused_missing_api_key"})
        return second_opinion_refusal("OPENAI_API_KEY is missing from the user environment.")

    used = openai_usage_total(usage_log)
    stop_at = float(config.get("stop_at_usd") or config.get("monthly_budget_usd") or 0.0)
    if stop_at and used + float(estimate["estimated_cost_usd"]) > stop_at:
        append_jsonl(usage_log, {**base_log, "status": "refused_budget", "usage_total_usd": round(used, 8)})
        return second_opinion_refusal(
            "Configured OpenAI budget would be exceeded.",
            [f"usage_total_usd={used:.8f}", f"stop_at_usd={stop_at:.8f}"],
        )

    request_body = {
        "model": config.get("model", "gpt-5.4-mini"),
        "input": prompt,
        "max_output_tokens": int(config.get("max_output_tokens") or 600),
        "text": {"format": {"type": "json_object"}},
    }
    endpoint = str(config.get("endpoint") or "https://api.openai.com/v1/responses")
    timeout_seconds = int(config.get("timeout_seconds") or 30)
    req = urllib.request.Request(
        endpoint,
        data=json.dumps(request_body).encode("utf-8"),
        headers={
            "Authorization": f"Bearer {api_key}",
            "Content-Type": "application/json",
        },
        method="POST",
    )
    try:
        with urllib.request.urlopen(req, timeout=timeout_seconds) as response:
            response_body = response.read().decode("utf-8")
    except urllib.error.HTTPError as exc:
        body = exc.read().decode("utf-8", errors="replace")
        append_jsonl(usage_log, {**base_log, "status": "api_error", "http_status": exc.code})
        append_jsonl(error_log, {"timestamp": base_log["timestamp"], "tool": "second_opinion", "http_status": exc.code, "error": redact_secrets(body)[:1000]})
        return second_opinion_refusal(f"OpenAI API returned HTTP {exc.code}.", ["See configured error log for sanitized details."])
    except urllib.error.URLError as exc:
        append_jsonl(usage_log, {**base_log, "status": "transport_error"})
        reason = redact_secrets(str(exc.reason))
        append_jsonl(error_log, {"timestamp": base_log["timestamp"], "tool": "second_opinion", "error": reason[:1000]})
        return second_opinion_refusal("OpenAI API request failed before a response was received.", [reason])

    try:
        parsed_response = json.loads(response_body)
        opinion = parse_second_opinion_json(extract_response_text(parsed_response))
    except (json.JSONDecodeError, ToolError) as exc:
        append_jsonl(usage_log, {**base_log, "status": "invalid_response"})
        error = redact_secrets(str(exc))
        append_jsonl(error_log, {"timestamp": base_log["timestamp"], "tool": "second_opinion", "error": error[:1000]})
        return second_opinion_refusal("OpenAI response could not be parsed as the required JSON schema.", [error])

    append_jsonl(usage_log, {**base_log, "status": "ok", "usage_total_usd_before": round(used, 8)})
    opinion["source_metadata"] = source_meta("OpenAI", "passed", "Medium", str(opinion.get("confidence", "Low")))
    return opinion


def record_runtime_health(component: str, passed: bool, reason: str) -> dict[str, Any]:
    key = component.lower()
    if passed:
        RUNTIME_FAILURES[key] = 0
    else:
        RUNTIME_FAILURES[key] = RUNTIME_FAILURES.get(key, 0) + 1
        if RUNTIME_FAILURES[key] >= 2:
            RUNTIME_DISABLED.add(key)
    return {
        "component": component,
        "passed": passed,
        "failure_count": RUNTIME_FAILURES.get(key, 0),
        "disabled": key in RUNTIME_DISABLED,
        "reason": reason,
    }


def runtime_disabled(component: str) -> bool:
    return component.lower() in RUNTIME_DISABLED


def unavailable_component(component: str, reason: str) -> dict[str, Any]:
    return {
        "status": "Unavailable",
        "Verified": [],
        "Inferred": [],
        "Unknown": [reason],
        "Assumption": [],
        "source_metadata": source_meta(component, "failed", "None", "High", reason),
        "failure_policy": record_runtime_health(component, False, reason),
    }


class PineProbe:
    def __init__(self, host: str = PINE_DEFAULT_HOST, port: int = PINE_DEFAULT_PORT, timeout: float = 1.5):
        self.host = host
        self.port = int(port)
        self.timeout = timeout
        self.sock: socket.socket | None = None

    def __enter__(self) -> "PineProbe":
        self.sock = socket.create_connection((self.host, self.port), timeout=self.timeout)
        self.sock.settimeout(self.timeout)
        return self

    def __exit__(self, _exc_type: Any, _exc: Any, _tb: Any) -> None:
        if self.sock:
            try:
                self.sock.close()
            except OSError:
                pass

    def command(self, opcode: int, payload: bytes = b"") -> bytes:
        if self.sock is None:
            raise ToolError("PINE socket is not connected")
        body = bytes([opcode]) + payload
        self.sock.sendall((len(body) + 4).to_bytes(4, "little") + body)
        header = self._recv_exact(4)
        total = int.from_bytes(header, "little")
        frame = self._recv_exact(total - 4)
        if not frame or frame[0] != 0:
            raise ToolError(f"PINE opcode 0x{opcode:02x} failed")
        return frame[1:]

    def _recv_exact(self, size: int) -> bytes:
        if self.sock is None:
            raise ToolError("PINE socket is not connected")
        buf = bytearray()
        while len(buf) < size:
            chunk = self.sock.recv(size - len(buf))
            if not chunk:
                raise ToolError("PINE socket closed before reply completed")
            buf.extend(chunk)
        return bytes(buf)

    def status(self) -> dict[str, Any]:
        payload = self.command(0x0F)
        code = int.from_bytes(payload[:4], "little")
        return {"code": code, "name": {0: "Running", 1: "Paused", 2: "Shutdown"}.get(code, f"Unknown({code})")}

    def read32(self, address: int) -> int:
        payload = self.command(0x02, int(address).to_bytes(4, "little"))
        return int.from_bytes(payload[:4], "little")

    def string_command(self, opcode: int) -> str:
        payload = self.command(opcode)
        return payload.split(b"\x00", 1)[0].decode("utf-8", errors="replace")


def parse_address_value(value: str) -> int | None:
    try:
        text = str(value).strip().lower()
        if text.startswith("0x"):
            return int(text, 16)
        if re.fullmatch(r"[0-9a-f]+", text):
            return int(text, 16)
    except ValueError:
        return None
    return None


def resolved_symbol_address(name: str) -> int | None:
    resolved = resolve_symbol(name)
    address = resolved.get("address")
    if isinstance(address, str) and address.startswith("0x"):
        return int(address, 16)
    return None


def pine_health_check(
    host: str = PINE_DEFAULT_HOST,
    port: int = PINE_DEFAULT_PORT,
    known_address: str = "0x0029f280",
    known_symbol: str = "conn.pointer",
) -> dict[str, Any]:
    if runtime_disabled("PINE"):
        return unavailable_component("PINE", "PINE collection is disabled for this MCP session after repeated failures.")
    checks: list[dict[str, Any]] = []
    unknown: list[str] = []
    verified: list[str] = []
    try:
        address = parse_address_value(known_address)
        if address is None:
            raise ToolError(f"invalid known_address: {known_address}")
        symbol_addr = resolved_symbol_address(known_symbol)
        with PineProbe(host, int(port)) as pine:
            status = pine.status()
            checks.append({"name": "emulator_reachable", "classification": "Verified", "status": status})
            verified.append("PINE socket accepted status request.")
            value = pine.read32(address)
            checks.append(
                {
                    "name": "known_address_readable",
                    "classification": "Verified",
                    "address": f"0x{address:08x}",
                    "value": f"0x{value:08x}",
                    "plausible": True,
                }
            )
            if symbol_addr is None:
                unknown.append(f"Symbol {known_symbol} did not resolve to an address.")
            else:
                symbol_value = pine.read32(symbol_addr)
                checks.append(
                    {
                        "name": "known_symbol_readable",
                        "classification": "Verified",
                        "symbol": known_symbol,
                        "address": f"0x{symbol_addr:08x}",
                        "value": f"0x{symbol_value:08x}",
                        "plausible": symbol_value != 0xFFFFFFFF,
                    }
                )
        policy = record_runtime_health("PINE", True, "PINE status and reads succeeded.")
        return {
            "status": "Healthy",
            "host": host,
            "port": port,
            "checks": checks,
            "Verified": verified,
            "Inferred": [],
            "Unknown": unknown,
            "Assumption": ["Known address plausibility only proves PINE read mechanics, not protocol meaning."],
            "source_metadata": source_meta("PINE", "passed", "Medium", "High"),
            "failure_policy": policy,
        }
    except (OSError, ToolError, TimeoutError) as exc:
        reason = f"PINE health check failed: {exc}"
        policy = record_runtime_health("PINE", False, reason)
        return {
            "status": "Failed",
            "host": host,
            "port": port,
            "checks": checks,
            "Verified": verified,
            "Inferred": [],
            "Unknown": [reason],
            "Assumption": [],
            "source_metadata": source_meta("PINE", "failed", "None", "High", reason),
            "failure_policy": policy,
        }


def latest_file(patterns: list[str], roots: list[Path]) -> str | None:
    matches: list[Path] = []
    for root in roots:
        if not root.exists():
            continue
        for pattern in patterns:
            matches.extend(p for p in root.rglob(pattern) if p.is_file())
    if not matches:
        return None
    matches.sort(key=lambda p: p.stat().st_mtime, reverse=True)
    return str(matches[0])


def latest_pcap_path() -> str | None:
    return latest_file(["*.pcap", "*.pcapng"], [ROOT / "docs" / "evidence", ROOT / "tests" / "results", ROOT / "captures"])


REGISTER_INTEREST = ["a0", "v1", "s0", "s2", "pc", "ra", "sp"]


TOOLS: dict[str, dict[str, Any]] = {
    "rig_doctor": {
        "description": "Health-check the PCSX2+PINE rig: process/window, PINE listener, auto-clear zombie clients, then a real PINE read + screen-state decode. Run before trusting the rig.",
        "inputSchema": {"type": "object", "properties": {}},
    },
    "rig_launch": {
        "description": "Bring up a clean, persistent, PINE-able PCSX2: kills stale instances/zombies/vpad daemon, launches detached via a clean-named ISO hardlink, polls until PINE binds and the game window boots. Takes ~60-120s.",
        "inputSchema": {"type": "object", "properties": {}},
    },
    "create_dump": {
        "description": "Labeled PINE dump of create/scenario memory (screen-state, area +0x03 scenario bitmask, 0x341ac8 per-group table, 0x6c4bac scenario array). Meaningful at the in-area lobby / create RULE screen.",
        "inputSchema": {"type": "object", "properties": {}},
    },
    "kaitai_compile": {
        "description": "Compile a Kaitai .ksy wire spec to a parser (validates the spec + generates code). Default ksy=docs/specs/kaitai/pal_app_frame.ksy, target=javascript.",
        "inputSchema": {
            "type": "object",
            "properties": {
                "ksy_path": {"type": "string"},
                "target": {"type": "string", "default": "javascript"},
            },
        },
    },
    "install_lua_dissector": {
        "description": "Install the PAL SN@P Wireshark Lua dissector (tools/wireshark/pal_snap.lua) into the Wireshark personal plugins dir so captures render decoded fields.",
        "inputSchema": {"type": "object", "properties": {}},
    },
    "pcap_timeline": {
        "description": "Build an ordered UDP/SN@P packet timeline from a pcap using tshark.",
        "inputSchema": {
            "type": "object",
            "properties": {
                "pcap_path": {"type": "string"},
                "udp_port": {"type": "integer", "default": 9090},
            },
            "required": ["pcap_path"],
        },
    },
    "extract_opcode_packets": {
        "description": "Extract UDP packets whose SN@P header opcode matches a hex opcode.",
        "inputSchema": {
            "type": "object",
            "properties": {
                "pcap_path": {"type": "string"},
                "opcode": {"type": "string"},
                "udp_port": {"type": "integer", "default": 9090},
            },
            "required": ["pcap_path", "opcode"],
        },
    },
    "compare_snapshots": {
        "description": "Compare two text memory snapshots and report changed offsets and regions.",
        "inputSchema": {
            "type": "object",
            "properties": {
                "baseline_snapshot_path": {"type": "string"},
                "state_snapshot_path": {"type": "string"},
            },
            "required": ["baseline_snapshot_path", "state_snapshot_path"],
        },
    },
    "decode_snapshot_symbols": {
        "description": "Decode known typed fields from a text snapshot using symbols.json.",
        "inputSchema": {
            "type": "object",
            "properties": {"snapshot_path": {"type": "string"}},
            "required": ["snapshot_path"],
        },
    },
    "resolve_symbol": {
        "description": "Resolve a symbol name or address using tools/outbreak_mcp/symbols.json.",
        "inputSchema": {
            "type": "object",
            "properties": {"name_or_address": {"type": "string"}},
            "required": ["name_or_address"],
        },
    },
    "symbol_audit": {
        "description": "Audit symbols.json for missing confidence, duplicates, unknown aliases, low-confidence references, and typo-prone close addresses.",
        "inputSchema": {
            "type": "object",
            "properties": {
                "category": {"type": "string"},
                "min_confidence": {"type": "string"},
            },
        },
    },
    "query_evidence_graph": {
        "description": "Query the sparse evidence graph for opcodes, functions, memory symbols, evidence files, unknowns, and assumptions.",
        "inputSchema": {
            "type": "object",
            "properties": {"query": {"type": "string"}},
            "required": ["query"],
        },
    },
    "pine_health_check": {
        "description": "Validate PINE reachability and diagnostic reads.",
        "inputSchema": {
            "type": "object",
            "properties": {
                "host": {"type": "string", "default": PINE_DEFAULT_HOST},
                "port": {"type": "integer", "default": PINE_DEFAULT_PORT},
                "known_address": {"type": "string", "default": "0x0029f280"},
                "known_symbol": {"type": "string", "default": "conn.pointer"},
            },
        },
    },
    "second_opinion": {
        "description": "Request a stateless OpenAI-backed evidence review of one hypothesis.",
        "inputSchema": {
            "type": "object",
            "properties": {
                "hypothesis": {"type": "string"},
                "confidence": {"type": "string", "enum": ["Low", "Medium", "High"]},
                "evidence": {"type": "array"},
                "question": {"type": "string"},
            },
            "required": ["hypothesis", "confidence", "evidence", "question"],
        },
    },
    "get_recent_commits": {"description": "Return recent git commits for audit context.", "inputSchema": {"type": "object", "properties": {"limit": {"type": "integer", "default": 10}}}},
    "validate_re_evidence": {
        "description": "Validate whether supplied RE evidence is usable for interpretation or server changes.",
        "inputSchema": {"type": "object", "properties": {"evidence": {"type": "array"}, "platform": {"type": "string", "default": "Unknown"}, "confidence": {"type": "string", "default": "Unknown"}, "proposed_change": {"type": "string"}}, "required": ["evidence"]},
    },
    "ghidra_ps2_plugin_status": {"description": "Report detectable Ghidra PS2/EE/R5900 support status without modifying projects.", "inputSchema": {"type": "object", "properties": {}}},
    "evidence_report": {
        "description": "Generate a Markdown evidence report from packet and optional snapshot inputs.",
        "inputSchema": {
            "type": "object",
            "properties": {
                "pcap_path": {"type": "string"},
                "baseline_snapshot_path": {"type": "string"},
                "state_snapshot_path": {"type": "string"},
                "udp_port": {"type": "integer", "default": 9090},
            },
            "required": ["pcap_path"],
        },
    },
}


def _run_node(script: str, timeout: int = 210) -> str:
    """Run a repo node rig tool (tools/<script>) and return its combined stdout+stderr."""
    p = subprocess.run(["node", str(ROOT / "tools" / script)], capture_output=True, text=True,
                        timeout=timeout, cwd=str(ROOT))
    return (p.stdout + p.stderr).strip() or f"(no output, exit {p.returncode})"


def _kaitai_compile(ksy_path: str = "docs/specs/kaitai/pal_app_frame.ksy", target: str = "javascript") -> str:
    """Compile a .ksy spec (validates it + generates a parser) via the local kaitai-struct-compiler."""
    bat = ROOT / "vendor" / "kaitai" / "kaitai-struct-compiler-0.10" / "bin" / "kaitai-struct-compiler.bat"
    if not bat.exists():
        return "kaitai-struct-compiler not installed — see docs/specs/kaitai/README.md"
    outdir = ROOT / "docs" / "specs" / "kaitai" / "generated"
    p = subprocess.run(["cmd", "/c", str(bat), "--target", target, str(ROOT / ksy_path), "--outdir", str(outdir)],
                       capture_output=True, text=True, timeout=120, cwd=str(ROOT))
    out = (p.stdout + p.stderr).strip()
    return f"exit {p.returncode}\n" + (out or f"(clean compile; parser in {outdir})")


def _install_lua_dissector() -> str:
    """Copy the SN@P Wireshark Lua dissector into the personal plugins dir."""
    src = ROOT / "tools" / "wireshark" / "pal_snap.lua"
    ps_cmd = ("$d=$env:APPDATA+'\\Wireshark\\plugins'; New-Item -ItemType Directory -Force -Path $d | Out-Null; "
              f"Copy-Item -Force '{src}' $d; 'installed -> ' + $d + '\\pal_snap.lua (restart Wireshark to load)'")
    p = subprocess.run(["powershell", "-NoProfile", "-Command", ps_cmd], capture_output=True, text=True, timeout=30)
    return (p.stdout + p.stderr).strip()


def call_tool(name: str, args: dict[str, Any]) -> Any:
    if name == "rig_doctor":
        return _run_node("rig-doctor.js")
    if name == "rig_launch":
        return _run_node("rig-launch.js")
    if name == "create_dump":
        return _run_node("create-dump.js")
    if name == "kaitai_compile":
        return _kaitai_compile(args.get("ksy_path", "docs/specs/kaitai/pal_app_frame.ksy"), args.get("target", "javascript"))
    if name == "install_lua_dissector":
        return _install_lua_dissector()
    if name == "pcap_timeline":
        return pcap_timeline(args["pcap_path"], int(args.get("udp_port", 9090)))
    if name == "extract_opcode_packets":
        return extract_opcode_packets(args["pcap_path"], args["opcode"], int(args.get("udp_port", 9090)))
    if name == "compare_snapshots":
        return compare_snapshots(args["baseline_snapshot_path"], args["state_snapshot_path"])
    if name == "decode_snapshot_symbols":
        return decode_snapshot_symbols(args["snapshot_path"])
    if name == "resolve_symbol":
        return resolve_symbol(args["name_or_address"])
    if name == "symbol_audit":
        return symbol_audit(args.get("category"), args.get("min_confidence"))
    if name == "query_evidence_graph":
        return query_evidence_graph(args["query"])
    if name == "pine_health_check":
        return pine_health_check(
            args.get("host", PINE_DEFAULT_HOST),
            int(args.get("port", PINE_DEFAULT_PORT)),
            args.get("known_address", "0x0029f280"),
            args.get("known_symbol", "conn.pointer"),
        )
    if name == "second_opinion":
        return second_opinion(
            args["hypothesis"],
            args["confidence"],
            args["evidence"],
            args["question"],
        )
    if name == "get_recent_commits":
        return get_recent_commits(int(args.get("limit", 10)))
    if name == "validate_re_evidence":
        return validate_re_evidence(args["evidence"], args.get("platform", "Unknown"), args.get("confidence", "Unknown"), args.get("proposed_change"))
    if name == "ghidra_ps2_plugin_status":
        return ghidra_ps2_plugin_status()
    if name == "evidence_report":
        return evidence_report(
            args["pcap_path"],
            args.get("baseline_snapshot_path"),
            args.get("state_snapshot_path"),
            int(args.get("udp_port", 9090)),
        )
    raise ToolError(f"unknown tool: {name}")


# Stdio framing mode, decided from the first line the client sends:
#   "ndjson" = newline-delimited JSON-RPC (the MCP stdio standard; Claude Code uses this)
#   "lsp"    = LSP-style Content-Length headers (kept for backward compatibility / CLI tests)
# Detected on read, mirrored on write. Defaults to ndjson (the MCP standard).
_framing_mode: str | None = None


def read_message() -> dict[str, Any] | None:
    global _framing_mode
    while True:
        line = sys.stdin.buffer.readline()
        if line == b"":
            return None
        stripped = line.strip()
        if not stripped:
            # Blank separator line between messages: ignore and keep reading.
            continue
        if stripped[:1] in (b"{", b"["):
            # Newline-delimited JSON-RPC (MCP stdio standard). One message per line.
            _framing_mode = "ndjson"
            return json.loads(stripped.decode("utf-8"))
        # Otherwise this line begins an LSP-style Content-Length header block.
        _framing_mode = "lsp"
        headers: dict[str, str] = {}
        cur = stripped
        while cur:
            key, _, value = cur.decode("ascii", errors="replace").partition(":")
            headers[key.lower()] = value.strip()
            nxt = sys.stdin.buffer.readline()
            if nxt == b"":
                return None
            cur = nxt.strip()
        length = int(headers.get("content-length", "0"))
        if length <= 0:
            return None
        body = sys.stdin.buffer.read(length)
        return json.loads(body.decode("utf-8"))


def write_message(message: dict[str, Any]) -> None:
    body = json.dumps(message, separators=(",", ":"), ensure_ascii=False).encode("utf-8")
    if _framing_mode == "lsp":
        sys.stdout.buffer.write(f"Content-Length: {len(body)}\r\n\r\n".encode("ascii"))
        sys.stdout.buffer.write(body)
    else:
        # Newline-delimited JSON-RPC (MCP stdio standard; default).
        sys.stdout.buffer.write(body + b"\n")
    sys.stdout.buffer.flush()


def result_response(msg_id: Any, result: Any) -> dict[str, Any]:
    return {"jsonrpc": "2.0", "id": msg_id, "result": result}


def error_response(msg_id: Any, code: int, message: str) -> dict[str, Any]:
    return {"jsonrpc": "2.0", "id": msg_id, "error": {"code": code, "message": message}}


def run_mcp() -> None:
    while True:
        msg = read_message()
        if msg is None:
            return
        msg_id = msg.get("id")
        method = msg.get("method")
        try:
            if method == "initialize":
                write_message(
                    result_response(
                        msg_id,
                        {
                            "protocolVersion": "2024-11-05",
                            "capabilities": {"tools": {}},
                            "serverInfo": {"name": "outbreak-tools", "version": "0.1.0"},
                        },
                    )
                )
            elif method == "notifications/initialized":
                continue
            elif method == "tools/list":
                write_message(
                    result_response(
                        msg_id,
                        {"tools": [{"name": name, **meta} for name, meta in TOOLS.items()]},
                    )
                )
            elif method == "tools/call":
                params = msg.get("params") or {}
                output = call_tool(params.get("name", ""), params.get("arguments") or {})
                text = output if isinstance(output, str) else json.dumps(output, indent=2, ensure_ascii=False)
                write_message(result_response(msg_id, {"content": [{"type": "text", "text": text}]}))
            else:
                write_message(error_response(msg_id, -32601, f"method not found: {method}"))
        except ToolError as exc:
            write_message(error_response(msg_id, -32000, str(exc)))
        except Exception as exc:  # Keep MCP failures explicit rather than silent.
            write_message(error_response(msg_id, -32001, f"{type(exc).__name__}: {exc}"))


def main() -> int:
    parser = argparse.ArgumentParser(description="outbreak-tools MCP server")
    sub = parser.add_subparsers(dest="command")
    call = sub.add_parser("call", help="call a tool directly for local testing")
    call.add_argument("tool")
    call.add_argument("arguments_json")
    sub.add_parser("list-tools", help="list available tools")
    args = parser.parse_args()

    if args.command == "list-tools":
        print(json.dumps({"tools": [{"name": name, **meta} for name, meta in TOOLS.items()]}, indent=2))
        return 0
    if args.command == "call":
        try:
            result = call_tool(args.tool, json.loads(args.arguments_json))
        except ToolError as exc:
            print(f"error: {exc}", file=sys.stderr)
            return 2
        print(result if isinstance(result, str) else json.dumps(result, indent=2, ensure_ascii=False))
        return 0
    run_mcp()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
