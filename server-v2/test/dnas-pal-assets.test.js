import assert from 'node:assert/strict';
import crypto from 'node:crypto';
import test from 'node:test';

import { transformV25Response } from '../src/dnas/application-codec.js';
import { FileDnasPacketStore } from '../src/dnas/packet-store.js';

const packetDirectory = process.env.DNAS_PACKET_DIR;

const I_CONNECT_BODY = Buffer.from(
  'AQgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABDAACAAX0wmzRP7HfVc9WqIfOF4MoO5i4r0kqcXVr6mFa6LkGNyVLKRi0NFMO1WPphtBmSghgBYmh/Gi9vT8fT0Qsdnp0i/BS2kE0Gp66S8wIuIPwAQrKAzuM9xvNwx9ditafzI9hNfJ/cHnQ/KAIg+T1ZKJeFesuW1OHvFpHDY+FjewNP+eFuaV7zXDXyz+AH6OR0nMo15xNhuurTLMXjBqGXXH8Qw94P1wG7N/rb6vpnd96ctKinQ9/J5zyyNQFqv704oN1IWHKL5iTOx3U8gzkYKw4ssAmekH3wux9bOf59+iVhrM2pDcHzs822MCs3hhhj714XrVL/0/cA28qCQMkG4OMaVW74zT/j+Y=',
  'base64'
);

function sha256(value) {
  return crypto.createHash('sha256').update(value).digest('hex');
}

test(
  'external PAL DNAS replay assets match the verified Pi baseline',
  { skip: packetDirectory ? false : 'set DNAS_PACKET_DIR to the external 325-file replay store' },
  async () => {
    const store = new FileDnasPacketStore(packetDirectory);
    const iConnect = await store.get('f4c26cd13fb1df55_01080000');
    const others184 = await store.get('b198010bd61490f8_01080001');
    const others44 = await store.get('b198010bd61490f8_01088008');

    assert.ok(iConnect);
    assert.ok(others184);
    assert.ok(others44);
    assert.equal(iConnect.length, 328);
    assert.equal(others184.length, 170);
    assert.equal(others44.length, 77);
    assert.equal(sha256(iConnect), 'bd0045be249c9614ab6d7ffdafc19888cbc3fb9c7731137c2440270c0cb6abca');
    assert.equal(sha256(others184), '0f32d9abfb9d89d215f4c6c86e8a2820df7927e8ad9a145a4adbdc1659db01ad');
    assert.equal(sha256(others44), '6f1855fdd9834646d9c6bd0539a4b98117dfc788906d8a4158cc4ab8507c5def');

    const transformed = transformV25Response(iConnect, I_CONNECT_BODY);
    assert.equal(sha256(transformed), 'a7677e55e95dd037e35b3e60de3e477a7175b584b993eb0f4f1cd4349d11005f');
  }
);
