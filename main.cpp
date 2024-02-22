#include <fstream>
#include <iostream>
#include <string>
#include "LineParsser.hpp"

typedef  std::map<std::string, float> mapStrFloat;

static int	file_not_found( std::string f ) {

	std::cerr << "Warning :[ File Not Found ]: " << f << std::endl;
	return 1;
}

void _parseLine( std::string line, char sep, mapStrFloat & InputData) {

	try {

		dataLine The_Line( line, sep);
		The_Line.FormatChecker();
		The_Line.splitDatas();
		The_Line.checkDataValidation();
		if (sep == ',')
			return (The_Line.hold_formation(InputData));
		The_Line.bounderFounder(InputData);
	} catch ( const char * msg ) {
		std::cout << msg << std::endl;
	}
}

void trim(std::string & line );
void first_line_checker(std::string & line, char & _del ) {

	size_t span = line.find(_del);
	std::string FirstSide ( line.substr(0, span) );
	trim(FirstSide);

	std::string SecondSide ( line.substr(span + 1));
	trim(SecondSide);

	if (_del == '|')
		if (_del == '|' && (FirstSide != "date" || SecondSide != "value"))
			throw "Eroor: On file head: use: data | value";
}

int read_the_File( std::string file, mapStrFloat & baseData, char sep ) {

	std::ifstream readfile ( file );
	if ( !readfile.is_open() )
		return file_not_found(file);

	std::string line;

	try {
		std::getline(readfile, line);
		first_line_checker(line, sep);
	} catch ( const char * msg ) {
		readfile.close();
		readfile.open(file.c_str());
		std::cout << msg << std::endl;
	} 

	while (std::getline(readfile, line))
		_parseLine(line, sep, baseData);

	readfile.close();
	return 0;
}

int main(int ac, char **av) {

	if (ac != 3) return 1;

	mapStrFloat baseData;
	read_the_File(av[2], baseData, ',');

	read_the_File(av[1], baseData, '|');

	return 0;
}