#!/usr/bin/env python3
#
# Create an ELF binary using the Go compile since it can generate ELF binaries
# with minimal effort.

import os
import subprocess

GO_DL_URL = "https://golang.org/dl/"

SOURCE = '''package main
import "fmt"

func main() {
  fmt.Println("Hello world!")
}
'''
SOURCE_FILE = "main.go"
OUTPUT_BINARY = "main"

COMPILE_CMD = f"go build -o {OUTPUT_BINARY} {SOURCE_FILE}"

def has_go_compiler():
  print("Checking for Go compiler")
  res = subprocess.run(["go", "version"])
  return res.returncode

def create_elf_executable():
  # Set the GO OS environment variable to "linux", which will generate the ELF
  # executable. Environment variables set with os.environ are not captured in
  # the host environment, only the subprocess.
  os.environ["GOOS"] = "linux"
  res = subprocess.run(COMPILE_CMD.split(" "))
  return res.returncode

def main():
  if not has_go_compiler():
    print(f"Go compiler not detected, try installing a Go compiler from {GO_DL_URL} and running this script again.")

  print(f"Creating {SOURCE_FILE}")
  with open(SOURCE_FILE, "w") as f:
    if f.write(SOURCE):
      print(f"Created {SOURCE_FILE}")
    else:
      print(f"{SOURCE_FILE} not created")
      return

  if not create_elf_executable():
    print(f"{OUTPUT_BINARY} as an ELF executable was not created")
    return

  print(f"Create {OUTPUT_BINARY} ELF executable")

if __name__ == '__main__':
  main()
