#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>
#include<iostream.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>

typedef struct InfoType{
	int id;
	char name[30], Gender, Department[15];
	float Attendant;
	};
struct treeType{
	InfoType Info;
	treeType *Left,*Right;};

//*************Write Data Into File**************************************

void write(char *filename,InfoType st){

		FILE*file;
		file=fopen(filename,"ab");
		if(file==NULL){
				printf("Create file fail");
				getch();
				exit(0);
			     }
		fwrite(&st,sizeof(InfoType),1,file);
		fclose(file);
		}

//****************************Update Data In File*********************
void up(treeType *root,char *filename){
			if(root!=NULL){
		up(root->Left,filename);
		write(filename,root->Info);
		up(root->Right,filename);


		} }
//*******************Insert Data To Tree**********************************

treeType *insert(treeType *root,InfoType Item){
	   treeType*p,*ptr;
	   p=(treeType*)malloc(sizeof(treeType));
	   p->Info=Item;
	   p->Left=NULL;
	   p->Right=NULL;
	   if(root==NULL)root=p;
	   else{ptr=root;
		while(1){
			if(Item.id<ptr->Info.id){
				if(ptr->Left!=NULL)ptr=ptr->Left;
				else{ptr->Left=p;break;} }
			else{if(ptr->Right!=NULL)ptr=ptr->Right;
				else{ptr->Right=p;break;}
				}
				}
				}
				return root;
}

//*****************Display Data On Screen******************************
void show(treeType *root){
		gotoxy(8,7);
		printf("%-5d ",root->Info.id);
		printf("%-20s ",root->Info.name);
		printf("%-5c ",root->Info.Gender);
		printf("%-20s ",root->Info.Department);
		printf("%-7.f",root->Info.Attendant);
//printf("\n    컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴");
      }
void title(){
//int gd=DETECT;
//int gm;
//initgraph(&gd,&gm,"C:\\TC\\BGI");
setfillstyle(2,WHITE);
line(23,73,620,73);
line(23,70,620,70);
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,4);
	setcolor(7);
outtextxy(240,5,"Student");
		gotoxy(7,4);
		printf(" %-5s ","ID");
		printf("%-20s ","Name");
		printf("%-5s ","Gender");
		printf("%-20s ","Department");
		printf("%-11s","Attendant");
	       }
int y1=6;
void Display(treeType *root){
		if(root!=NULL){
		Display(root->Left);
		gotoxy(7,y1);
		printf(" %-5d ",root->Info.id);   y1+=2;
		printf("%-20s ",root->Info.name);
		printf(" %-5c ",root->Info.Gender);
		printf(" %-20s ",root->Info.Department);
		printf("%-7.f",root->Info.Attendant);
		Display(root->Right);
		if(y1>10)y1=6;
		}
}

//*******************Create New List****************************************

treeType *create(treeType *root){
int n;clrscr();
//int gd=DETECT;
//int gm;
//initgraph(&gd,&gm,"C:\\TC\\BGI");
settextstyle(1,HORIZ_DIR,1);
setcolor(7);
outtextxy(100,88,"Enter number of Student :");
		gotoxy(48,7);
		scanf("%d",&n);
		for(int i=0;i<n;i++){InfoType NEW;
		float Attendant;  clrscr();

setfillstyle(2,RED);
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,4);
	setcolor(7);
outtextxy(270,5,"CREATE");
settextstyle(1,HORIZ_DIR,1);
outtextxy(150,72,"ID");
outtextxy(150,120,"Name");
outtextxy(150,170,"Gender");
outtextxy(150,215,"Department");
outtextxy(150,265,"Attendant");
		gotoxy(38,6);
		scanf("%ld",&NEW.id);
		gotoxy(38,9);
		fflush(stdin);gets(NEW.name);
		gotoxy(38,12);
		scanf("%c",&NEW.Gender);
		gotoxy(38,15);
		fflush(stdin);gets(NEW.Department);fflush(stdin);
		gotoxy(38,18);
		scanf("%f",&Attendant);NEW.Attendant=Attendant;
		root=insert(root,NEW);
		}return root;
	}
void input(char *filename){   InfoType NEW;
		float Attendant;
int gd=DETECT;
int gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
setfillstyle(2,RED);
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,4);
	setcolor(7);
