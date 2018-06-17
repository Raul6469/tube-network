#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

#include "network/Server.h"
#include "network/Client.h"

int main(int argc, char* argv[])
{
	std::thread runServer(Server::serve);
	std::thread runClient(Client::run);

	return 0;
}