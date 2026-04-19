import Brainfuck.Instruction

namespace Brainfuck

/--
Symmetric partner table: `pair[i]` is the index of the matching bracket, or `-1` if `i` is not a loop
boundary (matches TS `jumpTable.pair`).
Well-formed programs should satisfy `pair.size = instructions.size` and consistent bracket links.
-/
structure JumpTable where
  pair : Array Int

structure Program where
  instructions : Array Instruction
  jumpTable : JumpTable

end Brainfuck
