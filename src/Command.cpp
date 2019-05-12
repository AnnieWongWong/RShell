#include <iostream>
#include <sstream>
#include <vector>
#include <unistd.h> 
#include <stdio.h>
#include <string.h>
#include "Juat.h"
#include "Executable.h"
#include "SemiColon.h"
#include "OrStrat.h"
#include "AndStrat.h"

using namespace std;

void printInorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(node->left); 
  
    /* then print the data of node */
    if (node->getIsRoot()){
        node->getParent()->setBool(node->j->run(true));
    }
    else {
        if (node->j->run(node->successful())){
            if(node->getParent() != NULL){
                node->getParent()->setBool(node->right->j->run(true));
            }
            else {
                node->right->j->run(true);
            }
        }
    }
} 


int main(){
    // Executable x;
    // x.run();
    

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
    pch = strtok (point," ");
    
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
         pch = strtok (NULL," ");
         commandExists = true;
            
    }
    
    bool isConnector = false;
    bool firstNode = true;
    Node* root;
    Node* last;
    
    for (int i = 0; i < commandList.size(); i++){
        Juat* newJuat;
        for(int j = 0; j < commandList.at(i).size(); j++){
            if (commandList.at(i).at(j) == ";"){
                newJuat = new SemiColon;
                isConnector = true;
            }
            else if (commandList.at(i).at(j) == "&&"){
                newJuat = new AndStrat;
                isConnector = true;
            }
            else if (commandList.at(i).at(j) == "||"){
                newJuat = new OrStrat;
                isConnector = true;
            }
            else {
                newJuat = new Executable(commandList.at(i));
                isConnector = false;
            }
            if (firstNode){
                Node* current = new Node(NULL, NULL, NULL, newJuat, true);
                current->setRoot();
                firstNode = false;
                root = current;
            }
            else if (isConnector){
                Node* current = root;
                Node* next = new Node(current, NULL, NULL, newJuat, true);\
               // next->setConnecter();
                current->setParent(next);
                root = next;
            }
            else {
                Node* current = root;
                Node* next = new Node(NULL, NULL, current, newJuat, true);
                current->setright(next);
            }
            
        }
    }
    
    // for (int i = 0; i < commandList.size(); i++){
    //     for(int j = 0; j < commandList.at(i).size(); j++){
    //         cout << commandList.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }

    printInorder(root);


        
  return 0;
}

    