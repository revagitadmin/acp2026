#!/usr/bin/env bats

@test "concatenates two strings" {
  result=$(printf "hello\nworld\n" | ./demo8)
  echo "$result" | grep -q "helloworld"
}

@test "concatenates two different strings" {
  result=$(printf "good\nmorning\n" | ./demo8)
  echo "$result" | grep -q "goodmorning"
}

@test "concatenates with numbers in string" {
  result=$(printf "abc\n123\n" | ./demo8)
  echo "$result" | grep -q "abc123"
}
