#!/usr/bin/env bats

@test "calculates average runs correctly" {
  result=$(printf "Rohit\n45\n50\nVirat\n18\n75\nDhoni\n7\n30\nShubman\n99\n60\nHardik\n33\n40\nJadeja\n8\n20\nBumrah\n93\n5\nSiraj\n13\n10\nKuldeep\n23\n15\nShardul\n54\n25\nPant\n17\n70\n" | ./act4)
  echo "$result" | grep -q "36.36"
}