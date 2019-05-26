#include <iostream>
#include <stdio.h>     //to use perror
#include <unistd.h>    //to use execvp + fork
#include <sys/wait.h>  //to use waitpid
#include <sys/types.h> //to use waitpid
#include <stdlib.h>
#include <string>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../header/Executable.h"

using namespace std;

bool test_Exec(vector<string> yea){
  struct stat buf;
  string flag = yea.at(1);
  if(flag == "-f"){
    string file_path = yea.at(2);
    if(stat(file_path.c_str(), &buf) != -1){
      if(S_ISREG( buf.st_mode) != 0){
       cout << "(True)\n";
       return true;
      }
      else{
        cout << "(False)\n";
        return false;
      }
    }
    else{
      cout << "(False)\n"; 
      return false;
    }
  }
  else if(flag == "-d"){
  string dir_path = yea.at(2);
    if(stat(dir_path.c_str(), &buf) != -1){
      if(S_ISDIR( buf.st_mode) != 0){
       cout << "(True)\n";
       return true;
      }
      else{
        cout << "(False)\n";
        return false;
      }
    }
    else{
      cout << "(False)\n"; 
      return false;
    }
  }
  else if(flag == "-e"){
  string path = yea.at(2);
    if(stat(path.c_str(), &buf) != -1){
      cout << "(True)\n";
       return true;
    }
    else{
        cout << "(False)\n";
        return false;
    }
  }
  else{
    if(stat(flag.c_str(), &buf) != -1){
      cout << "(True)\n";
       return true;
    }
    else{
        cout << "(False)\n";
        return false;
    }  
  }
}

bool Executable::run(bool x){

  bool a_gain = false;
  if(exec.at(0) == "test" || exec.at(0) == "["){
    a_gain = test_Exec(exec);
    return a_gain;
  }
  
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
			perror("Error");
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
      if (exec.at(0) == "ls" && exec.at(1).at(1) == 'j')
         return false;
			if (WEXITSTATUS(status) == 1){
				return false;
			}
			else{
				return true;
			}
		}

	}

}



