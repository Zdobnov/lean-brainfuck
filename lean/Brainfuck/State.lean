import Brainfuck.Tape

namespace Brainfuck

structure State where
  tape : Tape
  ptr : Nat
  pc : Nat
  input : List (Fin 256)
  output : List (Fin 256)

end Brainfuck
