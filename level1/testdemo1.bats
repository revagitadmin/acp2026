#!/usr/bin/env bats

@test "Test max in positive floats" {
  run ./max_array <<EOF
3
1.5
2.7
0.9
EOF

  [[ "$output" == *"Maximum value = 2.70 at index 1"* ]]
}

@test "Test max at first index" {
  run ./max_array <<EOF
3
5.5
2.1
3.3
EOF

  [[ "$output" == *"Maximum value = 5.50 at index 0"* ]]
}

