#include "sed_is_for_loosers.hpp"

void paste_in_file(std::string filename, std::string paste)
{
	std::ofstream outFile(filename.c_str(), std::ios::trunc);
	outFile << paste;
	outFile.close();
}