#include <iostream>
#include "../header/Command.h"



using namespace std;

Command::Command(){
  eqex = false;
  root = NULL;
  power = NULL;

}

bool Command::run(){
	string userCommand;

	this->start_Command_prompt();
	
	//While loop to parse/tokenize userCommand
	//While loop to go through tree using the run of primitives 



}
