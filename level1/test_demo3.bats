#!/usr/bin/env bats

@test "basic case - first rectangle largest" {
  run bash -c "printf '3\n5\n4\n6\n3\n7\n2\n' | ./demo3"

  [ "$status" -eq 0 ]
  [[ "$output" == *"Length = 5.00"* ]]
  [[ "$output" == *"Width = 4.00"* ]]
  [[ "$output" == *"Area = 20.00"* ]]
}

@test "second rectangle largest" {
  run bash -c "printf '3\n2\n3\n5\n5\n4\n4\n' | ./demo3"

  [ "$status" -eq 0 ]
  [[ "$output" == *"Length = 5.00"* ]]
  [[ "$output" == *"Width = 5.00"* ]]
  [[ "$output" == *"Area = 25.00"* ]]
}

@test "last rectangle largest" {
  run bash -c "printf '3\n1\n2\n3\n3\n6\n6\n' | ./demo3"

  [ "$status" -eq 0 ]
  [[ "$output" == *"Length = 6.00"* ]]
  [[ "$output" == *"Width = 6.00"* ]]
  [[ "$output" == *"Area = 36.00"* ]]
}

@test "single rectangle case" {
  run bash -c "printf '1\n4\n5\n' | ./demo3"

  [ "$status" -eq 0 ]
  [[ "$output" == *"Length = 4.00"* ]]
  [[ "$output" == *"Width = 5.00"* ]]
  [[ "$output" == *"Area = 20.00"* ]]
}

@test "invalid input case" {
  run bash -c "printf '0\n' | ./demo3"

  [ "$status" -eq 0 ]
  [[ "$output" == *"Invalid number of rectangles"* ]]
}