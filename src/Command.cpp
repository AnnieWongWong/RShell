#include <iostream>
#include <sstream>
#include <vector>
#include <unistd.h> 
#include <stdio.h>
#include <string.h>
#include "../header/Juat.h"
#include "../header/Executable.h"
#include "../header/SemiColon.h"
#include "../header/OrStrat.h"
#include "../header/AndStrat.h"

using namespace std;


Command::Command(){
    this->root = NULL;
    this->power = NULL;
}

void Command::start_Command_prompt(){
    cout << "$ ";
}

bool printInorder(struct Node* node) 
{ 
    if (node == NULL) 
        return true; 
  
    /* first recur on left child */
    printInorder(node->left); 
  
    /* then print the data of node */
    if (node->getIsRoot()){
        if (node->j->getstring() == "exit") return false;
        if (node->getParent() != NULL){
            node->getParent()->setBool(node->j->run(true));
        }
        else {
            node->j->run(true);
                        return true;
        }
    }
    else {
        if (node->j->run(node->successful())){
            if(node->getParent() != NULL){
                if (node->right->j->getstring() == "exit") return false;
                node->getParent()->setBool(node->right->j->run(true));
            }
            else {
                if (node->right->j->getstring() == "exit") return false;
                node->right->j->run(true);
                                return true;
            }
        }
                if (node->getParent() == NULL) return true;
    }
} 