outtextxy(270,5,"INSERT");
settextstyle(1,HORIZ_DIR,1);
outtextxy(150,72,"ID");
outtextxy(150,120,"Name");
outtextxy(150,170,"Gender");
outtextxy(150,215,"Department");
outtextxy(150,265,"Attendant");

		gotoxy(38,6);
		scanf("%ld",&NEW.id);
		gotoxy(38,9);
		fflush(stdin);
		gets(NEW.name);
	       gotoxy(38,12);
	       scanf("%c",&NEW.Gender);
	       gotoxy(38,15);
	       fflush(stdin);
	       gets(NEW.Department);fflush(stdin);
	       gotoxy(38,18);
	       scanf("%f",&Attendant);
	       NEW.Attendant=Attendant;
		write(filename,NEW);

}
//*******************Read Data From File to Tree***************************
 treeType *read(char *filename,treeType *root){
		InfoType qq;
		FILE *file;
		file=fopen(filename,"rb");
		fseek(file,0L,2);

		long size=ftell(file)/sizeof(InfoType);
		if(size==0){
				printf("\nFile Empty");
				getch();
				exit(0);
				}
		rewind(file);
		fread(&qq,sizeof(InfoType),1,file);

		while(!feof(file)){
				root=insert(root,qq);
				fread(&qq,sizeof(InfoType),1,file);
				}
		fclose(file);
		return root;
		}
//**************Search******************

void SearchID(treeType *root,int item){

	if(root!=NULL){ SearchID(root->Left,item);
		if(root->Info.id==item)show(root);
		 SearchID(root->Right,item);

			}
	}
void SearchName(treeType *root,char item[]){
	if(root!=NULL){
		SearchName(root->Left,item);
		if(strcmp(root->Info.name,item)==0)show(root);
		SearchName(root->Right,item);
		}
	}
void Search(treeType *root){
clrscr();
int gd=DETECT;
int gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
setfillstyle(2,WHITE);
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,4);
setcolor(7);
outtextxy(275,5,"SEARCH");
	settextstyle(1,HORIZ_DIR,3);
	setcolor(13);
	outtextxy(200,60,"Search by ID");
	setcolor(WHITE);
	outtextxy(200,110,"Search by Name");
	outtextxy(200,160,"Back");

char c;int key=1;
do{
c=getch();
if(c==80)key++;
if(key==4)key=1;
if(key>3)key=1;
if(c==72)key--;
if(key==0)key=3;
if(key==1){
	setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(13);
	outtextxy(200,60,"Search by ID");
	setcolor(WHITE);
	outtextxy(200,110,"Search by Name");
	outtextxy(200,160,"Back");
}
if(key==2){
setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(200,60,"Search by ID");
	setcolor(13);
	outtextxy(200,110,"Search by Name");
	setcolor(WHITE);
	outtextxy(200,160,"Back");
}
if(key==3){
	setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(200,60,"Search by ID");
	outtextxy(200,110,"Search by Name");
	setcolor(13);
	outtextxy(200,160,"Back");

}
}while(c!=13);

switch(key){
case 1:{clrscr();
int id;
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,4);
setcolor(7);
outtextxy(220,5,"SEARCH BY ID");
			settextstyle(1,HORIZ_DIR,1);
			setcolor(7);
			outtextxy(100,89,"Student ID :");
			gotoxy(32,7);
			scanf("%d",&id);clrscr();title();
			SearchID(root,id);
			getch();break;}
case 2:{clrscr();
	setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,4);
	setcolor(7);
	outtextxy(190,5,"SEARCH BY NAME");
			settextstyle(1,HORIZ_DIR,1);
			setcolor(7);
			outtextxy(100,89,"Student Name :");
			gotoxy(35,7);
			char ch[30];
			fflush(stdin);gets(ch);clrscr();
			title();SearchName(root,ch);
			getch();break;}
case 3:break;

}
}
 //=============Delete Student Information=====================
treeType * minValueNode(treeType* root)
{
    treeType* current = root;

    /* loop down to find the leftmost leaf */
    while (current->Left != NULL)
	current = current->Left;

    return current;
}

