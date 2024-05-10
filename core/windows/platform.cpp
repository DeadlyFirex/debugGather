#ifdef _WIN32
#include "platform.h"
// #pragma comment(lib, "ws2_32.lib")

std::string core::get_hostname() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        return {"WSAStartup failed"};
    }
    char hostname[1024];
    if (gethostname(hostname, sizeof(hostname)) == SOCKET_ERROR) {
        WSACleanup();
        return {"gethostname failed"};
    }
    WSACleanup();
    return {hostname};
}

#endif
