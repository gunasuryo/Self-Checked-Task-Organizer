# Self-Checked-Task-Organizer
A software that will help you organize your daily goals with Task and Reward options. This software was developed by:
Teuku Salman Farizi (NPM: 1706043216) & Guna Suryo Aji (NPM: 1706043222) as the final project for the class "Pemrograman Lanjut", Computer Engineering, Faculty of Engineering, Universitas Indonesia.

##Program UI
#Menu
In the Main Menu of this software, there are three menus, Task Menu, Reward Menu, and exit. In the Main menu, shown the current time of one's personal computer and current point which is saved after you close the program. So, you'll be able to retrieve the point when you open the program the following time.

Screenshot of the Main Menu: ![](Main%20Menu)

#Task Menu
In the task menu, there are 5 available options which can be seen here : (SS Task menu)
The first option makes you able to add a task with specific points and deadline.
The second option is to delete a task that you've made.
The third option is to complete a task. The program will evaluate if you have done the task before the deadline. If you finish the task before deadline, you will get the points that you have set, and you'll get no point if you finish it after the deadline.
Screenshot : (SS finish before deadline) (SS finish after deadline)
The fourth option is to see tasks that you've done from the latest one to the oldest one consecutively and each shows the time they were finished. (SS Task History)
The fifth option is to go back to main menu.

#Reward Menu
In the reward menu, there are 5 available options. (SS Reward menu)
The first option is to add a reward you'd like to get, with the specific point that you need in order to get the reward. (SS Add reward)
The second option is to delete a reward that you don't want.(SS delete reward)
The third option is to get a reward that has been made.
Screenshot : (SS get reward)
The fourth option is to see rewards that you've claimed, from the latest one to the oldest one consecutively and each shows the time they were claimed. (SS Reward History)
The fifth option is to go back to main menu.



##Code explanation
#Data variable
For the data storage, we use struct method.
For example :

Task struct : 
struct task{
char namatask[20];
int pointtask;
int bulan,tanggal,jam,menit;
struct task *next;
};

Reward struct : 
struct reward{
char namareward[20];
int pointreward;
struct reward *next;
};

Reward history struct :
struct history{
 char RH[20];
 char time[50];
struct history *nextp;};
typedef struct history hist;
typedef hist *histp;

void push( histp *topP, char info[20] );
int isKosong( histp topP );
void printStack( histp skrgP );
histp stackP = NULL;

Task History struct :
struct qhistory{
 char QH[20];
 char qtime[50];
 char sukses[8];
struct qhistory *qnextp;};
typedef struct qhistory qhist;
typedef qhist *qhistp;
qhist*qhisthead=NULL, *qhisttail=NULL;

#History for reward and tasks
In reward and tasks history, we use the stack method, which has the principle of 'FILO', first in last out.
For example :
void push( histp *topP, char info[20] );
int isKosong( histp topP );
void printStack( histp skrgP );
histp stackP = NULL;
.
.
.
void push(histp *topP, char info[20]){
 histp newP;
 newP = malloc(sizeof(hist));
 
 if(newP!= NULL){
  strcpy( newP->RH, info);
  strcpy( newP->time, asctime (Sys_T));
  newP->nextp = *topP;
  *topP = newP;
 }else{
  printf("%s tidak dimasukkan. Tidak ada memory tersedia.\n\n", info[20]);
 }

}
int isKosong( histp topP ){
 return topP == NULL;
 
}

We use the same method for both reward and tasks history, with different veriables.



#Getting Current Time
We save data of time with different variables for each Months, Days, Hours, and minutes.
The code for the current is : (Required library is #include <time.h> )
struct tm *Sys_T;
getTime(){
    time_t current_time;
    char* c_time_string;
 
 
    /* Obtain current time. */
    current_time = time(NULL);
 Sys_T = localtime(&current_time); /*memasukan current_time ke struct tm*/
 
    if (current_time == ((time_t)-1))
    {
        (void) fprintf(stderr, "Failure to obtain the current time.\n");
        exit(EXIT_FAILURE);
    }


    /* Convert to local time format. */
    c_time_string = ctime(&current_time);

    if (c_time_string == NULL)
    {
        (void) fprintf(stderr, "Failure to convert the current time.\n");
        exit(EXIT_FAILURE);
    }

}
