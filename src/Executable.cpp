#ifndef __EXECUTABLE_CPP__
#define __EXECUTABLE_CPP__

#include "../header/Executable.h"
#include <iostream>
#include <stdio.h>     //to use perror
#include <unistd.h>    //to use execvp + fork
#include <sys/wait.h>  //to use waitpid
#include <sys/types.h> //to use waitpid
#include <stdlib.h>


using namespace std;


bool Executable::run(){
	int status = 0;
	char* args[exec.size()+1];
	
    for (int i = 0; i < exec.size(); i++){
        args[i] = (char*)exec.at(i).c_str();
    }
    args[exec.size()] = NULL;

	pid_t pid = fork();
	 
	if (pid == 0){
		//kid
		if (execvp(args[0], args) == -1){
			perror("fail");
			status = 1;
			_exit(status);
		}
	}
	
	if (pid > 0){
		//parent
		if (waitpid(0,&status,0) == -1){
			perror("wait");
		}
		if (WIFEXITED(status)){
			if (WEXITSTATUS(status) == 1){
				return false;
			}
			else{
				return true;
			}
		}

	}

}

string Executable::getConnex(){
  string ex = exec.at(0);
  return ex;

}

#endif
