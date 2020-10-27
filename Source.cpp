#include <iostream>
#include <string>
#include <conio.h>

#define PI 3.14159265358979323846;

using namespace std;
class ellipse {
	string name;
	int r;
	int R;
	int centreX;
	int centreY;
	double S;

	bool check(int valueR,int valuer)
	{
		if (valueR <= 0 || valuer <= 0)
		{
			return false;
		}
		return valueR > valuer ? true : false;
	}
	int size;
public:
	int *data;
	//конструкторы
	ellipse(string setname,int valuer, int valueR,int valueCentreX,int valueCentreY)
	{
		name = setname;
		r = valuer;
		R = valueR;
		centreX = valueCentreX;
		centreY = valueCentreY;
		//cout << this << "constructor" << endl;
	}
	ellipse()
	{
		name = "empty";
		r = 0;
		R = 0;
		S = 0;
		centreX = 0;
		centreY = 0;
		cout << this << "constructor" << endl;
	}
	ellipse(int size)
	{

		this->size = size;
		this->data = new int[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = i;
		}
		cout << "constructor called " << this << endl;
	}

	//copy constructor
	ellipse(const ellipse &other)
	{
		this->size = other.size;
		this->data = new int[other.size];

		for (int i = 0; i < other.size; i++)
		{
			this->data[i] = other.data[i];
		}
		cout << "copy constructor called " << this << endl;
	}

	//destructor
	~ellipse()
	{
		cout << "destructor called " << this << endl;
		delete[] data;
	}

	void countSquare()
	{
		S = r * R*PI;
	}

	int Getr()
	{
		return r;
	}
	int GetR()
	{
		return R;
	}
	int GetCentreX() {
		return centreX;
	}
	int GetCentreY() {
		return centreY;
	}
	string GetName()
	{
		return name;
	}

	void Setr(int valuer)
	{
		r = valuer;
	}
	void SetR(int valueR)
	{
		R = valueR;
	}
	void SetCentreX(int valuex)
	{
		centreX = valuex;
	}
	void SetCentreY(int valuey)
	{
		centreY = valuey;
	}
	void SetName(string setname)
	{
		name = setname;
	}

	void printInfo()
	{
		S = r * R*PI;
		cout << "name is " << name << endl << "r = " << r << endl << "R = " << R << endl << "S = " << S << endl
		<< "It's centre is located in (" << centreX << "," << centreY << ")" << endl << endl;
	}

	void inputName()
	{
		string setname;
		cout << "input name of ellipse: " << endl;
		cin >> setname;
		SetName(setname);
	}
	void inputradiuses()
	{
		int valuer;
		int valueR;
		cout << "\t\t\t\t\tnote: r must be less than R" << endl;
		do
		{
			cout << "input smaller radius: " << endl;
			cin >> valuer;

			cout << "input bigger radius: " << endl;
			cin >> valueR;

			if (!check(valueR,valuer))
			{
				cout << endl << "values are invalid,try again" << endl;
			}
		} while (!check(valueR, valuer));
		Setr(valuer);
		SetR(valueR);
	}
	void inputCentreCoordinates()
	{
		int valuex, valuey;
		cout << "input the x-coordinate of centre" << endl;
		cin >> valuex;
		SetCentreX(valuex);
		cout << "input the y-coordinate of centre" << endl;
		cin >> valuey;
		SetCentreY(valuey);
	}

	void addToRadiuses()
	{
		int valuer, valueR, addvaluer, addvalueR;
		cout << "\t\t\t\t\tnote: r must be less than R" << endl;
		do {
			valuer = Getr();
			valueR = GetR();
			cout << "input value to add to smaller radius: " << endl;
			cin >> addvaluer;
			valuer += addvaluer;

			cout << "input value to add to bigger radius: " << endl;
			cin >> addvalueR;
			valueR += addvalueR;
			if (!check(valueR,valuer))
			{
				cout << endl << "values are invalid,try again" << endl;
			}
		} while (!check(valueR,valuer));
		Setr(valuer);
		SetR(valueR);
	}
	void addToCoordinates()
	{
		int valuex, valuey, addvaluex, addvaluey;
		valuex = GetCentreX();
		valuey = GetCentreY();

		cout << "input value to add to the x-coordinate" << endl;
		cin >> addvaluex;
		valuex += addvaluex;
		SetCentreX(valuex);

		cout << "input value to add to the y-coordinate" << endl;
		cin >> addvaluey;
		valuey += addvaluey;
		SetCentreY(valuey);
	}

