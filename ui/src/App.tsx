import { useEffect, useMemo, useState } from "react";
import "./App.css";

import { parse } from "./core/parse.js";
import { validate, isValidationError, stringToBytes, bytesToString } from "./core/validate.ts";
import { createInterpreterClient } from "./worker/client.js";
import { createTape } from "./core/types.js";
import type { Program, State } from "./core/types.js";

function createInitialState(input: number[]): State {
  return {
    tape: createTape(),
    ptr: 0,
    pc: 0,
    input,
    output: [],
  };
}

export default function App() {
  const client = useMemo(() => createInterpreterClient(), []);

  const [code, setCode] = useState("++++++++[>++++++++<-]>+.");
  const [input, setInput] = useState("");

  const [state, setState] = useState<State | null>(null);
  const [steps, setSteps] = useState(0);
  const [status, setStatus] = useState<
    "idle" | "running" | "terminated" | "error" | "stopped" | "fuel"
  >("idle");

  useEffect(() => {
    client.onProgress((s, n) => {
      setState(s);
      setSteps(n);
      setStatus("running");
    });

    client.onTerminated((s, n) => {
      setState(s);
      setSteps(n);
      setStatus("terminated");
    });

    client.onError((s, _e, n) => {
      setState(s);
      setSteps(n);
      setStatus("error");
    });

    client.onStopped((s, n) => {
      setState(s);
      setSteps(n);
      setStatus("stopped");
    });

    client.onOutOfFuel((s, n) => {
      setState(s);
      setSteps(n);
      setStatus("fuel");
    });
  }, [client]);

  function handleRun() {
    try {
      const instructions = parse(code);
      const result = validate(instructions);

      if (isValidationError(result)) {
        alert(`Validation error at index ${result.index}`);
        return;
      }

      const program: Program = result;
      const initialState = createInitialState(stringToBytes(input));

      setState(initialState);
      setSteps(0);
      setStatus("running");

      client.start({
        program,
        state: initialState,
        batchSize: 1000,
        maxSteps: 100000,
      });
    } catch (e) {
      console.error(e);
      alert("Failed to run program");
    }
  }

  function handleStop() {
    client.stop();
  }

  return (
    <div style={{ padding: 20, fontFamily: "monospace" }}>
      <h1>Brainfuck Playground</h1>

      <h3>Code</h3>
      <textarea
        value={code}
        onChange={(e) => setCode(e.target.value)}
        rows={6}
        style={{ width: "100%" }}
      />

      <h3>Input</h3>
      <input
        value={input}
        onChange={(e) => setInput(e.target.value)}
        style={{ width: "100%" }}
      />

      <div style={{ marginTop: 10 }}>
        <button onClick={handleRun}>Run</button>
        <button onClick={handleStop} style={{ marginLeft: 10 }}>
          Stop
        </button>
      </div>

      <h3>Status: {status}</h3>
      <p>Steps: {steps}</p>

      {state && (
        <>
          <h3>Output</h3>
          <div>{bytesToString(state.output)}</div>

          <h3>Pointer: {state.ptr}</h3>

          <h3>Tape (first 20 cells)</h3>
          <div>
            {state.tape.slice(0, 20).map((v, i) => (
              <span
                key={i}
                style={{
                  display: "inline-block",
                  width: 30,
                  background: i === state.ptr ? "yellow" : "transparent",
                }}
              >
                {v}
              </span>
            ))}
          </div>
        </>
      )}
    </div>
  );
}