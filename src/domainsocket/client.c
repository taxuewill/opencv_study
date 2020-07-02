#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>

/**/

char path[]= "./namo_amitabha";

int main(void){

    printf("hello,client\n");
    int socket_client = -1;
    int data_len = 0;
    int addr_size = 0;
    struct sockaddr_un addr_srv;
    char str[100];
    memset(str,0,sizeof(char)*100);
    char content[] = "This is test for UDS";
    strncpy(str, content,sizeof(content));

    if((socket_client = socket(AF_UNIX, SOCK_STREAM, 0))<0){
        printf("create domain socket failed\n");
        return -1;
    }
    addr_srv.sun_family = AF_UNIX;
    strncpy(addr_srv.sun_path,path,sizeof(path));
    printf("domain:[%s]\n",addr_srv.sun_path);
    if(connect(socket_client,(struct sockaddr *)&addr_srv,sizeof(addr_srv)) < 0){
        perror("connect failed");
        return -1;
    }

    printf("connect success\n");
    
    if(send(socket_client,content,sizeof(content),0)<0){
        perror("send failed");
        close(socket_client);
        return -1;
    }else{
        printf("send success\n");
    }
    if((data_len = recv(socket_client,str,100,0))>0){
        str[data_len] = '\0';
        printf("echo from server:%s",str);
    }else{
        perror("recv failed");
        close(socket_client);
        return -1;
    }
    close(socket_client);
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
#define BUFFER_SIZE 1024
char buffer[BUFFER_SIZE] = {0};
char path[] = "./namo_amitabha";
void handleError(char *msg) { //错误处理函数
    perror(msg);
    exit(-1);
}
int main(void) {
    int clientSocket = socket(AF_UNIX, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        handleError("创建socket失败");
    }
    struct sockaddr_un addr;
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, path, sizeof(addr.sun_path));

    if (connect(clientSocket, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        handleError("连接服务端失败");
    }
    while(true) {
        fgets(buffer, BUFFER_SIZE, stdin);
        if(send(clientSocket, buffer, strlen(buffer), 0)==-1) {
            handleError("发送失败");
        }
        int numOfReaded = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        if(numOfReaded==-1) {
            handleError("对端已经关闭");
        }
        buffer[numOfReaded]=0;
        printf("%s", buffer);
    }
}

*/