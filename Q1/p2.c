#include <stdio.h>
//#include <stdlib.h>
#include<sys/ipc.h>
#include <string.h>
#include <sys/types.h>
//#include <fcntl.h>
//#include <sys/stat.h>
#include <mqueue.h>
#include<sys/msg.h>

#define MAX 10


struct mesg_buffer
{
      long mesg_type;
      char mesg_text[100];

} message;

int main()
{
    key_t key;
    int msgid;
    key = ftok("program",65);
    msgid =msgget(key,0666 | O_CREAT);
    
    msgrcv(msgid,&message,sizeof(message),1,0);

    printf("data rececived is :%s\n",message.mesg_text);
    msgctl(msgid, O_RDONLY, NULL);
    return 0;
}
