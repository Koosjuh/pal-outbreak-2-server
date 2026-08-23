'use strict';
/**
 * server/engine_adapter.js — the transport adapter for lobby_engine (CONSOLIDATION phase C0).
 *
 * The engine (lobby_engine.js) is transport-agnostic: it mutates lobby_state and returns EMISSION
 * PLANS — arrays of { to: player, kind: vehicle, args }. This module is the ONE place that turns a
 * plan into wire sends, per ROOM-ENGINE-DESIGN-2026-07-17 §4.2:
 *   - resolve each recipient PLAYER to its live transport session(s),
 *   - build the vehicle with a proven builder and send it through the reliable window
 *     (nextTxSeq / sendSnapPacket) so every push rides the selective-ACK/retransmit path,
 *   - a `needs-vehicle:*` kind (or any unmapped kind) is LOGGED and dropped — never silently lost,
 *     so every missing dictionary entry is observable in the journal.
 *
 * It is INJECTABLE (resolveSessions / builders / send / log are passed in) so it unit-tests without a
 * live UDP socket, and so the frontend owns transport (seq, generation echo, multiplex) — the adapter
 * never reaches around it. This module has NO side effects until a frontend constructs an adapter and
 * routes a transition's plan through it (nothing does yet in C0 — zero behavior change).
 */

/**
 * @param {object} deps
 *  - resolveSessions(player) -> array of session objects for that player (0..n; a player may hold
 *    multiple UDP endpoints, or none if not yet bound to a live session).
 *  - builders: { [kind]: (session, args) => Buffer|null }  — proven wire builders per vehicle. A
 *    builder returning null means "nothing to send" (e.g. empty room). Missing kind = needs-vehicle.
 *  - send(session, packet) — deliver one built packet on that session's reliable path.
 *  - log(line) — journal sink (needs-vehicle notices, counts).
 */
function createAdapter({ resolveSessions, builders = {}, send, log = () => {} }) {
  if (typeof resolveSessions !== 'function') throw new Error('engine_adapter: resolveSessions required');
  if (typeof send !== 'function') throw new Error('engine_adapter: send required');

  /**
   * Execute an emission plan. Returns a summary { sent, skippedNoSession, needsVehicle } for logging
   * and assertions. Never throws into the caller: a bad single emission is logged and skipped so one
   * transition can't wedge the handler.
   */
  function execute(plan, label = '') {
    const summary = { sent: 0, skippedNoSession: 0, needsVehicle: 0, byKind: {} };
    if (!Array.isArray(plan) || plan.length === 0) return summary;

    for (const emission of plan) {
      const { to, kind, args } = emission || {};
      if (!to || !kind) continue;
      summary.byKind[kind] = (summary.byKind[kind] || 0) + 1;

      const builder = builders[kind];
      if (typeof builder !== 'function') {
        // Unmapped or needs-vehicle:* — log once per emission, drop. NEVER forward unknown bytes.
        summary.needsVehicle++;
        log(`[engine ${label}] NEEDS-VEHICLE kind=${kind} to=${to.idKey || '?'} (no builder — dropped, journal-visible)`);
        continue;
      }

      const targets = resolveSessions(to) || [];
      if (targets.length === 0) {
        summary.skippedNoSession++;
        log(`[engine ${label}] no live session for ${to.idKey || '?'} (kind=${kind}) — skipped`);
        continue;
      }

      for (const session of targets) {
        let packet;
        try {
          packet = builder(session, args || {});
        } catch (e) {
          log(`[engine ${label}] builder threw for kind=${kind} to=${to.idKey || '?'}: ${e.message}`);
          continue;
        }
        if (!packet) continue;                 // builder chose to send nothing (e.g. empty)
        try {
          send(session, packet);
          summary.sent++;
        } catch (e) {
          log(`[engine ${label}] send failed kind=${kind} to=${to.idKey || '?'}: ${e.message}`);
        }
      }
    }

    if (summary.needsVehicle || summary.skippedNoSession) {
      log(`[engine ${label}] plan done: sent=${summary.sent} needs-vehicle=${summary.needsVehicle} no-session=${summary.skippedNoSession} kinds=${JSON.stringify(summary.byKind)}`);
    }
    return summary;
  }

  return { execute };
}

module.exports = { createAdapter };
