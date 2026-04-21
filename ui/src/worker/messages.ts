import type { Program, RuntimeError, State } from "../core/types.js";

export type WorkerStartMessage = {
  readonly type: "start";
  readonly program: Program;
  readonly state: State;
  readonly batchSize: number;
  readonly maxSteps?: number;
};

export type WorkerStopMessage = {
  readonly type: "stop";
};

export type WorkerIncomingMessage = WorkerStartMessage | WorkerStopMessage;

export type WorkerProgressMessage = {
  readonly type: "progress";
  readonly state: State;
  readonly stepsExecuted: number;
};

export type WorkerTerminatedMessage = {
  readonly type: "terminated";
  readonly state: State;
  readonly stepsExecuted: number;
};

export type WorkerErrorMessage = {
  readonly type: "error";
  readonly state: State;
  readonly error: RuntimeError;
  readonly stepsExecuted: number;
};

export type WorkerStoppedMessage = {
  readonly type: "stopped";
  readonly state: State;
  readonly stepsExecuted: number;
};

export type WorkerOutOfFuelMessage = {
  readonly type: "out_of_fuel";
  readonly state: State;
  readonly stepsExecuted: number;
};

export type WorkerOutgoingMessage =
  | WorkerProgressMessage
  | WorkerTerminatedMessage
  | WorkerErrorMessage
  | WorkerStoppedMessage
  | WorkerOutOfFuelMessage;