#include <stdio.h>
#include <iostream>
#include <fstream>

int main()
{
	  
std::ofstream outfile ("test.txt");

outfile << "my text here!" << std::endl;

outfile.close();
}
