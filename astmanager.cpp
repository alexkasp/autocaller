#include "astmanager.h"

int AsteriskManager::init()
{

	std::string command = "Action: login\r\nUsername: myasterisk\r\nSecret: mycode\r\nActionID: 1\r\n\r\n";
	_sock->write_some(buffer(command,command.size()));
	
	boost::asio::streambuf response;
    boost::asio::read_until(*_sock, response, "\r\n");
	return 0;
}

int AsteriskManager::deinit()
{
	std::string command = "Action: logoff\r\n\r\n";
	_sock->write_some(buffer(command,command.size()));
	
	return 0;
}

AsteriskManager::~AsteriskManager()
{
	deinit();
}
AsteriskManager::AsteriskManager()
{
	astport=5038;
	asthost = "127.0.0.1";

	ep.reset(new ip::tcp::endpoint( ip::address::from_string(asthost), astport));
	 _sock.reset(new ip::tcp::socket(service));
	_sock->connect(*ep);
	 boost::asio::streambuf response;
    boost::asio::read_until(*_sock, response, "\r\n");
	boost::asio::read_until(*_sock, response, "\r\n");
	init();
	
}

int AsteriskManager::call(std::string from,std::string to,std::string outline,std::string schema)
{
	
	std::string command = "Action: Originate\r\nChannel: SIP/"+to+"@"+outline+"\r\nExten: "+schema+"\r\nContext: vatscallback\r\nPriority: 1\r\nCallerID: "+from+"\r\nVariable: CALLERID(dnid)="+to+",CALLERID(num)="+to+"\r\nActionID: 2\r\n\r\n";
    
	_sock->write_some(buffer(command,command.size()));
	
}

int AsteriskManager::call(std::string from,std::string to)
{
	 
	std::string command = "Action: Originate\r\nChannel: SIP/"+from+"\r\nExten: "+to+"\r\nContext: vatsreserveoperator\r\nPriority: 1\r\nCallerID: "+from+"\r\nVariable: CALLERID(dnid)="+to+"\r\nActionID: 2\r\n\r\n";
    
	_sock->write_some(buffer(command,command.size()));
	
}

int AsteriskManager::call(std::string from,std::string to,std::string schema)
{
	
	std::string command = "Action: Originate\r\nChannel: Local/"+schema+"@vatsreserveschemastart\r\nExten: "+to+"\r\nContext: vatsreserveoperator\r\nPriority: 1\r\nCallerID: "+from+"\r\nVariable: CALLERID(dnid)="+to+"\r\nActionID: 2\r\n\r\n";
    
	_sock->write_some(buffer(command,command.size()));
	
}