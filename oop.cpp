class teacher
{
	int a;
	int phone;
	string name;
	string section[10];
	string subject;

 public:

	void input()
	{
		cout << "\n\t\t\t\t\t Enter teacher name:";
		cin.ignore();
		getline(cin, name);
		cout << "\n\t\t\t\t\tEnter subject : ";
		getline(cin, subject);
		cout << "\n\t\t\t\t\tenter the phone number: ";
		cin >> phone;
		while (1)
		{
			cout << "\n\t\t\t\t\tenter the number of section taught ";
			cin >> a;
			if (a <= 0)
				cout << "\n\t\t\t\t\tsections taught cannot be less than or equal to zero\n";
			else
				break;
		}
		cout << "\n\t\t\t\t\tthe section(s) (press enter after giving each section name):";
		cin.ignore();
		for (int i = 0; i < a; i++)
			cin >> section[i];
	}
	void show()
	{
		cout << "\n\t\t\t\t\tTeacher name: " << name << "\n";
		cout << "\n\t\t\t\t\tEnter subject : " << subject << "\n";
		cout << "\n\t\t\t\t\tenter the phone number: " << phone << "\n";
		cout << "\n\t\t\t\t\tthe sections taught :\n";
		for (int i = 0; i < a; i++)
			cout << "\n\t\t\t\t\t" << section[i] << "\n";
	}

	int getph()
	{
		return phone;
	}
	int geta()
	{
		return a;
	}
	string getnm()
	{
		return name;
	}
	string getsub()
	{
		return subject;
	}
	string getsec(int x)
	{
		return section[x];
	}
} t;

void Create();
void Add();
void Display();
void Delete();
void sbn();
void sbs();
void sbsec();



void Create()
{
	system("CLS");
	char ch = 'y';
	fil.open("teacher.dat", ios::out | ios::binary);
	while (ch == 'y' || ch == 'Y')
	{
		t.input();
		fil.write((char*)& t, sizeof(t));
		cout << "\n\t\t\t\t\tWant to Continue (Y/N):";
		cin >> ch;
	}
	fil.close();
}

void Add()              //Function to Add New Record in Data File
{
	system("CLS");
	char ch = 'y';
	fil.open("teacher.dat", ios::app | ios::binary);
	while (ch == 'y' || ch == 'Y')
	{
		t.input();
		fil.write((char*)& t, sizeof(t));
		cout << "\n\t\t\t\t\tWant to Continue (Y/N):";
		cin >> ch;
	}
	fil.close();
}

void Display() //Function to Display All Record from Data File
{
	system("CLS");
	fil.open("teacher.dat", ios::in | ios::binary);
	if (!fil)
	{
		cout << "\n\t\t\t\t\tFile not created\n";
		exit(0);
	}
	fil.read((char*)& t, sizeof(t));
	if (fil.eof())
	{
		cout << "\n\t\t\t\t\tNo records present.\n";
		return;
	}
	else
	{
		cout << "\n\t\t\t\t\t\tShowing Record(s)\n";
		while (!fil.eof())
		{
			t.show();
			fil.read((char*)& t, sizeof(t));
		}
	}
	fil.close();
}
void sbn()//function which searches record using name of faculty
{
	system("CLS");
	fil.open("teacher.dat", ios::in | ios::binary);
	if (!fil)
	{
		cout << "\n\t\t\t\t\tFile not created\n";
		exit(0);
	}
	fil.read((char*)& t, sizeof(t));
	if (fil.eof())
	{
		cout << "\n\t\t\t\t\tNo records present.\n";
		return;
	}
	string s;
	cout << "\n\t\t\t\t\tEnter the name of faculty to be searched : ";
	cin.ignore();
	getline(cin, s);
	while (1)
	{
		if (s == t.getnm())
		{
			cout << "\n\t\t\t\t\tFaculty found, here are the details :\n";
			t.show();
			return;
		}
		fil.read((char*)& t, sizeof(t));
	}
	cout << "\n\t\t\t\t\tFaculty does not exist.\n";
}
void sbs()//function which searches record using subject taught by faculty
{
	system("CLS");
	fil.open("teacher.dat", ios::in | ios::binary);
	if (!fil)
	{
		cout << "\n\t\t\t\t\tFile not created\n";
		exit(0);
	}
	fil.read((char*)& t, sizeof(t));
	if (fil.eof())
	{
		cout << "\n\t\t\t\t\tNo records present.\n";
		return;
	}
	string s;
	cout << "\n\t\t\t\t\tEnter the subject to be searched : ";
	cin.ignore();
	getline(cin, s);
	while (1)
	{
		if (s == t.getsub())
		{
			cout << "\n\t\t\t\t\tFaculty found, here are the details :\n";
			t.show();
			return;
		}
		fil.read((char*)& t, sizeof(t));
	}
	cout << "\n\t\t\t\t\tFaculty does not exist.\n";
}
void sbsec()//function which searches record using sections taught by faculty
{
	system("CLS");
	fil.open("teacher.dat", ios::in | ios::binary);
	if (!fil)
	{
		cout << "\n\t\t\t\t\tFile not created\n";
		exit(0);
	}
	fil.read((char*)& t, sizeof(t));
	if (fil.eof())
	{
		cout << "\n\t\t\t\t\tNo records present.\n";
		return;
	}
	string s;
	cout << "\n\t\t\t\t\tEnter the section to be searched : ";
	cin.ignore();
	getline(cin, s);
	int i = 0;
	while (!fil.eof())
	{
		for (int j = 0; j < t.geta(); j++)
			if (s == t.getsec(j))
			{
				i++;
				if (i == 1)
					cout << "\n\t\t\t\t\tFaculty found, here are the details :\n";
				t.show();
				cout << "\n";
				fil.read((char*)& t, sizeof(t));
				if (!fil.eof())
					j = -1;
			}
		fil.read((char*)& t, sizeof(t));
	}
	if (i == 0)
		cout << "\n\t\t\t\t\tFaculty does not exist.\n";
}
void Delete() //Function to Delete Particular Record from Data File
{
	system("CLS");
	string srch;
	fstream o;
	o.open("copy.dat", ios::out | ios::binary);
	fil.open("teacher.dat", ios::in | ios::binary);
	if (!fil)
	{
		cout << "\n\t\t\t\t\tFile not created\n";
		return;
	}
	cout << "\n\t\t\t\t\tEnter the name of the teacher whose record is to be deleted :";
	cin.ignore();
	getline(cin, srch);
	fil.read((char*)& t, sizeof(t));
	while (!fil.eof())
	{
		if (srch != t.getnm())
		{
			o.write((char*)& t, sizeof(t));
			//break;
		}
		fil.read((char*)& t, sizeof(t));
	}
	fil.close();
	o.close();
	remove("teacher.dat");
	rename("copy.dat", "teacher.dat");

}

