#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

/*
	stringToInt is a helper function that will 
	take a string called line and return the integer value
*/
int stringToInt(string line)
{
	stringstream s1(line);
	int temp = 0;
	s1 >> temp;
	return temp;
}

int main()
{

	string filename = "building.txt";
	int floorNum = 0;
	int numFloors = 0;
	string floorID;
	string resident;
	string extracted;
	int row = 0;
	int col = 0;
	int temp = 0;
	

	ifstream infile;
	infile.open(filename.c_str());

	while (!infile.eof())
	{
		infile >> resident;
		stringstream ss(resident);

		while (getline(ss, extracted, ','))
		{
			while (getline(ss, extracted, ':'))
			{
				stringstream ssExtracted(extracted);
				string out;
				ssExtracted >> out;
				temp++;
			}
			if (temp > col)
			{
				col = temp;
			}
			temp = 0;
			row++;
		}
	}
	infile.close();

	string **buildArr = new string *[row];
	buildArr[row] = new string [col];

	infile.open(filename.c_str());

	row = 0;
	col = 0;

	while (!infile.eof())
	{
		infile >> resident;
		stringstream ss(resident);

		while (getline(ss, extracted, ','))
		{
			stringstream ssextracted(extracted);
			string out;
			string ID = "ID:";
			ssextracted >> out;
			//cout << out << endl;

			if (out.length() < 3) // counts the number of floors.
			{
				floorNum = stringToInt(out);
				numFloors++;
				row = numFloors; 
			}
			else if (out.length() > 3)
			{
				if (out == "Floor ID:")
				{
				}
				else
				{
					resident = out;
					if (resident == ID.append("4"))
					{
						*buildArr[col] = resident;
					}
					else 
					{
						*buildArr[col] = resident;
						cout << resident << endl;
					}
					
				}
			}
			//buildArr[row][col] = out;
		}
		cout << "Resident on floor 4: " << buildArr[4] << endl;
		col++;
		cout << "this is the col value: " << col << endl;
		col = 0;
		cout << "this is the row value: " << row << endl; 
		
	}
	//cout << numFloors << endl;
	infile.close();

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			buildArr[i][j] = buildArr[i][j];
		}
	}

	cout << "new array: " << buildArr[4] << endl;

	for (int i = 0; i < row; i++)
	{
		delete [] buildArr[row];
	}
	delete [] buildArr;

	// string tempstring;
	// for (int i = 0; i < row; i++)
	// {
	// 	for (int j = (i+1); j < row; j++)
	// 	{
	// 		int num, num1;
	// 		stringstream stringstream(buildArr[i][0]);
	// 		stringstream >> num;
	// 		stringstream.str("");
	// 		stringstream.clear();
	// 		stringstream << (buildArr[j][0]);
	// 		stringstream >> num1;

	// 		if (num > num1)
	// 		{
	// 			tempstring = buildArr[i][0];
	// 			buildArr[i][0] = buildArr[j][0];
	// 			buildArr[j][0] = temp;
	// 		}
	// 	}
	// }
	// for(int i = 0; i < row - 1; i++)
	// {
	// 	for (int j = 0; j < col - 1; j++)
	// 	{
	// 		if (buildArr[i][j] != "")
	// 		{
	// 			cout << buildArr[i][0];
	// 			if (j != col - 1 && buildArr[i][j+1] != "")
	// 			{
	// 				cout << ",";
	// 			}
	// 		}
	// 	}

	// 	cout << endl;

	// }
	return 0;
}

/*
Expected output with the given building.txt:

Sunil,Alok,Kamilah,Pratik
Tamera,Zanetta,Keyundra,Alexzander,Nickalaus,Nathania,Annamaria,Ransen,Thuy,Yousef       
Jeffry,Shira,Sereena
Janna,Shaleen,Josi,Ndidi,Indalecio,Charlotta
Kejuan,Matricia,Takiya,Karalyn,Charls
Rebbecca
Kailyn,Kenda
Katheryne,Coury,Timithy,Melisssa,Clara,Lucus,Brittony,Makoto,Latona,Rudolph
*/
