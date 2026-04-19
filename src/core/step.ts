import type { Program, Ptr, State, StepResult, Tape } from "./types.js";
import { TAPE_LEN } from "./types.js";

/** Maps an integer to \([0, 255]\) for tape cell arithmetic. */
export function wrapByte(value: number): number {
  return ((value % 256) + 256) % 256;
}

export function readCell(tape: Tape, ptr: Ptr): number {
  return tape[ptr]!;
}

/** Returns a new tape of length `TAPE_LEN` with cell `ptr` set to `wrapByte(value)`. */
export function writeCell(tape: Tape, ptr: Ptr, value: number): Tape {
  const wrapped = wrapByte(value);
  const next = tape.slice();
  next[ptr] = wrapped;
  return next as Tape;
}

export function step(program: Program, state: State): StepResult {
  const n = program.instructions.length;
  if (state.pc >= n) {
    return { tag: "Terminated", state };
  }

  const pc = state.pc;
  const instr = program.instructions[pc]!;
  const pair = program.jumpTable.pair;

  switch (instr.tag) {
    case "MoveRight": {
      if (state.ptr === TAPE_LEN - 1) {
        return {
          tag: "Error",
          state,
          error: { tag: "PointerOutOfBounds", attemptedPtr: state.ptr + 1 },
        };
      }
      return {
        tag: "Running",
        state: {
          ...state,
          ptr: state.ptr + 1,
          pc: pc + 1,
        },
      };
    }
    case "MoveLeft": {
      if (state.ptr === 0) {
        return {
          tag: "Error",
          state,
          error: { tag: "PointerOutOfBounds", attemptedPtr: -1 },
        };
      }
      return {
        tag: "Running",
        state: {
          ...state,
          ptr: state.ptr - 1,
          pc: pc + 1,
        },
      };
    }
    case "Inc": {
      const v = readCell(state.tape, state.ptr);
      return {
        tag: "Running",
        state: {
          ...state,
          tape: writeCell(state.tape, state.ptr, v + 1),
          pc: pc + 1,
        },
      };
    }
    case "Dec": {
      const v = readCell(state.tape, state.ptr);
      return {
        tag: "Running",
        state: {
          ...state,
          tape: writeCell(state.tape, state.ptr, v - 1),
          pc: pc + 1,
        },
      };
    }
    case "Output": {
      const v = readCell(state.tape, state.ptr);
      return {
        tag: "Running",
        state: {
          ...state,
          output: [...state.output, v],
          pc: pc + 1,
        },
      };
    }
    case "Input": {
      if (state.input.length === 0) {
        return { tag: "Error", state, error: { tag: "NoInput" } };
      }
      const [head, ...rest] = state.input;
      return {
        tag: "Running",
        state: {
          ...state,
          tape: writeCell(state.tape, state.ptr, head!),
          input: rest,
          pc: pc + 1,
        },
      };
    }
    case "LoopStart": {
      const cell = readCell(state.tape, state.ptr);
      const nextPc = cell === 0 ? pair[pc]! + 1 : pc + 1;
      return {
        tag: "Running",
        state: {
          ...state,
          pc: nextPc,
        },
      };
    }
    case "LoopEnd": {
      const cell = readCell(state.tape, state.ptr);
      const nextPc = cell !== 0 ? pair[pc]! + 1 : pc + 1;
      return {
        tag: "Running",
        state: {
          ...state,
          pc: nextPc,
        },
      };
    }
  }
}
