// Statistics_Canada_v1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Student Name: Manlika Throngsiriwat
//Student Number: 2032382

#include <iostream>
#include <string>
using namespace std;

struct City
{
	int area_code; string name; string abbreviation; long population;  double surface_area;
};
//-1- Functions proyotypes ... using reference:
void add_cities_ref(City cities_array[], const int MAX); //cities_array and MAX are the formal parameters
void print_cities_ref(City cities_array[], const int MAX);
int search_city_code_ref(City cities_array[], const int MAX, int key);
int search_city_name_ref(City cities_array[], const int MAX, string key1);
void print_city_ref(City cities_array[], const int position);
int find_highest_area_ref(City cities_array[], const int MAX);
int find_lowest_area_ref(City cities_array[], const int MAX);
void sort_cities_ref(City cities_array[], const int MAX);
void show_menu_ref();
//-2- Control modules
int main()
{
	//Functions calls : call by REFERENCE
	//1- Declarations and Initializations
	const int MAX = 3;
	City cities_array[MAX];
	string country[MAX]; //Honestly, I don't know its function in this application.
						 //I declared it following by teacher's intruction (Q9).
	string key1;
	double find_highest; double find_lowest;
	int key; int position; int option = 0;
	char keep_looping;
	//2-Input-output data
	cout << "\t\t Application Statistics Canada \n";
	do
	{
		show_menu_ref(); //Menu options using switch case
		cin >> option;
		switch (option)
		{
		case 1:
			add_cities_ref(&cities_array[0], MAX); //cities_array and MAX are the effective parameters
			break;
		case 2:
			print_cities_ref(&cities_array[0], MAX);
			break;
		case 3:
			cout << "\n Search for a city by code area";
			cout << "\n\t Enter the Area code: ";
			cin >> key;
			cout << endl << endl;
			position = search_city_code_ref(&cities_array[0], MAX, key);
			break;
		case 4:
			sort_cities_ref(&cities_array[0], MAX);
			print_cities_ref(&cities_array[0], MAX);
			break;
		case 5:
			cout << "\n Search for a city by city name";
			cout << "\n\t Enter the city name: ";
			cin >> key1;
			cout << endl << endl;
			position = search_city_name_ref(&cities_array[0], MAX, key1);
			break;
		case 6:
			find_highest = find_highest_area_ref(&cities_array[0], MAX);
			cout << " The city having the highest surface area: " << find_highest << endl << endl;
			break;
		case 7:
			find_lowest = find_lowest_area_ref(&cities_array[0], MAX);
			cout << " The city having the lowest surface area: " << find_lowest << endl << endl;
			break;
		case 8:
			cout << "\n Exit the Application Statistics Canada... " << endl;
			exit(1);
			break;
		}
		cout << "\n\t\t Do you want to continue?\n\t\t\t (type y or Y (for yes), n or N (for no)): ";
		cin >> keep_looping;
		cout << endl << endl;
	} while (keep_looping == 'Y' || keep_looping == 'y');
	cout << " Application written by Manlika Throngsiriwat[2032382]...";
	cout << endl << endl;
	system("pause");
	return 0;
}
//-3- Functions implementations : Function Definitions
//module-01
void add_cities_ref(City cities_array[], const int MAX)
{
	cout << "\n Add the city information...USING REFERENCE\n";
	for (int index = 0; index < MAX; index++)
	{
		cout << "\n Enter area code        : "; cin >> cities_array[index].area_code;
		cout << "\n Enter city name        : "; cin >> cities_array[index].name;
		cout << "\n Enter city abbreviation: "; cin >> cities_array[index].abbreviation;
		cout << "\n Enter city population  : "; cin >> cities_array[index].population;
		cout << "\n Enter city surface area: "; cin >> cities_array[index].surface_area;
		cout << endl;
	}
}
//module-02
void print_cities_ref(City cities_array[], const int MAX)
{
	cout << "\n Print the city information...USING REFERENCE\n";
	for (int index = 0; index < MAX; index++)
	{
		cout << "\n Area code        : "; cout << cities_array[index].area_code;
		cout << "\n City name        : "; cout << cities_array[index].name;
		cout << "\n City abbreviation: "; cout << cities_array[index].abbreviation;
		cout << "\n City population  : "; cout << cities_array[index].population;
		cout << "\n City surface area: "; cout << cities_array[index].surface_area;
		cout << endl;
	}
}
//module-03
int search_city_code_ref(City cities_array[], const int MAX, int key)
{
	int position = -1;
	for (int index = 0; index < MAX; index++)
	{
		if (cities_array[index].area_code == key)
		{
			position = index;
			break;
		}
	}
	print_city_ref(&cities_array[0], position);
	return position;
}
//module-04
int search_city_name_ref(City cities_array[], const int MAX, string key1)
{
	int position = -1;
	for (int index = 0; index < MAX; index++)
	{
		if (cities_array[index].name == key1)
		{
			position = index;
			break;
		}
	}
	print_city_ref(&cities_array[0], position);
	return position;
}
//module-05
void print_city_ref(City cities_array[], int position)
{
	if (position == -1)
	{
		cout << " City not Found ..." << endl;
	}
	else
	{
		cout << " City Found ..." << endl;
		cout << "\n Area code        : " << cities_array[position].area_code;
		cout << "\n City name        : " << cities_array[position].name;
		cout << "\n City abbreviation: " << cities_array[position].abbreviation;
		cout << "\n City population  : " << cities_array[position].population;
		cout << "\n City surface area: " << cities_array[position].surface_area;
	}
}
//module-06
int find_highest_area_ref(City cities_array[], const int MAX)
{
	cout << "\n Find the city having the highest surface area...USING REFERENCE\n";
	double find_highest = cities_array[0].surface_area;
	for (int value = 0; value < MAX; value++)
	{
		if (cities_array[value].surface_area > find_highest)
		{
			find_highest = cities_array[value].surface_area;
		}
	}
	return find_highest;
}
//module-07
int find_lowest_area_ref(City cities_array[], const int MAX)
{
	cout << "\n Find the city having the lowest surface area...USING REFERENCE\n";
	double find_lowest = cities_array[0].surface_area;
	for (int value = 0; value < MAX; value++)
	{
		if (cities_array[value].surface_area < find_lowest)
		{
			find_lowest = cities_array[value].surface_area;
		}
	}
	return find_lowest;
}
//module-08
void sort_cities_ref(City cities_array[], const int MAX)
{
	cout << "\n Sort cities by surface area...USING REFERENCE\n";
	for (int city1 = 0; city1 < MAX; city1++)
	{
		for (int city2 = city1 + 1; city2 < MAX; city2++)
		{
			if (cities_array[city1].surface_area < cities_array[city2].surface_area)
			{
				City temporary_cities;
				temporary_cities = cities_array[city1];
				cities_array[city1] = cities_array[city2];
				cities_array[city2] = temporary_cities;
			}
		}
	}
}
//module-09
void show_menu_ref()
{
	cout << "\n MENU OPTIONS";
	cout << "\n\t 1- Add cities";
	cout << "\n\t 2- Print cities";
	cout << "\n\t 3- Search for a city by code area";
	cout << "\n\t 4- Sort cities by surface area";
	cout << "\n\t 5- Search for a city by name";
	cout << "\n\t 6- Find the city having the highest surface area";
	cout << "\n\t 7- Find the city having the lowest surface area";
	cout << "\n\t 8- Exit \n";
	cout << "\n Choose your option: ";
}
/*
				                 Application Statistics Canada

 MENU OPTIONS
         1- Add cities
         2- Print cities
         3- Search for a city by code area
         4- Sort cities by surface area
         5- Search for a city by name
         6- Find the city having the highest surface area
         7- Find the city having the lowest surface area
         8- Exit

 Choose your option: 1

 Add the city information...USING REFERENCE

 Enter area code        : 123

 Enter city name        : Bangkok

 Enter city abbreviation: BKK

 Enter city population  : 78456

 Enter city surface area: 2457.33


 Enter area code        : 456

 Enter city name        : Seoul

 Enter city abbreviation: SO

 Enter city population  : 7841

 Enter city surface area: 567.41


 Enter area code        : 789

 Enter city name        : Montral

 Enter city abbreviation: MTL

 Enter city population  : 55421

 Enter city surface area: 7894.65


                 Do you want to continue?
                         (type y or Y (for yes), n or N (for no)): y



 MENU OPTIONS
         1- Add cities
         2- Print cities
         3- Search for a city by code area
         4- Sort cities by surface area
         5- Search for a city by name
         6- Find the city having the highest surface area
         7- Find the city having the lowest surface area
         8- Exit

 Choose your option: 2

 Print the city information...USING REFERENCE

 Area code        : 123
 City name        : Bangkok
 City abbreviation: BKK
 City population  : 78456
 City surface area: 2457.33

 Area code        : 456
 City name        : Seoul
 City abbreviation: SO
 City population  : 7841
 City surface area: 567.41

 Area code        : 789
 City name        : Montral
 City abbreviation: MTL
 City population  : 55421
 City surface area: 7894.65

                 Do you want to continue?
                         (type y or Y (for yes), n or N (for no)): Y



 MENU OPTIONS
         1- Add cities
         2- Print cities
         3- Search for a city by code area
         4- Sort cities by surface area
         5- Search for a city by name
         6- Find the city having the highest surface area
         7- Find the city having the lowest surface area
         8- Exit

 Choose your option: 3

 Search for a city by code area
         Enter the Area code: 123


 City Found ...

 Area code        : 123
 City name        : Bangkok
 City abbreviation: BKK
 City population  : 78456
 City surface area: 2457.33

                 Do you want to continue?
                         (type y or Y (for yes), n or N (for no)): y



 MENU OPTIONS
         1- Add cities
         2- Print cities
         3- Search for a city by code area
         4- Sort cities by surface area
         5- Search for a city by name
         6- Find the city having the highest surface area
         7- Find the city having the lowest surface area
         8- Exit

 Choose your option: 4

 Sort cities by surface area...USING REFERENCE

 Print the city information...USING REFERENCE

 Area code        : 789
 City name        : Montral
 City abbreviation: MTL
 City population  : 55421
 City surface area: 7894.65

 Area code        : 123
 City name        : Bangkok
 City abbreviation: BKK
 City population  : 78456
 City surface area: 2457.33

 Area code        : 456
 City name        : Seoul
 City abbreviation: SO
 City population  : 7841
 City surface area: 567.41

                 Do you want to continue?
                         (type y or Y (for yes), n or N (for no)): y



 MENU OPTIONS
         1- Add cities
         2- Print cities
         3- Search for a city by code area
         4- Sort cities by surface area
         5- Search for a city by name
         6- Find the city having the highest surface area
         7- Find the city having the lowest surface area
         8- Exit

 Choose your option: 5

 Search for a city by city name
         Enter the city name: Seoul


 City Found ...

 Area code        : 456
 City name        : Seoul
 City abbreviation: SO
 City population  : 7841
 City surface area: 567.41

                 Do you want to continue?
                         (type y or Y (for yes), n or N (for no)): y



 MENU OPTIONS
         1- Add cities
         2- Print cities
         3- Search for a city by code area
         4- Sort cities by surface area
         5- Search for a city by name
         6- Find the city having the highest surface area
         7- Find the city having the lowest surface area
         8- Exit

 Choose your option: 6

 Find the city having the highest surface area...USING REFERENCE
 The city having the highest surface area: 7894


                 Do you want to continue?
                         (type y or Y (for yes), n or N (for no)): y



 MENU OPTIONS
         1- Add cities
         2- Print cities
         3- Search for a city by code area
         4- Sort cities by surface area
         5- Search for a city by name
         6- Find the city having the highest surface area
         7- Find the city having the lowest surface area
         8- Exit

 Choose your option: 7

 Find the city having the lowest surface area...USING REFERENCE
 The city having the lowest surface area: 567


                 Do you want to continue?
                         (type y or Y (for yes), n or N (for no)): y



 MENU OPTIONS
         1- Add cities
         2- Print cities
         3- Search for a city by code area
         4- Sort cities by surface area
         5- Search for a city by name
         6- Find the city having the highest surface area
         7- Find the city having the lowest surface area
         8- Exit

 Choose your option: 8

 Exit the Application Statistics Canada...

C:\Users\Manlika_puipuy\source\repos\Statistics_Canada_v1\Debug\Statistics_Canada_v1.exe (process 14180) exited with code 1.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/

