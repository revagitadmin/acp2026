#!/usr/bin/env bats

@test "destination found single match" {
  run bash -c "printf '101\nDelhi\n50\n102\nMumbai\n60\n103\nChennai\n40\n104\nKolkata\n70\nDelhi\n' | ./demo2"

  [ "$status" -eq 0 ]
  [[ "$output" == *"Flight found: 101"* ]]
}

@test "destination found multiple matches" {
  run bash -c "printf '101\nDelhi\n50\n102\nMumbai\n60\n103\nDelhi\n40\n104\nDelhi\n70\nDelhi\n' | ./demo2"

  [ "$status" -eq 0 ]
  [[ "$output" == *"Flight found: 101"* ]]
  [[ "$output" == *"Flight found: 103"* ]]
  [[ "$output" == *"Flight found: 104"* ]]
}

@test "destination not found (edge case)" {
  run bash -c "printf '101\nDelhi\n50\n102\nMumbai\n60\n103\nChennai\n40\n104\nKolkata\n70\nParis\n' | ./demo2"

  [ "$status" -eq 0 ]
  [[ "$output" == *"No flight found"* ]]
}

@test "case sensitivity edge case" {
  run bash -c "printf '101\nDelhi\n50\n102\nMumbai\n60\n103\nChennai\n40\n104\nKolkata\n70\ndelhi\n' | ./demo2"

  [ "$status" -eq 0 ]
  [[ "$output" == *"No flight found"* ]]
}

@test "all flights same destination" {
  run bash -c "printf '101\nDelhi\n50\n102\nDelhi\n60\n103\nDelhi\n40\n104\nDelhi\n70\nDelhi\n' | ./demo2"

  [ "$status" -eq 0 ]
  [[ "$output" == *"Flight found: 101"* ]]
  [[ "$output" == *"Flight found: 102"* ]]
  [[ "$output" == *"Flight found: 103"* ]]
  [[ "$output" == *"Flight found: 104"* ]]
}