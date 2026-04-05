#!/usr/bin/env bats

@test "TC1: simple increasing numbers" {
  run bash -c "echo -e '3\n1\n2\n3' | ./demo1"
  [[ "$output" == *"Maximum value = 3.00"* ]]
}

@test "TC2: decreasing numbers" {
  run bash -c "echo -e '3\n5\n4\n1' | ./demo1"
  [[ "$output" == *"Maximum value = 5.00"* ]]
}

@test "TC3: all same values" {
  run bash -c "echo -e '3\n2\n2\n2' | ./demo1"
  [[ "$output" == *"Maximum value = 2.00"* ]]
}

@test "TC4: negative numbers" {
  run bash -c "echo -e '3\n-1\n-2\n-3' | ./demo1"
  [[ "$output" == *"Maximum value = -1.00"* ]]
}

@test "TC5: mixed positive and negative" {
  run bash -c "echo -e '4\n-1\n5\n2\n3' | ./demo1"
  [[ "$output" == *"Maximum value = 5.00"* ]]
}

@test "TC6: single element" {
  run bash -c "echo -e '1\n10' | ./demo1"
  [[ "$output" == *"Maximum value = 10.00"* ]]
}

@test "TC7: decimals" {
  run bash -c "echo -e '3\n1.5\n2.7\n2.6' | ./demo1"
  [[ "$output" == *"Maximum value = 2.70"* ]]
}

@test "TC8: large numbers" {
  run bash -c "echo -e '3\n1000\n2000\n1500' | ./demo1"
  [[ "$output" == *"Maximum value = 2000.00"* ]]
}

@test "TC9: max at first index" {
  run bash -c "echo -e '3\n9\n2\n3' | ./demo1"
  [[ "$output" == *"Index of maximum value = 0"* ]]
}

@test "TC10: max at last index" {
  run bash -c "echo -e '3\n1\n2\n9' | ./demo1"
  [[ "$output" == *"Index of maximum value = 2"* ]]
}

@test "TC11: max in middle" {
  run bash -c "echo -e '3\n1\n9\n2' | ./demo1"
  [[ "$output" == *"Index of maximum value = 1"* ]]
}

@test "TC12: zeros" {
  run bash -c "echo -e '3\n0\n0\n0' | ./demo1"
  [[ "$output" == *"Maximum value = 0.00"* ]]
}

@test "TC13: mixed decimals" {
  run bash -c "echo -e '4\n1.1\n2.2\n3.3\n2.9' | ./demo1"
  [[ "$output" == *"Maximum value = 3.30"* ]]
}

@test "TC14: negative decimals" {
  run bash -c "echo -e '3\n-1.5\n-0.5\n-3.2' | ./demo1"
  [[ "$output" == *"Maximum value = -0.50"* ]]
}

@test "TC15: large dataset" {
  run bash -c "echo -e '5\n1\n9\n3\n7\n5' | ./demo1"
  [[ "$output" == *"Maximum value = 9.00"* ]]
}