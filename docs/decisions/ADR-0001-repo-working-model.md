# ADR-0001: Repository Working Model

## Status

Accepted

## Context

This project involves protocol reverse engineering, server implementation, emulator comparison, real hardware testing, and evidence-based documentation.

## Decision

The repository will treat code, documentation, evidence, and decisions as first-class project artifacts.

## Consequences

- Every meaningful change must be committed to Git.
- Every protocol finding must be evidence-backed or explicitly marked as hypothesis.
- Test results must be reproducible.
- Unknowns must remain tracked until resolved.
