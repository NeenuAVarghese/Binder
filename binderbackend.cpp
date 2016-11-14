#include <string>
#include "codearray.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include <fstream>

using namespace std;

int main()
{
	
	/* The child process id */
	pid_t childProcId = -1;
		
	/* Go through the binaries */
	for(int progCount = 0; 	progCount < NUM_BINARIES; ++progCount)
	{
			
		//TODO: Create a temporary file you can use the tmpnam() function for this.
		// E.g. fileName = tmpnam(NULL)
		char* fileName = tmpnam(NULL);
		//TODO: Open the file and write the bytes of the first program to the file.
		//These bytes are found in codeArray[progCount]

		FILE* myFile = fopen(fileName,"wb");
		if(!myFile)
		{
			perror("Error in opening file");
			exit(-1);	
		}
		if(fwrite(codeArray[progCount], sizeof(char), programLengths[progCount], myFile)< 0){
			perror("Error Writing file");
			exit(-1);	
		}
		fclose(myFile);

		
		//TODO: Make the file executable: this can be done using chmod(fileName, 0777)
		system(("chmod("+fileName+", 0777)").c_str());

		//TODO: Create a child process using fork
		pid_t childProcId = fork();


		if (childProcId < 0) { /* error occurred */
			fprintf(stderr, "Fork Failed");
			exit(-1);
		}
		/* I am a child process; I will turn into an executable */
		else {
			if (childProcId == 0)
			{

				//TODO: use execlp() in order to turn the child process into the process
				//running the program in the above file.	
				if (execlp(fileName, fileName, NULL) < 0)
				{
					perror("execlp");
					exit(-1);
				}

			}
			else {

			}
		}
	}
	
	/* Wait for all programs to finish */
	for(int progCount = 0; progCount < NUM_BINARIES; ++progCount)
	{
		/* Wait for one of the programs to finish */
		if(wait(NULL) < 0)
		{
			perror("wait");
			exit(-1);
		}	
	}
}