treeType* DeleteID(treeType* root, int key)
{
    if (root == NULL) return root;
    if (key < root->Info.id)
	root->Left = DeleteID(root->Left, key);
    else if (key > root->Info.id)
	root->Right = DeleteID(root->Right, key);
    else
    {
	if (root->Left == NULL)
	{
	    treeType *temp = root->Right;
	    free(root);
	    return temp;
	}
	else if (root->Right == NULL)
	{
	    treeType *temp = root->Left;
	    free(root);
	    return temp;
	}

	treeType* temp = minValueNode(root->Right);
	root->Info = temp->Info;
	root->Right = DeleteID(root->Right, temp->Info.id);
    }
    return root;
}

treeType* DeleteName(treeType* root,char* key)
{
    if (root == NULL) return root;
    else if(strcmp(root->Info.name,key)<0)root->Left=DeleteName(root->Left,key);
    else if(stricmp(root->Info.name,key)>0)
    root->Right=DeleteName(root->Right,key);
    else if(stricmp(root->Info.name,key)==0)
    {
	if (root->Left == NULL)
	{
	    treeType *temp = root->Right;
	    free(root);
	    return temp;
	}
	else if (root->Right == NULL)
	{
	    treeType *temp = root->Left;
	    free(root);
	    return temp;
	}

	treeType* temp = minValueNode(root->Right);
	root->Info = temp->Info;
	root->Right = DeleteName(root->Right, temp->Info.name);
    }
    return root;
}

treeType *Delete(treeType *root){
int gd=DETECT;
int gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,4);
setcolor(7);
outtextxy(285,5,"DELETE");

	settextstyle(1,HORIZ_DIR,3);
	setcolor(13);
	outtextxy(200,60,"Delete by ID");
	setcolor(WHITE);
	outtextxy(200,110,"Delete by Name");
	outtextxy(200,160,"Back");

char c;int key=1;
do{
c=getch();
if(c==80)key++;
if(key==4)key=1;
if(key>3)key=1;
if(c==72)key--;
if(key==0)key=3;

if(key==1){


setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(13);
	outtextxy(200,60,"Delete by ID");
	setcolor(WHITE);
	outtextxy(200,110,"Delete by Name");
	outtextxy(200,160,"Back");
}
if(key==2){
setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(200,60,"Delete by ID");
	setcolor(13);
	outtextxy(200,110,"Delete by Name");
	setcolor(WHITE);
	outtextxy(200,160,"Back");
}
if(key==3){
	setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(200,60,"Delete by ID");
	outtextxy(200,110,"Delete by Name");
	setcolor(13);
	outtextxy(200,160,"Back");

}
}while(c!=13);

switch(key){
case 1:{clrscr();
int id;
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,4);
setcolor(7);
outtextxy(220,5,"DELETE BY ID");
			settextstyle(1,HORIZ_DIR,1);
			setcolor(7);
			outtextxy(100,89,"Student ID :");
			gotoxy(32,7);
		       scanf("%d",&id);clrscr();
			root=DeleteID(root,id);
			break;}
case 2:{clrscr();_setcursortype(_SOLIDCURSOR);
			char ch[30];
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,4);
setcolor(6);
outtextxy(190,5,"DELETE BY NAME");
			settextstyle(1,HORIZ_DIR,1);
			setcolor(7);
			outtextxy(100,89,"Student Name :");
			gotoxy(35,7);
			fflush(stdin);gets(ch);
			clrscr();
			root=DeleteName(root,ch);
			break;}
case 3:break;

	}
 return root;
}
//===============Update Infomation of Customer==  ========================
treeType *Attendant_In_ID(treeType *root,int id){
int gd=DETECT;
int gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,3);
setcolor(7);
outtextxy(260,5,"Attendant (+)");
	treeType *ptr=root;
	if(root==NULL){
	clrscr();
	settextstyle(1,HORIZ_DIR,3);
	setcolor(RED);
	outtextxy(270,150,"NO DATA");getch();
	     }
	else if(id<root->Info.id)
		root->Left=Attendant_In_ID(root->Left,id);
	else if(id>root->Info.id)
		root->Right=Attendant_In_ID(root->Right,id);
	else if(root->Info.id==id){
		settextstyle(1,HORIZ_DIR,1);
		setcolor(7);
		outtextxy(100,89,"Attendant (+) :");
			gotoxy(30,7);
		float Attendant;
		scanf("%f",&Attendant);root->Info.Attendant=root->Info.Attendant+Attendant;
		clrscr();
		settextstyle(1,HORIZ_DIR,3);
		setcolor(RED);
		outtextxy(270,150,"Successfully");
		delay(1000);clrscr();
		}
	return ptr;
	}

