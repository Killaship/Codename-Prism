import core.sys.posix.stdio;
import core.sys.posix.unistd;

import io = std.stdio;
import std.string;

enum kPrompt = "> ";

void main()
{
    io.write(kPrompt);
    foreach (line; io.stdin.byLineCopy())
    {
        runCommand(line);
        io.write(kPrompt);
    }
}

void runCommand(string cmd)
{
    // Need to convert D string to null-terminated C string
    auto cmdz = cmd.toStringz();

    // We need to pass execv an array of program arguments
    // By convention, the first element is the name of the program

    // C arrays don't carry a length, just the address of the first element.
    // execv starts reading memory from the first element, and needs a way to 
    // know when to stop.  Instead of taking a length value as an argument,
    // execv expects the array to end with a null as a stopping marker.

    auto argsz = [cmdz, null];
    auto error = execv(cmdz, argsz.ptr);
    if (error)
    {
        perror(cmdz);
    }
}
