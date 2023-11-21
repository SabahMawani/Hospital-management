#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<time.h>

using namespace std;

class department
{
	protected:
		static int Neurology[10];
		static int Cardiology[10];
		static int Urology[10];
		static int Surgery[10];
		static int Recovery[10];
		static int Emergency[10];
		static int ENT[10];
		static int Physiotherapy[10];
		static int Oncology[10];
		static int Dentistry[10];
		
		void menu1()
		{
			cout<<"Departments:"<<endl;
			cout<<"1. Cardiology"<<endl;
			cout<<"2. Dentistry"<<endl;
			cout<<"3. Emergency"<<endl;
			cout<<"4. E.N.T"<<endl;
			cout<<"5. Neurology"<<endl;
			cout<<"6. Oncology"<<endl;
			cout<<"7. Physiotherapy"<<endl;
			cout<<"8. Recovery"<<endl;
			cout<<"9. Surgery"<<endl;
			cout<<"10. Urology"<<endl;
		}
	public:
		department()
		{
			ifstream file1,file2,file3,file4,file5,file6,file7,file8,file9,file10;
			file1.open("Cardiology.txt");
			file2.open("Dentistry.txt");
			file3.open("Emergency.txt"); 
			file4.open("ENT.txt"); 
			file5.open("Neurology.txt"); 
			file6.open("Oncology.txt"); 
			file7.open("Physiotherapy.txt"); 
			file8.open("Recovery.txt"); 
			file9.open("Surgery.txt"); 
			file10.open("Urology.txt"); 
			int i,id;
			string temp;		
			for(i=0;i<10;i++)
			{ 	
				fflush(stdin);
				getline(file1,temp);
				fflush(stdin);
    			id=stoi(temp);
    			if(id==0)
    				Cardiology[i]='\0';
    			else
					Cardiology[i]=id;
				getline(file2,temp);
				fflush(stdin);
				id=stoi(temp);
    			if(id==0)
    				Dentistry[i]='\0';
    			else
					Dentistry[i]=id;
				getline(file3,temp);
				fflush(stdin);
				id=stoi(temp);
				if(id==0)
    				Emergency[i]='\0';
    			else
					Emergency[i]=id;
				getline(file4,temp);
				fflush(stdin);
				id=stoi(temp);
				if(id==0)
    				ENT[i]='\0';
    			else
					ENT[i]=id;
				getline(file5,temp);
				fflush(stdin);
				id=stoi(temp);
				if(id==0)
    				Neurology[i]='\0';
    			else
					Neurology[i]=id;
				getline(file6,temp);
				fflush(stdin);
				id=stoi(temp);
				if(id==0)
    				Oncology[i]='\0';
    			else
					Oncology[i]=id;
				getline(file7,temp);
				fflush(stdin);
				id=stoi(temp);
				if(id==0)
    				Physiotherapy[i]='\0';
    			else
					Physiotherapy[i]=id;
				getline(file8,temp);
				fflush(stdin);
				id=stoi(temp);
				if(id==0)
    				Recovery[i]='\0';
    			else
					Recovery[i]=id;
				getline(file9,temp);
				fflush(stdin);
				id=stoi(temp);
				if(id==0)
    				Surgery[i]='\0';
    			else
					Surgery[i]=id;
				getline(file10,temp);
				fflush(stdin);
				id=stoi(temp);
				if(id==0)
    				Urology[i]='\0';
    			else
					Urology[i]=id;
			}
			file1.close();
			file2.close();
			file3.close();
			file4.close();
			file5.close();
			file6.close();
			file7.close();
			file8.close();
			file9.close();
			file10.close();
		}
		~department()
		{
			ofstream file1,file2,file3,file4,file5,file6,file7,file8,file9,file10;
			file1.open("Cardiology.txt");
			file2.open("Dentistry.txt");
			file3.open("Emergency.txt"); 
			file4.open("ENT.txt"); 
			file5.open("Neurology.txt"); 
			file6.open("Oncology.txt"); 
			file7.open("Physiotherapy.txt"); 
			file8.open("Recovery.txt"); 
			file9.open("Surgery.txt"); 
			file10.open("Urology.txt");
			for(int i=0;i<10;i++)
			{
				file1<<Cardiology[i]<<endl;
				file2<<Dentistry[i]<<endl;
				file3<<Emergency[i]<<endl;
				file4<<ENT[i]<<endl;
				file5<<Neurology[i]<<endl;
				file6<<Oncology[i]<<endl;
				file7<<Physiotherapy[i]<<endl; 
				file8<<Recovery[i]<<endl; 
				file9<<Surgery[i]<<endl;
				file10<<Urology[i]<<endl; 
			}
			file1.close();
			file2.close();
			file3.close();
			file4.close();
			file5.close();
			file6.close();
			file7.close();
			file8.close();
			file9.close();
			file10.close();
		}
		
};