treeType *Attendant_In_Name(treeType *root,char *name){
clrscr();
int gd=DETECT;
int gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
	treeType *ptr=root;
	if(root==NULL){
		clrscr();
		settextstyle(1,HORIZ_DIR,3);
	setcolor(RED);
	outtextxy(270,150,"NO DATA");getch();
	      }
	else if(strcmp(root->Info.name,name)<0)
		root->Left=Attendant_In_Name(root->Left,name);
	else if(strcmp(root->Info.name,name)>0)
		root->Right=Attendant_In_Name(root->Right,name);
	else if(strcmp(root->Info.name,name)==0){
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,4);
setcolor(7);
outtextxy(250,5,"STCOCK IN");
		settextstyle(1,HORIZ_DIR,1);
		setcolor(7);
		outtextxy(100,89,"Attendant (+) :");
			gotoxy(30,7);
		float Attendant;scanf("%f",&Attendant);
		root->Info.Attendant=root->Info.Attendant+Attendant;
	     clrscr();
	       settextstyle(1,HORIZ_DIR,1);
		setcolor(7);
		outtextxy(270,150,"Successfully"); delay(1000);
		clrscr();
		}
	return ptr;
	}

treeType *Attendant_In(treeType *root){
int gd=DETECT;
int gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,4);
setcolor(7);
outtextxy(250,5,"Attendant (+)");
	settextstyle(1,HORIZ_DIR,3);
	setcolor(13);
	outtextxy(200,60,"Attendant (+) by ID");
	setcolor(WHITE);
	outtextxy(200,110,"Attendant (+) by Name");
	outtextxy(200,160,"Back");
char c;int key=1;
do{
c=getch();
if(c==80)key++;
if(key==4)key=1;
if(key>3)key=1;
if(c==72)key--;
if(key==0)key=3;

if(key==1){
setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(13);
	outtextxy(200,60,"Attendant (+) by ID");
	setcolor(WHITE);
	outtextxy(200,110,"Attendant (+) by Name");
	outtextxy(200,160,"Back");
}
if(key==2){
setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(200,60,"Attendant (+) by ID");
	setcolor(13);
	outtextxy(200,110,"Attendant (+) by Name");
	setcolor(WHITE);
	outtextxy(200,160,"Back");
}
if(key==3){
	setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(200,60,"Attendant (+) by ID");
	outtextxy(200,110,"Attendant (+) by Name");
	setcolor(13);
	outtextxy(200,160,"Back");

}
}while(c!=13);

switch(key){
case 1:{clrscr();
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,4);
setcolor(7);
outtextxy(220,5,"Attendant (+) BY ID");

			settextstyle(1,HORIZ_DIR,1);
			setcolor(7);
			outtextxy(100,89,"Student ID :");
			gotoxy(32,7);
			int id;scanf("%d",&id);
			clrscr();
			root=Attendant_In_ID(root,id);
			//getch();
			break;}
case 2:{clrscr();_setcursortype(_SOLIDCURSOR);textcolor(BLACK);
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,4);
setcolor(7);
outtextxy(215,5,"Attendant (+) BY NAME");
			char ch[30]; char name[30];
			settextstyle(1,HORIZ_DIR,1);
			setcolor(7);
			outtextxy(100,89,"Student Name :");
			gotoxy(35,7);
			fflush(stdin);gets(name);
			clrscr();
			root=Attendant_In_Name(root,name);
		       //	getch();
			break;}
case 3:break;
	}
