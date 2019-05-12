#include <iostream>
#include <string>
#include <vector>
#include <unistd.h> 
#include <stdio.h>
#include <string.h>
#include "../header/AndStrat.h"
#include "../header/Command.h"
#include "../header/OrStrat.h"
#include "../header/SemiColon.h"
#include "../header/Executable.h"


using namespace std;



Command::Command(){
    this->root = NULL;
    this->power = NULL;
}

void Command::start_Command_prompt(){
    cout << "$ ";
}

bool Command::getEqex(){
    return eqex;
}

bool Command::run(){
  bool timeToExit = true;
  vector< vector<string> > commandList;
  vector<string> unfilteredCommand;
	string userCommand;

	this->start_Command_prompt();
	getline(cin,userCommand);
	
	string exitt = userCommand.substr(0,4);
	if (exitt == "exit"){
			return 0;
	}
	
	userCommand = userCommand.substr(0, userCommand.find(" #"));
	
	char* point = (char*)userCommand.c_str();
    char* pch;
    pch = strtok(point," ");
    
    bool prevConnector = false;
    bool firstEntry = true;
    bool semiColonExists = false;
    bool commandExists = true;
    
    vector<string> andVect(1, "&&");
    vector<string> orVect(1, "||");
    vector<string> semiVect(1, ";");
    
    while (pch != NULL){
        string command = pch;
        if (firstEntry){
            if (pch[strlen(pch)-1] == ';'){
                command = command.substr(0,command.size()-1);
                semiColonExists = true;
            }
            
            vector<string> temp;
            if (command.size() != 0){
                temp.push_back(command);
                commandList.push_back(temp);
            }
            
            if (semiColonExists){
                commandList.push_back(semiVect);
                semiColonExists = false;
                prevConnector = true;
            }
            else{
                prevConnector = false;
            }
            firstEntry = false;
        }
        
        else {
            if (pch[strlen(pch)-1] == ';'){
                command = command.substr(0,command.size()-1);
                semiColonExists = true;
                commandExists = true;
            }
            else if(pch[strlen(pch)-1] == '&' && pch[strlen(pch)-2] == '&'){
                commandList.push_back(andVect);
                prevConnector = true;
                commandExists = false;
            }
            else if(pch[strlen(pch)-1] == '|' && pch[strlen(pch)-2] == '|'){
                commandList.push_back(orVect);
                prevConnector = true;
                commandExists = false;
            }
            
            if (commandExists && prevConnector){
                vector<string> temp;
                
                if (command.size() != 0){
                    temp.push_back(command);
                    commandList.push_back(temp);
                }
                
                if (semiColonExists){
                    commandList.push_back(semiVect);
                    semiColonExists = false;
                    prevConnector = true;
                }
                else {
                    prevConnector = false;
                }
            }
            
            else if(commandExists && !prevConnector){
                if (command.size() != 0){
                    commandList.at(commandList.size()-1).push_back(command);
                }
                
                if (semiColonExists){
                    commandList.push_back(semiVect);
                    semiColonExists = false;
                    prevConnector = true;
                }
                else {
                    prevConnector = false;
                }
            }
        }
         pch = strtok(NULL," ");
         commandExists = true;
            
    }
    
    bool isConnector = false;
    bool lastNodE = false;
    bool firstNode = true;
    bool firstConnector = true;
    int i;
    Juat* newJuat;
   for ( i = 0; i < commandList.size(); i++){
            if (commandList.at(i).at(0) == ";"){
                newJuat = new SemiColon;
                isConnector = true;
            }
            else if (commandList.at(i).at(0) == "&&"){
                newJuat = new AndStrat;
                isConnector = true;
            }
            else if (commandList.at(i).at(0) == "||"){
                newJuat = new OrStrat;
                isConnector = true;
            }
            else {
                newJuat = new Executable(commandList.at(i));
                isConnector = false;
            }
            
            if (firstNode){
                Node* current = new Node(NULL, NULL, NULL, newJuat, true);
                firstNode = false;
                power = current;
                root = current;
                if(!isConnector) lastNodE = true;
            }
            else if (isConnector && firstConnector){
                Node* current = new Node(NULL, NULL, NULL, newJuat, true);
                root = current;
                current->setLeft(power);
                power = current;
                firstConnector = false;
                lastNodE = false;
            }
            else if (isConnector){
                Node* current = new Node(NULL, NULL, NULL, newJuat, true);
                current->setRight(root->right);
                current->setLeft(root);
                root = current;
                lastNodE = false;
            }
            else {
                Node* current = new Node(NULL, NULL, NULL, newJuat, true);
                current->setRight(root);
                root = current;
                lastNodE = true;
            }
    }
    if(lastNodE == true){
      Juat* newJuat = new SemiColon;
      Node* current = new Node(NULL, NULL, NULL, newJuat, true);
      this->power = current;
      current->setLeft(root);
      this->root = current;
    }
    Node* trav = this->power;
    bool execRanned = false;
    while(trav!=NULL){
            if(trav->left->j->getConnex() == "exit"){
              power = NULL;
              root = NULL;
              timeToExit = false;
              return timeToExit;
            }
            trav->left->evaluate1();
            execRanned = trav->left->getHohenheim();
            trav->evaluate2(execRanned);
            if(trav->j->getConnex() == ";")trav = trav->getParent();
            else if(trav->j->getConnex() == "&&"){
              if(trav->getHohenheim()) trav = trav->getParent();
              else{
                while(trav->j->getConnex() == "&&" || trav!= NULL){
                    trav = trav->getParent();                
                }
              }
            }
            else if(trav->j->getConnex() == "||"){
              if(!trav->getHohenheim())trav = trav->getParent();
              else{
                while(trav->j->getConnex() == "||" || trav!= NULL){
                    trav = trav->getParent();                
                }
              }
            }
    }
  power = NULL;
  root = NULL;
	return timeToExit;
}


    