class Patient
{
	protected:
		static string Name[100];
		static int Age[100];
		static char Sex[100];
		static string Address[100];
		static int Contact_num[100];
		static string Blood_Group[100];
		static int Patient_ID[100];
		static string Diagnosis[100];
		static string Symptoms[100];
		static string Medicine[100];
		static string Department[100];
	public:
		int CheckIfEmpty()
		{ 
			bool flag=false;
			int i; 
			for(i=0;i<100;i++)
			{
				if(Patient_ID[i]=='\0')
				{
					flag=true;
					break;
				}
			}
			if (flag)
				return i;
			else
				return -1;
		}
};

class Nurse : public department, public Patient
{	
	public: 
		void menu()
		{ 
		cout<<"Menu: "<<endl<<endl;
		cout<<"1. Add New Patient Record"<<endl;  
		cout<<"2. View Patient Information"<<endl;  
	    cout<<"3. Discharge Patient"<<endl;  
		cout<<"4. Logout "<<endl;  
		}
		
		void newrecord()
		{
			int ID,i;
			string id;
			bool flag=false;
			cout<<"Enter Patient ID: ";
			cin>>ID;
			for(i=0;i<100;i++)
			{
				if(Patient_ID[i]==ID)
				{
					flag=true;
					break;
				}
			}
			if(flag)
			{
				cout<<"Patient record exists!"<<endl;
			}
			else
			{
				id=to_string(ID);
				id+=".txt";
				ifstream file;
				file.open(id);
				if(file)
				{
					i=CheckIfEmpty();
					if(i==-1)
					{
						cout<<"There are no available spaces in the hospital."<<endl;
					}
					else
					{
						string var;
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[i]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[i]=var[0];
						getline(file,Address[i]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[i]);
						set_symptoms(i);
						cout<<"Is it an Emergency?"<<endl<<"1.	Yes"<<endl<<"2.	No"<<endl;
						cout<<"Enter your choice:";
						int dec;
						do
						{
							cin>>dec;
						}while(dec<1||dec>2);
						if(dec==1)
							set_department(i,dec);
						else
							set_department(i);
					}
					file.close();
				}
       			else 
       			{
       				ofstream record;
					record.open(id);
					if (!record) 
					{
						cout << "Record not created!";
					}
					else 
					{
						i=CheckIfEmpty();
						if(i==-1)
						{
							cout<<"There are no available spaces in the Hospital"<<endl;
						}
						cout<<"Enter the Name of the patient: ";
						fflush(stdin);
						getline(cin,Name[i]);
						fflush(stdin);
						cout<<"Enter the age of the patient: ";
						cin>>Age[i];
						cout<<"Enter the number corresponding to the sex: "<<endl;
						cout<<"1. Male"<<endl;
						cout<<"2. Female"<<endl; 
						cout<<"Enter number here: ";
						int num;
						do
						{
							cin>>num;
						}while(num<1||num>2);
						if(num==1)
							Sex[i]='M';
						else
							Sex[i]='F';
						cout<<"Enter the Address of the patient:";
						fflush(stdin);
						getline(cin,Address[i]);
						fflush(stdin);
						cout<<"Enter patient's Contact number: "; 
						cin>>Contact_num[i]; 
						cout<<"Enter patient's Blood Group:"<<endl; 
						cout<<"1. A+"<<endl;
						cout<<"2. O+"<<endl;
						cout<<"3. B+"<<endl; 
						cout<<"4. AB+"<<endl; 
						cout<<"5. A-"<<endl; 
						cout<<"6. O-"<<endl; 
						cout<<"7. B-"<<endl; 
						cout<<"8. AB-"<<endl;  
						cout<<"Enter number here: ";
						int num1;
						do
						{
							cin>>num1;
						}while(num1<1||num1>8);
						if(num1==1)
							Blood_Group[i]="A+";
						else if(num1==2)
							Blood_Group[i]="O+";
						else if(num1==3) 
						 	Blood_Group[i]="B+";
						else if(num1==4)
							Blood_Group[i]="AB+";
						else if(num1==5)
							Blood_Group[i]="A-";
						else if(num1==6)
							Blood_Group[i]="O-";
						else if(num1==7)
							Blood_Group[i]="B-";
						else
							Blood_Group[i]="AB-"; 
						Patient_ID[i]=ID;
						
						record<<Patient_ID[i]<<endl;
						record<<Name[i]<<endl;
						record<<Age[i]<<endl;
						record<<Sex[i]<<endl;
						record<<Address[i]<<endl;
						record<<Contact_num[i]<<endl;
						record<<Blood_Group[i]<<endl<<endl;
						set_symptoms(i);
						int dec;
						do
						{
							cout<<"Is it an Emergency?"<<endl<<"1.	Yes"<<endl<<"2.	No"<<endl;
							cout<<"Enter your choice:";
							cin>>dec;
							system("pause");
							system("cls");
						}while(dec<1||dec>2);
						if(dec==1)
							set_department(i,dec);
						else
							set_department(i);
						
						record.close(); 
					}
				}
			
	 		}
		
		}
		
