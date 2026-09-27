#!/usr/bin/env bats

@test "Maximum element in normal array" {
  run bash -c "printf '5\n1\n4\n2\n7\n3\n' | ./demo1"

  [ "$status" -eq 0 ]
  [[ "$output" == *"maximum value=7.00"* ]]
  [[ "$output" == *"indices of maximum value:3"* ]]
}

@test "Maximum at first index" {
  run bash -c "printf '4\n9\n3\n2\n1\n' | ./demo1"

  [ "$status" -eq 0 ]
  [[ "$output" == *"maximum value=9.00"* ]]
  [[ "$output" == *"indices of maximum value:0"* ]]
}

@test "Maximum at last index" {
  run bash -c "printf '4\n1\n2\n3\n8\n' | ./demo1"

  [ "$status" -eq 0 ]
  [[ "$output" == *"maximum value=8.00"* ]]
  [[ "$output" == *"indices of maximum value:3"* ]]
}

@test "Negative numbers test" {
  run bash -c "printf '3\n-5\n-2\n-9\n' | ./demo1"

  [ "$status" -eq 0 ]
  [[ "$output" == *"maximum value=-2.00"* ]]
  [[ "$output" == *"indices of maximum value:1"* ]]
}

@test "Single element array" {
  run bash -c "printf '1\n10\n' | ./demo1"

  [ "$status" -eq 0 ]
  [[ "$output" == *"maximum value=10.00"* ]]
  [[ "$output" == *"indices of maximum value:0"* ]]
}