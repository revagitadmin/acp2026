#!/usr/bin/env bats

@test "largest rectangle test case 1" {
    run bash -c 'printf "R1\n5\n4\nR2\n6\n3\nR3\n7\n2\n" | ./demo2'
  [ "$status" -eq 0 ]
  [[ "$output" == *"Largest rectangle: R1"* ]]
  [[ "$output" == *"Area = 20.00"* ]]
}

@test "largest rectangle test case 2" {
  run bash -c 'printf "R1\n2\n3\nR2\n5\n5\nR3\n4\n4\n" | ./demo2'
  [ "$status" -eq 0 ]
  [[ "$output" == *"Largest rectangle: R2"* ]]
  [[ "$output" == *"Area = 25.00"* ]]
}

@test "largest rectangle test case 3" {
  run bash -c 'printf "A\n10\n2\nB\n3\n3\nC\n4\n4\n" | ./demo2'
  [ "$status" -eq 0 ]
  [[ "$output" == *"Largest rectangle: A"* ]]
  [[ "$output" == *"Area = 20.00"* ]]
}

@test "largest rectangle test case 4" {
  run bash -c 'printf "X\n1\n2\nY\n3\n3\nZ\n2\n2\n" | ./demo2'
  [ "$status" -eq 0 ]
  [[ "$output" == *"Largest rectangle: Y"* ]]
  [[ "$output" == *"Area = 9.00"* ]]
}