		void displayrecord()
		{ 
			int ID,i;
			bool flag=false;
			cout<<"Enter Patient ID: ";
			cin>>ID;
			for(i=0;i<100;i++)
			{
				if(Patient_ID[i]==ID)
				{
					flag=true;
					break;
				}
			}
			if(flag)
			{ 
				cout<<"Patient Data: "<<endl<<endl;
				cout<<"Patient ID:  "<<Patient_ID[i]<<endl;
				cout<<"Patient Name: "<<Name[i]<<endl;
				cout<<"Patient Age: "<<Age[i]<<endl; 
				cout<<"Patient Sex: "<<Sex[i]<<endl; 
				cout<<"Patient Address: "<<Address[i]<<endl; 
				cout<<"Patient Contact Number: "<<Contact_num[i]<<endl; 
				cout<<"Patient Blood Group: "<<Blood_Group[i]<<endl; 
			}
			else
			{
				cout<<"The patient either does not exist or has already been discharged."<<endl;
			}	
		}  
		
		void set_department(int i)
		{
				string id=to_string(Patient_ID[i]); 
				int num;
				bool flag= false;
				do
				{
					cout<<"Choose the department you would like to send "<<Name[i]<<" to: "<<endl;
					menu1();
					cout<<"Enter the number corresponding to the department: ";
					cin>>num;
					if(num<1||num>10)
					{
						cout<<"Invalid Entry"<<endl<<endl;
						system("pause");
						system("cls");
					}
					else
					{
						break;
					}
				}while(1);
				fstream record; 
				id+=".txt"; 
				record.open(id,ios::app);  
				switch(num)
				{
					case 1:
						for(int j=0;j<10;j++)
						{
							if(Cardiology[j]=='\0')
							{
								Cardiology[j]=Patient_ID[i];
								flag=true;
								Department[i]="Cardiology";
								break;
							}
						}
						break;
					case 2:
						for(int j=0;j<10;j++)
						{
							if(Dentistry[j]=='\0')
							{
								Dentistry[j]=Patient_ID[i];
								flag=true;
								Department[i]="Dentistry";
								break;
							}
						}
						break;
					case 3:
						for(int j=0;j<10;j++)
						{
							if(Emergency[j]=='\0')
							{
								Emergency[j]=Patient_ID[i];
								flag=true;
								Department[i]="Emergency";
								break;
							}
						}
						break;
					case 4:
						for(int j=0;j<10;j++)
						{
							if(ENT[j]=='\0')
							{
								ENT[j]=Patient_ID[i];
								flag=true;
								Department[i]="E.N.T";
								break;
							}
						}
						break;
					case 5:
						for(int j=0;j<10;j++)
						{
							if(Neurology[j]=='\0')
							{
								Neurology[j]=Patient_ID[i];
								flag=true;
								Department[i]="Neurology";
								break;
							}
						}
						break;
					case 6:
						for(int j=0;j<10;j++)
						{
							if(Oncology[j]=='\0')
							{
								Oncology[j]=Patient_ID[i];
								flag=true;
								Department[i]="Oncology";
								break;
							}
						}
						break;
					case 7:
						for(int j=0;j<10;j++)
						{
							if(Physiotherapy[j]=='\0')
							{
								Physiotherapy[j]=Patient_ID[i];
								flag=true;
								Department[i]="Physiotherapy";
								break;
							}
						}
						break;
					case 8:
						for(int j=0;j<10;j++)
						{
							if(Recovery[j]=='\0')
							{
								Recovery[j]=Patient_ID[i];
								flag=true;
								Department[i]="Recovery";
								break;
							}
						}
						break;
					case 9:
						for(int j=0;j<10;j++)
						{
							if(Surgery[j]=='\0')
							{
								Surgery[j]=Patient_ID[i];
								flag=true;
								Department[i]="Surgery";
								break;
							}
						}
						break;
					case 10:
						for(int j=0;j<10;j++)
						{
							if(Urology[j]=='\0')
							{
								Urology[j]=Patient_ID[i];
								flag=true;
								Department[i]="Urology";
								break;
							}
						}
						break;
			}
			if(!flag)
			{
				cout<<"There are no available spaces in the department"<<endl<<"Please select a different department"<<endl;
				system("pause");
				set_department(i);
			}
			else
			{
				record<<"Department name: "<<Department[i]<<endl;
				record.close();
			}
		}
					
