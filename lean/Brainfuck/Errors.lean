namespace Brainfuck

inductive RuntimeError where
  | pointerOutOfBounds (attemptedPtr : Int)
  | noInput

inductive ValidationError where
  | unmatchedOpeningBracket (index : Nat)
  | unmatchedClosingBracket (index : Nat)

end Brainfuck
