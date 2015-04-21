#include <unistd.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <linux/limits.h>
#include "Shell.h"

int main(){
	//get current working directory
        Shell::instance()->loop();
}