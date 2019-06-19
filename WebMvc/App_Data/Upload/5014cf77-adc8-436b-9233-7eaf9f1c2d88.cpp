#include<iostream>
#include<conio.h>
#include<math.h>
#include<ctype.h>
using namespace std;
class solid{
		public:virtual void input()=0;
				 virtual void output()=0;
				 virtual float volume()=0;
			 enum type{pyramid,sylinder,prolepypet};
			 virtual type objtype()=0;
};
class pyramid:public virtual solid{
					private: float a,h;float Total;
					public:virtual void input();
							 virtual void output();
							 virtual float volume();
							 pyramid();
							 pyramid(float a,float h);
							 virtual type objtype(){return(solid::pyramid);}
};

pyramid::pyramid(){
	a=5;
	h=3;
}
pyramid::pyramid(float a,float h){
	this->a=a;
	this->h=h;
}
void pyramid::input(){
	cout<<"Input A : "; cin>>a;
	cout<<"Input H : ";cin>>h;
}
void pyramid::output(){
	cout<<endl<<"\t"<<a<<"\t"<<h<<"\t"<<volume()<<endl;
}
float pyramid::volume(){
	return((a*h)/3);
}

class sylinder:public virtual solid{
					private: float r,h;
					public: void input();
							 virtual void output();
							 virtual float volume();
							 sylinder();
							 sylinder(float a,float h);
							 virtual type objtype(){return(solid::sylinder);}
};

sylinder::sylinder(){
	r=5;
	h=3;
}
sylinder::sylinder(float r,float h){
	this->r=r;
	this->h=h;
}
void sylinder::input(){
	cout<<"Input R : ";cin>>r;
	cout<<"Input H : ";cin>>h;
}
void sylinder::output(){
	cout<<endl<<"\t"<<r<<"\t"<<h<<"\t"<<volume()<<endl;
}
float sylinder::volume(){
	return((3.14)*r*r*h);
}

