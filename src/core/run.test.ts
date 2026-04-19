import { describe, expect, it } from "vitest";
import { parse } from "./parse.js";
import { runSteps, runToCompletion } from "./run.js";
import { step } from "./step.js";
import type { Program, State } from "./types.js";
import { createTape } from "./types.js";
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

describe("runSteps", () => {
  it("executes at most maxSteps when still running", () => {
    const program: Program = {
      instructions: [
        { tag: "Inc" },
        { tag: "Inc" },
        { tag: "Inc" },
      ],
      jumpTable: { pair: [-1, -1, -1] },
    };
    const r = runSteps(program, baseState(), 2);
    expect(r.tag).toBe("Running");
    if (r.tag === "Running") {
      expect(r.state.pc).toBe(2);
    }
  });

  it("returns early on Terminated", () => {
    const program: Program = { instructions: [], jumpTable: { pair: [] } };
    const s = baseState();
    const r = runSteps(program, s, 100);
    expect(r).toEqual({ tag: "Terminated", state: s });
  });

  it("returns early on Error", () => {
    const program: Program = {
      instructions: [{ tag: "MoveLeft" }],
      jumpTable: { pair: [-1] },
    };
    const s = baseState({ ptr: 0 });
    const r = runSteps(program, s, 100);
    expect(r.tag).toBe("Error");
    if (r.tag === "Error") {
      expect(r.state).toBe(s);
      expect(r.error.tag).toBe("PointerOutOfBounds");
    }
  });
});

describe("runToCompletion", () => {
  it("terminates on a finite program", () => {
    const program: Program = {
      instructions: [{ tag: "Inc" }],
      jumpTable: { pair: [-1] },
    };
    const r = runToCompletion(program, baseState(), 10_000);
    expect(r.tag).toBe("Terminated");
  });

  it("returns OutOfFuel on infinite loop", () => {
    const program = programFromBf("+[]");
    const r = runToCompletion(program, baseState(), 50);
    expect(r).toEqual({
      tag: "OutOfFuel",
      state: expect.any(Object),
      steps: 50,
    });
    if (r.tag === "OutOfFuel") {
      expect(r.steps).toBe(50);
    }
  });

  it("OutOfFuel state matches last Running from step chain", () => {
    const program = programFromBf("+[]");
    const s0 = baseState();
    let current = s0;
    const max = 12;
    for (let i = 0; i < max; i += 1) {
      const r = step(program, current);
      if (r.tag !== "Running") {
        throw new Error("expected Running");
      }
      current = r.state;
    }
    const runR = runToCompletion(program, s0, max);
    expect(runR.tag).toBe("OutOfFuel");
    if (runR.tag === "OutOfFuel") {
      expect(runR.state).toEqual(current);
      expect(runR.steps).toBe(max);
    }
  });
});
