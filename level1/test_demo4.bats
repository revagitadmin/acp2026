#!/usr/bin/env bats

@test "flight found for valid destination" {
  run bash -c "printf 'AI101\nDelhi\n50\nAI102\nMumbai\n30\nAI103\nChennai\n20\nAI104\nKolkata\n40\nMumbai\n' | ./demo4.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"Flight found:-"* ]]
  [[ "$output" == *"Flight Number:- AI102"* ]]
  [[ "$output" == *"Destination:- Mumbai"* ]]
  [[ "$output" == *"Available Seats:- 30"* ]]
}

@test "flight not found for invalid destination" {
  run bash -c "printf 'AI101\nDelhi\n50\nAI102\nMumbai\n30\nAI103\nChennai\n20\nAI104\nKolkata\n40\nHyderabad\n' | ./demo4.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"flight Not found to your destination: Hyderabad"* ]]
}

@test "first flight matches destination" {
  run bash -c "printf 'AI101\nDelhi\n50\nAI102\nMumbai\n30\nAI103\nChennai\n20\nAI104\nKolkata\n40\nDelhi\n' | ./demo4.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"Flight Number:- AI101"* ]]
  [[ "$output" == *"Destination:- Delhi"* ]]
  [[ "$output" == *"Available Seats:- 50"* ]]
}

@test "last flight matches destination" {
  run bash -c "printf 'AI101\nDelhi\n50\nAI102\nMumbai\n30\nAI103\nChennai\n20\nAI104\nKolkata\n40\nKolkata\n' | ./demo4.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"Flight Number:- AI104"* ]]
  [[ "$output" == *"Destination:- Kolkata"* ]]
  [[ "$output" == *"Available Seats:- 40"* ]]
}

@test "middle flight matches destination" {
  run bash -c "printf 'AI101\nDelhi\n50\nAI102\nMumbai\n30\nAI103\nChennai\n20\nAI104\nKolkata\n40\nChennai\n' | ./demo4.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"Flight Number:- AI103"* ]]
  [[ "$output" == *"Destination:- Chennai"* ]]
  [[ "$output" == *"Available Seats:- 20"* ]]
}

@test "search is case sensitive" {
  run bash -c "printf 'AI101\nDelhi\n50\nAI102\nMumbai\n30\nAI103\nChennai\n20\nAI104\nKolkata\n40\ndelhi\n' | ./demo4.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"flight Not found to your destination: delhi"* ]]
}

@test "flight found with zero available seats" {
  run bash -c "printf 'AI101\nDelhi\n0\nAI102\nMumbai\n30\nAI103\nChennai\n20\nAI104\nKolkata\n40\nDelhi\n' | ./demo4.exe"
  [ "$status" -eq 0 ]
  [[ "$output" == *"Flight Number:- AI101"* ]]
  [[ "$output" == *"Available Seats:- 0"* ]]
}