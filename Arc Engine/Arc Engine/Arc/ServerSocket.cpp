#include "ServerSocket.h"

Arc::ServerSocket::ServerSocket( unsigned int port )
	: _port(port)
{
	_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (_socket == INVALID_SOCKET)
	{
		printError("Creating server socket failed");
		cleanup();
		return;
	}

	struct addrinfo *result = nullptr;
	struct addrinfo hints;
	int res;

	memset(&hints, 0, sizeof(hints));

	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	stringstream strPort;
	strPort << port;

	res = getaddrinfo(NULL, strPort.str().c_str(), &hints, &result);

	if (res != 0) 
	{
		printError("getaddrinfo() failed");
		cleanup();
		freeaddrinfo(result);
		return;
	}

	res = bind(_socket, result->ai_addr, (int)result->ai_addrlen);

	if (res == SOCKET_ERROR)
	{
		printError("bind() failed");
		cleanup();
		freeaddrinfo(result);
		return;
	}

	res = listen(_socket, SOMAXCONN);

	if (res == SOCKET_ERROR)
	{
		printError("listen() failed");
		cleanup();
		freeaddrinfo(result);
		return;
	}

	freeaddrinfo(result);
}

Arc::ServerSocket::~ServerSocket( void )
{
	closesocket(_socket);

	while ( ! _clients.isEmpty())
		delete _clients.popBack();
}

void Arc::ServerSocket::cleanup( void )
{
#ifdef WINDOWS

	closesocket(_socket);
	WSACleanup();

#else // LINUX

	close(_socket);

#endif // WINDOWS
}

void Arc::ServerSocket::printError( string msg )
{
#ifdef WINDOWS

	ERRORF(toString(), msg + ", error %i", WSAGetLastError());

#else

	ERROR(toString(), msg);

#endif
}

bool Arc::ServerSocket::isClientAvailable( void )
{
	return true;
}

Arc::Socket* Arc::ServerSocket::waitForClient( void )
{
	SOCKET client = accept(_socket, NULL, NULL);

	if (client == INVALID_SOCKET)
	{
		printError("accept() failed");
		cleanup();
		return nullptr;
	}

	Socket* pSocket = New Socket(client);
	_clients.add(pSocket);
	return pSocket;
}

bool Arc::ServerSocket::closeClient( Socket* pSocket )
{
	if ( ! _clients.contains(pSocket))
		return false;

	delete pSocket;
	return true;
}