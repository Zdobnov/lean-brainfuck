import Brainfuck.Constants
import Brainfuck.Errors
import Brainfuck.Program
import Brainfuck.State
import Brainfuck.Tape

namespace Brainfuck

inductive StepResult where
  | running (s : State)
  | terminated (s : State)
  | error (s : State) (e : RuntimeError)

/--
Partner index `j` at `pc`; target PC is `j + 1` (as `Nat`), matching TS `pair[pc] + 1` for valid tables.
Negative `j` (e.g. TS sentinel `-1`) is treated as malformed here: conservative fall-through `pc + 1`.
-/
private def jumpAfterPartner (jt : JumpTable) (pc : Nat) : Nat :=
  match jt.pair.get? pc with
  | none => pc + 1
  | some j =>
      if j < 0 then
        pc + 1
      else
        Int.toNat j + 1

def step (p : Program) (s : State) : StepResult :=
  let n := p.instructions.size
  if _ : s.pc ≥ n then
    StepResult.terminated s
  else
    match p.instructions.get? s.pc with
    | none => StepResult.terminated s
    | some .moveRight =>
        if s.ptr = TAPE_LEN - 1 then
          StepResult.error s (.pointerOutOfBounds (Int.ofNat (s.ptr + 1)))
        else
          StepResult.running { s with ptr := s.ptr + 1, pc := s.pc + 1 }
    | some .moveLeft =>
        if s.ptr = 0 then
          StepResult.error s (.pointerOutOfBounds (-1))
        else
          StepResult.running { s with ptr := s.ptr - 1, pc := s.pc + 1 }
    | some .inc =>
        if hptr : s.ptr < TAPE_LEN then
          let i : Fin TAPE_LEN := ⟨s.ptr, hptr⟩
          let v := readCell s.tape i
          StepResult.running {
            s with
              tape := writeCell s.tape i (Fin.val v + 1),
              pc := s.pc + 1
          }
        else
          StepResult.error s (.pointerOutOfBounds (Int.ofNat s.ptr))
    | some .dec =>
        if hptr : s.ptr < TAPE_LEN then
          let i : Fin TAPE_LEN := ⟨s.ptr, hptr⟩
          let v := readCell s.tape i
          StepResult.running {
            s with
              tape := writeCell s.tape i (Fin.val v + 255),
              pc := s.pc + 1
          }
        else
          StepResult.error s (.pointerOutOfBounds (Int.ofNat s.ptr))
    | some .output =>
        if hptr : s.ptr < TAPE_LEN then
          let i : Fin TAPE_LEN := ⟨s.ptr, hptr⟩
          let cell := readCell s.tape i
          StepResult.running {
            s with
              output := s.output ++ [cell],
              pc := s.pc + 1
          }
        else
          StepResult.error s (.pointerOutOfBounds (Int.ofNat s.ptr))
    | some .input =>
        match s.input with
        | [] => StepResult.error s .noInput
        | b :: bs =>
            if hptr : s.ptr < TAPE_LEN then
              let i : Fin TAPE_LEN := ⟨s.ptr, hptr⟩
              StepResult.running {
                s with
                  tape := writeCell s.tape i (Fin.val b),
                  input := bs,
                  pc := s.pc + 1
              }
            else
              StepResult.error s (.pointerOutOfBounds (Int.ofNat s.ptr))
    | some .loopStart =>
        if hptr : s.ptr < TAPE_LEN then
          let i : Fin TAPE_LEN := ⟨s.ptr, hptr⟩
          let cell := readCell s.tape i
          if Fin.val cell = 0 then
            StepResult.running { s with pc := jumpAfterPartner p.jumpTable s.pc }
          else
            StepResult.running { s with pc := s.pc + 1 }
        else
          StepResult.error s (.pointerOutOfBounds (Int.ofNat s.ptr))
    | some .loopEnd =>
        if hptr : s.ptr < TAPE_LEN then
          let i : Fin TAPE_LEN := ⟨s.ptr, hptr⟩
          let cell := readCell s.tape i
          if Fin.val cell ≠ 0 then
            StepResult.running { s with pc := jumpAfterPartner p.jumpTable s.pc }
          else
            StepResult.running { s with pc := s.pc + 1 }
        else
          StepResult.error s (.pointerOutOfBounds (Int.ofNat s.ptr))

end Brainfuck
