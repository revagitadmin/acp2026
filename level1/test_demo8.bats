#!/usr/bin/env bats

@test "basic concatenation" {
  run bash -c "printf 'Hello\nWorld\n' | ./demo8"

  [ "$status" -eq 0 ]
  [[ "$output" == *"Concatenated string: HelloWorld"* ]]
}

@test "single character strings" {
  run bash -c "printf 'A\nB\n' | ./demo8"

  [ "$status" -eq 0 ]
  [[ "$output" == *"Concatenated string: AB"* ]]
}

@test "numbers as strings" {
  run bash -c "printf '123\n456\n' | ./demo8"

  [ "$status" -eq 0 ]
  [[ "$output" == *"Concatenated string: 123456"* ]]
}

@test "same strings" {
  run bash -c "printf 'Test\nTest\n' | ./demo8"

  [ "$status" -eq 0 ]
  [[ "$output" == *"Concatenated string: TestTest"* ]]
}

@test "empty-like case (second short)" {
  run bash -c "printf 'Hello\nA\n' | ./demo8"

  [ "$status" -eq 0 ]
  [[ "$output" == *"Concatenated string: HelloA"* ]]
}