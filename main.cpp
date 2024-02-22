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
bool first_line_checker(std::string & line, char & _del ) {

	size_t span = line.find(_del);
	std::string FirstSide ( line.substr(0, span) );
	trim(FirstSide);

	std::string SecondSide ( line.substr(span + 1));
	trim(SecondSide);

	if (_del == '|')
		if ( FirstSide.compare("date") || SecondSide.compare("value") )
			return false;
	if (_del == ',')
		if ( FirstSide.compare("date") || SecondSide.compare("exchange_rate") )
			return false;

	return true;
}

int read_the_File( std::string file, mapStrFloat & baseData, char sep ) {

	std::ifstream readfile ( file );

	if ( !readfile.is_open() )
		return file_not_found(file);

	std::string line;
	std::getline(readfile, line);

	if ( !first_line_checker(line, sep) ) {		/* check the first line of file if is correct */
		std::cout << "Warning: File Head: use: date | value" << std::endl;
		return (readfile.close(), 0);
	}

	while (std::getline(readfile, line))
		_parseLine(line, sep, baseData);

	readfile.close();
	return 1;
}

int main(int ac, char **av) {

	if (ac != 3) return 1;

	mapStrFloat baseData;

	if ( read_the_File(av[2], baseData, ',') )
		if ( read_the_File(av[1], baseData, '|') )
			return 0;

	return 0;
}