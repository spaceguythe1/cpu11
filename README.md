# cpu11

**cpu11** is a small experimental CPU emulator written in C. It loads instruction streams from text files and runs them through a simple clock-driven execution loop. The project is intended for learning and experimentation, not as a general-purpose processor.

## Overview

The command-line program in `cpu11.c` reads a program file and executes its instructions using an accumulator and a simulated memory array. The current instruction set is intentionally small, with basic load, store, clear, and halt operations.

## Project files

- `cpu11.c` — emulator implementation
- `default.txt` — sample program
- `buildcpu11.sh` — build script
- `instuection set for cpu11` — instruction-set notes

## Build

Compile from the project directory with a C23-capable GCC:

```sh
gcc -std=c23 -Wall -Wextra cpu11.c -o cpu11
```

Alternatively, run the included build script:

```sh
./buildcpu11.sh
```

## Run

Start the emulator:

```sh
./cpu11
```

At the prompt, enter `run`, then provide a program path. Enter `x` to try the built-in default file path, or enter the path to a program file:

```text
run
x
```

## Example program

`default.txt` demonstrates the current instruction format:

```text
BLK
LOD 10101010
STA 00000000
LOD 00000000
BLK
LDA 00000000
CLR
BLK
HAL
```

## Instructions

The currently implemented or recognized instructions are:

| Instruction | Purpose |
| --- | --- |
| `BLK` | No-op / placeholder |
| `HAL` | Stop execution |
| `LOD {d1}` | Load a bit pattern into the accumulator |
| `CLR` | Clear memory state |
| `LDA {d1}` | Load a value from memory into the accumulator |
| `STA {d1}` | Store the accumulator value in memory |

The instruction notes also describe possible future opcodes, including `ADD`, `SUB`, `AND`, `OR`, `JMP`, and `JZE`; these are not presented here as implemented features.

## Scope

cpu11 is a compact project for exploring instruction decoding, accumulator-based execution, memory addressing, and emulator loops. Potential areas for development include stricter instruction parsing, additional opcodes and registers, command-line arguments, diagnostics, and an assembler with labels.

## License

No license file is included. Check with the project owner before redistributing or reusing the code.
