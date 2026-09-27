# cpu11

A small, experimental custom CPU emulator written in C. This project is a toy CPU design and runtime for executing simple instruction streams from text files, with a minimal instruction set and a very lightweight emulator loop.

## What this project does

`cpu11.c` contains a simple command-line simulator that:

- prompts for a command
- reads a text file containing CPU instructions
- executes each instruction in a clock-driven loop
- tracks a simple accumulator and memory array
- supports a few basic operations such as load, store, clear, halt, and memory access

This is not a full general-purpose processor or production-grade architecture; it is a learning project and a playful custom CPU design.

## Repository contents

- `cpu11.c` — main emulator implementation
- `default.txt` — example CPU program used by the emulator
- `buildcpu11.sh` — quick build script
- `instuection set for cpu11` — notes on the instruction set
- `README.md` — project overview and usage

## Features

- tiny custom instruction set
- accumulator-based CPU behavior
- simple text-file based program loading
- memory simulation using a byte array
- clock/counter loop for sequential instruction execution
- easy build and run flow for experimentation

## Build

From the project root, run:

```bash
gcc -std=c23 -Wall -Wextra cpu11.c -o cpu11
```

Or use the included script:

```bash
./buildcpu11.sh
```

## Run

```bash
./cpu11
```

When prompted, choose `run` and provide a file path such as:

```bash
./cpu11
run
x 
```

If you type `x`, the program attempts to use the built-in default file path; or provide a valid program path

## Example program

The included `default.txt` contains a simple program like this:

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

## Instruction set

This project uses a minimal custom set, as described in the instruction notes file. The implemented/recognized instructions include:

- `BLK` — no-op / placeholder instruction
- `HAL` — halt execution
- `LOD {d1}` — load a bit pattern into the accumulator
- `CLR` — clear memory state
- `LDA {d1}` — load value from memory into accumulator
- `STA {d1}` — store accumulator value into memory

The notes file also lists more advanced opcodes planned for future expansion, including arithmetic and branching instructions such as `ADD`, `SUB`, `AND`, `OR`, `JMP`, and `JZE`.

## Notes

This repository is intentionally small and experimental. It’s a good example of a custom CPU toy project for learning about:

- instruction decoding
- accumulator architecture
- memory addressing
- simple emulation loops
- CPU-style execution flow

## Future ideas

Possible improvements for a next iteration:

- proper instruction parsing and validation
- support for more opcodes and registers
- command-line argument parsing
- error messages and debugging output
- assembler or textual machine code format with labels
- better documentation and a clearer architecture spec

## License

No explicit license file is included in this repository. Treat the project as experimental code for learning and personal use unless otherwise specified.
