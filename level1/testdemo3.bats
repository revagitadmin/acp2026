#!/usr/bin/env bats

setup() {
    gcc demo3.c -o r
}

@test "Test largest rectangle (3)" {
    run ./r <<EOF
3
11
11
12
12
13
13
EOF

    [[ "$output" == *"3"* ]]
    [[ "$output" == *"169.00"* ]]
}

@test "Test largest rectangle (1)" {
    run ./r <<EOF
3
10
10
3
3
4
4
EOF

    [[ "$output" == *"1"* ]]
    [[ "$output" == *"100.00"* ]]
}

@test "Test largest rectangle (2)" {
    run ./r <<EOF
3
2
2
7
7
2
1
EOF

    [[ "$output" == *"2"* ]]
    [[ "$output" == *"49.00"* ]]
}