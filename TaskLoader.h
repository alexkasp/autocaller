
#include "TaskManagerInterface.h"
#include <vector>
#include <map>

typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;

class TaskLoader
{

		std::map<int,TaskManagerInterface*> managers;
		void ParseTask(socket_ptr sock);
		void ServerSide();
	public:
		int AddManager(TaskManagerInterface* manager);
		void StartListen();
};