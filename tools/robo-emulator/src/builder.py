import os

BUILD_DIR = "./build"
BUILD_OUT = BUILD_DIR + "/main.o"

class Builder:
  def __init__(self, compiler, lib, input):
    self.compiler = compiler
    self.input = input
    self.lib = lib

    os.system(f"rm -rf {BUILD_DIR}")
    os.system(f"mkdir -p {BUILD_DIR}")

  def compile(self):
    os.system(f"cp {self.input} ./cpp-lib/main.ino.cpp")
    os.system(f"{self.compiler} -I{self.lib}/Board {self.lib}/Board/*.cpp ./cpp-lib/main.ino.cpp ./cpp-lib/main.cpp -o {BUILD_OUT}")

  def run(self):
    os.system(BUILD_OUT)
