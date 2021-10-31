#pragma once
#include <string>

#include <stdio.h>  // defines FILENAME_MAX
#include <unistd.h> // for getcwd()

std::string getcwd_str() {
  std::string cwd("\0",FILENAME_MAX+1);
  return getcwd(&cwd[0],cwd.capacity());
}
