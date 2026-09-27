#!/usr/bin/env bats

@test "basic swap test" {
  run bash -c "printf '3\n1\n2\n3\n4\n5\n6\n' | ./demo5"

  [ "$status" -eq 0 ]
  [[ "$output" == *"Array A: 4 5 6"* ]]
  [[ "$output" == *"Array B: 1 2 3"* ]]
}

@test "single element array" {
  run bash -c "printf '1\n10\n20\n' | ./demo5"

  [ "$status" -eq 0 ]
  [[ "$output" == *"Array A: 20"* ]]
  [[ "$output" == *"Array B: 10"* ]]
}

@test "arrays with same elements" {
  run bash -c "printf '3\n1\n1\n1\n1\n1\n1\n' | ./demo5"

  [ "$status" -eq 0 ]
  [[ "$output" == *"Array A: 1 1 1"* ]]
  [[ "$output" == *"Array B: 1 1 1"* ]]
}

@test "negative numbers test" {
  run bash -c "printf '3\n-1\n-2\n-3\n4\n5\n6\n' | ./demo5"

  [ "$status" -eq 0 ]
  [[ "$output" == *"Array A: 4 5 6"* ]]
  [[ "$output" == *"Array B: -1 -2 -3"* ]]
}

@test "zero elements test" {
  run bash -c "printf '0\n' | ./demo5"

  [ "$status" -eq 0 ]
  [[ "$output" == *""* ]]
}