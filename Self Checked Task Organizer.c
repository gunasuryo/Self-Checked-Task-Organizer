#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>


int point, keluar,balik, a=1;
/*struct untuk history reward*/
struct history{
	char RH[20];
	char time[50];
struct history *nextp;};
typedef struct history hist;
typedef hist *histp;
hist*histhead=NULL, *histtail=NULL;
/*fungsi untuk membuat stack history reward*/
void push( histp *topP, char info[20] );
int isKosong( histp topP );
void printStack( histp skrgP );
histp stackP = NULL;

/*struct untuk history task*/
struct qhistory{
	char QH[20];
	char qtime[50];
	char sukses[8];
struct qhistory *qnextp;};
typedef struct qhistory qhist;
typedef qhist *qhistp;
qhist*qhisthead=NULL, *qhisttail=NULL;
/*fungsi untuk membuat stack history task*/
void qpush( qhistp *qtopP, char qinfo[20] );
int qisKosong( qhistp qtopP );
void qprintStack( qhistp qskrgP );
qhistp qstackP = NULL;

/*struct untuk task*/	
struct task{
char namatask[20];
int pointtask;
int bulan,tanggal,jam,menit;
struct task *next;

};
typedef struct task task;
	task*taskhead=NULL, *tasktail=NULL;
/*struct untuk reward*/
struct reward{
char namareward[20];
int pointreward;
struct reward *next;

};
typedef struct reward reward;
	reward*rewardhead=NULL, *rewardtail=NULL;
	
	
struct tm *Sys_T; /*struct untuk waktu*/
getTime(){
    time_t current_time;
    char* c_time_string;
	
	
    /* Mendapatkan waktu sekarang. */
    current_time = time(NULL);
	Sys_T = localtime(&current_time); /*memasukan current_time ke struct tm*/
	
    if (current_time == ((time_t)-1))
    {
        (void) fprintf(stderr, "Failure to obtain the current time.\n");
        exit(EXIT_FAILURE);
    }


    /* Convert ke format local time  */
    c_time_string = ctime(&current_time);

    if (c_time_string == NULL)
    {
        (void) fprintf(stderr, "Failure to convert the current time.\n");
        exit(EXIT_FAILURE);
    }

}
//	int i,loadpoint,loadbulan,loadtanggal,loadjam,loadmenit;
//	char loadnama[20];
		
int main(){
	
	/*load point dari file .txt*/
    FILE *in;
	in = fopen("point.txt", "r");
    fscanf(in,"%d",&point);
    
//    FILE *loadtask = fopen("task.txt", "r");
//// 	task *load = taskhead;
//// 	for(i=0;i<1;i++){	
////		fgets(loadnama, 20,loadtask);	
////		fscanf(loadtask,"%d",load->pointtask);
////		fscanf(loadtask,"%d",load->bulan);
////		fscanf(loadtask,"%d",load->tanggal);
////		fscanf(loadtask,"%d",load->jam);
////		fscanf(loadtask,"%d",load->menit);
////		load = load->next;
//	}

	
	menu();
}

