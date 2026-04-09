#!/usr/bin/env bats

@test "swaps two strings" {
  result=$(printf "hello\nworld\n" | ./act5)
  echo "$result" | grep -q "world"
  echo "$result" | grep -q "hello"
}

@test "swaps two different strings" {
  result=$(printf "apple\nbanana\n" | ./act5)
  echo "$result" | grep -q "banana"
  echo "$result" | grep -q "apple"
}
