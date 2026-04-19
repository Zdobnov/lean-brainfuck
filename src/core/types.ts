/**
 * Core domain types for the Brainfuck interpreter.
 * Jump semantics (fixed):
 * - LoopStart at i: if current cell === 0, set pc to the instruction index immediately after
 *   the matching LoopEnd, i.e. pair[i] + 1.
 * - LoopEnd at i: if current cell !== 0, set pc to the instruction index immediately after
 *   the matching LoopStart, i.e. pair[i] + 1.
 *
 * Here jumpTable.pair[i] is the index of the matching bracket (LoopStart ↔ LoopEnd).
 */

export const TAPE_LEN = 30_000 as const;

/** Pure Brainfuck instruction set (loop boundaries are not encoded as jump offsets). */
export type Instruction =
  | { readonly tag: "MoveRight" }
  | { readonly tag: "MoveLeft" }
  | { readonly tag: "Inc" }
  | { readonly tag: "Dec" }
  | { readonly tag: "Output" }
  | { readonly tag: "Input" }
  | { readonly tag: "LoopStart" }
  | { readonly tag: "LoopEnd" };

/**
 * Symmetric partner table: for each index i where instructions[i] is LoopStart or LoopEnd,
 * pair[i] is the index of the matching bracket. Entries at non-bracket indices are unused
 * (convention: -1 after validation).
 * Invariant: pair.length === instructions.length.
 */
export type JumpTable = {
  readonly pair: readonly number[];
};

export type Program = {
  readonly instructions: readonly Instruction[];
  readonly jumpTable: JumpTable;
};

/**
 * Fixed-length tape: exactly TAPE_LEN cells, each 0–255 in normal operation.
 * Tape values must be created only via createTape() and must preserve the invariant
 * length === TAPE_LEN (30000). Do not construct or resize manually.
 */
export type Tape = readonly number[] & { readonly length: typeof TAPE_LEN };

export function createTape(): Tape {
  const cells = new Array<number>(TAPE_LEN);
  for (let i = 0; i < TAPE_LEN; i += 1) {
    cells[i] = 0;
  }
  return cells as Tape;
}

export type Ptr = number;
export type PC = number;

export type State = {
  readonly tape: Tape;
  readonly ptr: Ptr;
  readonly pc: PC;
  readonly input: readonly number[];
  readonly output: readonly number[];
};

export type RuntimeError =
  | { readonly tag: "PointerOutOfBounds"; readonly attemptedPtr: number }
  | { readonly tag: "NoInput" };

export type ValidationError =
  | { readonly tag: "UnmatchedOpeningBracket"; readonly index: number }
  | { readonly tag: "UnmatchedClosingBracket"; readonly index: number };

/** Interpreter status after a step or when reporting outcome. */
export type StepResult =
  | { readonly tag: "Running"; readonly state: State }
  | { readonly tag: "Terminated"; readonly state: State }
  | { readonly tag: "Error"; readonly state: State; readonly error: RuntimeError };
