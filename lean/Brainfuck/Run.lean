import Brainfuck.Program
import Brainfuck.State
import Brainfuck.Step

namespace Brainfuck

/--
Runs at most `maxSteps` calls to `step`. Stops immediately on `terminated` or `error`.
If `maxSteps = 0`, returns `running` with the initial state (no `step` calls).
Matches TS `runSteps(program, state, maxSteps)` up to argument order `(maxSteps, program, state)`.
-/
def runSteps (maxSteps : Nat) (p : Program) (s : State) : StepResult :=
  match maxSteps with
  | 0 => .running s
  | maxSteps'+1 =>
      match step p s with
      | .terminated st => .terminated st
      | .error st e => .error st e
      | .running s' => runSteps maxSteps' p s'

end Brainfuck
