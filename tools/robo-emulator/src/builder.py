import os

class Builder:
  def __init__(self, compiler, lib, input):
    self.compiler = compiler
    self.input = input
    self.lib = lib

    os.system(f"rm -rf ./build")
    os.system(f"mkdir -p ./build")

  def compile(self):
    self._prepare_file()
    os.system(f"{self.compiler} -fPIC -shared -I{self.lib}/Board {self.lib}/Board/*.cpp ./cpp-lib/main.ino.cpp -o ./build/main.so")

  def _prepare_file(self):
    input_file = open(self.input, "r")
    input_code = input_file.read()
    input_file.close()

    parts = input_code.split("void setup()")
    declaration = parts[0]
    rest = parts[1]
    output_code = declaration + "extern \"C\" {\nvoid setup()" + rest + "}"

    output_file = open("./cpp-lib/main.ino.cpp", "w")
    output_file.write(output_code)
    output_file.close()
