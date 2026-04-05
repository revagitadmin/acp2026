#!/usr/bin/env bats

# ---------------- EASY TEST CASES ----------------

@test "E1: simple increasing areas" {
  run bash -c "echo -e 'A\n2\n3\nB\n3\n4\nC\n4\n5' | ./a.exe"
  [[ "$output" == *"Rectangle with largest area: C"* ]]
}

@test "E2: first rectangle largest" {
  run bash -c "echo -e 'A\n5\n5\nB\n2\n2\nC\n3\n3' | ./a.exe"
  [[ "$output" == *"Rectangle with largest area: A"* ]]
}

@test "E3: second rectangle largest" {
  run bash -c "echo -e 'A\n1\n1\nB\n6\n2\nC\n2\n2' | ./a.exe"
  [[ "$output" == *"Rectangle with largest area: B"* ]]
}

@test "E4: all equal areas" {
  run bash -c "echo -e 'A\n2\n2\nB\n2\n2\nC\n2\n2' | ./a.exe"
  [[ "$output" == *"Rectangle with largest area: C"* ]]
}

@test "E5: decimal values" {
  run bash -c "echo -e 'A\n1.5\n2\nB\n2.0\n2\nC\n1\n3' | ./a.exe"
  [[ "$output" == *"Rectangle with largest area: B"* ]]
}

# ---------------- MEDIUM TEST CASES ----------------

@test "M1: negative dimensions" {
  run bash -c "echo -e 'A\n-2\n3\nB\n2\n2\nC\n1\n1' | ./a.exe"
  [[ "$output" == *"Rectangle with largest area: B"* ]]
}

@test "M2: zero area case" {
  run bash -c "echo -e 'A\n0\n5\nB\n2\n3\nC\n1\n1' | ./a.exe"
  [[ "$output" == *"Rectangle with largest area: B"* ]]
}

@test "M3: mixed decimals" {
  run bash -c "echo -e 'A\n2.5\n2\nB\n3.1\n1\nC\n1.5\n2' | ./a.exe"
  [[ "$output" == *"Rectangle with largest area: A"* ]]
}

@test "M4: large values" {
  run bash -c "echo -e 'A\n100\n200\nB\n300\n100\nC\n150\n150' | ./a.exe"
  [[ "$output" == *"Rectangle with largest area: B"* ]]
}

@test "M5: same max area (tie case)" {
  run bash -c "echo -e 'A\n2\n5\nB\n5\n2\nC\n3\n3' | ./a.exe"
  [[ "$output" == *"Rectangle with largest area: C"* ]]
}

# ---------------- DIFFICULT TEST CASES ----------------

@test "D1: very small decimals" {
  run bash -c "echo -e 'A\n0.1\n0.2\nB\n0.3\n0.1\nC\n0.05\n0.5' | ./a.exe"
  [[ "$output" == *"Rectangle with largest area: B"* ]]
}

@test "D2: negative and positive mix" {
  run bash -c "echo -e 'A\n-5\n-5\nB\n4\n4\nC\n3\n3' | ./a.exe"
  [[ "$output" == *"Rectangle with largest area: A"* ]]
}

@test "D3: floating precision" {
  run bash -c "echo -e 'A\n2.333\n3\nB\n3\n2.333\nC\n2\n4' | ./a.exe"
  [[ "$output" == *"Rectangle with largest area: C"* ]]
}

@test "D4: one very large dominating value" {
  run bash -c "echo -e 'A\n1\n1\nB\n2\n2\nC\n1000\n1000' | ./a.exe"
  [[ "$output" == *"Rectangle with largest area: C"* ]]
}

@test "D5: tricky equal comparisons" {
  run bash -c "echo -e 'A\n4\n5\nB\n2\n10\nC\n1\n20' | ./a.exe"
  [[ "$output" == *"Rectangle with largest area: C"* ]]
}