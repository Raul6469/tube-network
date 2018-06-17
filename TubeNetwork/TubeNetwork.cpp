#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

std::string make_daytime_string()
{
	return "Hello";
}

void server()
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

			std::string message = make_daytime_string();

			boost::system::error_code ignored_error;
			boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main(int argc, char* argv[])
{
	try
	{
		if (argc != 2)
		{
			std::cerr << "Usage: client <host>" << std::endl;
			return 1;
		}

		boost::asio::io_context io_context;

		std::thread runServer(server);

		tcp::resolver resolver(io_context);
		tcp::resolver::results_type endpoints =
			resolver.resolve(argv[1], "daytime");

		tcp::socket socket(io_context);
		boost::asio::connect(socket, endpoints);

		for (;;)
		{
			boost::array<char, 128> buf;
			boost::system::error_code error;

			size_t len = socket.read_some(boost::asio::buffer(buf), error);

			if (error == boost::asio::error::eof)
				break; // Connection closed cleanly by peer.
			else if (error)
				throw boost::system::system_error(error); // Some other error.

			std::cout.write(buf.data(), len);
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}