#include <stdio.h>
#include <iostream>
#include <fstream>

int main()
{
	  
std::ofstream outfile ("test.txt");

outfile << "This is first File!" << std::endl;

outfile.close();
}
