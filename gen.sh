#!/bin/bash
curl http://davidbau.com/generated/sudoku.txt | sed '/+/d' | sed 's/./|/5' | sed 's/./|/9' | sed 's/./|/17' | sed 's/./|/21' | sed 's/./|/29' | sed 's/./|/33' | sed 's/   / 0 /g' | sed '/-/d' | head -9 | sed 's/|//g' | sed 's/ //g'



