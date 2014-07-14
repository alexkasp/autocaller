EVENTREADERDIR=./EventReader
TESTDIR=./tests

default: ${EVENTREADERDIR}/parser.o ${EVENTREADERDIR}/eventreader.o logger.o
	export CFLAGS="$CFLAGS -O0 -fbuiltin -g"
	export CXXFLAGS="$CXXFLAGS -O0 -fbuiltin -g"
	g++  main.cpp CallViewer.cpp astmanager.cpp Task.cpp TaskManagerInterface.cpp logger.o ${EVENTREADERDIR}/parser.o ${EVENTREADERDIR}/eventreader.o \
	SimpleTaskManager.cpp TaskLoader.cpp TaskParser.cpp ReserveOperatorTaskManager.cpp ReserveSchemaTaskManager.cpp -o main \
	-lpthread -std=c++0x -I /usr/local/boost/include/ -L /usr/local/boost/lib/ -Wl,-Bstatic -lboost_log -lboost_log_setup \
	-lboost_filesystem -lboost_system -lboost_regex -lboost_date_time -lboost_thread -Wl,-Bdynamic -lm -lcurl -ggdb
test:
	g++ ${TESTDIR}/test.cpp -o test -lgtest -lpthread 

debug: parser.o eventreader.o
	
	g++ main.cpp  ${EVENTREADERDIR}/parser.o ${EVENTREADERDIR}/eventreader.o CallViewer.cpp astmanager.cpp Task.cpp TaskManagerInterface.cpp \
	SimpleTaskManager.cpp TaskLoader.cpp TaskParser.cpp ReserveOperatorTaskManager.cpp ReserveSchemaTaskManager.cpp -o main \
	-lpthread -std=c++0x -I /usr/local/boost/include/ -L /usr/local/boost/lib/ -Wl,-Bstatic -lboost_system -lboost_regex -lboost_date_time -lboost_thread \
	-Wl,-Bdynamic -lm -lcurl -ggdb

${EVENTREADERDIR}/parser.o: ${EVENTREADERDIR}/Parser.cpp ${EVENTREADERDIR}/Parser.h
	export CFLAGS="$CFLAGS -O0 -fbuiltin -g"
	export CXXFLAGS="$CXXFLAGS -O0 -fbuiltin -g"
	g++ -c ${EVENTREADERDIR}/Parser.cpp -o ${EVENTREADERDIR}/parser.o -std=c++0x

${EVENTREADERDIR}/eventreader.o: ${EVENTREADERDIR}/EventReader.cpp ${EVENTREADERDIR}/EventReader.h 
	export CFLAGS="$CFLAGS -O0 -fbuiltin -g"
	export CXXFLAGS="$CXXFLAGS -O0 -fbuiltin -g"
	g++ -c  ${EVENTREADERDIR}/EventReader.cpp -o ${EVENTREADERDIR}/eventreader.o -std=c++0x
logger.o:
	export CFLAGS="$CFLAGS -O0 -fbuiltin -g"
	export CXXFLAGS="$CXXFLAGS -O0 -fbuiltin -g"
	g++ -c Logger.cpp -o logger.o -std=c++0x -I /usr/local/boost/include/ -ggdb
testlog:
	export CFLAGS="$CFLAGS -O0 -fbuiltin -g"
	export CXXFLAGS="$CXXFLAGS -O0 -fbuiltin -g"
	g++ testlog.cpp -o testlog -std=c++0x -I /usr/local/boost/include/ -L /usr/local/boost/lib/ -Wl,-Bstatic -lboost_log -lboost_log_setup \
	-lboost_filesystem -lboost_system -lboost_regex -lboost_date_time -lboost_thread -Wl,-Bdynamic -lm -lcurl -ggdb
clean:
	rm -f ./main ./test ${EVENTREADERDIR}/eventreader.o ${EVENTREADERDIR}/parser.o