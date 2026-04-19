import Init.Data.Array.Lemmas
import Init.Data.Vector
import Brainfuck.Constants

namespace Brainfuck

/-- Fixed-length tape: exactly `TAPE_LEN` cells, each a byte in 0..255. -/
abbrev Tape := Vector (Fin 256) TAPE_LEN

/-- Same values as `Vector.get`, but Nat-indexed `GetElem` lines up with `Vector.set` in proofs. -/
def readCell (t : Tape) (i : Fin TAPE_LEN) : Fin 256 :=
  match i with
  | ⟨idx, h⟩ => t[idx]'h

/-- Reduce a natural to a byte (mod 256), matching TS `wrapByte`. -/
def wrapByte (n : Nat) : Fin 256 :=
  Fin.ofNat' 256 n

/--
Update one cell; returns a new `Tape` of the same length.
Uses `Fin` destructuring so the bound proof matches `Vector.set`'s `(i : Nat) (h : i < TAPE_LEN)`.
-/
def writeCell (t : Tape) (i : Fin TAPE_LEN) (value : Nat) : Tape :=
  match i with
  | ⟨idx, h⟩ => Vector.set t idx (wrapByte value) h

/-- Used by `Proofs.read_after_write_same` — `Array.get_set_eq` applies to `Vector.toArray`. -/
theorem readCell_writeCell_eq_wrapByte (t : Tape) (i : Fin TAPE_LEN) (v : Nat) :
    readCell (writeCell t i v) i = wrapByte v := by
  rcases i with ⟨idx, h⟩
  dsimp [readCell, writeCell]
  simpa [Vector.size_toArray] using Array.get_set_eq t.toArray idx (wrapByte v) (by simpa [Vector.size_toArray] using h)

end Brainfuck
