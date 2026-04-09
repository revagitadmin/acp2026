#!/usr/bin/env bats

@test "name1 is longer" {
  result=$(printf "Trivikram\nRam\n" | ./act7)
  echo "$result" | grep -q "name 1 is greater"
}

@test "name2 is longer" {
  result=$(printf "Ram\nTrivikram\n" | ./act7)
  echo "$result" | grep -q "name 2 is greater"
}

@test "both names equal length" {
  result=$(printf "Ram\nAnu\n" | ./act7)
  echo "$result" | grep -q "Both are equal"
}