	void set_department(int i,int j)
	{
		string id=to_string(Patient_ID[i]);
		id+=".txt";
		bool flag=false;
		for(j=0;j<10;j++)
		{
			if(Emergency[j]=='\0')
			{
				Emergency[j]=Patient_ID[i];
				flag=true;
				fstream record; 
				record.open(id,ios::app);
				record<<"Department: Emergency"<<endl;
				Department[i]="Emergency";
				break;
			}
		}
		if(!flag)
		{
			cout<<"The emergency department is full"<<endl<<"Please select a different department"<<endl;
			set_department(i);
		}
	}			
		
        void set_symptoms(int i)
		{ 
        	time_t rawtime;
			struct tm * timeinfo;
			time ( &rawtime );
			timeinfo = localtime ( &rawtime );
			string id=to_string(Patient_ID[i]); 
			id+=".txt";
			cout<<"Enter the symptoms of the Patient: "; 
			fflush(stdin);
			getline(cin,Symptoms[i]); 
			fflush(stdin);
			fstream record; 
			record.open(id,ios::app);
			record<<"Patient admitted on: "<<asctime (timeinfo)<<endl;
			record<<"Symptoms: "<<Symptoms[i]<<endl;
		} 
		Nurse()
		{
			int i;
			bool flag=false;
			for(i=0;i<100;i++)
			{
				if(Patient_ID[i]!='\0')
				{
					flag=true;
					break;
				}
			}
			if(!flag)
			{
				ifstream file;
				int j=0;
				string id;
				string var;
				for(i=0;i<10;i++)
				{
					if(Cardiology[i]!='\0')
					{
						id=to_string(Cardiology[i]);
						id+=".txt";
						file.open(id);
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[j]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[j]=var[0];
						getline(file,Address[j]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[j]);
						Department[j]="Cardiology";
						j++;
						file.close();
					}
					if(Dentistry[i]!='\0')
					{
						id=to_string(Dentistry[i]);
						id+=".txt";
						file.open(id);
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[j]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[j]=var[0];
						getline(file,Address[j]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[j]);
						Department[j]="Dentistry";
						j++;
						file.close();
					}
					if(Emergency[i]!='\0')
					{
						id=to_string(Emergency[i]);
						id+=".txt";
						file.open(id);
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[j]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[j]=var[0];
						getline(file,Address[j]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[j]);
						Department[j]="Emergency";
						j++;
						file.close();
					}
					if(ENT[i]!='\0')
					{
						id=to_string(ENT[i]);
						id+=".txt";
						file.open(id);
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[j]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[j]=var[0];
						getline(file,Address[j]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[j]);
						Department[j]="E.N.T";
						j++;
						file.close();
					}
					if(Neurology[i]!='\0')
					{
						id=to_string(Neurology[i]);
						id+=".txt";
						file.open(id);
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[j]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[j]=var[0];
						getline(file,Address[j]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[j]);
						Department[j]="Neurology";
						j++;
						file.close();
					}
					if(Oncology[i]!='\0')
					{
						id=to_string(Oncology[i]);
						id+=".txt";
						file.open(id);
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[j]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[j]=var[0];
						getline(file,Address[j]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[j]);
						Department[j]="Oncology";
						j++;
						file.close();
					}
					if(Physiotherapy[i]!='\0')
					{
						id=to_string(Physiotherapy[i]);
						id+=".txt";
						file.open(id);
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[j]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[j]=var[0];
						getline(file,Address[j]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[j]);
						Department[j]="Physiotherapy";
						j++;
						file.close();
					}
					if(Recovery[i]!='\0')
					{
						id=to_string(Recovery[i]);
						id+=".txt";
						file.open(id);
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[j]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[j]=var[0];
						getline(file,Address[j]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[j]);
						Department[j]="Recovery";
						j++;
						file.close();
					}
					if(Surgery[i]!='\0')
					{
						id=to_string(Surgery[i]);
						id+=".txt";
						file.open(id);
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[j]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[j]=var[0];
						getline(file,Address[j]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[j]);
						Department[j]="Surgery";
						j++;
						file.close();
					}
					if(Urology[i]!='\0')
					{
						id=to_string(Urology[i]);
						id+=".txt";
						file.open(id);
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[j]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[j]=var[0];
						getline(file,Address[j]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[j]);
						Department[j]="Urology";
						j++;
						file.close();
					}
				}
			}
		}
		void Discharge()
		{
			time_t rawtime;
			struct tm * timeinfo;
			time ( &rawtime );
			timeinfo = localtime ( &rawtime );
			int id,i;
			bool flag=false;
			cout<<"Enter ID of patient to be discharged: ";
			cin>>id;
			for(int i=0;i<100;i++)
			{
				if(Patient_ID[i]==id)
				{
					flag=true;
					break;
				}
			}
			if(flag)
			{
				fstream record;
				string r;
				r=to_string(id);
				r+=".txt";
				record.open(r,ios::app);
				Name[i].clear();
				Sex[i]='\0';
				Address[i].clear(); 
				Contact_num[i]='\0'; 
				Blood_Group[i].clear(); 
				Symptoms[i].clear(); 
				Diagnosis[i].clear(); 
				Medicine[i].clear(); 
				if(Department[i]=="Cardiology")
				{
					for(int j=0;j<100;j++)
					{
						if(Patient_ID[i]==Cardiology[j])
						{
							Cardiology[j]='\0';
							break;
						}
					}
				}
				else if(Department[i]=="Dentistry")
				{
					for(int j=0;j<100;j++)
					{
						if(Patient_ID[i]==Dentistry[j])
						{
							Dentistry[j]='\0';
							break;
						}
					}
				}
				else if(Department[i]=="Emergency")
				{
					for(int j=0;j<100;j++)
					{
						if(Patient_ID[i]==Emergency[j])
						{
							Emergency[j]='\0';
							break;
						}
					}
				}
				else if(Department[i]=="E.N.T")
				{
					for(int j=0;j<100;j++)
					{
						if(Patient_ID[i]==ENT[j])
						{
							ENT[j]='\0';
							break;
						}
					}
				}
				else if(Department[i]=="Neurology")
				{
					for(int j=0;j<100;j++)
					{
						if(Patient_ID[i]==Neurology[j])
						{
							Neurology[j]='\0';
							break;
						}
					}
				}
				else if(Department[i]=="Oncology")
				{
					for(int j=0;j<100;j++)
					{
						if(Patient_ID[i]==Oncology[j])
						{
							Oncology[j]='\0';
							break;
						}
					}
				}
				else if(Department[i]=="Physiotherapy")
				{
					for(int j=0;j<100;j++)
					{
						if(Patient_ID[i]==Physiotherapy[j])
						{
							Physiotherapy[j]='\0';
							break;
						}
					}
				}
				else if(Department[i]=="Recovery")
				{
					for(int j=0;j<100;j++)
					{
						if(Patient_ID[i]==Recovery[j])
						{
							Recovery[j]='\0';
							break;
						}
					}
				}
				else if(Department[i]=="Surgery")
				{
					for(int j=0;j<100;j++)
					{
						if(Patient_ID[i]==Surgery[j])
						{
							Surgery[j]='\0';
							break;
						}
					}
				}
				else if(Department[i]=="Urology")
				{
					for(int j=0;j<100;j++)
					{
						if(Patient_ID[i]==Urology[j])
						{
							Urology[j]='\0';
							break;
						}
					}
				}
				Patient_ID[i]='\0';
				Department[i].clear();
				if(Patient_ID[i]=='\0')
				{
					record<<"Patient has been discharged on: "<<asctime (timeinfo)<<endl;
					record.close();
					cout<<"The patient has been discharged successfully"<<endl;
				}
				else
					cout<<"Operation Unsuccessful!"<<endl<<"Patient was not discharged"<<endl<<endl;
			}
			else
				cout<<"Patient either does not exist or has already been discharged"<<endl;
		}
}; 

