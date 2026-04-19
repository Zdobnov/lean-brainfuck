import Brainfuck.Program
import Brainfuck.Run
import Brainfuck.State
import Brainfuck.Step
import Brainfuck.Tape

namespace Brainfuck

theorem runSteps_zero (p : Program) (s : State) :
    runSteps 0 p s = StepResult.running s := by
  rfl

theorem read_after_write_same (t : Tape) (i : Fin TAPE_LEN) (v : Nat) :
    readCell (writeCell t i v) i = wrapByte v :=
  readCell_writeCell_eq_wrapByte t i v

theorem step_terminated_when_pc_at_end (p : Program) (s : State)
    (h : s.pc ≥ p.instructions.size) :
    step p s = StepResult.terminated s := by
  simp [step, h]

end Brainfuck
