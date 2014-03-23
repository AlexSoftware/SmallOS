#include "header.h"
#include "Functions.h"
#include <string>
#include "string.h"


/*struct user{
	string login;
	string passw;
};
*/


void signup()
{
	system("cls");
	user usr1;

	cout << "Enter your username: ";
	cin >> usr1.login;
	cout << "Enter your password: ";
	cin >> usr1.passw;
	system("cls");
		const string filename = "\\" + usr1.login + "\\auth.txt";
		//const char *fn = filename.c_str();
		bool canProceed = fe(filename);

		if (canProceed == true){

		//if (!(FileExists(filename.c_str()))){
	const string command = "@MD " + usr1.login;
	system(command.c_str());

	ofstream fout(filename.c_str());
	fout <<  usr1.login.c_str();
	fout << endl << usr1.passw.c_str();
	fout << endl << filename.c_str() << endl;
	fout.close();
			}else{
				cout << "User already exists!" << endl;
				Sleep(2000);
			}
    

	MMD();
	
}
void signin()
{

	system("cls");
	user usr;
	cout << "Enter your login: ";
	cin >> usr.login;
	cout << "Enter your password: ";
	cin >> usr.passw;
	system("cls");

    string u1 = "";
	string p1 = "";

	if (authorize(usr) == true){
		cout << "Hello, " << usr.login << "!" << endl;
		logon(usr.login);
	}else{
		cerr << "[STDERR] User with this login/password not exists!" << endl;
		Sleep(1500);
		MMD();
		}
	
	}




void logon(string ussername){
    system ("cls");
	const string filename = "\\" + ussername + "\\auth.txt";
	cout << "Enviroment is on: " << filename << endl;
		char dateStr1 [9];
		char timeStr1 [9];
		_strtime_s( timeStr1 );
		_strdate_s( dateStr1);
		cout << "Today is " << dateStr1 << ". Time is " << timeStr1 << endl;
	OS(ussername);
}

void OS(string username){
	const string filename = "\\" + username + "\\auth.txt";
	
	string ucmd = "";
	
	cout << ">";
	cin >> ucmd;
	do{
	if (ucmd == "username"){ cout << "You're logged as " << username << endl;OS(username);break;}
	if (ucmd == "changepassword"){chpsw(username);break;}	
	if (ucmd == "time"){
		char dateStr [9];
		char timeStr [9];
		_strdate_s( dateStr);
		printf( "Date: %s \n", dateStr);
		_strtime_s( timeStr );
		printf( "Time: %s \n", timeStr);
		break;
		}
	if (ucmd == "logoff"){ logoff(username);break;}
	if (ucmd == "removeme"){ 
		cout << "Now Your account will be deleted! FOREVER!" << endl;
		system("cls");
		string cmdr = "@RD " + username;
		remove(filename.c_str());
		system(cmdr.c_str());
		logoff(username);
	}
	if (ucmd == "about"){ cout << "SmallOS by Serdukov Alexander. We are trying to hack pentagon for you!" << endl;}
	
    cout << "Unknown command: " << ucmd << endl; OS(username);
	
	}
	while(false);


}

void logoff(string usn)
{
	system("cls");
	cout << "Bye, " << usn << "!" << endl;
	cout << "Saving your settings..." << endl;
	cout << "Cleaning OS enviroment" << endl;
	
	usn = "";
	system("pause");
	system("cls");
	MMD();
}

		
void chpsw(string un)
{
	    string pi = "";
		const string filename = "\\" + un + "\\auth.txt";
		
		ifstream fin(filename.c_str());
		cout << "Enter your old password: ";
		cin >> pi;
		string usname = "";
		string pn = "";
		fin >> usname;
		fin >> pn;
		fin.close();
		if (pi == pn){
			cout << "Enter new password" << endl;
			string nnp = "";
			cin >> nnp;
				remove(filename.c_str());
				ofstream fout(filename.c_str());
				fout << un << endl;
				fout << nnp;
				fout.close();
             cout << "Password changed!Now you'll be logged off!" << endl;
			 Sleep(1500);
			 system("cls");
			 logoff(un);


			}else{
				cout << "Incorrect password!!!" << endl;
				Sleep(2000);
				system("cls");
				logoff(un);
			}
}


bool authorize(user ul)
{
	const string filename = "\\" + ul.login + "\\auth.txt";
	ifstream fin(filename.c_str());
	user u2;


	fin >> u2.login;
	fin >> u2.passw;

	if (ul.passw == u2.passw){
		return true;
		}else{
			//cout << ul.login << " " << ul.passw << " " << u2.login << " " << u2.passw << " " << filename << endl;
			//cin >> u2.passw;
			return false;
		}
}

bool fe(string path)
{
ifstream fin;
fin.open(path);
if (fin == false){
	return true;
	}else{
		return false;
	}
fin.close();

}