class Doctor: private Patient, private department
{
	public:
		Doctor()
		{
			int i;
			bool flag=false;
			for(i=0;i<100;i++)
			{
				if(Patient_ID[i]!='\0')
				{
					flag=true;
					break;
				}
			}
			if(!flag)
			{
				ifstream file;
				int j=0;
				string id;
				string var;
				for(i=0;i<10;i++)
				{
					if(Cardiology[i]!='\0')
					{
						id=to_string(Cardiology[i]);
						id+=".txt";
						file.open(id);
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[j]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[j]=var[0];
						getline(file,Address[j]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[j]);
						getline(file,Blood_Group[j]);
						Department[j]="Cardiology";
						j++;
						file.close();
					}
					if(Dentistry[i]!='\0')
					{
						id=to_string(Dentistry[i]);
						id+=".txt";
						file.open(id);
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[j]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[j]=var[0];
						getline(file,Address[j]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[j]);
						Department[j]="Dentistry";
						j++;
						file.close();
					}
					if(Emergency[i]!='\0')
					{
						id=to_string(Emergency[i]);
						id+=".txt";
						file.open(id);
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[j]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[j]=var[0];
						getline(file,Address[j]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[j]);
						Department[j]="Emergency";
						j++;
						file.close();
					}
					if(ENT[i]!='\0')
					{
						id=to_string(ENT[i]);
						id+=".txt";
						file.open(id);
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[j]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[j]=var[0];
						getline(file,Address[j]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[j]);
						Department[j]="E.N.T";
						j++;
						file.close();
					}
					if(Neurology[i]!='\0')
					{
						id=to_string(Neurology[i]);
						id+=".txt";
						file.open(id);
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[j]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[j]=var[0];
						getline(file,Address[j]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[j]);
						Department[j]="Neurology";
						j++;
						file.close();
					}
					if(Oncology[i]!='\0')
					{
						id=to_string(Oncology[i]);
						id+=".txt";
						file.open(id);
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[j]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[j]=var[0];
						getline(file,Address[j]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[j]);
						Department[j]="Oncology";
						j++;
						file.close();
					}
					if(Physiotherapy[i]!='\0')
					{
						id=to_string(Physiotherapy[i]);
						id+=".txt";
						file.open(id);
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[j]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[j]=var[0];
						getline(file,Address[j]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[j]);
						Department[j]="Physiotherapy";
						j++;
						file.close();
					}
					if(Recovery[i]!='\0')
					{
						id=to_string(Recovery[i]);
						id+=".txt";
						file.open(id);
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[j]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[j]=var[0];
						getline(file,Address[j]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[j]);
						Department[j]="Recovery";
						j++;
						file.close();
					}
					if(Surgery[i]!='\0')
					{
						id=to_string(Surgery[i]);
						id+=".txt";
						file.open(id);
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[j]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[j]=var[0];
						getline(file,Address[j]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[j]);
						Department[j]="Surgery";
						j++;
						file.close();
					}
					if(Urology[i]!='\0')
					{
						id=to_string(Urology[i]);
						id+=".txt";
						file.open(id);
						getline (file, var);
						Patient_ID[i]=stoi(var);
						getline(file,Name[j]);
						getline(file,var); 
						Age[i]=stoi(var); 
						getline(file,var);
						Sex[j]=var[0];
						getline(file,Address[j]);
						getline(file,var);
						Contact_num[i]=stoi(var); 
						getline(file,Blood_Group[j]);
						Department[j]="Urology";
						j++;
						file.close();
					}
				}
			}
		}
		void menu()
		{
			cout<<"Menu: "<<endl<<endl;
			cout<<"1. Add Patient Diagnosis"<<endl;
			cout<<"2. View Patient History"<<endl;
			cout<<"3. Change Department"<<endl;
			cout<<"4. Log out"<<endl;
		}
		void View_History()
		{
			int i,ID;
			bool flag=false;
			cout<<"Enter Patient ID: ";
			cin>>ID;
			for(i=0;i<100;i++)
			{
				if(Patient_ID[i]==ID)
				{
					flag=true;
					break;
				}
			}
			if(flag)
			{
				system("cls");
				string id=to_string(ID),line;
				id+=".txt";
				ifstream record;
				record.open(id);
				getline(record,line);
				cout<<"Patient ID: "<<line<<endl;
				getline(record,line);
				cout<<"Name: "<<line<<endl;
				getline(record,line);
				cout<<"Age: "<<line<<endl;
				getline(record,line);
				cout<<"Sex: "<<line<<endl;
				getline(record,line);
				cout<<"Address: "<<line<<endl;
				getline(record,line);
				cout<<"Contact Number: "<<line<<endl;
				getline(record,line);
				cout<<"Blood Group: "<<line<<endl;
				while(record.good())
				{
					getline(record,line);
					fflush(stdin);
					cout<<line<<endl;
				}
				record.close();
			}
			else
				cout<<"The patient either does not exist or has already been discharged."<<endl;
		}
		void Change_Dep()
		{
			int num1;
			int i,ID;
			bool flag1=false;
			bool flag=false;
			string s;
			cout<<"Enter Patient ID: ";
			cin>>ID;
			for(i=0;i<100;i++)
			{
				if(Patient_ID[i]==ID)
				{
					flag1=true;
					break;
				}
			}
			if(flag1)
			{
				string id=to_string(ID),line;
				id+=".txt";
				fflush(stdin);
				do
				{
					cout<<"Choose the department you would like to switch "<<Name[i]<<" to: "<<endl;
					menu1();
					cout<<"Enter the number corresponding to the department: ";
					cin>>num1;
					if(num1<1||num1>10)
					{
						cout<<"Invalid Entry"<<endl<<endl;
						system("pause");
						system("cls");
					}
					else
					{
						break;
					}
				}while(1);
				switch(num1)
				{
					case 1:
						for(int j=0;j<10;j++)
						{
							if(Cardiology[j]=='\0')
							{
								Cardiology[j]=Patient_ID[i];
								flag=true;
								s="Cardiology";
								break;
							}
						}
						break;
					case 2:
						for(int j=0;j<10;j++)
						{
							if(Dentistry[j]=='\0')
							{
								Dentistry[j]=Patient_ID[i];
								flag=true;
								s="Dentistry";
								break;
							}
						}
						break;
					case 3:
						for(int j=0;j<10;j++)
						{
							if(Emergency[j]=='\0')
							{
								Emergency[j]=Patient_ID[i];
								flag=true;
								s="Emergency";
								break;
							}
						}
						break;
					case 4:
						for(int j=0;j<10;j++)
						{
							if(ENT[j]=='\0')
							{
								ENT[j]=Patient_ID[i];
								flag=true;
								s="E.N.T";
								break;
							}
						}
						break;
					case 5:
						for(int j=0;j<10;j++)
						{
							if(Neurology[j]=='\0')
							{
								Neurology[j]=Patient_ID[i];
								flag=true;
								s="Neurology";
								break;
							}
						}
						break;
					case 6:
						for(int j=0;j<10;j++)
						{
							if(Oncology[j]=='\0')
							{
								Oncology[j]=Patient_ID[i];
								flag=true;
								s="Oncology";
								break;
							}
						}
						break;
					case 7:
						for(int j=0;j<10;j++)
						{
							if(Physiotherapy[j]=='\0')
							{
								Physiotherapy[j]=Patient_ID[i];
								flag=true;
								s="Physiotherapy";
								break;
							}
						}
						break;
					case 8:
						for(int j=0;j<10;j++)
						{
							if(Recovery[j]=='\0')
							{
								Recovery[j]=Patient_ID[i];
								flag=true;
								s="Recovery";
								break;
							}
						}
						break;
					case 9:
						for(int j=0;j<10;j++)
						{
							if(Surgery[j]=='\0')
							{
								Surgery[j]=Patient_ID[i];
								flag=true;
								s="Surgery";
								break;
							}
						}
						break;
					case 10:
						for(int j=0;j<10;j++)
						{
							if(Urology[j]=='\0')
							{
								Urology[j]=Patient_ID[i];
								flag=true;
								s="Recovery";
								break;
							}
						}
						break;
				}
				if(!flag)
					cout<<"There are no available spaces in the department"<<endl;
				else if(flag)
				{
					if(Department[i]=="Cardiology")
					{
						for(int j=0;j<10;j++)
						{
							if(Patient_ID[i]==Cardiology[j])
							{
								Cardiology[j]='\0';
								break;
							}
						}
					}
					else if(Department[i]=="Dentistry")
					{
						for(int j=0;j<10;j++)
						{
							if(Patient_ID[i]==Dentistry[j])
							{
								Dentistry[j]='\0';
								break;
							}
						}
					}
					else if(Department[i]=="Emergency")
					{
						for(int j=0;j<10;j++)
						{
							if(Patient_ID[i]==Emergency[j])
							{
								Emergency[j]='\0';
								break;
							}
						}
					}
					else if(Department[i]=="E.N.T")
					{
						for(int j=0;j<10;j++)
						{
							if(Patient_ID[i]==ENT[j])
							{
								ENT[j]='\0';
								break;
							}
						}
					}
					else if(Department[i]=="Neurology")
					{
						for(int j=0;j<10;j++)
						{
							if(Patient_ID[i]==Neurology[j])
							{
								Neurology[j]='\0';
								break;
							}
						}
					}
					else if(Department[i]=="Oncology")
					{
						for(int j=0;j<10;j++)
						{
							if(Patient_ID[i]==Oncology[j])
							{
								Oncology[j]='\0';
								break;
							}
						}
					}
					else if(Department[i]=="Physiotherapy")
					{
						for(int j=0;j<10;j++)
						{
							if(Patient_ID[i]==Physiotherapy[j])
							{
								Physiotherapy[j]='\0';
								break;
							}
						}
					}
					else if(Department[i]=="Recovery")
					{
						for(int j=0;j<10;j++)
						{
							if(Patient_ID[i]==Recovery[j])
							{
								Recovery[j]='\0';
								break;
							}
						}
					}
					else if(Department[i]=="Surgery")
					{
						for(int j=0;j<10;j++)
						{
							if(Patient_ID[i]==Surgery[j])
							{
								Surgery[j]='\0';
								break;
							}
						}
					}
					else if(Department[i]=="Urology")
					{
						for(int j=0;j<10;j++)
						{
							if(Patient_ID[i]==Urology[j])
							{
								Urology[j]='\0';
								break;
							}
						}
					}
					Department[i]=s;
					fstream file;
					file.open(id,ios::app);
					file<<"Department changed to "<<Department[i]<<endl;
					file.close();
					cout<<"Department has succesfully been changed"<<endl<<endl;		
				}
			}
			else
				cout<<"The patient either does not exist or has already been discharged."<<endl;
		}
		void Set_Medicine(int i)
		{
			cout<<"Enter the medicine prescribed for "<<Name[i]<<" here: "<<endl;
			fflush(stdin);
			getline(cin,Medicine[i]);
			fflush(stdin);
		}
		void Set_Diagnosis()
		{
			int ID,i;
			string id;
			bool flag=false;
			cout<<"Enter Patient ID: ";
			cin>>ID;
			for(i=0;i<100;i++)
			{
				if(Patient_ID[i]==ID)
				{
					flag=true;
					break;
				}
			}
			if(!flag)
			{
				cout<<"Patient isn't admitted!"<<endl;
			}
			else
			{
				id=to_string(ID);
				id+=".txt";
				fstream file;
				file.open(id,ios::app);
				cout<<"Enter the diagnosis of "<<Name[i]<<" here: "<<endl;
				fflush(stdin);
				getline(cin,Diagnosis[i]);
				fflush(stdin);
				file<<"Diagnosis: "<<Diagnosis[i]<<endl;
				Set_Medicine(i);
				file<<"Medicine: "<<Medicine[i]<<endl;
				file.close();
			}
		}
};