/*================================================================================*/

int main()
{
	int a = 1, w;
	ifstream file1;
	ofstream file2;
	Grade g1;
	char ch5;
	char ch;
	char ch1;
	int ch2;
	//	load();

	do {
		CLS();
		RULE("*");
		cout << "\t\t\tUNIVERSITY MANAGEMENT SYSTEM";
		RULE("*");
		cout << "\t1. STUDENT INFORMATION SECTION\n";
		cout << "\t2. LIBRARY MANAGEMENT SYSTEM\n";
		cout << "\t3. FACULTY SECTION\n";
		cout << "\t0. Exit.\n\n";
		cout << "Enter your choice : ";
		fflush(stdin);
		cin >> ch5;
		if (ch5 == '1')
		{
			fflush(stdin);
			//			load();
			do {
			studentMenu:
				CLS();
				RULE("*");
				cout << "\t\t\tSTUDENT INFORMATION SECTION";
				RULE("*");
				cout << "\t1. Admission Details.\n";
				cout << "\t2. Grading System.\n";
				cout << "\t3. Placement Cell.\n";
				cout << "\t0. Exit.\n\n";
				cout << "Enter your choice : ";
				fflush(stdin);
				cin >> ch1;
				if (ch1 == '1')
				{
					fflush(stdin);
					//			load();
					do
					{
						CLS();
						RULE("*");
						cout << "\t\t\tSTUDENT INFORMATION SECTION";
						RULE("*");
						cout << "\t\t\t     ADMISSION DETAILS";
						RULE('-');

						cout << "\t1.  Register Student\n";
						cout << "\t2.  Display all Records.\n";
						cout << "\t3.  Search for a Record\n";
						cout << "\t4.  Delete a Record.\n";
						cout << "\t0.  Exit.\n";
						cout << "\nEnter your choice : ";

						cin >> ch2;
						switch (ch2)
						{
						case 1:
							insertStudent();
							break;
						case 2:
							dispStudentRecord();
							break;
						case 3:
							searchByRollNo(2);
							break;
						case 4:
							delStudentRecord();
							break;
						}

						fflush(stdin);
						if (ch2)
							cin >> ch;
						else
							load();
					} while (ch2 != 0);
				}

				if (ch1 == '2')
				{
					fflush(stdin);
					load();
					do
					{
						CLS();
						RULE("*");
						cout << "\t\t\tSTUDENT INFORMATION SECTION";
						RULE("*");
						cout << "\t\t\t    	GRADING SYSTEM";
						RULE('-');

						cout << "\t1.  Upload Grades\n";
						cout << "\t2.  View All Grades\n";
						cout << "\t3.  Search Grades By Roll Number\n";
						cout << "\t0.  Exit.\n";
						cout << "\nEnter your choice : ";

						cin >> w;
						switch (w)
						{
						case 1:
							insertGrade();
							break;
						case 2:
							dispGrade();
							break;
						case 3:
							searchGradeByRollNo(2);
							break;
						}
						fflush(stdin);
						if (w)
							cin >> ch;
						else
							load();
					} while (w != 0);
				}
				// Dibya's Code for Main Function
				if (ch1 == '3')
				{
					fflush(stdin);
					load();
				placementMenu:
					CLS();
					RULE("*");
					cout << "\t\t\tSTUDENT INFORMATION SECTION";
					RULE("*");
					cout << "\t\t\t    	PLACEMENT CELL";
					RULE('-');
					cout << "\t\t\t1. Add Student\n";
					cout << "\t\t\t2. Add Company\n";
					cout << "\t\t\t3. Show Eligible students\n";
					cout << "\t\t\t4. Back\n";
					cout << "\t\t\t5. Exit\n";
					cout << "\t\t\tEnter your choice: ";
					int choice;
					cin >> choice;
					int n, m;
					company c[m];
					Students s[n];
					placement p[m];
					switch (choice)
					{

					case 1:
					{
						CLS();
						cout << "Enter the number of Students who want to sit in placement: ";
						cin >> n;
						cout << endl;
						RULE('-');
						cout << " \n\nEnter the Students details:- \n ";
						RULE('-');
						for (int i = 0; i < n; i++)
						{
							cout << "##### Student " << i + 1 << " #####" << endl;
							s[i].getSData();
						}
						cout << endl << endl;
						break;
					}
					case 2:
					{
						CLS();
						cout << "\nEnter the number of Companies: ";
						cin >> m;
						RULE('-');
						cout << "\n\nEnter the company details: \n";
						RULE('-');
						for (int i = 0; i < m; i++)
						{
							cout << "##### Company " << i + 1 << " #####" << endl;
							c[i].getCData();
						}
						break;
					}
					case 3:
					{
						cout << "\nEnter Company's Name: ";
						char companyName[100];
						cin.getline(companyName, 100);
						char cName[100], sName[100];
						int packageLPA, sRoll;
						float minCGPA, sCGPA;
						int eCount = 0;
						ifstream fin("studentList.txt");
						while (!(fin.eof()))
						{
							fin.getline(cName, 100);
							fin >> packageLPA >> minCGPA;
							if (strcmp(companyName, cName) == 0)
							{
								break;
							}
						}
						fin.close();
						ifstream fin2("companyList.txt");
						while (!(fin2.eof()))
						{
							fin2.getline(sName, 100);
							fin2 >> sRoll >> sCGPA;
							if (sCGPA >= minCGPA)
							{
								eCount++;
								cout << "##### Student " << eCount << " #####" << endl;
								cout << "\n\nName: " << sName << endl;
								cout << "\nRoll. No.: " << sRoll << endl;
								cout << "\nCGPA: " << sCGPA << endl;
							}
						}
						fin2.close();
						break;
					}
					case 4:
					{
						goto studentMenu;
						break;
					}
					case 5:
					{
						exit(0);
					}
					default:
					{
						cout << "\nInvalid Choice. Please try again.";
						goto placementMenu;
					}
					}
				}
			} while (ch1 != '0');
		}

		if (ch5 == '2')
		{
			fflush(stdin);
			load();
			CLS();
			Library lib;
			lib.mainMenu();
		}

		if (ch5 == '3')
		{
			int opt;
			fflush(stdin);
			load();
			do {
				CLS();
				cout << "\n\t\t\t\t\t* * * * * * FACULTY SECTION * * * * * *\n" << endl;
				cout << "\n\t\t\t\t\t1. Create Data File" << endl;
				cout << "\n\t\t\t\t\t2. Add New Record in Data File" << endl;
				cout << "\n\t\t\t\t\t3. Display Record From Data File" << endl;
				cout << "\n\t\t\t\t\t4. Delete Particular Record From Data File" << endl;
				cout << "\n\t\t\t\t\t5. Search by name" << endl;
				cout << "\n\t\t\t\t\t6. Search by subject taught" << endl;
				cout << "\n\t\t\t\t\t7. Search by section taught" << endl;
				cout << "\n\t\t\t\t\t8. Exit From the Program" << endl;
				cout << "\n\t\t\t\t\t0. Back To Main Menu" << endl;
				cout << "\n\t\t\t\t\tEnter your choice : ";
				cin >> opt;
				switch (opt)
				{
				case 1:
					Create();
					break;
				case 2:
					Add();
					break;
				case 3:
					Display();
					break;
				case 4:
					Delete();
					break;
				case 5:
					sbn();
					break;
				case 6:
					sbs();
					break;
				case 7:
					sbsec();
					break;
				case 8:
					CLS();
					exit(0);
				}
				fflush(stdin);
				if (opt)
					cin >> ch;
				else
					load();
			} while (opt != 0);
		}
	} while (ch5 != '0');
	CLS();
	return 0;
}
