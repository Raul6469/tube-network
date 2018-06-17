#include "Server.h"

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

void Server::serve()
{
	try
	{
		boost::asio::io_context io_context;

		tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 13));

		for (;;)
		{
			std::cout << "Listening..." << std::endl;

			tcp::socket socket(io_context);
			acceptor.accept(socket);

			std::cout << "Connected" << std::endl;

			std::string message = "Hello world!";

			boost::system::error_code ignored_error;
			boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}