return root;
}
//=================================================
treeType *Attendant_Out_ID(treeType *root,int id){
int gd=DETECT;
int gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
	if(root==NULL){
	clrscr();
int gd=DETECT;
int gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,3);
setcolor(RED);
outtextxy(270,150,"NO DATA");
	       getch();
	       }
	else if(id<root->Info.id)root->Left=Attendant_Out_ID(root->Left,id);
	else if(id>root->Info.id)root->Right=Attendant_Out_ID(root->Right,id);
	else if(root->Info.id==id){
	     clrscr();
	    float Attendant;
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,4);
setcolor(7);
outtextxy(245,5,"Attendant (-)");
		settextstyle(1,HORIZ_DIR,1);
		setcolor(7);
		outtextxy(100,89,"Attendant (-) :");
			gotoxy(37,7);
	       scanf("%f",&Attendant);
	       root->Info.Attendant=root->Info.Attendant-Attendant;
	       clrscr();
		settextstyle(1,HORIZ_DIR,2);
		setcolor(RED);
		outtextxy(270,150,"Successfully");
		delay(1000);clrscr();
		}
	return root;
	}
//=================================================================

treeType *Attendant_Out_Name(treeType *root,char *name){
int gd=DETECT;
int gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
	if(root==NULL){
		clrscr();
		settextstyle(1,HORIZ_DIR,3);
		setcolor(RED);
		outtextxy(270,150,"NO DATA");
		getch();}
	else if(strcmp(root->Info.name,name)<0)
		root->Left=Attendant_Out_Name(root->Left,name);
	else if(strcmp(root->Info.name,name)>0)
		root->Right=Attendant_Out_Name(root->Right,name);
	else if(strcmp(root->Info.name,name)==0){clrscr();
			settextstyle(1,HORIZ_DIR,1);
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,4);
setcolor(7);
outtextxy(245,5,"Attendant (-)");
		settextstyle(1,HORIZ_DIR,1);
		setcolor(7);
		outtextxy(100,89,"Attendant (-) :");
			gotoxy(37,7);
		float Attendant;scanf("%f",&Attendant);
		root->Info.Attendant=root->Info.Attendant-Attendant;
		clrscr();
		settextstyle(1,HORIZ_DIR,2);
		setcolor(RED);
		outtextxy(270,150,"Successfully");
		delay(1000);clrscr();
		}
	return root;
	}
treeType *Attendant_Out(treeType *root){
int gd=DETECT;
int gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,4);
setcolor(7);
outtextxy(245,5,"Attendant (-)");
	settextstyle(1,HORIZ_DIR,3);
	setcolor(13);
	outtextxy(200,60,"Attendant (-) by ID");
	setcolor(WHITE);
	outtextxy(200,110,"Attendant (-) by Name");
	outtextxy(200,160,"Back");
char c;int key=1;
do{
c=getch();
if(c==80)key++;
if(key==4)key=1;
if(key>3)key=1;
if(c==72)key--;
if(key==0)key=3;

if(key==1){
setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(13);
	outtextxy(200,60,"Attendant (-) by ID");
	setcolor(WHITE);
	outtextxy(200,110,"Attendant (-) by Name");
	outtextxy(200,160,"Back");
}
if(key==2){
setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(200,60,"Attendant (-) by ID");
	setcolor(13);
	outtextxy(200,110,"Attendant (-) by Name");
	setcolor(WHITE);
	outtextxy(200,160,"Back");
}
if(key==3){
	setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(200,60,"Attendant (-) by ID");
	outtextxy(200,110,"Attendant (-) by Name");
	setcolor(13);
	outtextxy(200,160,"Back");

}
}while(c!=13);

switch(key){
case 1:{clrscr();
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,4);
setcolor(7);
outtextxy(225,5,"Attendant (+) BY ID");
			settextstyle(1,HORIZ_DIR,1);
			setcolor(7);
		       outtextxy(100,89,"Student ID :");
			gotoxy(32,7);
		       int id;
			scanf("%d",&id);
			clrscr();
			root=Attendant_Out_ID(root,id);
			break;}
case 2:{clrscr();
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,4);
setcolor(7);
outtextxy(215,5,"Attendant (+) BY NAME");
			settextstyle(1,HORIZ_DIR,1);
			setcolor(7);
			outtextxy(100,89,"Student Name :");
			gotoxy(37,7);
			char name[30];fflush(stdin);gets(name);
			clrscr();
			root=Attendant_Out_Name(root,name);
			break;}
