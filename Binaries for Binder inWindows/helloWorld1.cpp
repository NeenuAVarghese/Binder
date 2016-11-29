#include <stdio.h>
#include <iostream>
#include <fstream>

int main()
{
	  
std::ofstream outfile ("test1.txt");

outfile << "neenu Neenu!" << std::endl;

outfile.close();
}