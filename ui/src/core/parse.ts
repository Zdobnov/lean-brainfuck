import type { Instruction } from "./types.js";

function charToInstruction(ch: string): Instruction | undefined {
  switch (ch) {
    case ">":
      return { tag: "MoveRight" };
    case "<":
      return { tag: "MoveLeft" };
    case "+":
      return { tag: "Inc" };
    case "-":
      return { tag: "Dec" };
    case ".":
      return { tag: "Output" };
    case ",":
      return { tag: "Input" };
    case "[":
      return { tag: "LoopStart" };
    case "]":
      return { tag: "LoopEnd" };
    default:
      return undefined;
  }
}

/**
 * Extracts Brainfuck instructions from source; all other characters are skipped.
 */
export function parse(source: string): Instruction[] {
  const out: Instruction[] = [];
  for (let i = 0; i < source.length; i += 1) {
    const inst = charToInstruction(source[i]!);
    if (inst !== undefined) {
      out.push(inst);
    }
  }
  return out;
}
