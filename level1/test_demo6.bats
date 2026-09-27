#!/usr/bin/env bats

@test "basic dynamic array test" {
  run bash -c "printf '3\n1\n2\n3\n' | ./demo6"

  [ "$status" -eq 0 ]
  [[ "$output" == *"1 2 3"* ]]
}

@test "single element array" {
  run bash -c "printf '1\n10\n' | ./demo6"

  [ "$status" -eq 0 ]
  [[ "$output" == *"10"* ]]
}

@test "negative numbers test" {
  run bash -c "printf '3\n-1\n-2\n-3\n' | ./demo6"

  [ "$status" -eq 0 ]
  [[ "$output" == *"-1 -2 -3"* ]]
}

@test "mixed numbers test" {
  run bash -c "printf '5\n1\n-2\n3\n0\n5\n' | ./demo6"

  [ "$status" -eq 0 ]
  [[ "$output" == *"1 -2 3 0 5"* ]]
}

@test "zero size (edge case)" {
  run bash -c "printf '0\n' | ./demo6"

  [ "$status" -eq 0 ]
}