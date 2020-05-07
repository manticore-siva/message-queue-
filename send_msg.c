/********************************************/
//                                          //
//   Name        : SivaPragasam.v           //
//   Description : message V queue          // 
//   Date        : 07/05/2020               //
//   Title       : queue messge system call //
/*******************************************/                     

/* 
   NOTE :
   	1 > first create a msgget an set a msgget values an permisions important msgget used to create a message queue 

   	2>  now send a message so we can use msgsnd system call an the secand perameter need a structure so we can make a struct

   	3>  carefully to give struct values an every function after use perror for checking purpose

   	4>  finally to open a root terminal after Run the program
*/


#include <stdio.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <error.h>
#include <string.h>

struct mymsg
{
	long mtype;            // its used to set a periority
	char mtext[200];       // its used to stote a send message datas
};

int main()
{

	int msgget_ret;   // return value of msgget

	int msgsend_ret;
	
	struct mymsg data;

	data.mtype = 1;   // here set a periority

	char st[] = "Hii Linux Programming\n";   // create string to send a message data

	strncpy(data.mtext, st, strlen(st)+1);  // this strncpy used to copy a string than store to mtext struct array now store a send data

	perror("strncpy");    // here checking send data store or not

	msgget_ret = msgget(123, IPC_CREAT);  // 108 its like key than user assign value

	perror("msgget");     // here checking message queue build or not

	msgsend_ret = msgsnd(msgget_ret, &data,strlen(st)+1, 0);  // this system call used to send a messages

	perror("msgsnd");   // here checking msgsnd send or not

}
