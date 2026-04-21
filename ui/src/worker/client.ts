import type { Program, State, RuntimeError } from "../core/types.js";
import type {
  WorkerOutgoingMessage,
  WorkerStartMessage,
} from "./messages.js";

export type InterpreterClient = {
  start: (params: {
    program: Program;
    state: State;
    batchSize: number;
    maxSteps?: number;
  }) => void;
  stop: () => void;

  onProgress: (fn: (state: State, steps: number) => void) => void;
  onTerminated: (fn: (state: State, steps: number) => void) => void;
  onError: (fn: (state: State, error: RuntimeError, steps: number) => void) => void;
  onStopped: (fn: (state: State, steps: number) => void) => void;
  onOutOfFuel: (fn: (state: State, steps: number) => void) => void;
};

export function createInterpreterClient(): InterpreterClient {
  const worker = new Worker(
    new URL("./interpreter.worker.ts", import.meta.url),
    { type: "module" }
  );

  let onProgressCb: ((s: State, n: number) => void) | null = null;
  let onTerminatedCb: ((s: State, n: number) => void) | null = null;
  let onErrorCb: ((s: State, e: RuntimeError, n: number) => void) | null = null;
  let onStoppedCb: ((s: State, n: number) => void) | null = null;
  let onOutOfFuelCb: ((s: State, n: number) => void) | null = null;

  worker.onmessage = (e: MessageEvent<WorkerOutgoingMessage>) => {
    const msg = e.data;

    switch (msg.type) {
      case "progress":
        onProgressCb?.(msg.state, msg.stepsExecuted);
        break;
      case "terminated":
        onTerminatedCb?.(msg.state, msg.stepsExecuted);
        break;
      case "error":
        onErrorCb?.(msg.state, msg.error, msg.stepsExecuted);
        break;
      case "stopped":
        onStoppedCb?.(msg.state, msg.stepsExecuted);
        break;
      case "out_of_fuel":
        onOutOfFuelCb?.(msg.state, msg.stepsExecuted);
        break;
    }
  };

  return {
    start(params) {
      const message: WorkerStartMessage = {
        type: "start",
        ...params,
      };
      worker.postMessage(message);
    },

    stop() {
      worker.postMessage({ type: "stop" });
    },

    onProgress(fn) {
      onProgressCb = fn;
    },
    onTerminated(fn) {
      onTerminatedCb = fn;
    },
    onError(fn) {
      onErrorCb = fn;
    },
    onStopped(fn) {
      onStoppedCb = fn;
    },
    onOutOfFuel(fn) {
      onOutOfFuelCb = fn;
    },
  };
}