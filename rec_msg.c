/***********************************************/
//                                             //
//   Name        : SivaPragasam.v              //
//   Description : message V queue reciver side// 
//   Date        : 07/05/2020                  //
//   Title       : queue messge V system call  //
/***********************************************/



/*
     NOTE :

     	1 >  First crea a message queue we can use msgget system call an give a same key id

	2>  then create a structure to store a recive datas

	3>  then use the msgrcv system call it can be used to recive a message

	4> finally run the program in root user

*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <error.h>
#include <string.h>

struct msgrcv
{
	long mtype;
	char mtext[200];
};

int main()
{
	int msgget_ret;                      /// this used to store a msgget return value

	ssize_t rcv_ret;

	struct msgrcv data;

	data.mtype = 1;

	msgget_ret = msgget(123,IPC_CREAT);   /// here creat message queue

	perror("msgget");    // checking msgget working or nor

	rcv_ret = msgrcv(msgget_ret, &data,200,1,0);

	perror("msgrcv");

	printf("%s\n",data.mtext);

}
