#include <stdio.h>
#include <iostream>
#include <fstream>

int main()
{
	  
std::ofstream outfile ("test1.txt");

outfile << "This is second File!" << std::endl;

outfile.close();
}