 #include<iostream.h>
 #include<conio.h>
 #include<stdio.h>
 #include<string.h>
 #include<fstream.h>
 char ch;
 int ans;
 long totsal,monthly_sal;
 class EMPLOYEE{
		int empno,year;
		float basic,da,sal;
		char name[50],dept[20],post[30];
		public:
		void getdata();
		void show();
		void modify();
		void prsnal_detail();
		float calcsal();
		float calctax();
		float getsal()
				{ return sal;}
		int getempno()
				{ return empno;}
		int getyear()
				{return year;}
		char *getname()
				{return name;}
		char *getdept()
				{return dept;}
	      }obj, obj1;

 void EMPLOYEE::getdata()
 {
 cin.get(ch);
 cout<<"\nEnter the name of the employee    : "; gets(name);
 cout<<"Enter the department of the employee:"; gets(dept);
 cout<<"Enter the employee number           :"; cin>>empno;
 cout<<"Enter the post of the employee      :"; gets(post);
 cout<<"Enter the following personal details:"<<endl;
 cout<<"\tBasic          : ";  cin>>basic;
 cout<<"\tDaily allowance: ";  cout<<basic*1.42;
 cout<<"\tWorking years  : ";  cin>>year;
 }

 void EMPLOYEE::modify()
 {
 int enumb;
 char nme[50],dep[20];
 cin.get(ch);
 cout<<"Press '.' to retain old name else enter the new name.....\n";
 cin.getline(nme,50);
 cin.get(ch);
 cout<<"Press '*' to retain the same department else enter the new department.....\n";
 cin.getline(dep,20);
 cin.get(ch);
 cout<<"Press -1 to retain employee number else enter the new one .....\n";
 cin>>enumb;
     if(strcmpi(nme,".")!=0)
     {
     strcpy(name,nme);
     }
     if(strcmpi(dep,"*")!=0)
     {
     strcpy(dept,dep);
     }
     if(enumb!=-1)
     {
     empno=enumb;
     }
 getch();
 }

 float EMPLOYEE::calcsal()
 {
  int yr;
  float benifit=0,pris=0,s=0,tax;
  da=1.42*basic;
  cout<<da;
  tax=calctax();
  yr=getyear();
  s=basic+da;
  if((yr>=5) && (yr<15))
  {
  benifit=s*(0.10);
  }
  else if( (yr>=15)&&(yr<25))
  {
  benifit=s*(0.30);
  }
  else if(yr>=25)
  {
  benifit=s*0.50;
  }
  cout<<"benifit="<<benifit<<endl;
  cout<<yr;
  cout<<"ANNUAL SALARY\n";
  totsal=12*(basic+da)-tax;
  cout<<totsal<<endl;
  cout<<"MONTHLY SALARY\n";
  monthly_sal=basic+da-(tax/12);
  cout<<monthly_sal<<endl;
  return totsal;
 }

 float EMPLOYEE::calctax()
 {
  long tottax, annbasic=12*basic;
  if(annbasic<=250000)
  tottax=0;
  else if((annbasic>250000)&&(annbasic<=500000))
  tottax=annbasic*0.05;
  else if((annbasic>500000)&&(annbasic<=3000000))
  tottax=annbasic*0.1;
  else
  tottax=annbasic*0.3;
  return tottax;
 }

 void data_entry()
 {
   switch(ans)
   {
   case 1:   ofstream filein("emp.dat",ios::out|ios::app|ios::binary);
	     if(!filein)
	     {cout<<"failed to open\n";}
	     cout<<"Enter the details of employee......\n";
	     do
	     {
	     obj.getdata();
	     filein.write((char*)&obj,sizeof(obj));
	     cout<<"Want to enter more data(y/n)\n";
	     cin>>ch;
	     } while(ch!='n');
	     filein.close();
	     break;

   case 2:   ofstream fin("emp.dat",ios::out|ios::binary);
	     if(!fin)
	     {cout<<"failed to open\n";}
	     cout<<"Enter the details of employee......\n";
	     do
	     {
	     obj.getdata();
	     fin.write((char*)&obj,sizeof(obj));
	     cout<<"Want to enter more data(y/n)\n";
	     cin>>ch;
	     } while(ch!='n');
	     fin.close();
	     break;
   }
 }

 void private_display()
 {
   int as,enub;
   char sname[50],found='n';
   do
   {
    clrscr();
    ch='y';
    cout<<"\tSelect to search in reference to:-\n";
    cout<<"\t-----------------------\n";
    cout<<"\t1.Name\n";
    cout<<"\t2.Employee number\n";
    cout<<"\t-----------------------\n";
    cout<<"\t";cin>>as;
    switch(as)
    {
    case 1: ifstream cal("emp.dat",ios::in|ios::out|ios::binary);
	    cout<<"Enter the name to be searched for.\n";
	    cin.get(ch);
	    cin.getline(sname,50);
	    while(cal)
	    {
		cal.read((char*)&obj,sizeof(obj));
		if(cal.eof())break;
		if(strcmpi(obj.getname(),sname)==0)
		{
		found='y';
		obj.show();
		}
	    }
	    if(found=='n')
	    {cout<<"Required data dosent exist...!!!"; }
	    cal.close();
	    break;

    case 2: ifstream srch("emp.dat",ios::in|ios::out|ios::binary);
	    cout<<"Enter the employee number to be searched for.\n";
	    cin>>enub;
	    while(srch)
	    {
		srch.read((char*)&obj,sizeof(obj));
		if(srch.eof())break;
		if(obj.getempno()==enub)
		{
		found='y';
		obj.show();
		}
	    }
	    if(found=='n')
	    {cout<<"Required data dosent exist...!!!/n";}
	    srch.close();
	    break;
    }
   cout<<"Want to see more....(y/n)\n";cin>>ch;
   }while(ch!='n');
 }


 void display()
 {
 switch(ans)
 {

      case 1: char sdept[20];
	      ifstream dat("emp.dat",ios::in|ios::binary);
	      cout<<"\t_______________________________________________________________________\n";
	      cout<<"\t|         NAME        |       DEPARTMENT      |     EMPLOYEE NUMBER    |\n";
	      while(dat)
	      {
	      dat.read((char*)&obj,sizeof(obj));
	      if(!dat)break;
	      cout<<"\t|---------------------|-----------------------|------------------------|\n";
	      cout<<"\t\t"<<obj.getname()<<"\t\t"<<obj.getdept()<<"\t\t"<<obj.getempno()<<"\t\n";
	      cout<<"\t|---------------------|-----------------------|------------------------|\n";
	      }
	      dat.close();
	      cout<<"PRESS ENTER TO ESCAPE.";
	      break;

      case 2:private_display();
	     break;
 }
 }

 void EMPLOYEE::show()
 {
 cout<<"Name           : "<<name<<"\n";
 cout<<"Department     : "<<dept<<"\n";
 cout<<"Employee number: "<<empno<<"\n";
 cout<<"Post           :"<<post<<endl;
 cout<<"Salary         :"<<endl;
 calcsal();
 }


 void main()
 {
 clrscr();
 int choice;
 do
 {
 clrscr();
 cout<<"\t\tWelcome to Employee Management system......\n";
 cout<<"\t\tSelect your choice...............\n";
 cout<<"\t\t _______________________________________________\n";
 cout<<"\t\t|1.To enter the employee details                |\n";
 cout<<"\t\t|2.To see the employee details                  |\n";
 cout<<"\t\t|3.To add a new employee record in sorted way   |\n";
 cout<<"\t\t|4.To modify a record                           |\n";
 cout<<"\t\t|5.To delete a record                           |\n";
 cout<<"\t\t|6.To exit                                      |\n";
 cout<<"\t\t|_______________________________________________|\n";
 cout<<"\t\t";cin>>choice;
      switch(choice)
      {
	    case 1: cout<<"\t\tSelect your choice.....\n";
		    cout<<"\t\t----------------------------------------------------\n";
		    cout<<"\t\t1:To enter at the end of pre existing data\n";
		    cout<<"\t\t2:To enter new data(!!..Deletes old record..!!)\n";
		    cout<<"\t\t----------------------------------------------------\n";
		    cout<<"\t\t";cin>>ans;
		    data_entry();
		    break;

	    case 2: cout<<"Select to get employee details.....\n";
		    cout<<"\t-------------------------------\n";
		    cout<<"\t1:On basis of department.\n";
		    cout<<"\t2:Individually(###Along with salary calculation###).\n";
		    cout<<"\t-------------------------------\n";
		    cout<<"\t\t";cin>>ans;
		    display();
		    getch();
		    break;

	    case 3: fstream add("emp.dat",ios::in|ios::binary);
		    ofstream addrecord("temp.dat",ios::out|ios::binary);
		    cout<<"Enter the new record\n";
		    obj.getdata();
		    char last='y';
		    while(!add.eof())
		    {
		     add.read((char*)&obj1,sizeof(obj1));
		     if(add.eof())break;
		     if(obj.getempno()<obj1.getempno())
		     {
		     addrecord.write((char*)&obj,sizeof(obj));
		     last='a';
		     break;
		     }

		     else
		     {
		     addrecord.write((char*)&obj1,sizeof(obj1));
		     }
		    }
		     if(last=='a')
		     {
		     while(!add.eof())
		     {
		      addrecord.write((char*)&obj1,sizeof(obj1));
		      add.read((char*)&obj1,sizeof(obj1));
		      if(add.eof())break;
		     }
		     }
		     else
		     {
		      addrecord.write((char*)&obj,sizeof(obj));
		     }
		     addrecord.close();
		     add.close();
		     remove("emp.dat");
		     rename("temp.dat","emp.dat");
		     cout<<"New data inerted properly\n";
		     getch();
		     break;

	  case 4:  int emno,pos;
		   char found='n';
		   cout<<"enter the employee no. of employee whose record you want to modify\n";
		   cin>>emno;
		   fstream old("emp.dat",ios::in|ios::out|ios::binary);
		   while(!old.eof())
		       {
			pos=old.tellg();
			old.read((char*)&obj,sizeof(obj));
			if(old.eof())
			break;
			if(obj.getempno()==emno)
			{
			obj.show();
			obj.modify();
			old.seekg(pos);
			cin.get(ch);
			old.write((char*)&obj,sizeof(obj));
			found='y';
			cout<<"record modified";
			break;
			}
		       }
		   old.close();
		   if(found=='n')
		   cout<<"record not found\n";
		   getch();
		   break;

	    case 5:ifstream mod("emp.dat",ios::in|ios::binary);
		    ofstream del("temp.dat",ios::out|ios::binary);
		    int eno;
		    char cha='y';
		    last='b';
		    cout<<"Enter the employee number of the employee whose record to delete\n";
		    cin>>eno;
		    while(!mod.eof())
		    {
		       mod.read((char*)&obj,sizeof(obj));
		       if(mod.eof())
		       break;
		       if(obj.getempno()==eno)
			  {
			  obj.show();
			  cout<<"sure to delete this record(y/n)\n";
			  cin>>cha;
			  last='b';
			  if(cha=='n')
			  del.write((char*)&obj,sizeof(obj));
			  }
		       else
			  {
			  del.write((char*)&obj,sizeof(obj));
			  }
		    }
		    mod.close();
		    del.close();
		    remove("emp.dat");
		    rename("temp.dat","emp.dat") ;
		    if(last=='b'&&cha=='y')
		    {
		    cout<<"record deleted successfully\n";
		    cout<<"PRESS ENTER\n";
		    }
		    getch();
		    break;

	   case 6: break;

	   default:cout<<"!! WRONG CHOICE !!";
		   break;

      }
 }while(choice!=6);
 cout<<"PRESS ENTER.";
 getch();
 }



