#include "Logger.h"

#define BOOST_LOG_DYN_LINK

BoostLoggerInFile::BoostLoggerInFile(std::string logname)
{
	filename = logname;
	init();
}

void BoostLoggerInFile::init()
{
	namespace logging = boost::log;
	namespace src = boost::log::sources;
	namespace sinks = boost::log::sinks;
	namespace keywords = boost::log::keywords;
	namespace expr = boost::log::expressions;
    
	logging::add_file_log
    (
		keywords::auto_flush = true,
        keywords::file_name = filename,                                        /*< file name pattern >*/
        keywords::rotation_size = 10 * 1024 * 1024,                                   /*< rotate files every 10 MiB... >*/
        keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0), /*< ...or at midnight >*/
        keywords::format = "[%TimeStamp%]: %Message%"                                 /*< log record format >*/
    );

   /* logging::core::get()->set_filter
    (
        logging::trivial::severity >= logging::trivial::info
    );*/
	boost::log::add_common_attributes();
}

void BoostLoggerInFile::LogMsg(std::string message)
{
	  using namespace boost::log::trivial;
	  BOOST_LOG_SEV(lg, info) << message;
}