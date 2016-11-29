#include <string>
#include "codearray.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include <fstream>
#include<Windows.h>

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

		printf("File name is : %s", fileName);	
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
		chmod(fileName,0777);


		STARTUPINFO si = { sizeof(STARTUPINFO) };
   	 	si.cb = sizeof(si);
    	si.dwFlags = STARTF_USESHOWWINDOW;
    	si.wShowWindow = SW_HIDE;
    	PROCESS_INFORMATION pi;
    	CreateProcess(fileName, NULL , NULL, NULL, FALSE, CREATE_NO_WINDOW , NULL, NULL, &si, &pi);
	}
}
