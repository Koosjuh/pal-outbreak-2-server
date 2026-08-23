# Ghidra PS2 Setup

`ghidra_ps2_plugin_status` reports detectable local support for PS2 EE/R5900
analysis without modifying Ghidra projects.

The tool checks:

- Whether Ghidra MCP reachability is known.
- Whether the current program appears to be PS2 EE/R5900.
- Whether Emotion Engine processor support appears active.
- Whether local plugin/support files are detectable by filename.
- Whether manual setup is probably needed.

This tool does not rename symbols, change project files, or install plugins.
If Ghidra MCP is unavailable, status remains `Unknown` rather than inferred.
