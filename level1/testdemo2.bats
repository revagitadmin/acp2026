#!/usr/bin/env bats

setup() {
  gcc demo2.c -o rect
}

@test "Test largest rectangle (anto wins)" {
  run ./rect <<EOF
anto
12.3
11.3
karen
9.0
8.9
jerrin
4.0
4.0
EOF

  [[ "$output" == *"anto"* ]]
  [[ "$output" == *"138.99"* ]]
}

@test "Test largest rectangle (karen wins)" {
  run ./rect <<EOF
anto
2.0
2.0
karen
5.0
5.0
jerrin
3.0
3.0
EOF

  [[ "$output" == *"karen"* ]]
  [[ "$output" == *"25.00"* ]]
}