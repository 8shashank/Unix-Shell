#include <unistd.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <linux/limits.h>
#include "Shell.h"

/*
@brief: Main class for the program
*/
int main(){
  //Create a shell instance and start loop
  Shell::instance()->loop();
}