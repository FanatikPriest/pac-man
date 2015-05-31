#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

/*
Reads a text file and generates a two-dimensional character array that represents the map of a level.
*/
namespace MapLoader
{
	int ROWS    = 0;
	int COLUMNS = 0;

	char** read_map_from_file()
	{
		string line;
		ifstream file("data/level_map");

		if (!file.is_open())
		{
			throw "Cannot load level map.";
		}

		ROWS = (int) count(istreambuf_iterator<char>(file), istreambuf_iterator<char>(), '\n');

		char** map = new char*[ROWS];

		file.clear();
		file.seekg(0, ios::beg);

		getline(file, line);

		COLUMNS = line.length();

		int lines_read  = 0;
		int buffer_size = COLUMNS + 1;

		do
		{
			map[lines_read] = new char[buffer_size];

			strcpy_s(map[lines_read], buffer_size, line.c_str());

			lines_read++;
		}
		while (getline(file, line));

		file.close();

		return map;
	}
}