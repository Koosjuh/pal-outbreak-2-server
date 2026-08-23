// Ghidra Java postScript: export all function decompiles in the overlay-dump format.
// analyzeHeadless <proj> <name> -process <prog> -scriptPath <dir> -postScript ExportDecomp.java <outdir>
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Program;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.File;
import java.io.PrintWriter;

public class ExportDecomp extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outdir = args.length > 0 ? args[0] : ".";
        new File(outdir).mkdirs();
        Program prog = currentProgram;
        String modname = prog.getName().replaceAll("\\..*$", "");
        PrintWriter out = new PrintWriter(new File(outdir, modname + "-decompile.txt"), "UTF-8");
        out.println("Program: " + prog.getName() + ", image base: " + prog.getImageBase());
        out.println();
        DecompInterface dec = new DecompInterface();
        dec.openProgram(prog);
        ConsoleTaskMonitor mon = new ConsoleTaskMonitor();
        FunctionManager fm = prog.getFunctionManager();
        int n = 0;
        for (Function f : fm.getFunctions(true)) {
            StringBuilder callers = new StringBuilder();
            int cc = 0;
            for (Function c : f.getCallingFunctions(mon)) { if (cc++ > 0) callers.append(", "); callers.append(c.getName()).append("@0x").append(c.getEntryPoint()); }
            StringBuilder callees = new StringBuilder();
            int ce = 0;
            for (Function c : f.getCalledFunctions(mon)) { if (ce++ > 0) callees.append(", "); callees.append(c.getName()).append("@0x").append(c.getEntryPoint()); }
            String code;
            try {
                DecompileResults res = dec.decompileFunction(f, 60, mon);
                code = (res != null && res.decompileCompleted()) ? res.getDecompiledFunction().getC() : "// decompile failed";
            } catch (Exception e) { code = "// decompile exception: " + e.getMessage(); }
            out.println("================================================================");
            out.println("FUNCTION " + f.getName() + " @ 0x" + f.getEntryPoint() + " size=" + f.getBody().getNumAddresses());
            out.println("CALLERS (" + cc + "): " + callers);
            out.println("CALLEES (" + ce + "): " + callees);
            out.println(code);
            n++;
        }
        out.close();
        println("EXPORTED " + n + " functions from " + modname);
    }
}