case 3:break;
	}
	  return root;
}
treeType *Update(treeType *root){
int gd=DETECT;
int gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,4);
setcolor(7);
outtextxy(265,5,"UPDATE");
	settextstyle(1,HORIZ_DIR,3);
	setcolor(13);
	outtextxy(200,60,"Attendant (+)");
	setcolor(WHITE);
	outtextxy(200,110,"Attendant (-)");
	outtextxy(200,160,"Back");
char c;int key=1;
do{
c=getch();
if(c==80)key++;
if(key==4)key=1;
if(key>3)key=1;
if(c==72)key--;
if(key==0)key=3;

if(key==1){
setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(13);
	outtextxy(200,60,"Attendant (+)");
	setcolor(WHITE);
	outtextxy(200,110,"Attendant (-)");
	outtextxy(200,160,"Back");
}
if(key==2){
setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(200,60,"Attendant (+)");
	setcolor(13);
	outtextxy(200,110,"Attendant (-)");
	setcolor(WHITE);
	outtextxy(200,160,"Back");
}
if(key==3){
	setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(200,60,"Attendant (+)");
	outtextxy(200,110,"Attendant (-)");
	setcolor(13);
	outtextxy(200,160,"Back");

}
}while(c!=13);

switch(key){
case 1:{clrscr();
	root=Attendant_In(root);
	break;}
case 2:{clrscr();
	root=Attendant_Out(root);
	break;}
case 3:break;
	}
  return root;
}
void name(){
int gd=DETECT;
int gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
setbkcolor(BLUE);
settextstyle(1,HORIZ_DIR,4);
	setcolor(YELLOW);
outtextxy(40,4,"ROYAL UNIVERSITY OF PHNOM PENH");
settextstyle(4,HORIZ_DIR,4);
	setcolor(YELLOW);
outtextxy(100,50,"Department of Computer Science");
	settextstyle(1,HORIZ_DIR,2);
	setcolor(10);
outtextxy(100,100,"Attendant Management System");
	settextstyle(1,HORIZ_DIR,3);
	setcolor(7);
	outtextxy(100,145,"Lecture    : Dan Vournpheng");
	setcolor(7);
	outtextxy(100,190,"Developed  :");
	settextstyle(1,HORIZ_DIR,1);
	outtextxy(240,240,"1. Vann Davin");
	outtextxy(240,270,"2. Chhit Samnang");
	outtextxy(240,300,"3. Mat Naseat");
	outtextxy(240,330,"4. Ly Suhaita");
int a=(getmaxx()-textwidth("<<<               >>>"))/2;
       do{
 settextstyle(0, 0, 1);
 setcolor(BLUE);
 outtextxy(a,getmaxy()-15,"<<<               >>>");
 setcolor(2);
 outtextxy(a,getmaxy()-15,"    PRESS ANY KEY    ");
 delay(250);if(kbhit()){getch();break;}
 setcolor(BLUE);
 outtextxy(a,getmaxy()-15,"<<<               >>>");
 setcolor(2);
 outtextxy(a,getmaxy()-15,"  < PRESS ANY KEY >  ");
 delay(250);if(kbhit()){getch();break;}
 setcolor(BLUE);
 outtextxy(a,getmaxy()-15,"<<<               >>>");
 setcolor(2);
 outtextxy(a,getmaxy()-15," << PRESS ANY KEY >> ");
 delay(250);if(kbhit()){getch();break;}
 setcolor(BLUE);
 outtextxy(a,getmaxy()-15,"<<<               >>>");
 setcolor(2);
 outtextxy(a,getmaxy()-15,"<<< PRESS ANY KEY >>>");
 delay(250);if(kbhit()){getch();break;}
 }while(1);
       clrscr();
}

