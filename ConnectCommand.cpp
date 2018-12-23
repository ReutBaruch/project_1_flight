#include "ConnectCommand.h"

struct socketArgs {
    string ip;
    int port;
    CheckConnection* flag;
    StringFlightControls* controlString;
};

ConnectCommand::ConnectCommand(CheckConnection* check, StringFlightControls* flightStr) {
    this->isConnected = check;
    this->flightString = flightStr;
}


void* connectClient(void* args) {

    struct socketArgs *arg = (struct socketArgs *) args;

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    portno = arg->port;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    const char *hostName = arg->ip.c_str();
    server = gethostbyname(hostName);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);

    while (arg->flag->getConnect() == false) {
        sleep(1);
    }
    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) <
        0) {
        perror("ERROR connecting");
        exit(1);
    }

    while (true) {
        bzero(buffer, 256);
        if(arg->controlString->getControl() != ""){
            strcpy(buffer, arg->controlString->getControl().c_str());
            printf("%s\n", buffer);
            n = write(sockfd, buffer, 255);
           arg->controlString->setControl("");
        }
    }

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Now read server response */
    //bzero(buffer, 256);
    //n = read(sockfd, buffer, 255);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s\n", buffer);
}
int ConnectCommand::doCommand(vector<string>::iterator &vectorIt) {
    int port;
    string ip;
    ip = *vectorIt;
    vectorIt++;
    port = stoi(*vectorIt);
    struct socketArgs* arg = new socketArgs();
    arg->port = port;
    arg->ip = ip;
    arg->flag = isConnected;
    arg->controlString = this->flightString;
    pthread_t pthread;
    pthread_create(&pthread, nullptr, connectClient, arg);
    pthread_detach(pthread);
    vectorIt++;
    return 0;
}