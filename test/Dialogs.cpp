#include "header.h"
#include "Dialogs.h"




void MMD()
{   
    cout << "SmallOS by <you will know who, if you sign in and type ""about""." << endl;
	cout << "1. Sign up" << endl;
	cout << "2. Sign in" << endl;
    cout << "3. Shutdown guest" << endl;
	
	cout << "Enter your choise: ";
	int choise = 0;
	cin >> choise;
	switch (choise)
	{
	case 1: signup();break;
	case 2: signin();break;
	case 3: exit(0);break;
	default : MMD();break;
	}

}