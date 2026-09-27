#!/usr/bin/env bats

@test "equal strings test" {
  run bash -c "printf 'Apple\nApple\n' | ./demo7"

  [ "$status" -eq 0 ]
  [[ "$output" == *"Strings are equal"* ]]
}

@test "first string greater" {
  run bash -c "printf 'Delhi\nChennai\n' | ./demo7"

  [ "$status" -eq 0 ]
  [[ "$output" == *"String 1 is greater"* ]]
}

@test "second string greater" {
  run bash -c "printf 'Cat\nDog\n' | ./demo7"

  [ "$status" -eq 0 ]
  [[ "$output" == *"String 2 is greater"* ]]
}

@test "prefix case (shorter string)" {
  run bash -c "printf 'Cat\nCater\n' | ./demo7"

  [ "$status" -eq 0 ]
  [[ "$output" == *"String 2 is greater"* ]]
}

@test "reverse prefix case" {
  run bash -c "printf 'Cater\nCat\n' | ./demo7"

  [ "$status" -eq 0 ]
  [[ "$output" == *"String 1 is greater"* ]]
}