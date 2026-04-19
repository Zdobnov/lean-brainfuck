namespace Brainfuck

/-- Brainfuck tape length per spec (matches TS `TAPE_LEN`). -/
def TAPE_LEN : Nat := 30000

theorem tapeLen_pos : 0 < TAPE_LEN := by decide

end Brainfuck
