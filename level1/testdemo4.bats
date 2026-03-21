#!/usr/bin/env bats

setup() {
  gcc demo4.c -o program
}

@test "Test 1: Single match (your exact case)" {
  run ./program <<EOF
3421
chennai
21
2341
mumbai
12
123
delhi
1
453
hawai
2
chennai
EOF

  [[ "$output" == *"Flight found! Flight Number: 3421, Seats Available: 21"* ]]
}

@test "Test 2: Multiple matches" {
  run ./program <<EOF
101
delhi
10
102
delhi
20
103
mumbai
30
104
delhi
40
delhi
EOF

  [[ "$output" == *"Flight Number: 101"* ]]
  [[ "$output" == *"Flight Number: 102"* ]]
  [[ "$output" == *"Flight Number: 104"* ]]
}

@test "Test 3: No match" {
  run ./program <<EOF
101
delhi
10
102
mumbai
20
103
chennai
30
104
goa
40
hyderabad
EOF

  [[ "$output" == *"No flights available to hyderabad"* ]]
}

@test "Test 4: Case sensitivity" {
  run ./program <<EOF
101
Delhi
10
102
Mumbai
20
103
Chennai
30
104
Goa
40
delhi
EOF

  [[ "$output" == *"No flights available to delhi"* ]]
}

@test "Test 5: Match first flight" {
  run ./program <<EOF
201
goa
30
202
pune
40
203
jaipur
50
204
lucknow
60
goa
EOF

  [[ "$output" == *"Flight Number: 201"* ]]
}

@test "Test 6: Match last flight" {
  run ./program <<EOF
301
a
10
302
b
20
303
c
30
304
d
40
d
EOF

  [[ "$output" == *"Flight Number: 304"* ]]
}

@test "Test 7: Numeric destination" {
  run ./program <<EOF
401
123
10
402
456
20
403
789
30
404
999
40
456
EOF

  [[ "$output" == *"Flight Number: 402"* ]]
}

@test "Test 8: All same destination" {
  run ./program <<EOF
501
blr
10
502
blr
20
503
blr
30
504
blr
40
blr
EOF

  [[ "$output" == *"Flight Number: 501"* ]]
  [[ "$output" == *"Flight Number: 504"* ]]
}

@test "Test 9: Short names" {
  run ./program <<EOF
601
x
5
602
y
10
603
z
15
604
x
20
x
EOF

  [[ "$output" == *"Flight Number: 601"* ]]
  [[ "$output" == *"Flight Number: 604"* ]]
}

@test "Test 10: Mixed data" {
  run ./program <<EOF
701
hyd
25
702
chennai
35
703
hyd
45
704
delhi
55
hyd
EOF

  [[ "$output" == *"Flight Number: 701"* ]]
  [[ "$output" == *"Flight Number: 703"* ]]
}