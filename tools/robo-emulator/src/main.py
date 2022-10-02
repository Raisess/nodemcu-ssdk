#! /bin/python

# e.g.: ./src/main.py ../../main/main.ino

import sys
import os

CXX = "clang++"
LIB_PATH = "/usr/local/include/robo"
LIB_SRC = f"{LIB_PATH}/ROBO_Board/*.cpp {LIB_PATH}/ROBO_Core/*.cpp"

BUILD_DIR = "./build"
BUILD_OUT = BUILD_DIR + "/main.so"

if __name__ == "__main__":
    ino_file = sys.argv[1]

    os.system(f"cp {ino_file} ./cpp-lib/main.ino.cpp")
    os.system("rm -rf " + BUILD_DIR)
    os.system("mkdir -p " + BUILD_DIR)
    os.system(f"{CXX} -I{LIB_PATH}/ROBO_Board -I{LIB_PATH}/ROBO_Core {LIB_SRC} ./cpp-lib/main.ino.cpp ./cpp-lib/main.cpp -o {BUILD_OUT}")

    print("\t\tRunning with ROBO Emulator\n")

    os.system(BUILD_OUT)
