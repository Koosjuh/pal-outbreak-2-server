# Corpus methodology — engineering standard

Adopted 2026-08-07 as a permanent project rule, after a review found that the xref tooling behind a
create-room investigation was a **linear sweep with no control flow**. It missed a writer, which
invalidated every "exhaustive", "exactly N" and "zero references" claim in a document that was about
to become code.

This is not a one-time correction. It carries into every session, handoff, specification, protocol
document and implementation.

---

## 1. What the tooling can and cannot establish

The xref tooling is a **discovery** mechanism. It finds references. It does not prove their absence,
their uniqueness or their reachability.

| claim | status |
|---|---|
| "found N writers" | **valid** — that is what a sweep does |
| "exactly N writers" | requires independent, control-flow-aware verification |
| "no reference found" | **not** evidence that no reference exists |
| "the only caller / writer / reader" | requires control-flow-aware confirmation |
| "unreachable" | requires actual reachability analysis |

Always consider, before promoting anything to fact:

- **indirect calls** and function pointers stored in tables or structs;
- **jump tables** (the client uses several — screen dispatch, transport slots, selector dispatch);
- **pointer dispatch** — a base passed into a helper evades an absolute-address scan entirely;
- **register clobbering** — a linear sweep loses a base after any path reassigns it;
- **MIPS delay slots** — the instruction after a `jal` executes BEFORE the callee, so a store there
  writes the PREVIOUS value. This has cost this project seven weeks once and recurred inside a corpus
  record. Always print the delay slot.

## 2. The rule that follows

**Whenever an implementation decision depends on exclusivity or absence, do targeted deeper analysis
of that specific path before writing code.** Not the whole binary — the one path the decision rests
on.

If that analysis cannot be done, the claim is **Likely** at best, the code must not depend on it, and
the document must say so.

## 3. The corpus is living, not an archive

Whenever we find an incorrect annotation, an incomplete xref conclusion, a mistaken protocol
assumption, a better explanation, or a newly verified runtime observation — do **not** simply use the
new understanding in the current implementation and move on.

1. **Verify** the new conclusion.
2. **Correct** the relevant corpus document or annotation.
3. **Record** what changed and why.
4. **Preserve** the previous conclusion as SUPERSEDED. Never silently rewrite history — a reader who
   remembers the old claim must be able to find out what happened to it.
5. **Update** dependent specifications, open questions and design documents that relied on it.
6. **Continue** implementation from the corrected understanding.

Every protocol investigation should leave the corpus more accurate than it found it.

## 4. Scope — incremental, never a rewrite

Do **not** launch a repository-wide corpus audit. Apply this when normal work touches an affected
area: fix it, document it, update the corpus, continue. Over time the corpus converges toward a
verified reference without interrupting implementation.

## 5. Evidence ranking, unchanged and restated

Runtime behaviour of a real client > the corpus > V1 source and traces > BioServer (conceptual only).
Direct disassembly settles conflicts between any of them. A memory image says WHAT a value is; it
never says what WROTE it — that is what the corpus is for, and it is why an image alone did not solve
walls that the corpus later did.

## 6. Worked examples from the session that produced this rule

- A corpus record claimed `FUN_005c3a40` set `0x6ff2b0` from a call's return. The store was in the
  **delay slot** and wrote the pre-call literal. Corrected.
- `SERVER_BUILD_PUNCHLIST.md` named `room_create_menu_sm` (0x610830) as the create commit and
  `room_slot_claim_ownership` (0x60f2c0) as requiring registry `0x35c000`. Neither is on the live
  create path — but the "zero references to 0x35c000" finding that supported this was produced by the
  same unreliable sweep, so **both the original claim and its refutation are Likely**, not Confirmed.
- "Exactly three writers of `0x6cba7d`" was six. The model survived; the exhaustiveness claim did not.
