# Brainfuck Playground

A Brainfuck interpreter implemented in TypeScript with a non-blocking browser runtime and a Lean 4 formal model.

---

## Features

- Full Brainfuck interpreter
- Immutable state transitions
- Bracket validation with jump table
- Non-blocking execution via Web Worker
- Step-batched execution for long-running programs
- Minimal React UI for interaction
- Lean 4 formal model with basic proofs

---

## Architecture

### 1. Core (TypeScript)

Located in `src/core`.

Pure interpreter logic:

- `parse.ts` — converts source code into instructions
- `validate.ts` — checks bracket correctness and builds jump table
- `step.ts` — executes a single instruction
- `run.ts` — executes multiple steps

Key properties:

- No side effects
- Immutable state transitions
- Fully test-covered

---

### 2. Worker

Located in `src/worker`.

Handles execution outside the main thread.

Responsibilities:

- Runs interpreter in batches
- Sends progress updates
- Handles stop signals
- Prevents UI blocking

Execution model:

- Uses batching (`runSteps`)
- Yields to event loop between batches
- Supports long-running and infinite programs

---

### 3. UI (React + Vite)

Located in `ui/`.

Features:

- Code input
- Input stream
- Run / Stop controls
- Live state visualization:
  - output
  - pointer
  - program counter
  - tape snapshot

---

### 4. Formal Model (Lean 4)

Located in `lean/`.

Includes:

- Instruction model
- Program representation
- State definition
- Step semantics
- Selected correctness proofs

Example theorems:

- `runSteps_zero`
- `read_after_write_same`
- `step_terminated_when_pc_at_end`

---

## Design Decisions

### Immutable State

Each step produces a new state.

Pros:
- Easier reasoning
- Safer concurrency
- Matches functional model

Trade-off:
- Higher allocation cost

---

### Jump Table

Precomputed bracket matching:

- O(1) loop jumps
- Avoids runtime scanning

---

### Worker-based Execution

Interpreter runs in Web Worker:

- No UI blocking
- Supports infinite programs
- Enables progress updates

---

### Batching

Execution happens in chunks:

- Prevents long synchronous loops
- Allows interruption (Stop)
- Keeps UI responsive

---

### Lean Formalization

Lean model mirrors interpreter structure.

Benefits:

- Precise semantics
- Machine-checked properties
- Clear separation of concerns

---

## Trade-offs

- `runSteps` does not track exact steps when early termination occurs
- Program validity is not encoded in types (checked at runtime)
- Tape is copied on each write (simpler but less efficient)
- Lean model is partial (not all properties proven)

---

## How to Run

### Install dependencies

```bash
npm install