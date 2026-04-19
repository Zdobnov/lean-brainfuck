import { describe, expect, it } from "vitest";
import type { Instruction } from "./types.js";
import { validate } from "./validate.js";

function isError(
  r: ReturnType<typeof validate>,
): r is { tag: "UnmatchedOpeningBracket" | "UnmatchedClosingBracket"; index: number } {
  return r.tag === "UnmatchedOpeningBracket" || r.tag === "UnmatchedClosingBracket";
}

describe("validate", () => {
  it("accepts empty program", () => {
    const r = validate([]);
    expect(isError(r)).toBe(false);
    if (!isError(r)) {
      expect(r.instructions).toEqual([]);
      expect(r.jumpTable.pair).toEqual([]);
    }
  });

  it("accepts program without brackets", () => {
    const instrs: Instruction[] = [
      { tag: "Inc" },
      { tag: "MoveRight" },
      { tag: "Output" },
    ];
    const r = validate(instrs);
    expect(isError(r)).toBe(false);
    if (!isError(r)) {
      expect(r.instructions).toEqual(instrs);
      expect(r.jumpTable.pair).toEqual([-1, -1, -1]);
    }
  });

  it("accepts simple pair []", () => {
    const instrs: Instruction[] = [{ tag: "LoopStart" }, { tag: "LoopEnd" }];
    const r = validate(instrs);
    expect(isError(r)).toBe(false);
    if (!isError(r)) {
      expect(r.jumpTable.pair).toEqual([1, 0]);
    }
  });

  it("accepts nested brackets", () => {
    const instrs: Instruction[] = [
      { tag: "LoopStart" },
      { tag: "LoopStart" },
      { tag: "Inc" },
      { tag: "LoopEnd" },
      { tag: "LoopEnd" },
    ];
    const r = validate(instrs);
    expect(isError(r)).toBe(false);
    if (!isError(r)) {
      expect(r.jumpTable.pair).toEqual([4, 3, -1, 1, 0]);
    }
  });

  it("rejects extra opening bracket", () => {
    const r = validate([{ tag: "LoopStart" }, { tag: "LoopStart" }, { tag: "LoopEnd" }]);
    expect(r).toEqual({ tag: "UnmatchedOpeningBracket", index: 0 });
  });

  it("rejects extra closing bracket", () => {
    const r = validate([{ tag: "LoopEnd" }]);
    expect(r).toEqual({ tag: "UnmatchedClosingBracket", index: 0 });
  });
});
