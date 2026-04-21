/// <reference lib="webworker" />

import { runSteps } from "../core/run.js";
import type { Program, State } from "../core/types.js";
import type {
  WorkerIncomingMessage,
  WorkerOutgoingMessage,
  WorkerStartMessage,
} from "./messages.js";

let running = false;
let stopRequested = false;

let currentProgram: Program | null = null;
let currentState: State | null = null;

let batchSize = 1000;
let maxSteps: number | undefined;
let stepsExecuted = 0;

function resetExecution(): void {
  running = false;
  stopRequested = false;
  currentProgram = null;
  currentState = null;
  batchSize = 1000;
  maxSteps = undefined;
  stepsExecuted = 0;
}

function postMessageTyped(message: WorkerOutgoingMessage): void {
  self.postMessage(message);
}

function startExecution(message: WorkerStartMessage): void {
  currentProgram = message.program;
  currentState = message.state;
  batchSize = Math.max(1, Math.floor(message.batchSize));
  maxSteps =
    message.maxSteps !== undefined
      ? Math.max(0, Math.floor(message.maxSteps))
      : undefined;
  stepsExecuted = 0;
  stopRequested = false;
  running = true;

  pump();
}

function pump(): void {
  if (!running || currentProgram === null || currentState === null) {
    return;
  }

  if (stopRequested) {
    postMessageTyped({
      type: "stopped",
      state: currentState,
      stepsExecuted,
    });
    resetExecution();
    return;
  }

  const remainingSteps =
    maxSteps !== undefined ? maxSteps - stepsExecuted : undefined;

  if (remainingSteps !== undefined && remainingSteps <= 0) {
    postMessageTyped({
      type: "out_of_fuel",
      state: currentState,
      stepsExecuted,
    });
    resetExecution();
    return;
  }

  const effectiveBatchSize =
    remainingSteps !== undefined
      ? Math.min(batchSize, remainingSteps)
      : batchSize;

  const result = runSteps(currentProgram, currentState, effectiveBatchSize);

  switch (result.tag) {
    case "Running": {
      currentState = result.state;
      stepsExecuted += effectiveBatchSize;

      postMessageTyped({
        type: "progress",
        state: currentState,
        stepsExecuted,
      });

      setTimeout(pump, 0);
      return;
    }

    case "Terminated": {
      postMessageTyped({
        type: "terminated",
        state: result.state,
        stepsExecuted,
      });
      resetExecution();
      return;
    }

    case "Error": {
      postMessageTyped({
        type: "error",
        state: result.state,
        error: result.error,
        stepsExecuted,
      });
      resetExecution();
      return;
    }
  }
}

self.onmessage = (event: MessageEvent<WorkerIncomingMessage>): void => {
  const message = event.data;

  switch (message.type) {
    case "start": {
      resetExecution();
      startExecution(message);
      return;
    }

    case "stop": {
      if (running) {
        stopRequested = true;
      }
      return;
    }
  }
};