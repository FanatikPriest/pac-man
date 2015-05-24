#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace MapLoader
{
	const int ROWS    = 30;
	const int COLUMNS = 28;

	char** read_map_from_file() {
		string line;
		ifstream file("data/level_map");

		if (!file.is_open())
		{
			throw "Cannot load level map.";
		}

		char** map = new char*[ROWS];

		int line_count  = 0;
		int bugger_size = COLUMNS + 1;

		while (getline(file, line))
		{
			map[line_count] = new char[bugger_size];

			strcpy_s(map[line_count], bugger_size, line.c_str());

			line_count++;
		}

		file.close();

		return map;
	}
}