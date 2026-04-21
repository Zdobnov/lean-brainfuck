import type { Instruction, Program, ValidationError } from "./types.ts";

const PAIR_SENTINEL = -1;

/**
 * Checks bracket nesting and builds the symmetric partner table.
 * Returns the first error in left-to-right scan order (closing before leftover opens at EOF).
 */
export function validate(instructions: readonly Instruction[]): Program | ValidationError {
  const n = instructions.length;
  const pair = new Array<number>(n);
  for (let i = 0; i < n; i += 1) {
    pair[i] = PAIR_SENTINEL;
  }

  const stack: number[] = [];

  for (let i = 0; i < n; i += 1) {
    const instr = instructions[i]!;
    if (instr.tag === "LoopStart") {
      stack.push(i);
    } else if (instr.tag === "LoopEnd") {
      const open = stack.pop();
      if (open === undefined) {
        return { tag: "UnmatchedClosingBracket", index: i };
      }
      pair[open] = i;
      pair[i] = open;
    }
  }

  if (stack.length > 0) {
    return { tag: "UnmatchedOpeningBracket", index: stack[0]! };
  }

  return {
    instructions: [...instructions],
    jumpTable: { pair },
  };
}

export function stringToBytes(s: string): number[] {
  return Array.from(s).map((c) => c.charCodeAt(0));
}

export function bytesToString(bytes: readonly number[]): string {
  return String.fromCharCode(...bytes);
}

export function isValidationError(value: Program | ValidationError): value is ValidationError {
  return "tag" in value;
}