class prolepypet:public virtual solid{
					  private:float a,b,c;
					  public:virtual void input();
								virtual void output();
								virtual float volume();
								prolepypet();
								prolepypet(float a,float b,float c);
								virtual type objtype(){return(solid::prolepypet);}
};
void prolepypet::input(){
	cout<<"Input a : ";cin>>a;
	cout<<"Input b : ";cin>>b;
	cout<<"Input c : ";cin>>c;
}
void prolepypet::output(){
	cout<<endl<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<volume()<<endl;
}
float prolepypet::volume(){
	return(a*b*c);
}
prolepypet::prolepypet(){
	a=3;
	b=1;
	c=2;
}
prolepypet::prolepypet(float a,float b,float c){
	this->a=a;
	this->b=b;
	this->c=c;
}
int main(){
int i,n,m=6;char ch;
cout<<"input n: ";cin>>n;
	solid *obj[6]={
						new pyramid(2,3),
						new pyramid(8,4.3),
						new sylinder(2.2,3.1),
						new sylinder(1.3,2.0),
						new prolepypet(2.2,3.0,2),
						new prolepypet(1,2,3)
				  };

	A:
 	cout<<"Please Choose option below...\n";
	cout<<"O Show all Initialize\n";
	cout<<"I Input N object\n";
	cout<<"D Output N object\n";
	cout<<"choose O I D 0 to exit .....\n"<<endl;
	ch=getch();
	switch(ch){
		case'O':case'o':cout<<"1 Show all objects\n";
	 A1:
	cout<<"1 Show all objects\n";
	cout<<"2 Show all pyramid\n";
	cout<<"3 Show all sylinder\n";
	cout<<"4 Show all prolepypet\n";

			switch(getch()){
		case '1':{ cout<<"\n\t\tShow all objects\n";
				for(i=0;i<m;i++)
				obj[i]->output();
				getch();
				cout<<"Are you sure to continue[y/n]";
							switch(getch()){
								case'Y':case'y':goto A1;
								case'N':case'n':goto A;
								default:goto A1;
							}
		}
		case'2':{cout<<"\n\t\tShow all pyramid\n\n";
				cout<<"\t\tPyramid=1/3(a*h)\n\n";
				cout<<"\ta\th\tVolume\n";
				for(i=0;i<m;i++)
				if(obj[i]->objtype()==solid::pyramid)
				obj[i]->output();
					getch();
					cout<<"Are you sure to continue[y/n]";
							switch(getch()){
								case'Y':case'y':goto A1;
								case'N':case'n':goto A;
								default:goto A1;
							}
		}
		case'3':{cout<<"\n\t\tShow all sylinder\n";
				cout<<"\t\tSylinder=3.14*r*r*h\n\n";
				cout<<"\tr\th\tVolume\n";
				for(i=0;i<m;i++)
			if(obj[i]->objtype()==solid::sylinder)
			obj[i]->output();
			getch();cout<<"Are you sure to continue[y/n]";
							switch(getch()){
								case'Y':case'y':goto A1;
								case'N':case'n':goto A;
								default:goto A1;
							}
			}
		case'4':{cout<<"\n\t\tShow all prolepypet\n";
			 cout<<"\t\tProlepypet=a*b*c\n\n";
			 cout<<"\ta\tb\tc\tVolume\n";
				for(i=0;i<m;i++)
			if(obj[i]->objtype()==solid::prolepypet)
			obj[i]->output();
			getch();cout<<"Are you sure to continue[y/n]";
							switch(getch()){
								case'Y':case'y':goto A1;
								case'N':case'n':goto A;
								default:goto A1;
							}
			}
			}
	case'I':case'i':{
				B:
				cout<<"\t\t\n1 Input pyramid  "<<endl;
				cout<<"\t\t\n2 Input sylinder  "<<endl;
				cout<<"\t\t\n3 Input prolepypet "<<endl;
				switch(getch()){
					case'1':for(i=0;i<n;i++)
						if(obj[i]->objtype()==solid::pyramid)
						obj[i]->input();
						for(i=0;i<n;i++)
						if(obj[i]->objtype()==solid::pyramid){
						obj[i]->output();}
						getch();
						B1:
						cout<<"Are you sure to continue[y/n]";
							switch(getch()){
								case'Y':case'y':goto B;
								case'N':case'n':goto A;
								default:goto B1;
							}
					case'2':{for(i=0;i<n;i++)
						if(obj[i]->objtype()==solid::sylinder){
						obj[i]->input();}
						for(i=0;i<n;i++)
						if(obj[i]->objtype()==solid::sylinder){
						obj[i]->output();}
						getch();
						B2:
						cout<<"Are you sure to continue[y/n]";
							switch(getch()){
								case'Y':case'y':goto B;
								case'N':case'n':goto A;
								default:goto B2;
							}
						}
					case'3':{for(i=0;i<n;i++)
						if(obj[i]->objtype()==solid::prolepypet)
						obj[i]->input();
						for(i=0;i<n;i++)
						if(obj[i]->objtype()==solid::prolepypet){
						obj[i]->output();}
						getch();
						B3:
						cout<<"Are you sure to continue[y/n]";
							switch(getch()){
								case'Y':case'y':goto B;
								case'N':case'n':goto A;
								default:goto B3;
							}

						}
						default:goto B;
				}
	 case'd':{
				C:
				cout<<"\t\t\n1 Output pyramid  "<<endl;
				cout<<"\t\t\n2 Output sylinder  "<<endl;
				cout<<"\t\t\n3 Output prolepypet "<<endl;
				switch(getch()){
					case'1':{for(i=0;i<n;i++)
						if(obj[i]->objtype()==solid::pyramid)
						obj[i]->output();getch();
						C1:
						cout<<"Are you sure to continue[y/n]";
							switch(getch()){
								case'Y':case'y':goto C;
								case'N':case'n':goto A;
								default:goto C1;
							}
						}
					case'2':{for(i=0;i<n;i++)
						if(obj[i]->objtype()==solid::sylinder)
						obj[i]->output();getch();
						C2:
						cout<<"\nAre you sure to continue[y/n]";
							switch(getch()){
								case'Y':case'y':goto C;
								case'N':case'n':goto A;
								default:goto C2;
								}
						}
					case'3':{for(i=0;i<n;i++)
						if(obj[i]->objtype()==solid::prolepypet)
						obj[i]->output();getch();
					  C3:
						cout<<"\nAre you sure to continue[y/n]";
							switch(getch()){
								case'Y':case'y':goto C;
								case'N':case'n':goto A;
								default:goto C3;
								}
						}
					}
				}
	  goto A;
	}
	default:goto A;
 }
}

