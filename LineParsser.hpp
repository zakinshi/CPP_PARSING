#ifndef __LINE____PARSSER__HPP__
#define __LINE____PARSSER__HPP__

#include <cstddef>
#include <string>
#include <map>


class dataLine {

	public:
		dataLine( std::string, char );

		void	FormatChecker();
		void	splitDatas   ();
		void	checkDataValidation();

		void	hold_formation(std::map<std::string, float> & );
		void	bounderFounder(std::map<std::string, float> & );

	private:
		dataLine();
		std::string _line;

		char		_del;
		size_t		_sep;

		std::string _StrValue;
		
		std::string _Date;
		float		_Value;

};

#endif