runDumper: logger.o log_message.o log_dumper.o
	g++ -std=c++11 logger.o log_message.o log_dumper.o -o runDumper -l sqlite3

runGenerator: logger.o log_message.o log_generator.o
	g++ -std=c++11 logger.o log_message.o log_generator.o -o runGenerator -l sqlite3

log_dumper.o: log_dumper.cpp
	g++ -std=c++11 -c log_dumper.cpp -l sqlite3

log_message.o: log_message.cpp
	g++ -std=c++11 -c log_message.cpp -l sqlite3

logger.o: logger.cpp
	g++ -std=c++11 -c logger.cpp -l sqlite3

log_generator.o: log_generator.o
	g++ -std=c++11 -c log_generator.cpp -l sqlite3

clean:
	rm *.o runDumper
