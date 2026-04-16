#!/usr/bin/env bats

setup() {
    gcc demo10.c -o program
}

############################
# 🟢 EASY TEST CASES
############################

@test "TC1: Single element" {
    run ./program <<EOF
1
5
EOF

    [ "$status" -eq 0 ]
    [[ "$output" == *"array element5 "* ]]
}

@test "TC2: Three elements" {
    run ./program <<EOF
3
1
2
3
EOF

    [ "$status" -eq 0 ]
    [[ "$output" == *"array element1 2 3 "* ]]
}

@test "TC3: Two elements" {
    run ./program <<EOF
2
10
20
EOF

    [ "$status" -eq 0 ]
    [[ "$output" == *"array element10 20 "* ]]
}

@test "TC4: All zeros" {
    run ./program <<EOF
4
0
0
0
0
EOF

    [ "$status" -eq 0 ]
    [[ "$output" == *"array element0 0 0 0 "* ]]
}

@test "TC5: Zero size" {
    run ./program <<EOF
0
EOF

    [ "$status" -eq 0 ]
    [[ "$output" == *"array element"* ]]
}

############################
# 🟡 MEDIUM TEST CASES
############################

@test "TC6: Negative size (bug - still passes)" {
    run ./program <<EOF
-3
EOF

    [ "$status" -eq 0 ]
}

@test "TC7: Mixed values" {
    run ./program <<EOF
5
-1
-2
3
4
5
EOF

    [ "$status" -eq 0 ]
    [[ "$output" == *"array element-1 -2 3 4 5 "* ]]
}

@test "TC8: Large numbers" {
    run ./program <<EOF
3
100000
200000
300000
EOF

    [ "$status" -eq 0 ]
    [[ "$output" == *"array element100000 200000 300000 "* ]]
}

@test "TC9: Repeated values" {
    run ./program <<EOF
4
7
7
7
7
EOF

    [ "$status" -eq 0 ]
    [[ "$output" == *"array element7 7 7 7 "* ]]
}

@test "TC10: Partial input (hang protection)" {
    run timeout 2 ./program <<EOF
3
10
20
EOF

    [ "$status" -ne 0 ]
}

############################
# 🔴 DIFFICULT TEST CASES
############################

@test "TC11: Non-integer size" {
    run ./program <<EOF
abc
EOF

    [ "$status" -ne 0 ]
}

@test "TC12: Non-integer element" {
    run ./program <<EOF
2
10
abc
EOF

    [ "$status" -ne 0 ]
}

@test "TC13: Huge allocation (may fail malloc)" {
    run ./program <<EOF
1000000000
EOF

    [[ "$output" == *"Memory allcoation failed"* ]]
}

@test "TC14: Special characters" {
    run ./program <<EOF
2
@
#
EOF

    [ "$status" -ne 0 ]
}

@test "TC15: Floating input" {
    run ./program <<EOF
2
1.5
2.5
EOF

    [ "$status" -ne 0 ]
}