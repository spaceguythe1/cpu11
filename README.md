# cpu11

`cpu11` is a small, intentionally rough CPU emulator written in C. It reads a text file of instructions, decodes each line with a custom mnemonic set, and executes it against an 8-bit accumulator and 256-byte memory model.

The implementation in `cpu11.c` is the source of truth for the actual supported instruction set and behavior. This project is meant as a toy instruction-set experiment, not a polished or general-purpose CPU design.

## Overview

The program in `cpu11.c` is a command-line emulator. It starts by asking for an action, then reads a program file and executes it line by line. The core model is:

- 8-bit accumulator (`accum`)
- 256-byte memory array (`mem[256]`)
- clock/counter-based stepping (`clok()`, `counter()`) 
- line-oriented instruction parsing using fixed character positions in each input line

There is no formal assembler, linker, or OS-like environment here; the repo mainly consists of the emulator and sample text programs.

The repo includes:

- `cpu11.c` — emulator implementation and interactive runner
- `buildcpu11.sh` — build script
- `snake.txt` — larger sample program
- `line.txt` — small text-output demo
- `apple.txt` — data file referenced by the built-in sample name
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

Then provide a file path. The program also recognizes a few built-in names:

```text
snake
line
badapple
```

Those names are handled directly in `cpu11.c` by mapping them to absolute paths such as `/home/joseph/cpu11/snake.txt`. If those paths are different on your machine, edit the code or pass the actual file path directly.

## Program format

The emulator expects one instruction per line. The format is intentionally simple and matches the sample files in the repo:

```text
LOD 00000001
STA 00101001
JMP
HAL
```

Most instructions are a mnemonic followed by an optional 8-bit binary operand (`d1`). The parser is crude and reads fixed character positions from each line, so spacing and formatting need to match the sample files closely.

## Memory and registers

- `accum` is an 8-bit accumulator used for math and data movement.
- `mem[256]` is a byte-addressable memory array.
- `count` is the instruction counter used to select which line to execute.
- `TAC` writes the count into `mem[0]` and `mem[1]` as a 16-bit value (`mem[0]` low byte, `mem[1]` high byte).
- `JMP` and `JZE` read the jump target from that stored 16-bit value.

## Instructions implemented in the code

The actual emulator supports the following instruction mnemonics in `cpu11.c`:

| Instruction | Purpose |
| --- | --- |
| `SCA` | Prompt for an 8-bit binary value and store it in the accumulator |
| `HAL` | Halt execution |
| `LOD {d1}` | Load an 8-bit binary immediate into the accumulator |
| `CLR` | Clear all memory bytes to zero |
| `TAC` | Store the instruction counter in `mem[0]` and `mem[1]` |
| `LDA {d1}` | Load memory at the given address into the accumulator |
| `STA {d1}` | Store the accumulator to memory at the given address |
| `ADD {d1}` | Add memory contents to the accumulator |
| `SUB {d1}` | Subtract memory contents from the accumulator |
| `AND {d1}` | Bitwise AND with memory contents |
| `ORR {d1}` | Bitwise OR with memory contents |
| `JMP` | Jump to the address stored in `mem[0]` and `mem[1]` |
| `JZE` | Conditional jump if the zero flag is set |
| `YEL {d1}` | Interpret the operand as a character index and print the matching character |
| `WIP` | Screen refresh/clear helper |

Important: the README previously listed `DIF` and `BLK`, but those are not implemented in the current code. The notes file may mention a broader or older conceptual instruction list, but the actual emulator logic in `cpu11.c` is the source of truth.

## Notes

`cpu11` is best understood as a toy instruction-set experiment. It demonstrates:

- accumulator-based execution
- a simple memory model
- line-oriented instruction parsing
- jump and zero-flag behavior
- clock/counter stepping
- rough custom assembly programs used for demos

The project is not a fully general CPU design or a polished educational emulator package. It is a small, self-contained experiment in C with intentionally minimal structure and custom program conventions.

## License

No license file is included in the repository. Check with the project owner before redistributing or reusing the code.
