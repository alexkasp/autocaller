#include "TaskLoader.h"

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>

#include <vector>

#include "TaskParser.h"

void TaskLoader::StartListen()
{
	boost::thread serverthread(boost::bind(&TaskLoader::ServerSide,this));

	//serverthread.join();
}

int TaskLoader::AddManager(TaskManagerInterface* manager)
{
	int size = managers.size();
	managers.insert(std::make_pair(manager->GetStrategyCode(),manager));

	return (size == managers.size());
}

/*
	void TaskLoader::ParseTask(socket_ptr sock)
	Get data from net in form:
		start
		phones
		...
		end phones
		operators
		...
		end operators
		...
		end
	received data send to TaskParser object for decode
*/
void TaskLoader::ParseTask(socket_ptr sock)
{
	try
  {
	  int ParseMode = 0;

	  std::cout<<"create data for task"<<std::endl;
	  std::vector<std::string> nums;
	  std::vector<std::string> operators;
	  std::string caller;
	  std::string schema;
	  std::string outline;
	  std::string taskname;

	  int StrategyCode = 0;

	  TaskParser parser(nums,operators,caller,schema,outline,taskname);

		for (;;)
		{
		  std::string data;
		  boost::asio::streambuf response;
		  boost::asio::read_until(*sock, response, "\n\n");

		  std::istream str(&response);
		  while(std::getline(str, data))
		  {
			int result = parser.Parse(data);
			if(result)
			{
				int ManagerStrategy = parser.GetStrategyCode();
				auto x = managers.find(ManagerStrategy);
				if(x!=managers.end())
				{
					TaskManagerInterface* tmi = x->second;
					int taskindex = tmi->CreateTask(nums,operators,caller,schema,outline,taskname);
					tmi->Start(taskindex);
				}
			}

		  }
		  std::cout<<"end parse"<<std::endl;
		}
  }
  catch (std::exception& e)
  {
	std::cerr << "Exception in thread: " << e.what() << "\n";
  }
}

void TaskLoader::ServerSide()
{
	boost::asio::io_service io_service;

    ip::tcp::acceptor acceptor(io_service, ip::tcp::endpoint(ip::tcp::v4(), 3001));

   
	boost::system::error_code error;
	boost::asio::streambuf response;
	std::istream is(&response);
	std::string s;
    for (;;)
    {      
		try
		{
			socket_ptr sock(new ip::tcp::socket(io_service));
   
			acceptor.accept(*sock);
			std::cout<<"Start listen TaskLoader"<<std::endl;
			boost::thread t(boost::bind(&TaskLoader::ParseTask,this,sock));
			
		}
		 catch (std::exception& e)
		{
			std::cerr << "Exception in acceptor: " << e.what() << "\n";
		}
    }
}