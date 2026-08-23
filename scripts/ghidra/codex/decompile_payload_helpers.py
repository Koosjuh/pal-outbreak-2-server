# Codex-owned focused export for PAL EE SN@P payload helper analysis.
# Output: D:/projects/pal-outbreak-2-server/analysis/ghidra-payload-helpers-export.txt

from ghidra.app.decompiler import DecompInterface
from java.io import FileWriter, BufferedWriter, PrintWriter

targets = [
    (0x001c3880, "TCP frame/body receive helper"),
    (0x001c3a60, "read u8 from payload cursor"),
    (0x001c3ab0, "read u16 from payload cursor"),
    (0x001c3b10, "read u32 from payload cursor"),
    (0x001c3b90, "read/copy variable payload bytes"),
    (0x001c7a70, "02 65 04 slot-detail handler"),
]

out_path = "D:/projects/pal-outbreak-2-server/analysis/ghidra-payload-helpers-export.txt"
pw = PrintWriter(BufferedWriter(FileWriter(out_path)))
ifc = DecompInterface()
ifc.openProgram(currentProgram)

try:
    pw.println("PAL EE SN@P payload helper focused export")
    pw.println("Program: " + currentProgram.getName())
    fm = currentProgram.getFunctionManager()
    for addr_value, note in targets:
        pw.println()
        pw.println("----------------------------------------------------------------")
        fn = fm.getFunctionAt(toAddr(addr_value))
        if fn is None:
            pw.println("NO_FUNCTION @ 0x%08x  %s" % (addr_value, note))
            continue
        entry = fn.getEntryPoint().getOffset()
        size = fn.getBody().getMaxAddress().getOffset() - entry + 1
        pw.println("FN %s @ 0x%08x size=0x%x  %s" % (fn.getName(), entry, size, note))
        pw.println("callers:")
        callers = fn.getCallingFunctions(monitor)
        for caller in callers:
            pw.println("  0x%08x %s" % (caller.getEntryPoint().getOffset(), caller.getName()))
        pw.println("callees:")
        callees = fn.getCalledFunctions(monitor)
        for callee in callees:
            pw.println("  0x%08x %s" % (callee.getEntryPoint().getOffset(), callee.getName()))
        pw.println("----------------------------------------------------------------")
        res = ifc.decompileFunction(fn, 90, monitor)
        if res is not None and res.decompileCompleted():
            pw.println(res.getDecompiledFunction().getC())
        else:
            pw.println("DECOMPILE_FAILED: " + ("null" if res is None else res.getErrorMessage()))
        pw.flush()
finally:
    ifc.dispose()
    pw.close()

println("Done: " + out_path)
