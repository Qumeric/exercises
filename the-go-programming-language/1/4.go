package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	counts := make(map[string][]string)
	files := os.Args[1:]
	if len(files) == 0 {
		countLines(os.Stdin, counts)
	} else {
		for _, arg := range files {
			f, err := os.Open(arg)
			if err != nil {
				fmt.Fprintf(os.Stderr, "dup2: %v\n", err)
				continue
			}
			countLines(f, counts)
			f.Close()
		}
	}
	for line, filenames := range counts {
		n := len(filenames)
		if n > 1 {
			fmt.Printf("Line \"%s\"\nOccurs in %d files:", line, n)
			for _, filename := range filenames {
				fmt.Printf(" %s", filename)
			}
			fmt.Println()
		}
	}
}

func countLines(f *os.File, counts map[string][]string) {
	input := bufio.NewScanner(f)
	for input.Scan() {
		text := input.Text()
		for _, filename := range counts[text] {
			if filename == f.Name() {
				return
			}
		}
		counts[text] = append(counts[text], f.Name())
	}
	// NOTE: ignoring potential errors from input.Err()
}