int department::Neurology[10]={};
int department::Cardiology[10]={};
int department::Urology[10]={};
int department::Surgery[10]={};
int department::Recovery[10]={};
int department::Dentistry[10]={};
int department::Emergency[10]={};
int department::ENT[10]={};
int department::Physiotherapy[10]={};
int department::Oncology [10]={}; 
string Patient::Name[100]={};
int Patient::Age[100]={};
char Patient::Sex[100]={};
string Patient::Address[100]={};
int Patient::Contact_num[100]={};
string Patient::Blood_Group[100]={};
int Patient::Patient_ID[100]={}; 
string Patient::Diagnosis[100]={}; 
string Patient::Symptoms[100]={}; 
string Patient::Medicine[100]={}; 
string Patient::Department[100]={};

int password(void);
int main()
{
	int choice;
	while(1)
	{
		cout<<"Main Menu:"<<endl;
		cout<<"1. Login"<<endl;
		cout<<"2. Exit"<<endl;
		cout<<"Enter the number corresponding to your choice: ";
		cin>>choice;
		system("cls");
		while(choice<1||choice>2)
		{
			cout<<"Invalid Entry!"<<endl;
			cout<<"Enter the number corresponding to your choice: ";
			cin>>choice;
		}
		if(choice==1)
		{
			int select=password();
			system("pause");
			system("cls");
			if(select==1)
			{
				Doctor d;
				int num;
				bool flag1 =true;
				while(flag1)
				{
					do
					{
						d.menu();
						cout<<"Enter the number corresponding to your choice: ";
						cin>>num;
						if(num<1||num>4)
						{
							cout<<"Invalid choice!"<<endl;
							system("pause");
							system("cls");
						}	
						else
						{
							system("cls");
							break;
						}
					}while(1);
					system("cls");
					switch (num)
					{
						case 1:
							d.Set_Diagnosis();
							system("cls");
							break;
						case 2:
							d.View_History();
							system("pause");
							system("cls");
							break;
						case 3:
							d.Change_Dep();
							system("pause");
							system("cls"); 
							break;
						case 4:
							flag1=false;
							system("cls");
							break;
					}
				}
			}
			else if(select==2)
			{
				Nurse n;
				int num;
				bool flag=true;
				while(flag)
				{
					do
					{
						n.menu();
						cout<<"Enter the number corresponding to your choice: ";
						cin>>num;
						if(num<1||num>4)
						{
							cout<<"Invalid choice!"<<endl;
							system("pause");
							system("cls");
						}	
						else
						{
							system("cls");
							break;
						}
					}while(1);
					switch (num)
					{
						case 1: 
							n.newrecord();
							system("cls");
							break;
						case 2:
							n.displayrecord();
							system("pause");
							system("cls");
							break;
						case 3:
							n.Discharge();
							system("pause");
							system("cls");
							break;
						case 4:
							flag=false;
							system("cls");
							break;
					}
				}
				
			}
		}
		else
			break;
	}
	
}

int password(void)
{
	string Password1="Doctor";
	string Password2="Nurse";
	int attempt=0;
	string pass="";
	char ch;
	
	do
	{
		cout<<"Hospital Management System"<<endl<<endl;
		cout<<"---------------------------------"<<endl<<endl;
		cout<<"             Login               "<<endl<<endl;
		cout<<"---------------------------------"<<endl<<endl;
		cout<<"Enter the password here: ";
		ch = _getch();
		while(ch != 13)
		{
			pass.push_back(ch);
			cout << '*';
    		ch = _getch();
		}
		cout<<endl<<endl<<endl;
		attempt++;
		if(pass!=Password1&&pass!=Password2)
		{
			cout<<"Invalid Password!"<<endl;
			pass="";
			system("pause");
			system("cls");
		}
		else
			break;
	}while(attempt<3);
	if(pass==Password1)
	{
		cout<<"Password has been verified"<<endl;
		return 1;
	}
	else if(pass==Password2)
	{
		cout<<"Password has been verified"<<endl;
		return 2;
	}
	else
		return 3;
}
