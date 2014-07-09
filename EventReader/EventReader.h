#pragma once

#ifndef __linux__
#include <boost\asio.hpp>
#include <boost\thread.hpp>
#include <boost\algorithm\string\split.hpp>
#include <boost\algorithm\string.hpp>
#else
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#endif

#include <string>
#include "datatypes.h"
#include "iexecuter.h"

using namespace boost::asio;


class EventReader
{
	std::string asthost;
	int astport;
	io_service service;
	ParamMap data;
	ExecuterInterface* Executer;

public:
	EventReader(std::string host,int port);
	~EventReader(void);
	int start(void);
private:
	int SendRequest(std::string url);
	int parseline(std::string line,int& _state,int& _event);
	int processevent(const std::string data);
public:
	void SetExecuter(ExecuterInterface* iexecuter);
	int AddParam(std::string data, ParamMap& eventdata);
};

