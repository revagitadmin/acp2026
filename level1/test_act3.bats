#!/usr/bin/env bats

@test "finds highest bill among 3 consumers" {
  result=$(printf "3\n101\n100\n5\n102\n200\n5\n103\n50\n5\n" | ./act3)
  echo "$result" | grep -q "102"
  echo "$result" | grep -q "1000.00"
}

@test "finds highest bill among 2 consumers" {
  result=$(printf "2\n201\n80\n3\n202\n120\n3\n" | ./act3)
  echo "$result" | grep -q "202"
  echo "$result" | grep -q "360.00"
}
