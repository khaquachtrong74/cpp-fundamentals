# Auther khaquachtrong74
{pkgs ? import <nixpkgs>{}}:

pkgs.mkShell{
    packages = with pkgs;[
        gcc # GNU C compiler
        gdb # GNU Debugger
#        gnumake # GNU Make, a build automation tool
        cmake # Build systems generator
#        valgrind # A memory error detection tool
    ];
    shellHook =''
        echo "Turn on C development enviroment!"
        echo "GCC, GDB, and Make are available"
    '';
}
