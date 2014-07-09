#ifndef __AST_MANAGER
#define __AST_MANAGER

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>

using namespace boost::asio;

class AsteriskManager
{
	boost::shared_ptr<ip::tcp::endpoint> ep;
	boost::shared_ptr<ip::tcp::socket> _sock;

	io_service service;

	std::string asthost;
	int astport;
	public:
		AsteriskManager();
		~AsteriskManager();
		int init();
		int deinit();
		int call(std::string from,std::string to,std::string outline,std::string schema);
		int call(std::string from,std::string to);
		int call(std::string from,std::string to,std::string schema);
};
#endif