	void subFromCoordinates()
	{
		int valuex, valuey, subvaluex, subvaluey;
		valuex = GetCentreX();
		valuey = GetCentreY();

		cout << "input value to sub from the x-coordinate" << endl;
		cin >> subvaluex;
		valuex -= subvaluex;
		SetCentreX(valuex);

		cout << "input value to sub from the y-coordinate" << endl;
		cin >> subvaluey;
		valuey -= subvaluey;
		SetCentreY(valuey);
	}
	void subFromRadiuses()
	{
		int valuer, valueR, subvaluer, subvalueR;
		cout << "\t\t\t\t\tnote: r must be less than R" << endl;
		do {
			valuer = Getr();
			valueR = GetR();
			cout << "input value to sub from smaller radius: " << endl;
			cin >> subvaluer;
			valuer -= subvaluer;

			cout << "input value to sub from bigger radius: " << endl;
			cin >> subvalueR;
			valueR -= subvalueR;
			if (!check(valueR, valuer))
			{
				cout << endl << "values are invalid,try again" << endl;
			}
		} while (!check(valueR,valuer));
		SetR(valueR);
		Setr(valuer);
	}
};

class Myclass {
	int size;
public:
	int *data;


};

//Myclass foo2()
//{
//	cout << "function foo2 called" << endl;
//	Myclass temp;
//	return temp;
//}

int menu() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 7) % 7;
		if (key == 0) cout << "-> Change radiuses" << endl;
		else  cout << "   Change radiuses" << endl;

		if (key == 1) cout << "-> Change name" << endl;
		else  cout << "   Change name" << endl;

		if (key == 2) cout << "-> Change centre coordinates" << endl;
		else  cout << "   Change centre coordinates" << endl;

		if (key == 3) cout << "-> Add some value to radiuses" << endl;
		else  cout << "   Add some value to radiuses" << endl;

		if (key == 4) cout << "-> Add some value to coordinates" << endl;
		else  cout << "   Add some value to coordinates" << endl;

		if (key == 5) cout << "-> Subtract some value from radiuses" << endl;
		else  cout << "   Subtract some value from radiuses" << endl;

		if (key == 6) cout << "-> Subtract some value from coordinates" << endl;
		else  cout << "   Subtract some value from coordinates" << endl;

		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

int main() {

	//Myclass a;
	//Myclass b(a);
	ellipse a;
	cout << "Welcome!\n\t\tPress any key to start\n\t";

while (_getch() != 27)
{
	int answer = menu();
	switch (answer)
	{
		case 0://change radiuses
		{
			cout << "Here is info about ellipse: " << endl;
			a.printInfo();
			a.inputradiuses();
			cout << endl << "Here is new info about ellipse: " << endl;
			a.countSquare();
			a.printInfo();
			cout << endl;
			cout << "press any key to continue " << endl << "press esc to quit" << endl;
			break;
		}
		case 1://change name
		{
			cout << "Here is info about ellipse: " << endl;
			a.printInfo();
			a.inputName();
			cout << endl << "Here is new info about ellipse: " << endl;
			a.countSquare();
			a.printInfo();
			cout << endl;
			cout << "press any key to continue " << endl << "press esc to quit" << endl;
			break;
		}
		case 2://change centre coordinates
		{
			cout << "Here is info about ellipse: " << endl;
			a.printInfo();
			a.inputCentreCoordinates();
			cout << endl << "Here is new info about ellipse: " << endl;
			a.countSquare();
			a.printInfo();
			cout << endl;
			cout << "press any key to continue " << endl << "press esc to quit" << endl;
			break;
		}
		case 3://add to radiuses
		{
			cout << "Here is info about ellipse: " << endl;
			a.printInfo();
			a.addToRadiuses();
			cout << endl << "Here is new info about ellipse: " << endl;
			a.countSquare();
			a.printInfo();
			cout << endl;
			cout << "press any key to continue " << endl << "press esc to quit" << endl;
			break;
		}
		case 4://add to coordinates
		{
			cout << "Here is info about ellipse: " << endl;
			a.printInfo();
			a.addToCoordinates();
			cout << endl << "Here is new info about ellipse: " << endl;
			a.countSquare();
			a.printInfo();
			cout << endl;
			cout << "press any key to continue " << endl << "press esc to quit" << endl;
			break;
		}
		case 5://sub from radiuses
		{
			cout << "Here is info about ellipse: " << endl;
			a.printInfo();
			a.subFromRadiuses();
			cout << endl << "Here is new info about ellipse: " << endl;
			a.countSquare();
			a.printInfo();
			cout << endl;
			cout << "press any key to continue " << endl << "press esc to quit" << endl;
			break;
		}
		case 6://sub from coordinates
		{
			cout << "Here is info about ellipse: " << endl;
			a.printInfo();
			a.subFromCoordinates();
			cout << endl << "Here is new info about ellipse: " << endl;
			a.countSquare();
			a.printInfo();
			cout << endl;
			cout << "press any key to continue " << endl << "press esc to quit" << endl;
			break;
		}
	}
}

	const int size = 5;
	ellipse arr[size];
	arr[0] = ellipse("vadik", 1, 2, 0, 0);
	arr[0].printInfo();

	system("pause");
	return 0;
}