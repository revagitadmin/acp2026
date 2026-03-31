#!/usr/bin/env bats

@test "counts vowels and consonants in Hello" {
  result=$(printf "Hello\n" | ./act8)
  echo "$result" | grep -q "vowels: 2"
  echo "$result" | grep -q "consonants: 3"
}

@test "counts vowels and consonants in Hello World" {
  result=$(printf "Hello World\n" | ./act8)
  echo "$result" | grep -q "vowels: 3"
  echo "$result" | grep -q "consonants: 7"
}

@test "counts vowels only string" {
  result=$(printf "aeiou\n" | ./act8)
  echo "$result" | grep -q "vowels: 5"
  echo "$result" | grep -q "consonants: 0"
}