/*menampilkan menu utama sekaligus melakukan save data yang tersedia*/
int menu(){
	system("color 37"); /*mengubah warna tampilan program, dengan backround 3 dan warna tulisan 7*/
	/*melakukan save data point ke file .txt*/
		FILE *out=fopen("point.txt","w");
	fprintf(out,"%d",point);
 	/*melakukan save data task ke file .txt*/
 		FILE *savetask=fopen("task.txt","w");
	task *save = taskhead;
		while(save!=NULL){
		fprintf(savetask,"%s\n",save->namatask);
		fprintf(savetask,"%d\n",save->pointtask);
		fprintf(savetask,"%d\n",save->bulan);
		fprintf(savetask,"%d\n",save->tanggal);
		fprintf(savetask,"%d\n",save->jam);
		fprintf(savetask,"%d\n",save->menit);
		 save = save->next;
	}
	/*melakukan save data reward ke file .txt*/
		FILE *savereward=fopen("reward.txt","w");
	reward *saveR = rewardhead;
		while(save!=NULL){
		fprintf(savereward,"%s\n",saveR->namareward);
		fprintf(savereward,"%d\n",saveR->pointreward);
		 saveR = saveR->next;
	}
	/*melakukan save history task ke file .txt*/
		FILE *savetaskhis=fopen("task_history.txt","w");
	qhist *save2 = qhisthead;
		while(save2!=NULL){
		fprintf(savetaskhis,"%s\n",save2->QH);
		fprintf(savetaskhis,"%s\n",save2->qtime);
		fprintf(savetaskhis,"%s\n",save2->sukses);
		 save2 = save2->qnextp;
	}
	/*melakukan save reward task ke file .txt*/
			FILE *saverewardhis=fopen("reward_history.txt","w");
	hist *save3 = histhead;
		while(save3!=NULL){
		fprintf(saverewardhis,"%s\n",save3->RH);
		fprintf(saverewardhis,"%s\n",save3->time);
		 save3 = save3->nextp;
	}
	
 fclose(out);
 fclose(savetask);
 fclose(savereward);
 fclose(savetaskhis);
 fclose(saverewardhis);
 system("cls");
 	printf("||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("|||||||||SELF-CHECKED TASK ORGANIZER||||||||\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("waktu sekarang: %s\n",getTime());
	printf("point sekarang: %d\n\n",point);

	printf("Menu: \n");
	printf("[1]Menu task\n");
	printf("[2]Menu Reward\n");
	printf("[3]Bantuan dan Informasi\n");
	printf("[4]exit\n");


	switch (getch()){
		case '1':
			system("cls");
			showtask();
			break;	
		case '2':
			system("cls");
			menureward();
			break;	
		case'3':
			system("cls");
			bantuan();
			break;
		case'4':
			printf("\nterimakasih telah menggunakan program kami\n");
			keluar=1;
			exit(0);
			break;	


	}


}
/*menampilkan bantuan dan informasi*/
bantuan(){
	printf("BANTUAN: \n");
	printf("Peringatan: dimohon untuk memakai opsi exit pada menu utama apabila selesai menggunakan program agar data dapat di save dengan normal.\n\n");
	
	printf("Petunjuk Task: \n");
	printf("1.pilih opsi 1 pada main menu untuk mengakses menu task\n");
	printf("2.pilih opsi 1 pada menu task untuk menambah task. Masukan data nama maximal 20 char, lalu tekan enter\n");
	printf("3.masukan data point dan deadline berupa interger lalu tekan enter. (Pada bulan dapat dimasukan integer 1-12, 1 =Januari 12=Desember)\n");
	printf("4.Untuk menghapus task pilih opsi 2 pada menu task. Masukan data nama task maximal 20 char, lalu tekan enter\n");
	printf("5.pilih opsi 3 pada menu task untuk menyelesaikan task. Masukan data nama task maximal 20 char, lalu tekan enter\n");
	printf("6.Untuk melihat riwayat task yang telah diselesaikan, pilih opsi 4\n");
	printf("7.Untuk kembali ke menu utama, pilih opsi 5\n\n");
	
	printf("Petunjuk Reward: \n");
	printf("1.pilih opsi 2 pada main menu untuk mengakses menu reward\n");
	printf("2.pilih opsi 1 pada menu reward untuk menambah reward. Masukan data nama maximal 20 char, lalu tekan enter\n");
	printf("3.masukan data point berupa interger lalu tekan enter.\n");
	printf("4.Untuk menghapus reward pilih opsi 2 pada menu task. Masukan data nama reward maximal 20 char, lalu tekan enter\n");
	printf("5.pilih opsi 3 pada menu task untuk claim reward. Masukan data nama reward maximal 20 char, lalu tekan enter\n");
	printf("6.Untuk melihat riwayat reward yang telah diclaim, pilih opsi 4\n");
	printf("7.Untuk kembali ke menu utama, pilih opsi 5\n\n");
	
	printf("Informasi:\n");
	printf(" Program ini dikembangkan oleh Teuku Salman Farizi (NPM: 1706043216) dan Guna Suryo Aji (NPM: 1706043222) pada bulan desember 2018 \n dalam rangka penyelesaian Proyek akhir matakuliah Pemrograman Lanjut Teknik Komputer, Departemen Teknik Elektro, Fakultas Teknik Universitas Indonesia.\n");
	system("pause");
	menu();
}

/*Menampilkan daftar Linked List Task*/
showtask(){
	task *showtask;
	showtask = taskhead;
	printf("\nDAFTAR TASK: \n");
	while(showtask != NULL){
		printf(" [%s] point : %d \n\n",showtask->namatask,showtask->pointtask);
		printf("deadline: bulan %d, tanggal %d, jam %d menit %d\n",showtask->bulan,showtask->tanggal,showtask->jam,showtask->menit);
		showtask = showtask->next;
	}
	printf("\n");
	menutask();
}

menutask(){
		printf("Pilihan:\n");
	printf("[1]Tambah task\n");
	printf("[2]Hapus task\n");
	printf("[3]Finish task\n");
	printf("[4]Show completed task\n");
	printf("[5]Kembali ke menu\n");
	
	switch (getch()){
		case '1':
			addtask();
			break;
		case '2':
			deletetask();
			break;
		case'3':
			finishtask();
			break;
		case'4':
			qprintStack(qstackP);
			break;			
		case '5':		
			menu();
			break;
	}

system("cls");
showtask();
}

menureward(){
	system("cls");
	/*Menampilkan daftar Linked List Reward*/
		reward *showData;
	showData = rewardhead;
	printf("\nDAFTAR REWARD: \n");
	while(showData != NULL){
		printf("%s : point %d \n",showData->namareward,showData->pointreward);
		showData = showData->next;
	}
	printf("\n");
	printf("Pilihan:\n");
	printf("[1]Tambah Reward\n");
	printf("[2]Claim reward\n");
	printf("[3]Hapus Reward\n");
	printf("[4]Show reward history\n");
	printf("[5]Kembali ke menu\n");
	
	
	switch (getch()){
		case '1':
			addreward();
			break;
		case '2':
			claimreward();
			break;
		case '3':
			deletereward();
			break;
		case '4':
			printStack(stackP);
			break;
		case '5':
			menu();
			break;
	}
	
}
/*melakukan insert ke Linked List Task*/
addtask(){
	printf("TAMBAH TASK\n");
	char datanama[20];
	char datadesc[100];
	int datapoint;
	int databulan,datatanggal,datajam,datamenit;
	printf("\nMasukan nama task:");
	scanf("%s",&datanama);
	printf("\nMasukan point dari task:");
	scanf("%d",&datapoint);
	printf("masukan tanggal deadline (dalam integer)\n");
	printf("bulan: ");
	scanf("%d",&databulan);
	printf("tanggal: ");
	scanf("%d",&datatanggal);
	printf("jam: ");
	scanf("%d",&datajam);
	printf("menit: ");
	scanf("%d",&datamenit);
	
	task *barutask;
	barutask=(task*)malloc(sizeof(task));
	strcpy(barutask->namatask, datanama);
	barutask->pointtask = datapoint;
	barutask->bulan = databulan;
	barutask->tanggal = datatanggal;
	barutask->jam = datajam;
	barutask->menit = datamenit;
	
	barutask->next = NULL;
	
	if (taskhead == NULL){
		taskhead = barutask;
		tasktail = barutask;
	}
	else{
		tasktail->next = barutask;
		tasktail=barutask;
	}
	printf("\n");
}
/*melakukan insert ke Linked List Reward*/
addreward(){
		printf("TAMBAH REWARD \n");
	char datanama[20];
	char datadesc[100];
	int datapoint;
	
	printf("\nMasukan nama reward:");
	scanf("%s",&datanama);
	printf("\nMasukan point untuk claim reward:");
	scanf("%d",&datapoint);
	
	reward *baru;
	baru=(reward*)malloc(sizeof(reward));
	strcpy( baru->namareward, datanama);
	baru->pointreward = datapoint;

	baru->next = NULL;
	
	if (rewardhead == NULL){
		rewardhead = baru;
		rewardtail = baru;
	}
	else{
		rewardtail->next = baru;
		rewardtail=baru;
	}
	printf("\n");
	menureward();
}
/*melakukan delete ke Linked List Task*/
deletetask(){
	char datanama[20];
	int compare;
	int hasil = 0;
	printf("Masukan nama task yang akan dihapus:");
	scanf("%s",&datanama);
	
	task *hapus = taskhead, *previous=NULL;
	
	
	while(hapus!=NULL){
		compare = strcmp(hapus->namatask,datanama);
		if(compare==0){
			if(previous==NULL){
			taskhead = hapus->next;
			}
			else{
			previous->next=hapus->next;
			}
		printf("task %s telah dihapus dari daftar\n",datanama);
		system("pause");
		hasil = 1;
		free(hapus);
		break;
		}
	previous = hapus;
	hapus = hapus->next;
}
}
/*melakukan delete ke Linked List Reward*/
deletereward(){
	char datanama[20];
	int compare;
	int hasil = 0;
	printf("Masukan nama reward yang akan dihapus:");
	scanf("%s",&datanama);
	
	reward *hapus = rewardhead, *previous=NULL;
	
	
	while(hapus!=NULL){
		compare = strcmp(hapus->namareward,datanama);
		if(compare==0){
			if(previous==NULL){
			rewardhead = hapus->next;
			}
			else{
			previous->next=hapus->next;
			}
		printf("reward %s telah dihapus dari daftar\n",datanama);
		system("pause");
		hasil = 1;
		free(hapus);
		break;
		}
	previous = hapus;
	hapus = hapus->next;
	
}
menureward();
}
/*menyelesaikan Task*/
finishtask(){
	char datanama[20];
	int compare,deadline;
	int hasil = 0;
	printf("Masukan nama task yang telah diselesaikan:");
	gets(datanama);
	
	task *finish = taskhead, *previous=NULL;
	
	
	while(finish!=NULL){
		compare = strcmp(finish->namatask,datanama);
		if(compare==0){
			if(previous==NULL){
			taskhead = finish->next;
			}
			else{
			previous->next=finish->next;
			}
		deadline = cekdeadline(finish->bulan,finish->tanggal,finish->jam,finish->menit);/*mendapatkan hasil perbandingan deadline dengan waktu sekarang*/
		if(deadline==1){/*apabila task diselesaikan sebelum deadline*/
		printf("task %s telah selesai dan anda mendapatkan point %d!!! (point sekarang: %d)\n",datanama,finish->pointtask,point);
		point = point + finish->pointtask;
			qpush1(&qstackP, datanama);
		}
		else{/*apabila task diselesaikan setelah deadline*/
			printf("Task %s sudah meleawati deadline. Anda tidak mendapatkan point... (point sekarang: %d) \n ",datanama,point);
			qpush0(&qstackP, datanama);
		}
		hasil = 1;
		free(finish);
		system("pause");
		break;
		}
		else{
			
		}
	previous = finish;
	finish = finish->next;
}
}
/*membandingkan waktu sekarang dengan deadline task*/
int cekdeadline(int bulan, int tanggal, int jam, int menit){
	int deadline;
	getTime();
	if(Sys_T->tm_mon+1 > bulan){
		deadline = 0;}
	else if(Sys_T->tm_mday > tanggal){
			deadline = 0;}
			else if(!Sys_T->tm_hour > jam){
				deadline = 0;}
				else if(Sys_T->tm_min > menit){
					deadline = 0;}
				else{
					deadline = 1;
				}
			
	return deadline;
}
/*mengambil reward*/
claimreward(){
	char datanama[20];
	int compare;
	int hasil = 0;
	printf("Masukan nama reward yang akan di claim:");
	scanf("%s",&datanama);
	
	reward *claim = rewardhead, *previous=NULL;
	
	
	while(claim!=NULL){
		compare = strcmp(claim->namareward,datanama);
		if(compare==0){
			if(previous==NULL){
			rewardhead = claim->next;
			}
			else{
			previous->next=claim->next;
			}
			point = point - claim->pointreward;
		printf("reward %s telah di claim dan point anda sekarang %d\n",datanama,point);
		system("pause");
		push(&stackP, datanama);
		hasil = 1;
		free(claim);
		break;
		}
	previous = claim;
	claim = claim->next;

}
	menureward();
	
	
}
/*menambah data ke atas stack reward history*/
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
/*menambah data ke atas stack task history yang selesai sebelum deadline*/
void qpush1(qhistp *qtopP, char qinfo[20]){
	qhistp qnewP;
	qnewP = malloc(sizeof(qhist));
	
	if(qnewP!= NULL){		
		strcpy( qnewP->QH, qinfo);
		strcpy(qnewP->qtime,asctime (Sys_T));
		strcpy(qnewP->sukses,"(sukses)");
		qnewP->qnextp = *qtopP;
		*qtopP = qnewP;
		
		
	}else{
	printf("%s tidak dimasukkan. Tidak ada memory tersedia.\n\n", qinfo[20]);
	}

}
/*menambah data ke atas stack task history yang selesai setelah deadline*/
void qpush0(qhistp *qtopP, char qinfo[20]){
	qhistp qnewP;
	qnewP = malloc(sizeof(qhist));
	
	if(qnewP!= NULL){

		strcpy( qnewP->QH, qinfo);
		strcpy(qnewP->qtime,asctime (Sys_T));
		strcpy(qnewP->sukses,"(gagal)");
		qnewP->qnextp = *qtopP;
		*qtopP = qnewP;
	
	}else{
	printf("%s tidak dimasukkan. Tidak ada memory tersedia.\n\n", qinfo[20]);
	}
}
/*menampilkan stack reward history*/
void printStack(histp skrgP){
	if(skrgP == NULL) {
      printf( "Reward history kosong.\n\n");	
}else {
	printf("History reward : \n\n");
	while(skrgP!=NULL){
		printf("\t%d.",a);
		         printf( "%s\n", skrgP->RH );
		         printf( "%s\n", skrgP->time);
		         skrgP = skrgP->nextp;
		a++;
	}
	a=1;
}
system("pause");
system("cls");
}
/*menunjukan apabila reward history kosong*/
int isKosong( histp topP ){
	return topP == NULL;
	
}
/*menampilkan stack task history*/
void qprintStack(qhistp qskrgP){
	if(qskrgP == NULL) {
      printf( "task history kosong.\n\n");	
}else {
	printf("History task : \n\n");
	while(qskrgP!=NULL){
		         printf( "\t%d. %s\n",a, qskrgP->QH );
		         printf( "\tSelesai pada :%s \t(%s)\n",qskrgP->qtime,qskrgP->sukses);
		         qskrgP = qskrgP->qnextp;
		a++;
	}
	a=1;
}
system("pause");
}
/*menunjukan apabila task history kosong*/
int qisKosong( qhistp qtopP ){
	return qtopP == NULL;
	
}