void main(){
	clrscr();treeType *root;
	char filename[]="Student.bin";
name();
clrscr();
A:
clrscr();

int gd=DETECT;
int gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
textcolor(BLACK);
setbkcolor(BLACK);
settextstyle(1,HORIZ_DIR,4);
setcolor(YELLOW);
outtextxy(280,5,"MENU");
	settextstyle(1,HORIZ_DIR,3);
	setcolor(13);
	outtextxy(200,60,"CREATE");
	setcolor(WHITE);
	outtextxy(200,110,"INSERT");
	outtextxy(200,160,"DELETE");
	outtextxy(200,210,"SEARCH");
	outtextxy(200,260,"DISPLAY");
	outtextxy(200,310,"UPDATE");
	outtextxy(200,360,"EXIT");
char c;int key=1;
do{
c=getch();
if(c==80)key++;
if(key==8)key=1;
if(key>7)key=1;
if(c==72)key--;
if(key==0)key=7;

if(key==1){
setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(13);
	outtextxy(200,60,"CREATE");
	setcolor(WHITE);
	outtextxy(200,110,"INSERT");
	outtextxy(200,160,"DELETE");
	outtextxy(200,210,"SEARCH");
	outtextxy(200,260,"DISPLAY");
	outtextxy(200,310,"UPDATE");
	outtextxy(200,360,"EXIT");
}
if(key==2){
setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(200,60,"CREATE");
	setcolor(13);
	outtextxy(200,110,"INSERT");
	setcolor(WHITE);
	outtextxy(200,160,"DELETE");
	outtextxy(200,210,"SEARCH");
	outtextxy(200,260,"DISPLAY");
	outtextxy(200,310,"UPDATE ");
	outtextxy(200,360,"EXIT");
}
if(key==3){
	setbkcolor(BLACK);
	settextstyle(1,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(200,60,"CREATE");
	outtextxy(200,110,"INSERT");
	setcolor(13);
	outtextxy(200,160,"DELETE");
	setcolor(WHITE);
	outtextxy(200,210,"SEARCH");
	outtextxy(200,260,"DISPLAY");
	outtextxy(200,310,"UPDATE");
	outtextxy(200,360,"EXIT");
}
if(key==4){
	settextstyle(1,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(200,60,"CREATE");
	outtextxy(200,110,"INSERT");
	outtextxy(200,160,"DELETE");
	setcolor(13);
	outtextxy(200,210,"SEARCH");
	setcolor(WHITE);
	outtextxy(200,260,"DISPLAY");
	outtextxy(200,310,"UPDATE");
	outtextxy(200,360,"EXIT");
}
if(key==5){
	settextstyle(1,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(200,60,"CREATE");
	outtextxy(200,110,"INSERT");
	outtextxy(200,160,"DELETE");
	outtextxy(200,210,"SEARCH");
	setcolor(13);
	outtextxy(200,260,"DISPLAY");
	setcolor(WHITE);
	outtextxy(200,310,"UPDATE");
	outtextxy(200,360,"EXIT");
}
if(key==6){
	settextstyle(1,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(200,60,"CREATE");
	outtextxy(200,110,"INSERT");
	outtextxy(200,160,"DELETE");
	outtextxy(200,210,"SEARCH");
	outtextxy(200,260,"DISPLAY");
	setcolor(13);
	outtextxy(200,310,"UPDATE");
	setcolor(WHITE);
	outtextxy(200,360,"EXIT");
}
if(key==7){
	settextstyle(1,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(200,60,"CREATE");
	outtextxy(200,110,"INSERT");
	outtextxy(200,160,"DELETE");
	outtextxy(200,210,"SEARCH");
	outtextxy(200,260,"DISPLAY");
	outtextxy(200,310,"UPDATE");
	setcolor(13);
	outtextxy(200,360,"EXIT");
}
}while(c!=13);

switch(key){
case 1:{clrscr();
	root=NULL;
	root=create(root);
	remove(filename);
	up(root,filename);goto A;}
case 2:{clrscr();closegraph();
	clrscr();
	input(filename);goto A;}
case 3:{clrscr();
	root=NULL;
	//textcolor(BLACK);
	root=read(filename,root);root=Delete(root);
	remove(filename);up(root,filename);
	goto A;}
case 4:{ clrscr();
	root=NULL;root=read(filename,root);
	Search(root);	goto A;}
case 5:{clrscr();
	root=NULL;
	clrscr();root=read(filename,root);title();
	Display(root);getch();goto A;}
case 6:{clrscr();
	root=NULL;
	clrscr();root=read(filename,root);
	root=Update(root);remove(filename);up(root,filename);
	goto A;}
case 7:{clrscr();
	setbkcolor(BLACK);
	settextstyle(5,HORIZ_DIR,5);
	setcolor(7);
       outtextxy(200,200,"Thank You");
	delay(1000);
	exit(0);
	}
	}
}
