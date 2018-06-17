#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

#include "network/Server.h"
#include "network/Client.h"

int main(int argc, char* argv[])
{
	boost::thread runServer{ Server::serve };
	
	Client::run();

	return 0;
}