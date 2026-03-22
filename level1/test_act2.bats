#!/usr/bin/env bats

@test "free scheme for units less than 50" {
  result=$(printf "35\n3\n" | ./act2)
  echo "$result" | grep -q "0.00"
  echo "$result" | grep -q "free unit consumption scheme"
}

@test "normal bill for units between 50 and 100" {
  result=$(printf "75\n3\n" | ./act2)
  echo "$result" | grep -q "225.00"
  echo "$result" | grep -q "Normal consumption"
}

@test "extra charge for units above 100" {
  result=$(printf "120\n3\n" | ./act2)
  echo "$result" | grep -q "460.00"
  echo "$result" | grep -q "High consumption alert"
}
