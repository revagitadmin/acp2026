#!/usr/bin/env bats

@test "creates and prints array of size 3" {
  result=$(echo "3
10
20
30" | ./demo6)
  echo "$result" | grep -q "10"
  echo "$result" | grep -q "20"
  echo "$result" | grep -q "30"
}

@test "creates and prints array of size 2" {
  result=$(echo "2
5
15" | ./demo6)
  echo "$result" | grep -q "5"
  echo "$result" | grep -q "15"
}

@test "pointer set to null after delete" {
  result=$(echo "2
1
2" | ./demo6)
  echo "$result" | grep -q "NULL"
}
