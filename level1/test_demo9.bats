#!/usr/bin/env bats

@test "basic file read/write test" {
  run bash -c "printf '2\n1 John 85.5\n2 Alice 90.0\n' | ./demo9"

  [ "$status" -eq 0 ]
  [[ "$output" == *"1	John	85.50"* ]]
  [[ "$output" == *"2	Alice	90.00"* ]]
}

@test "single student test" {
  run bash -c "printf '1\n5 Bob 75.0\n' | ./demo9"

  [ "$status" -eq 0 ]
  [[ "$output" == *"5	Bob	75.00"* ]]
}

@test "multiple students test" {
  run bash -c "printf '3\n1 A 50\n2 B 60\n3 C 70\n' | ./demo9"

  [ "$status" -eq 0 ]
  [[ "$output" == *"1	A	50.00"* ]]
  [[ "$output" == *"2	B	60.00"* ]]
  [[ "$output" == *"3	C	70.00"* ]]
}

@test "zero students test" {
  run bash -c "printf '0\n' | ./demo9"

  [ "$status" -eq 0 ]
}

@test "float precision test" {
  run bash -c "printf '1\n10 Ram 88.123\n' | ./demo9"

  [ "$status" -eq 0 ]
  [[ "$output" == *"10	Ram	88.12"* ]]
}