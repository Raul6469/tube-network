#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

#include "Server.h"
#include "Client.h"

int main(int argc, char* argv[])
{
	std::thread runServer(Server::serve);
	std::thread runClient(Client::run);

	return 0;
}