#include <iostream>
#include <cstdlib>
#include <cli-creator/Cli.h>

using namespace CliCreator;

auto init = [](Arguments args) {
  auto project_name = args[0];

  std::system(("cp -r /usr/local/etc/robo ./" + project_name).c_str());

  return 0;
};

int main(int argc, char* argv[]) {
  Cli cli;

  cli.commands["--init"] = init;

  return cli.handle(argc, argv);
}
