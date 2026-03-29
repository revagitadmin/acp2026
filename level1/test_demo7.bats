#!/usr/bin/env bats

@test "equal strings returns 0" {
  result=$(echo "apple
apple" | ./demo7)
  echo "$result" | grep -q "both strings are equal"
}

@test "string1 greater returns 1" {
  result=$(echo "banana
apple" | ./demo7)
  echo "$result" | grep -q "string 1 is greater"
}

@test "string2 greater returns -1" {
  result=$(echo "apple
banana" | ./demo7)
  echo "$result" | grep -q "string 2 is greater"
}
