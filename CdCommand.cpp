#include "CdCommand.h"

CdCommand::CdCommand(v_Iterator begin,v_Iterator end)
{
  directory=*(begin+1);
}

void CdCommand::execute(){
  Shell* s=Shell::instance();
  s->changeCurrentDirectory(directory);  //change current dir of main shell
}

CdCommand::~CdCommand(){}