import { describe, expect, it } from "vitest";
import { parse } from "./parse.js";

describe("parse", () => {
  it("returns empty array for empty string", () => {
    expect(parse("")).toEqual([]);
  });

  it("ignores non-Brainfuck characters", () => {
    expect(parse("a\nb\t \rhello 世界")).toEqual([]);
    expect(parse("x>x")).toEqual([
      { tag: "MoveRight" },
    ]);
    expect(parse("foo+bar-baz")).toEqual([{ tag: "Inc" }, { tag: "Dec" }]);
  });

  it("maps all Brainfuck symbols in order", () => {
    expect(parse("><+-.,[]")).toEqual([
      { tag: "MoveRight" },
      { tag: "MoveLeft" },
      { tag: "Inc" },
      { tag: "Dec" },
      { tag: "Output" },
      { tag: "Input" },
      { tag: "LoopStart" },
      { tag: "LoopEnd" },
    ]);
  });
});
