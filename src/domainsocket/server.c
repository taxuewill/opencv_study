#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>


char path[]= "./namo_amitabha";

int main(void){

    printf("hello,server\n");

    int socket_srv = -1;
    int socket_client = -1;
    // int t = -1;
    int len = 0;
    struct sockaddr_un addr_srv, addr_client;
    char str[1024] = {0};
    // memset(str,0,sizeof(char)*100);
    

    if((socket_srv = socket(AF_UNIX, SOCK_STREAM, 0))<0){
        printf("create domain socket failed\n");
        return -1;
    }else{
        printf("create domain socket\n");
    }

    //create server socket

    printf("start cpy path\n");
    addr_srv.sun_family = AF_UNIX;
    memset(addr_srv.sun_path,0 ,sizeof(addr_srv.sun_path));
    strncpy(addr_srv.sun_path,path,sizeof(path));

    printf("domain:[%s]\n",addr_srv.sun_path);

    if(remove(path) == -1&& errno != ENOENT){
        perror("remove error");
        return -1;
    }else{
        printf("remove\n");
    }
    

    if(bind(socket_srv,(struct sockaddr*)&addr_srv,sizeof(addr_srv))<0){
        printf("bind failed\n");
        perror("bind error");
        return -1;
    }

    if(listen(socket_srv, 100)<0){
        return -1;
    }

    while(1){
        int nRecv;
        if((socket_client = accept(socket_srv,NULL,NULL)) == -1){ //(struct sockaddr *)&addr_client,&sz
            printf("accept failed\n");
            return -1;
        }
        printf("accept one  %d\n",socket_client);
        if((nRecv = recv(socket_client,str,1024,0))<0){
            perror("recv failed");
            close(socket_client);
            break;
        }else{
            str[nRecv] = '\0';
            printf("get client content [%s],%d\n",str,nRecv);
            
        }
        printf("nRecv %d\n",nRecv);
        if(send(socket_client,str,nRecv,0)<0){
            perror("send failed");
            close(socket_client);
            break;
        }
        close(socket_client);
    }

    close(socket_srv);
    printf("close server\n");

    return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <unistd.h>
#define BACK_LOG 1000
#define BUFFER_SIZE 1024
char buffer[BUFFER_SIZE] = {0};
char path[] = "./namo_amitabha";
void handleError(char *msg) { //错误处理函数
    perror(msg);
    exit(-1);
}

void bindToAddress(int serverSocket) { //将socket与某个地址绑定
    struct sockaddr_un address;
    address.sun_family = AF_UNIX;//使用Unix domain
    strncpy(address.sun_path, path, sizeof(path));//这个地址的类型有3种，参考上文所说，这里我们使用“系统路径”这一类型
    if (remove(path) == -1 && errno != ENOENT) { //绑定之前先要将这个路径对应的文件删除，否则会报EADDRINUSE
        handleError("删除失败");
    }
    if (bind(serverSocket, (struct sockaddr *)&address, sizeof(address)) == -1) {
        handleError("地址绑定失败");
    }
}

void echo(int socket) {
    int numberOfReaded, numberOfWrited = 0;
    while (true) {
        numberOfReaded = recv(socket, buffer, BUFFER_SIZE, 0);//读取客户端进程发送的数据
        if (numberOfReaded == -1) {
            handleError("读取数据错误");
        } else if (numberOfReaded == 0) {
            printf("客户端关闭连接\n");
            close(socket);
            return;
        }
        printf("收到对端进程数据长度为%d，开始echo", numberOfReaded);
        if (numberOfReaded > 0) {
            numberOfWrited = write(socket, buffer, numberOfReaded);//然后原版返回
            printf("  写入的结果为%d\n", numberOfWrited);
        }
    }
}

void handleRequest(int serverSocket) {
    int socket = accept(serverSocket, NULL, NULL);//监听客户端的请求，没有请求到来的话会一直阻塞
    if (socket == -1) {
        handleError("accept 错误");
    }
    printf("client socket is %d",socket);
    puts("client发起连接...");
    echo(socket);
}
int main(void) {
    int serverSocket = socket(AF_UNIX, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        handleError("创建socket失败");
    }
    bindToAddress(serverSocket);
    if (listen(serverSocket, BACK_LOG) == -1) {//转为被动模式
        handleError("监听失败");
    }
    while (true) {
        handleRequest(serverSocket);
    }
}

*/