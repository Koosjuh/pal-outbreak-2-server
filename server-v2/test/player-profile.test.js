import assert from 'node:assert/strict';
import test from 'node:test';

import {
  DEFAULT_CHARACTER_STATS_LENGTH,
  PlayerProfileError,
  PlayerProfileRegistry
} from '../src/state/player-profile.js';

/**
 * The identity/attribute half of bioserver's Client (Client.java), keyed on
 * the account session id. The one structural property these tests defend is
 * P2: a profile stores NO location - presence is the single home of WHERE.
 */

function refusalCode(fn) {
  try {
    fn();
  } catch (error) {
    assert.ok(error instanceof PlayerProfileError, `expected a PlayerProfileError, got ${error}`);
    return error.code;
  }
  return assert.fail('expected a refusal');
}

test('a fresh profile carries the bioserver Client defaults', () => {
  const profiles = new PlayerProfileRegistry();
  const profile = profiles.open({ accountSessionId: 'acct-1', handle: 'KOOS' });
  // Client.java constructor: playernum unset (0), host 0, no gamenumber.
  assert.equal(profile.playernum, 0);
  assert.equal(profile.hostflag, 0);
  assert.equal(profile.gamenumber, 0);
  // charstats default to 0xD0 zeros - what op-0x0a ships today (Observation).
  assert.equal(profile.characterStats.length, DEFAULT_CHARACTER_STATS_LENGTH);
  assert.ok(profile.characterStats.every((byte) => byte === 0));
  // The name the roster renders is the login handle, verbatim.
  assert.equal(profile.handle, 'KOOS');
});

test('P2: a profile exposes no location field at all', () => {
  const profiles = new PlayerProfileRegistry();
  const profile = profiles.open({ accountSessionId: 'acct-1', handle: 'KOOS' });
  for (const forbidden of ['boxId', 'roomHandle', 'slot', 'area', 'room', 'serverEntryId', 'location']) {
    assert.equal(
      profile[forbidden],
      undefined,
      `a profile must not carry "${forbidden}"; presence is the single home of location`
    );
  }
});

test('character stats are store-and-echo: a copy in, a copy out', () => {
  const profiles = new PlayerProfileRegistry();
  const profile = profiles.open({ accountSessionId: 'acct-1', handle: 'KOOS' });
  const blob = Buffer.alloc(0xd0, 0x5a);
  profile.setCharacterStats(blob);
  blob.fill(0);                                       // caller mutates its copy
  assert.equal(profile.characterStats[0], 0x5a);      // the store is unaffected
  profile.characterStats.fill(7);                     // reader mutates its copy
  assert.equal(profile.characterStats[0], 0x5a);      // the store is unaffected
});

test('the 0xF0 charstats variant is accepted; empty and oversized blobs are refused', () => {
  const profiles = new PlayerProfileRegistry();
  const profile = profiles.open({ accountSessionId: 'acct-1', handle: 'KOOS' });
  profile.setCharacterStats(Buffer.alloc(0xf0, 1));
  assert.equal(profile.characterStats.length, 0xf0);
  assert.equal(refusalCode(() => profile.setCharacterStats(Buffer.alloc(0))), 'PROFILE_CHARSTATS');
  assert.equal(
    refusalCode(() => profile.setCharacterStats(Buffer.alloc(0x201))), 'PROFILE_CHARSTATS'
  );
  assert.equal(refusalCode(() => profile.setCharacterStats('not a buffer')), 'PROFILE_CHARSTATS');
});

test('attribute setters are bounds-checked', () => {
  const profiles = new PlayerProfileRegistry();
  const profile = profiles.open({ accountSessionId: 'acct-1', handle: 'KOOS' });
  // playernum 0..4 (0 unassigned, 1 host, 2..4 joiners).
  profile.setPlayerNum(4);
  assert.equal(profile.playernum, 4);
  assert.equal(refusalCode(() => profile.setPlayerNum(5)), 'PROFILE_PLAYERNUM');
  assert.equal(refusalCode(() => profile.setPlayerNum(-1)), 'PROFILE_PLAYERNUM');
  profile.setHostFlag(1);
  assert.equal(profile.hostflag, 1);
  assert.equal(refusalCode(() => profile.setHostFlag(2)), 'PROFILE_HOSTFLAG');
  profile.setGameNumber(7);
  assert.equal(profile.gamenumber, 7);
  assert.equal(refusalCode(() => profile.setGameNumber(-1)), 'PROFILE_GAMENUMBER');
});

test('the registry is keyed, bounded and fail-closed', () => {
  const profiles = new PlayerProfileRegistry({ maximumProfiles: 2 });
  profiles.open({ accountSessionId: 'acct-1', handle: 'A' });
  assert.equal(refusalCode(() => profiles.open({ accountSessionId: 'acct-1', handle: 'B' })),
    'PROFILE_DUPLICATE');
  profiles.open({ accountSessionId: 'acct-2', handle: 'B' });
  // Full table refuses the NEW profile; it never evicts a live one.
  assert.equal(refusalCode(() => profiles.open({ accountSessionId: 'acct-3', handle: 'C' })),
    'PROFILE_CAPACITY');
  assert.equal(profiles.get('acct-1').handle, 'A');
  assert.equal(profiles.size, 2);
  assert.equal(profiles.release('acct-1'), true);
  assert.equal(profiles.release('acct-1'), false);
  assert.equal(profiles.get('acct-1'), null);
  assert.equal(refusalCode(() => profiles.open({ accountSessionId: '', handle: 'X' })),
    'PROFILE_KEY');
  assert.equal(refusalCode(() => profiles.open({ accountSessionId: 'acct-4', handle: '' })),
    'PROFILE_HANDLE');
});

test('all() lists live profiles in open order - the relay-scope iteration', () => {
  const profiles = new PlayerProfileRegistry();
  profiles.open({ accountSessionId: 'acct-1', handle: 'A' });
  profiles.open({ accountSessionId: 'acct-2', handle: 'B' });
  profiles.open({ accountSessionId: 'acct-3', handle: 'C' });
  profiles.release('acct-2');
  assert.deepEqual(profiles.all().map((profile) => profile.handle), ['A', 'C']);
});
