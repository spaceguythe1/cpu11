# cpu11

`cpu11` is a small experimental CPU emulator written in C. It reads a text file of instructions, decodes each line with a custom mnemonic set, and executes it against a simple accumulator-based machine model with a memory array and clock/counter logic.

This project is intentionally rough and educational rather than a polished or general-purpose CPU implementation. The code and sample programs are built around ad hoc instruction formats and a few demo programs, including a small snake-style example.

## Overview

The program in `cpu11.c` is a command-line emulator. When run, it asks for an action and then reads a program file. It executes the instructions line by line, using an 8-bit accumulator and a 256-byte memory array. The implementation includes a simulated clock, counter updates, conditional jump logic, and a few display/output instructions.

The repo includes a few sample program files rather than a formal assembler or OS-like environment:

- `cpu11.c` — emulator implementation and interactive runner
- `buildcpu11.sh` — build script
- `snake.txt` — larger sample program
- `line.txt` — small text-output demo
- `apple.txt` — additional data file referenced by the sample names
- `instuection set for cpu11` — notes describing the custom instruction set

## Build

Compile with a C23-capable GCC:

```sh
gcc -std=c23 -Wall -Wextra cpu11.c -o cpu11
```

Or use the included script:

```sh
./buildcpu11.sh
```

## Run

Start the emulator:

```sh
./cpu11
```

At the prompt, enter:

```text
run
```

Then provide a file path, or use one of the built-in names the program recognizes:

```text
snake
line
badapple
```

The built-in names map to repo-local files and are handled in the code directly.

## Program format

The emulator expects one instruction per line. The format is intentionally simple and matches the sample files in the repo:

```text
LOD 00000001
STA 00101001
JMP
HAL
```

Most instructions are mnemonic plus an optional binary operand (`d1`), usually 8 bits long. The parser is crude and assumes the exact format used by the sample programs.

## Instructions

The current project recognizes and/or implements the following instructions:

| Instruction | Purpose |
| --- | --- |
| `SCA` | Prompt for an 8-bit value and store it in the accumulator |
| `HAL` | Stop execution |
| `LOD {d1}` | Load an 8-bit value into the accumulator |
| `CLR` | Clear memory |
| `TAC` | Store the instruction counter in memory addresses `mem[0]` and `mem[1]` |
| `LDA {d1}` | Load a byte from memory into the accumulator |
| `STA {d1}` | Store the accumulator to a memory address |
| `ADD {d1}` | Add memory contents to the accumulator |
| `SUB {d1}` | Subtract memory contents from the accumulator |
| `AND {d1}` | Bitwise AND with the accumulator |
| `ORR {d1}` | Bitwise OR with the accumulator |
| `JMP` | Jump using the counter value stored in memory |
| `JZE` | Conditional jump if the zero flag is set |
| `DIF` | Render an 8x8 display-style image from memory |
| `YEL {d1}` | Print a character based on bit pattern data |
| `BLK` | No-op / placeholder |

The notes file also references a broader or older conceptual instruction list, but the actual emulator code is the source of truth for what the project currently supports.

## Notes

`cpu11` is best understood as a toy instruction-set experiment. It demonstrates:

- accumulator-based execution
- a simple memory model
- line-oriented instruction parsing
- jump and zero-flag behavior
- clock/counter stepping
- rough, custom "assembly" programs used for demos

The project is not a fully general CPU design or a polished educational emulator package. It is a small, self-contained experiment in C with intentionally minimal structure and custom program conventions.

## License

No license file is included in the repository. Check with the project owner before redistributing or reusing the code.
