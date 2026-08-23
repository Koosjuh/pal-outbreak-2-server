# Ghidra Jython focused export for PAL EE SN@P opcode 0x48 helpers.

from ghidra.app.decompiler import DecompInterface

TARGETS = [
    0x001e094c,
    0x001d9f78,
    0x001d8c10,
    0x001d8710,
    0x001d81a4,
    0x001d8b60,
    0x001d7b30,
]

out_path = "D:/projects/pal-outbreak-2-server/analysis/ghidra-snap-op48-helpers.txt"
ifc = DecompInterface()
ifc.openProgram(currentProgram)

with open(out_path, "w") as out:
    out.write("PAL EE SN@P opcode 0x48 helper export\n")
    out.write("Program: %s\n" % currentProgram.getName())
    for entry in TARGETS:
        fn = currentProgram.getFunctionManager().getFunctionAt(toAddr(entry))
        out.write("\n----------------------------------------------------------------\n")
        if fn is None:
            out.write("NO_FUNCTION @ 0x%08x\n" % entry)
            continue
        start = fn.getEntryPoint().getOffset()
        size = fn.getBody().getMaxAddress().getOffset() - start + 1
        out.write("FN %s @ 0x%08x size=0x%x\n" % (fn.getName(), start, size))
        out.write("callers:\n")
        for caller in fn.getCallingFunctions(monitor):
            out.write("  0x%08x %s\n" % (caller.getEntryPoint().getOffset(), caller.getName()))
        out.write("callees:\n")
        for callee in fn.getCalledFunctions(monitor):
            out.write("  0x%08x %s\n" % (callee.getEntryPoint().getOffset(), callee.getName()))
        out.write("----------------------------------------------------------------\n")
        result = ifc.decompileFunction(fn, 90, monitor)
        if result is not None and result.decompileCompleted():
            out.write(result.getDecompiledFunction().getC())
            out.write("\n")
        else:
            out.write("DECOMPILE_FAILED: %s\n" % ("null" if result is None else result.getErrorMessage()))

ifc.dispose()
print("Done: " + out_path)
