import assert from 'node:assert/strict';
import test from 'node:test';

import { CONNECTION_PURPOSE, LobbyArmingRegistry } from '../src/sessions/lobby-arming.js';

function fixedClock() {
  const state = { now: 1_000 };
  return {
    state,
    clock: () => state.now,
    advance: (ms) => { state.now += ms; }
  };
}

test('an unarmed address is a boot-auth connection', () => {
  const registry = new LobbyArmingRegistry();
  assert.equal(registry.resolvePurpose('192.0.2.248'), CONNECTION_PURPOSE.BOOT_AUTH);
  assert.equal(registry.isArmed('192.0.2.248'), false);
});

test('a completed lbs.jsp arms the address for the lobby transcript', () => {
  const registry = new LobbyArmingRegistry();
  registry.arm('192.0.2.248', { sessionConnectionId: 's1', userid: 'player1' });
  assert.equal(registry.isArmed('192.0.2.248'), true);
  assert.equal(registry.resolvePurpose('192.0.2.248'), CONNECTION_PURPOSE.LOBBY);
  // Another address is unaffected.
  assert.equal(registry.resolvePurpose('192.0.2.249'), CONNECTION_PURPOSE.BOOT_AUTH);
});

test('an arming lapses back to boot auth after its lifetime', () => {
  const { clock, advance } = fixedClock();
  const registry = new LobbyArmingRegistry({ clock, ttlMs: 1_000 });
  registry.arm('10.0.0.5');
  assert.equal(registry.resolvePurpose('10.0.0.5'), CONNECTION_PURPOSE.LOBBY);
  advance(1_001);
  assert.equal(registry.resolvePurpose('10.0.0.5'), CONNECTION_PURPOSE.BOOT_AUTH);
  // The lapsed entry is dropped rather than lingering.
  assert.equal(registry.size, 0);
});

test('re-arming refreshes the lifetime', () => {
  const { clock, advance } = fixedClock();
  const registry = new LobbyArmingRegistry({ clock, ttlMs: 1_000 });
  registry.arm('10.0.0.5');
  advance(900);
  registry.arm('10.0.0.5');
  advance(900);
  assert.equal(registry.resolvePurpose('10.0.0.5'), CONNECTION_PURPOSE.LOBBY);
});

test('disarming returns the address to boot auth immediately', () => {
  const registry = new LobbyArmingRegistry();
  registry.arm('10.0.0.5');
  assert.equal(registry.disarm('10.0.0.5'), true);
  assert.equal(registry.resolvePurpose('10.0.0.5'), CONNECTION_PURPOSE.BOOT_AUTH);
});

test('the registry is bounded and sheds rather than growing without limit', () => {
  const { clock } = fixedClock();
  const registry = new LobbyArmingRegistry({ clock, maxEntries: 2 });
  assert.notEqual(registry.arm('10.0.0.1'), null);
  assert.notEqual(registry.arm('10.0.0.2'), null);
  // Refused, and the refused address stays on the safe boot-auth transcript.
  assert.equal(registry.arm('10.0.0.3'), null);
  assert.equal(registry.size, 2);
  assert.equal(registry.resolvePurpose('10.0.0.3'), CONNECTION_PURPOSE.BOOT_AUTH);
  // An existing address can still refresh even at capacity.
  assert.notEqual(registry.arm('10.0.0.1'), null);
});

test('ignores empty or non-string addresses instead of arming something useless', () => {
  const registry = new LobbyArmingRegistry();
  assert.equal(registry.arm(''), null);
  assert.equal(registry.arm(undefined), null);
  assert.equal(registry.isArmed(''), false);
  assert.equal(registry.isArmed(null), false);
  assert.equal(registry.size, 0);
});

test('rejects an unusable configuration rather than defaulting around it', () => {
  assert.throws(() => new LobbyArmingRegistry({ ttlMs: 0 }), TypeError);
  assert.throws(() => new LobbyArmingRegistry({ ttlMs: -1 }), TypeError);
  assert.throws(() => new LobbyArmingRegistry({ maxEntries: 0 }), TypeError);
});

test('an arming does not survive long enough to break a later boot', () => {
  // The D907 regression, reproduced. A player registers, plays, and reboots a
  // few minutes later. The arming must be gone by then, or the fresh boot's
  // BOOT-AUTH connection is handed the lobby challenge and the client refuses
  // it. Observed on 2026-08-04: armed 18:00:48, reboot 18:03:58, D907.
  let now = 1_000_000;
  const registry = new LobbyArmingRegistry({ clock: () => now });

  registry.arm('192.0.2.248', { userid: 'test123' });
  // The lobby connection and its resume both arrive within ~15 s and must be
  // armed.
  now += 15_000;
  assert.equal(registry.resolvePurpose('192.0.2.248'), CONNECTION_PURPOSE.LOBBY);

  // Three minutes later, a reboot. Boot auth must NOT get the lobby transcript.
  now += 3 * 60 * 1000;
  assert.equal(
    registry.resolvePurpose('192.0.2.248'),
    CONNECTION_PURPOSE.BOOT_AUTH,
    'a stale arming would present the lobby challenge to a boot-auth connection'
  );
});

test('DNAS clears an arming, because DNAS precedes boot auth', () => {
  const registry = new LobbyArmingRegistry();
  registry.arm('192.0.2.248', { userid: 'test123' });
  assert.equal(registry.resolvePurpose('192.0.2.248'), CONNECTION_PURPOSE.LOBBY);

  // A console doing DNAS is starting over.
  assert.equal(registry.disarm('192.0.2.248'), true);
  assert.equal(registry.resolvePurpose('192.0.2.248'), CONNECTION_PURPOSE.BOOT_AUTH);
  // Disarming something unknown is not an error.
  assert.equal(registry.disarm('10.0.0.1'), false);
  assert.equal(registry.disarm(''), false);
});

test('hundreds of concurrent consoles can all be armed at once', () => {
  const registry = new LobbyArmingRegistry();
  for (let index = 0; index < 500; index += 1) {
    const address = `10.${Math.floor(index / 254)}.0.${(index % 254) + 1}`;
    assert.notEqual(registry.arm(address, { userid: `p${index}` }), null, `player ${index}`);
  }
  assert.equal(registry.resolvePurpose('10.0.0.1'), CONNECTION_PURPOSE.LOBBY);
  assert.equal(registry.resolvePurpose('10.1.0.1'), CONNECTION_PURPOSE.LOBBY);
});
