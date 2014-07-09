default:
	export CFLAGS="$CFLAGS -O0 -fbuiltin -g"
	export CXXFLAGS="$CXXFLAGS -O0 -fbuiltin -g"
	g++ main.cpp Parser.cpp EventReader.cpp CRMUrlBuilder.cpp  -o main -lpthread -std=c++0x -I /usr/local/boost/include/ -L /usr/local/boost/lib/ -Wl,-Bstatic -lboost_system -lboost_regex -lboost_date_time -Wl,-Bdynamic -lm -lcurl
	
test:
	g++ test.cpp corefunc.cpp sipheader.cpp sipmanager.cpp callbox.cpp -o test -std=c++0x -I /usr/local/boost/include/ -L /usr/local/boost/lib/ -Wl,-Bstatic  -lboost_system -lboost_regex -Wl,-Bdynamic -lm
	
thread:
	g++ thread.cpp -o thread -std=c++0x -I /usr/local/boost/include/ -L /usr/local/boost/lib/ -Wl,-Bstatic  -lboost_system -lboost_regex -lboost_thread -Wl,-Bdynamic -lm -lpthread -lrt
	
client:
	g++ simple_client.cpp -o simple -std=c++0x -I /usr/local/boost/include/ -L /usr/local/boost/lib/ -Wl,-Bstatic  -lboost_system -lboost_regex -lboost_thread -Wl,-Bdynamic -lm -lpthread -lrt
	
iptable:
	g++ iplist.cpp iptest.cpp -o iplist -std=c++0x -I /usr/local/boost/include/ -L /usr/local/boost/lib/ -Wl,-Bstatic  -lboost_system -lboost_regex -Wl,-Bdynamic -lm -lpthread -lrt
	
logs:
	g++ messagelog.cpp corefunc.cpp makelogs.cpp filemanager.cpp storagemanager.cpp sipheader.cpp sipmanager.cpp callbox.cpp iplist.cpp  -o logs -lpthread -std=c++0x -I /usr/local/boost/include/ -L /usr/local/boost/lib/ -Wl,-Bstatic  -lboost_system -lboost_regex -lboost_date_time -Wl,-Bdynamic -lm

serv:
	g++ simpleserv.cpp -o serv -std=c++0x -I /usr/local/boost/include/ -L /usr/local/boost/lib/ -Wl,-Bstatic -lboost_thread -lboost_system -lboost_regex -Wl,-Bdynamic -lm -lpthread -lrt

clean:
	rm -f ./test ./main ./thread ./logs ./serv