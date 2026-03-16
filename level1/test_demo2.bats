#!/usr/bin/env bats

@test "r1 has the largest area" {
  run bash -c "printf 'RectA\n10\n5\nRectB\n3\n2\nRectC\n4\n2\n' | ./demo2.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"RectA has the largest area: 50.00"* ]]
}

@test "r2 has the largest area" {
  run bash -c "printf 'RectA\n3\n2\nRectB\n10\n5\nRectC\n4\n2\n' | ./demo2.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"RectB has the largest area: 50.00"* ]]
}

@test "r3 has the largest area" {
  run bash -c "printf 'RectA\n3\n2\nRectB\n4\n2\nRectC\n10\n5\n' | ./demo2.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"RectC has the largest area: 50.00"* ]]
}

@test "all rectangles have equal area" {
  run bash -c "printf 'RectA\n5\n4\nRectB\n10\n2\nRectC\n4\n5\n' | ./demo2.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"Two or more rectangles have equal largest area: 20.00"* ]]
}

@test "two rectangles have equal largest area" {
  run bash -c "printf 'RectA\n10\n5\nRectB\n10\n5\nRectC\n2\n3\n' | ./demo2.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"Two or more rectangles have equal largest area: 50.00"* ]]
}

@test "areas are printed correctly" {
  run bash -c "printf 'RectA\n4\n3\nRectB\n2\n5\nRectC\n6\n1\n' | ./demo2.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"RectA: 12.00"* ]]
  [[ "$output" == *"RectB: 10.00"* ]]
  [[ "$output" == *"RectC: 6.00"* ]]
}

@test "handles float dimensions" {
  run bash -c "printf 'RectA\n2.5\n4.0\nRectB\n6.0\n3.0\nRectC\n1.5\n2.0\n' | ./demo2.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"RectB has the largest area: 18.00"* ]]
}

@test "handles 1x1 rectangles" {
  run bash -c "printf 'RectA\n1\n1\nRectB\n1\n1\nRectC\n1\n1\n' | ./demo2.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"Two or more rectangles have equal largest area: 1.00"* ]]
}