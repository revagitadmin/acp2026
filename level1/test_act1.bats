#!/usr/bin/env bats

@test "finds highest and lowest temperature" {
  result=$(printf "7\n32.5\n28.0\n35.1\n30.0\n27.5\n33.0\n29.8\n" | ./act1)
  echo "$result" | grep -q "35.10"
  echo "$result" | grep -q "27.50"
}