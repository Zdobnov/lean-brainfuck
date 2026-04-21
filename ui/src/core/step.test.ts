import { describe, expect, it } from "vitest";
import { parse } from "./parse.js";
import { step, readCell, writeCell } from "./step.js";
import type { Program, State } from "./types.js";
import { createTape, TAPE_LEN } from "./types.js";
import { validate } from "./validate.js";

function programFromBf(source: string): Program {
  const r = validate(parse(source));
  if (r.tag === "UnmatchedOpeningBracket" || r.tag === "UnmatchedClosingBracket") {
    throw new Error(`invalid BF: ${source}`);
  }
  return r;
}

function baseState(overrides: Partial<State> = {}): State {
  return {
    tape: createTape(),
    ptr: 0,
    pc: 0,
    input: [],
    output: [],
    ...overrides,
  };
}

describe("step helpers", () => {
  it("writeCell + readCell round-trip with wrap", () => {
    const t0 = createTape();
    const t1 = writeCell(t0, 0, 255);
    expect(readCell(t1, 0)).toBe(255);
    expect(t1.length).toBe(TAPE_LEN);
  });
});

describe("step", () => {
  it("Inc wraps 255 -> 0", () => {
    const tape = writeCell(createTape(), 0, 255);
    const program: Program = {
      instructions: [{ tag: "Inc" }],
      jumpTable: { pair: [-1] },
    };
    const r = step(program, baseState({ tape }));
    expect(r.tag).toBe("Running");
    if (r.tag === "Running") {
      expect(readCell(r.state.tape, 0)).toBe(0);
      expect(r.state.pc).toBe(1);
    }
  });

  it("Dec wraps 0 -> 255", () => {
    const program: Program = {
      instructions: [{ tag: "Dec" }],
      jumpTable: { pair: [-1] },
    };
    const r = step(program, baseState());
    expect(r.tag).toBe("Running");
    if (r.tag === "Running") {
      expect(readCell(r.state.tape, 0)).toBe(255);
      expect(r.state.pc).toBe(1);
    }
  });

  it("MoveLeft at ptr 0 -> PointerOutOfBounds", () => {
    const program: Program = {
      instructions: [{ tag: "MoveLeft" }],
      jumpTable: { pair: [-1] },
    };
    const s = baseState({ ptr: 0 });
    const r = step(program, s);
    expect(r).toEqual({
      tag: "Error",
      state: s,
      error: { tag: "PointerOutOfBounds", attemptedPtr: -1 },
    });
  });

  it("MoveRight at ptr 29999 -> PointerOutOfBounds", () => {
    const program: Program = {
      instructions: [{ tag: "MoveRight" }],
      jumpTable: { pair: [-1] },
    };
    const s = baseState({ ptr: TAPE_LEN - 1 });
    const r = step(program, s);
    expect(r).toEqual({
      tag: "Error",
      state: s,
      error: { tag: "PointerOutOfBounds", attemptedPtr: TAPE_LEN },
    });
  });

  it("Output appends current cell", () => {
    const tape = writeCell(createTape(), 0, 42);
    const program: Program = {
      instructions: [{ tag: "Output" }],
      jumpTable: { pair: [-1] },
    };
    const r = step(program, baseState({ tape }));
    expect(r.tag).toBe("Running");
    if (r.tag === "Running") {
      expect(r.state.output).toEqual([42]);
      expect(r.state.pc).toBe(1);
    }
  });

  it("Input writes first byte and consumes it", () => {
    const program: Program = {
      instructions: [{ tag: "Input" }],
      jumpTable: { pair: [-1] },
    };
    const r = step(program, baseState({ input: [7, 8, 9] }));
    expect(r.tag).toBe("Running");
    if (r.tag === "Running") {
      expect(readCell(r.state.tape, 0)).toBe(7);
      expect(r.state.input).toEqual([8, 9]);
      expect(r.state.pc).toBe(1);
    }
  });

  it("Input on empty input -> NoInput", () => {
    const program: Program = {
      instructions: [{ tag: "Input" }],
      jumpTable: { pair: [-1] },
    };
    const s = baseState();
    const r = step(program, s);
    expect(r).toEqual({
      tag: "Error",
      state: s,
      error: { tag: "NoInput" },
    });
  });

  it("LoopStart jumps when cell is 0", () => {
    const program = programFromBf("[]");
    const r = step(program, baseState());
    expect(r.tag).toBe("Running");
    if (r.tag === "Running") {
      expect(r.state.pc).toBe(2);
    }
  });

  it("LoopStart falls through when cell is non-zero", () => {
    const program = programFromBf("[]");
    const tape = writeCell(createTape(), 0, 1);
    const r = step(program, baseState({ tape }));
    expect(r.tag).toBe("Running");
    if (r.tag === "Running") {
      expect(r.state.pc).toBe(1);
    }
  });

  it("LoopEnd jumps when cell is non-zero", () => {
    const program = programFromBf("[+]");
    const tape = writeCell(createTape(), 0, 1);
    const r = step(program, baseState({ tape, pc: 2 }));
    expect(r.tag).toBe("Running");
    if (r.tag === "Running") {
      expect(r.state.pc).toBe(1);
    }
  });

  it("LoopEnd falls through when cell is 0", () => {
    const program = programFromBf("[+]");
    const r = step(program, baseState({ pc: 2 }));
    expect(r.tag).toBe("Running");
    if (r.tag === "Running") {
      expect(r.state.pc).toBe(3);
    }
  });

  it("pc at end -> Terminated", () => {
    const program: Program = {
      instructions: [{ tag: "Inc" }],
      jumpTable: { pair: [-1] },
    };
    const s = baseState({ pc: 1 });
    const r = step(program, s);
    expect(r).toEqual({ tag: "Terminated", state: s });
  });
});
