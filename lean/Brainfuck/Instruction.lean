namespace Brainfuck

/-- Raw Brainfuck instruction (loop boundaries; jump table lives in `Program`). -/
inductive Instruction where
  | moveRight
  | moveLeft
  | inc
  | dec
  | output
  | input
  | loopStart
  | loopEnd

end Brainfuck
