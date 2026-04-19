import { step } from "./step.js";
import type { Program, State, StepResult } from "./types.js";

export type RunToCompletionResult =
  | StepResult
  | { readonly tag: "OutOfFuel"; readonly state: State; readonly steps: number };

/**
 * Runs at most `maxSteps` calls to `step`. Stops early on `Terminated` or `Error`.
 * If `maxSteps` is 0, returns `Running` with the initial `state`.
 */
export function runSteps(program: Program, state: State, maxSteps: number): StepResult {
  let current = state;
  for (let i = 0; i < maxSteps; i += 1) {
    const r = step(program, current);
    if (r.tag === "Terminated" || r.tag === "Error") {
      return r;
    }
    current = r.state;
  }
  return { tag: "Running", state: current };
}

/**
 * Runs `step` until `Terminated`, `Error`, or `maxSteps` executed without halting.
 */
export function runToCompletion(
  program: Program,
  state: State,
  maxSteps: number,
): RunToCompletionResult {
  let current = state;
  for (let i = 0; i < maxSteps; i += 1) {
    const r = step(program, current);
    if (r.tag === "Terminated" || r.tag === "Error") {
      return r;
    }
    current = r.state;
  }
  return { tag: "OutOfFuel", state: current, steps: maxSteps };
}
