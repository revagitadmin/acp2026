#!/usr/bin/env bats

# ─── Basic Tests ───────────────────────────────────────────

@test "finds max in a simple list" {
  run bash -c "echo '5
1.5 3.2 9.8 2.1 4.0' | ./find_max"
  [ "$status" -eq 0 ]
  [[ "$output" == *"Maximum value : 9.80"* ]]
  [[ "$output" == *"Found at index: 2"* ]]
}

@test "finds max at first index" {
  run bash -c "echo '4
9.0 3.0 1.5 2.5' | ./find_max"
  [ "$status" -eq 0 ]
  [[ "$output" == *"Maximum value : 9.00"* ]]
  [[ "$output" == *"Found at index: 0"* ]]
}

@test "finds max at last index" {
  run bash -c "echo '4
1.0 2.0 3.0 9.9' | ./find_max"
  [ "$status" -eq 0 ]
  [[ "$output" == *"Maximum value : 9.90"* ]]
  [[ "$output" == *"Found at index: 3"* ]]
}

# ─── Single Element ────────────────────────────────────────

@test "single element is the max" {
  run bash -c "echo '1
42.0' | ./find_max"
  [ "$status" -eq 0 ]
  [[ "$output" == *"Maximum value : 42.00"* ]]
  [[ "$output" == *"Found at index: 0"* ]]
}

# ─── Negative Numbers ──────────────────────────────────────

@test "handles all negative numbers" {
  run bash -c "echo '3
-1.5 -0.5 -3.0' | ./find_max"
  [ "$status" -eq 0 ]
  [[ "$output" == *"Maximum value : -0.50"* ]]
  [[ "$output" == *"Found at index: 1"* ]]
}

@test "handles mix of negative and positive" {
  run bash -c "echo '4
-5.0 0.0 3.5 -1.0' | ./find_max"
  [ "$status" -eq 0 ]
  [[ "$output" == *"Maximum value : 3.50"* ]]
  [[ "$output" == *"Found at index: 2"* ]]
}

# ─── Duplicate Max Values ──────────────────────────────────

@test "returns first index when duplicates exist" {
  run bash -c "echo '4
5.0 9.9 9.9 1.0' | ./find_max"
  [ "$status" -eq 0 ]
  [[ "$output" == *"Maximum value : 9.90"* ]]
  [[ "$output" == *"Found at index: 1"* ]]
}

# ─── Edge Case: Invalid n ──────────────────────────────────

@test "rejects n = 0" {
  run bash -c "echo '0' | ./find_max"
  [ "$status" -eq 1 ]
  [[ "$output" == *"n must be greater than 0"* ]]
}

@test "rejects negative n" {
  run bash -c "echo '-3' | ./find_max"
  [ "$status" -eq 1 ]
  [[ "$output" == *"n must be greater than 0"* ]]
}