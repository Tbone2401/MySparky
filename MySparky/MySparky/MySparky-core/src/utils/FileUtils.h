#pragma once

#include <string>
#include <memory>
#include <stdio.h>

namespace mysparky
{
	void close_file(std::FILE* file) { std::fclose(file); }

	std::string read_file(const char* filePath)
	{
		FILE *file;
		errno_t err = fopen_s(&file, filePath, "r"); // Read only no T, only if it is binary you should use a b
		std::fseek(file, 0, SEEK_END);
		unsigned long length = std::ftell(file);
		char* data = new char[length + 1];

		memset(data, 0, length + 1);
		
		fseek(file, 0, SEEK_SET);
		fread(data, 1, length, file);

		fclose(file);
		std::string result(data);
		delete[] data;
		return result;
	}
}