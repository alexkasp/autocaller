#include "Logger.h"

#define BOOST_LOG_DYN_LINK

boost::log::sources::severity_logger< boost::log::trivial::severity_level > LoggerCall::lg;

void LoggerCall::init()
{
	namespace logging = boost::log;
	namespace src = boost::log::sources;
	namespace sinks = boost::log::sinks;
	namespace keywords = boost::log::keywords;
	namespace expr = boost::log::expressions;
    
	logging::add_file_log
    (
        keywords::file_name = "sample.log"
    );

    logging::core::get()->set_filter
    (
        logging::trivial::severity >= logging::trivial::info
    );

}

LoggerCall::LoggerCall()
{
	
	init();
	
	boost::log::add_common_attributes();

    

}

int LoggerCall::LogMsg(std::string msg)
{
	using namespace boost::log::trivial;
  //  boost::log::sources::severity_logger< severity_level > lg;
	BOOST_LOG_SEV(lg, trace) << msg;
}