bool Command::run(bool x) {
    bool again = true;
    vector< vector<string> > commandList;
    vector<string> unfilteredCommand;
    string userCommand;

    this->start_Command_prompt();
    getline(cin,userCommand);


    string exitt = userCommand.substr(0,4);
    if (exitt == "exit"){
            return false;
    }
    
    userCommand = userCommand.substr(0, userCommand.find(" #"));

    int numLeftParen = 0;
    int numRightParen = 0;
    for (int i = 0; i < userCommand.size(); ++i)
    {
        if (userCommand.at(i) == '(')
        {
            numLeftParen++;
        }
        else if (userCommand.at(i) == ')')
        {
            numRightParen++;
        }
    }

    if (numLeftParen != numRightParen)
    {
        cout << "Error: missing or extra parenthesis" << endl;
        return true;
    }
    
    char* point = (char*)userCommand.c_str();
    char* pch;
    pch = strtok (point," ");
    
    bool prevConnector = false;
    bool firstEntry = true;
    bool semiColonExists = false;
    bool commandExists = true;
    bool leftParenExists = false;
    bool rightParenExists = false;
    bool doubleConnector = false;
    bool prevRightParen = false;
    bool prevCommand = false;
    
    vector<string> andVect(1, "&&");
    vector<string> orVect(1, "||");
    vector<string> semiVect(1, ";");
    vector<string> leftParen(1, "(");
    vector<string> rightParen(1, ")");

    while (pch != NULL)
    {
        char lastChar = pch[strlen(pch)-1];
        char firstChar = pch[0];
        string command = pch;

        if (firstEntry)
        {
            if ( command == ";" ||  command == "&&" || command == "||")         //if the user command start with a connector stop executung 
            {
                cout << "-bash: syntax error near unexpected token '" << command << "'" << endl;
                return true;
            }
            
            if (firstChar == '(')
            {
                while (firstChar == '(')
                {
                    command = command.substr(1,command.size());
                    commandList.push_back(leftParen);
                    firstChar = command.at(0);
                }
                prevConnector = true;
                leftParenExists = true;
                commandExists = true;
                prevCommand = false;
            }
            
            if (lastChar == ')'){
                rightParenExists = true;
            }
            
            if (lastChar == ';')
            {
                semiColonExists = true;
                commandExists = true;
                prevConnector = true;
                command = command.substr(0,command.size()-1);
            }

            string commandCopy = command;
            if (rightParenExists){
                char lastCharCopy = commandCopy.at(commandCopy.size()-1);

                while (lastCharCopy == ')'){
                    commandCopy = commandCopy.substr(0,commandCopy.size()-1);
                    lastCharCopy = commandCopy.at(commandCopy.size()-1);
                }
            }

            if (commandCopy.size() != 0){
                vector<string> temp;
                temp.push_back(commandCopy);
                commandList.push_back(temp);
                prevCommand = true;
                prevConnector = false;
            }            

            if (semiColonExists)
            {
                commandList.push_back(semiVect);
                semiColonExists = false;
                prevCommand = false;
                prevConnector = true;
            }
            
            if (rightParenExists)
            {
                while (lastChar == ')')
                {
                    command = command.substr(0,command.size()-1);
                    commandList.push_back(rightParen);
                    lastChar = command.at(command.size()-1);                
                }
                prevCommand = false;
                prevConnector = true;
                rightParenExists = false;
            }

            firstEntry = false;
        }
        
        else 
        {

            if (firstChar == '(' && prevConnector || firstChar == '(' && commandList.size() == 1)              //For a left parenthesis to be valid the previous node must be a connector
            {
                while (firstChar == '(')
                {
                    command = command.substr(1,command.size());
                    commandList.push_back(leftParen);
                    firstChar = command.at(0);
                }
                prevConnector = true;
                leftParenExists = true;
                commandExists = true;
                prevCommand = false;
            }

            if (lastChar == ';'){
                if (prevConnector && command.size() == 1 && !leftParenExists && (prevRightParen && prevConnector)){         //a connector cannot follow another connector
                    doubleConnector = true;
                } 
                else {
                    command = command.substr(0,command.size()-1);
                    semiColonExists = true;
                    commandExists = true;
                }
            }
            else if(command == "&&"){
                if (prevConnector && !leftParenExists  && (prevRightParen && prevConnector)){                                  //a connector cannot follow another connector
                    doubleConnector = true;
                }
                else {
                    commandList.push_back(andVect);
                    prevConnector = true;
                    commandExists = false;
                    prevCommand = false;
                }
            }
            else if(command == "||"){
                if (prevConnector && !leftParenExists && (prevRightParen && prevConnector)){                                     //a connector cannot follow another connector
                    doubleConnector = true;
                }         
                else {
                    commandList.push_back(orVect);
                    prevConnector = true;
                    commandExists = false;        
                    prevCommand = false;
                }      
            }

            if (doubleConnector)
            {
                cout << "-bash: syntax error near unexpected token r u here '" << command << "'" << endl;
                doubleConnector = false;
                return true;               
            }
            
            if (commandExists && prevConnector){
                if (lastChar == ')') {            //For a right parenthesis to be valid the previous node cannot be a connector
                    rightParenExists = true;  
                    leftParenExists = false;
                }

                
                string commandCopy = command;
                if (rightParenExists){
                    char lastCharCopy = commandCopy.at(commandCopy.size()-1);

                    while (lastCharCopy == ')'){
                        commandCopy = commandCopy.substr(0,commandCopy.size()-1);
                        lastCharCopy = commandCopy.at(commandCopy.size()-1);
                    }
                }
                
                vector<string> temp;

                if (commandCopy.size() != 0){
                    temp.push_back(commandCopy);
                    commandList.push_back(temp);
                    prevConnector = false;
                    prevCommand = true;
                }
                
                if (rightParenExists)
                {
                    while (lastChar == ')'){
                        command = command.substr(0,command.size()-1);
                        commandList.push_back(rightParen);
                        lastChar = command.at(command.size()-1);
                    }
                    prevConnector = true;
                    rightParenExists = false;
                    prevCommand = false;
                }

                if (semiColonExists){
                    commandList.push_back(semiVect);
                    prevConnector = true;
                    prevCommand = false;
                    semiColonExists = false;
                }
                else {
                    prevConnector = false;
                }
            }
            
            else if(prevCommand || commandExists && !prevConnector || commandExists && rightParenExists || commandExists && leftParenExists)
            {
                if (lastChar == ')') {          
                    rightParenExists = true;  
                }

                string commandCopy = command;
                if (rightParenExists){
                    char lastCharCopy = commandCopy.at(commandCopy.size()-1);

                    while (lastCharCopy == ')'){
                        commandCopy = commandCopy.substr(0,commandCopy.size()-1);
                        lastCharCopy = commandCopy.at(commandCopy.size()-1);
                    }
                }

                if (commandCopy.size() != 0){
                    commandList.at(commandList.size()-1).push_back(commandCopy);
                    prevConnector = false;
                    prevCommand = true;
                }

                if (rightParenExists)
                {
                    while (lastChar == ')'){
                        command = command.substr(0,command.size()-1);
                        commandList.push_back(rightParen);
                        lastChar = command.at(command.size()-1);
                    }
                    prevConnector = true;
                    rightParenExists = false;
                    leftParenExists = false;
                    prevRightParen = true;
                    prevCommand = false;
                }                
                
                if (semiColonExists){
                    commandList.push_back(semiVect);
                    prevConnector = true;
                    semiColonExists = false;
                    prevCommand = false;
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
                //if (!isConnector){
                  Node* current = new Node(NULL, NULL, NULL, newJuat, true);
                  current->setRoot();
                  firstNode = false;
                  root = current;
                //}
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
    
    for (int i = 0; i < commandList.size(); i++){
        for(int j = 0; j < commandList.at(i).size(); j++){
            cout << commandList.at(i).at(j) << " ";
        }
        cout << endl;
    }

    again = printInorder(root);


        
  return again;
}

