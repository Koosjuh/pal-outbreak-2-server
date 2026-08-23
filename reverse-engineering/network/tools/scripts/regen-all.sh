#!/usr/bin/env bash
# Regenerate every derived index + the consolidated library from indexes/functions.json + records.
set -e
D="$(cd "$(dirname "$0")" && pwd)"
node "$D/build-callgraph.js"
node "$D/re.js" gen-index
node "$D/gen-docs.js"
node "$D/gen-protocol-menu.js"
node "$D/gen-subcommands.js"
node "$D/gen-library.js"
node "$D/re.js" coverage
