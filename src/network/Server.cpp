#include "../../includes/network/Server.hpp"

void printMsg(std::string msg)
{
    std::cout << msg << std::endl;
}

// int main()
// {
//     int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
//     std::cout << serverSocket << std::endl;
// }

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addr_len = sizeof(address);
    char buffer[1024] = {0};


    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        return (printMsg("Socket failed"),1);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) return (printMsg("Bind failed"),1);

    if (listen(server_fd, 3) < 0) return (printMsg("Listen failed"),1);
    
    std::cout << "Server listening on port " << PORT << "...\n";
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addr_len)) < 0)
        return (printMsg("Accept failed"),1);
    // valread = read(new_socket, buffer, 1024);
    // std::cout << buffer << std::endl;

    return 0;
}
