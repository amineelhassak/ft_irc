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

int main()
{
    int                     server_fd;
    struct sockaddr_in      address;
    /*
        int                   new_socket;
        int addr_len = sizeof(address);
        char buffer[1024] = {0};
    */

    // 1. Creating the Server Socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        return (printMsg("Socket failed"),1);
    printf("Socket created\n");
    /*
    * socketfd: It is the file descriptor for the socket.
    * AF_INET: It specifies the IPv4 protocol family.
    * SOCK_STREAM: It defines that the TCP type socket.
    * */
    // 2. Defining Server Address

    // std::cout << server_fd << std::endl;
    // address.sin_family = AF_INET;
    // address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);
    // htons(): This function is used to convert the unsigned int from machine byte order to network byte order.
    std::cout << address.sin_port << std::endl;

    // if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    //     return (printMsg("Bind failed"),1);
    // if (listen(server_fd, 3) < 0)
    //     return (printMsg("Listen failed"),1);    
    // std::cout << "Server listening on port " << PORT << "...\n";

    // if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addr_len)) < 0)
    //     return (printMsg("Accept failed"),1);
    return 0;
}
