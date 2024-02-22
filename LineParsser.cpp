#include <cstddef>
#include <iostream>
#include "LineParsser.hpp"
#include "DateParsser.hpp"
#include "ValueParser.hpp"

typedef  std::map<std::string, float> mapStrFloat;

dataLine::dataLine(std::string l, char c): _line(l), _del( c ) {
	_Value = 0.0f;
}

void dataLine::hold_formation(mapStrFloat & _DataFile) {

	_DataFile[_Date] = _Value;
}

void dataLine::bounderFounder(mapStrFloat & _DataFile) {

	mapStrFloat::iterator it = _DataFile.lower_bound(_Date);
	if (it != _DataFile.end() ) {

		if ( it->first != _Date && it != _DataFile.begin() )
			it--;
		else if ( it->first != _Date) {
			std::cout << "key not found in begin" << std::endl; return;
		}
		std::cout << it->first << std::flush;
		std::cout << "\t=> " << _Value << "\t= " << it->second * _Value << std::endl;
	}
}

void dataLine::checkDataValidation() {

	FormatDate DateCheck(_Date);

	sinshi ValueChecker;
	ValueChecker.value = _StrValue;
	_Value = ValueChecker.ValueCheckin();
}

void dataLine::FormatChecker( void ) {

	size_t size = _line.length();

	if (!size)
		throw "NonExepted: EMPTY_LINE";

	size_t span = _line.find(_del, 0);
	const std::string to_thorwed ("Error: bad input \t=> " + _line);
	if (span == std::string::npos )
		throw to_thorwed.c_str();

	size_t new_span = _line.find(_del, span + 1);
	if (new_span != std::string::npos )
		throw "Data_Format_Error: Additional_data_place";
	_sep = span;
}

void trim(std::string & line ) {

	std::string::size_type start = line.find_first_not_of(' ');
	if (start == std::string::npos)
		return;

	std::string::size_type end = line.find_last_not_of(' ');

	line = line.substr(start, end - start + 1);
}

void dataLine::splitDatas( void ) {

	std::string FirstSide ( _line.substr(0, _sep) );
	trim(FirstSide);
	_Date = FirstSide;

	std::string SecondSide ( _line.substr(_sep + 1));
	trim(SecondSide);
	_StrValue = SecondSide;

}

