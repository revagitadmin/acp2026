#!/usr/bin/env bats

# ─── Basic: first rectangle is largest ────────────────────

@test "rectangle 1 has largest area" {
  run bash -c "printf '3\n10\n5\n2\n3\n4\n2\n' | ./demo3.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"The Rectangle 1"* ]]
  [[ "$output" == *"largest area"* ]]
}

# ─── Last rectangle is largest ────────────────────────────

@test "rectangle 3 has largest area" {
  run bash -c "printf '3\n2\n3\n4\n2\n10\n5\n' | ./demo3.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"The Rectangle 3"* ]]
  [[ "$output" == *"largest area"* ]]
}

# ─── Middle rectangle is largest ──────────────────────────

@test "rectangle 2 has largest area" {
  run bash -c "printf '3\n2\n3\n10\n5\n4\n2\n' | ./demo3.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"The Rectangle 2"* ]]
  [[ "$output" == *"largest area"* ]]
}

# ─── Single rectangle ─────────────────────────────────────

@test "single rectangle is the largest" {
  run bash -c "printf '1\n6\n4\n' | ./demo3.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"The Rectangle 1"* ]]
  [[ "$output" == *"largest area"* ]]
}

# ─── Area display check ───────────────────────────────────

@test "areas are displayed correctly" {
  run bash -c "printf '2\n4\n3\n5\n2\n' | ./demo3.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"The area of rectangle 1 is 12"* ]]
  [[ "$output" == *"The area of rectangle 2 is 10"* ]]
}

# ─── Float dimensions ─────────────────────────────────────

@test "handles float dimensions" {
  run bash -c "printf '2\n3\n4\n6\n3\n' | ./demo3.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"The Rectangle 2"* ]]
  [[ "$output" == *"largest area"* ]]
}

# ─── All equal areas ──────────────────────────────────────

@test "all rectangles have equal area returns rectangle 1" {
  run bash -c "printf '3\n4\n5\n10\n2\n5\n4\n' | ./demo3.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"The Rectangle 1"* ]]
  [[ "$output" == *"largest area"* ]]
}

# ─── Two rectangles ───────────────────────────────────────

@test "two rectangles first is largest" {
  run bash -c "printf '2\n8\n8\n3\n3\n' | ./demo3.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"The Rectangle 1"* ]]
  [[ "$output" == *"largest area"* ]]
}

# ─── Large number of rectangles ───────────────────────────

@test "five rectangles last is largest" {
  run bash -c "printf '5\n1\n1\n2\n2\n3\n3\n4\n4\n10\n10\n' | ./demo3.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"The Rectangle 5"* ]]
  [[ "$output" == *"largest area"* ]]
}