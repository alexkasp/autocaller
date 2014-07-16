#ifndef __LOGGER_H
#define __LOGGER_H
#include <boost/log/trivial.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/expressions/formatters/date_time.hpp>
#include "LoggerInterface.h"

class BoostLoggerInFile: public LoggerInterface
{
    boost::log::sources::severity_logger< boost::log::trivial::severity_level > lg;

		std::string filename;
		BoostLoggerInFile();
	public:
		BoostLoggerInFile(std::string logname);
		void init();
		void LogMsg(std::string message);
};


#endif
