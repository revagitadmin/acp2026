#!/usr/bin/env bats

@test "swap two arrays of size 3" {
  result=$(echo "3
1
2
3
4
5
6" | ./demo5)
  echo "$result" | grep -q "4"
  echo "$result" | grep -q "1"
}

@test "swap two arrays of size 2" {
  result=$(echo "2
10
20
30
40" | ./demo5)
  echo "$result" | grep -q "30"
  echo "$result" | grep -q "10"
}
