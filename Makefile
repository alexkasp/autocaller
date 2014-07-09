default:
	export CFLAGS="$CFLAGS -O0 -fbuiltin -g"
	export CXXFLAGS="$CXXFLAGS -O0 -fbuiltin -g"
	g++ main.cpp ../Parser.cpp ../EventReader.cpp CallViewer.cpp astmanager.cpp Task.cpp TaskManagerInterface.cpp SimpleTaskManager.cpp TaskLoader.cpp TaskParser.cpp ReserveOperatorTaskManager.cpp ReserveSchemaTaskManager.cpp -o main -lpthread -std=c++0x -I /usr/local/boost/include/ -L /usr/local/boost/lib/ -Wl,-Bstatic -lboost_system -lboost_regex -lboost_date_time -lboost_thread -Wl,-Bdynamic -lm -lcurl
debug:
	export CFLAGS="$CFLAGS -O0 -fbuiltin -g"
	export CXXFLAGS="$CXXFLAGS -O0 -fbuiltin -g"
	g++ main.cpp ../Parser.cpp ../EventReader.cpp CallViewer.cpp astmanager.cpp Task.cpp TaskManagerInterface.cpp SimpleTaskManager.cpp TaskLoader.cpp TaskParser.cpp ReserveOperatorTaskManager.cpp ReserveSchemaTaskManager.cpp -o main -lpthread -std=c++0x -I /usr/local/boost/include/ -L /usr/local/boost/lib/ -Wl,-Bstatic -lboost_system -lboost_regex -lboost_date_time -lboost_thread -Wl,-Bdynamic -lm -lcurl -ggdb
	
clean:
	rm -f /main