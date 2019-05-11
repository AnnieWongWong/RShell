#include <iostream>
#include <sstream>
#include <vector>
#include <unistd.h> 
#include <stdio.h>
#include <string.h>
#include "Command.h"


using namespace std;


Command::Command(){
	

}

void Command::run(){

    vector<string> unfilteredCommand;
    string userCommand;
    	
    this->start_Command_prompt();
	  getline(cin,userCommand);
	
	string exitt = userCommand.substr(0,4);
	if (exitt == "exit"){
			return 0;
	}
	
	userCommand = userCommand.substr(0, userCommand.find("#"));
	
	char* point = (char*)userCommand.c_str();
    char* pch;
    pch = strtok (point," ");
    
    while (pch != NULL){
        unfilteredCommand.push_back(pch);
        // for (int i = 0; i < unfilteredCommand.at(0).size(); i++){
        //     cout << unfilteredCommand.at(0).at(i) << " ";
        // }
        pch = strtok (NULL, " ");
    }
    
    for (int i = 0; i < unfilteredCommand.size(); i++){
        //vector<string> executeable;
        //Base* executeable = new
        // if (this->root == NULL){
            
        // }
        
        cout << unfilteredCommand.at(i) << endl;
    }
    
    
    
  return 0;
  
    
    
}


}
