#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
#include<fstream>

using namespace std;

class Stone {
public:

	Stone() {};
	
	string stoneName = "Not Entered";
	string keyWord= "Not Entered";
	string color = "Not Entered";
	unsigned int vecPosition = 0; //in archiveVecSetup() this gets modified to the position of the Stone object in the Stone vector.
	
	Stone(string& name, string& key, string& kolor)//able to take three string arguments to initialize the first three class members of Stone
	{
		stoneName ="stone name: " + name;
		keyWord ="keywords: "+ key;
		color ="color: "+ kolor;
	}
	void endUserInit();
};
string toLowerCaseString(std::string& str1)
{
	for (unsigned int c = 0; c < str1.size(); c++)
	{
		str1[c] = tolower(str1[c]);
	}
	return str1;
}
//takes a string argument converts all characters in string to lower case and returns the lower case version of the argument string
vector<Stone> archiveVecSetup(vector<Stone>& sVec)
{
	string border;
	ifstream inFile;
	ofstream outFile;
	string fileInput;
	
	inFile.open("Stone_Archive.txt");

	if (!inFile.is_open())
	{
		cout << "Unable to open Archive file." << endl;
		exit(5);
	}

	while (!inFile.eof())
	{
		Stone* fileStone = new Stone;
		//cin.ignore();?
		getline(inFile, fileInput);
		fileStone->stoneName = fileInput;

		getline(inFile, fileInput);
		fileStone->keyWord = fileInput;

		getline(inFile, fileInput);
		fileStone->color = fileInput;

		getline(inFile, border);
		
		sVec.push_back(*fileStone);
	}
	for (unsigned int k = 0 ; k < sVec.size(); k++) 
	{
		sVec[k].vecPosition = k;
	}
	
	return sVec;
}
//sets up the Stone vector argument to take info from Stone Archive text file and convert into Stone vector objects then returns the newly modified Stone vector
Stone searchArchive(vector<Stone>& sVec)
{
	
	string searchStone;
	bool stoneFound = false;
	

	archiveVecSetup(sVec);
	cout << "Which stone are you looking for?" << endl;
	getline(cin, searchStone);
	searchStone = toLowerCaseString(searchStone);

	for (unsigned int j = 0; j < sVec.size(); j++)
	{
		
		if ("stone name: "+ searchStone== sVec[j].stoneName)
			{

				cout<<"Found Stone!"<<endl;
				stoneFound = true;
				//sVec[j].vecPosition= j;
				return sVec[j];
			}
	}
	if (!stoneFound)
	{
		cout << "Sorry no stone with that name was found. Please check spelling and try again." << endl;
		system("pause");
		return sVec[0];
		exit(6);
	}
	return sVec[0];
}
//searches for a stone name in Archive (sVec) and returns the Stone object
void displayAttempt()
{

	ofstream outFile;
	ifstream inFile;
	vector<Stone> stoneVec;
	Stone* newStone = new Stone;
	string fromFile;
	string border;
	inFile.open("Stone_Archive.txt");

	if (inFile.is_open())
	{

		while (!inFile.eof())
		{
			std::getline(inFile, fromFile);
			toLowerCaseString(fromFile);
			newStone->stoneName = fromFile;
			getline(inFile, fromFile);
			toLowerCaseString(fromFile);
			newStone->keyWord = fromFile;
			getline(inFile, fromFile);
			toLowerCaseString(fromFile);
			newStone->color = fromFile;
			getline(inFile, border);

			stoneVec.push_back(*newStone);
		}

		for (unsigned int i = 0; i < stoneVec.size(); i++)
		{

			std::cout << stoneVec[i].stoneName << std::endl;
			std::cout << stoneVec[i].keyWord << std::endl;
			std::cout << stoneVec[i].color << std::endl;
			std::cout << border << endl;

		}
	}
}
//opens the Stone Archive text file and displays content
void stoneModAttempt() {
	ofstream outFile;
	ifstream inFile;
	vector<Stone> stoneVec;
	Stone* newStone = new Stone;
	string fromFile;
	string border = "----------------------------";
	string fromUser;
	char charFromUser;

	inFile.open("Stone_Archive.txt");

	if (inFile.is_open())
	{

		while (!inFile.eof())
		{
			getline(inFile, fromFile);
			newStone->stoneName = fromFile;
			getline(inFile, fromFile);
			newStone->keyWord = fromFile;
			getline(inFile, fromFile);
			newStone->color = fromFile;
			getline(inFile, border);

			stoneVec.push_back(*newStone);
		}

		for (unsigned int i = 0; i < stoneVec.size(); i++)
		{
			std::cout << stoneVec[i].stoneName << std::endl;
			std::cout << stoneVec[i].keyWord << std::endl;
			std::cout << stoneVec[i].color << std::endl;
			std::cout << border << endl;

		}
		inFile.close();
	}
	else
	{
		std::cerr << "Cannot open file" << endl;
	}

	std::cout << "Which stone would you like to append?" << std::endl;
	cin.ignore();
	getline(cin, fromUser);
	toLowerCaseString(fromUser);
	for (unsigned int i = 0; i < stoneVec.size(); i++)
	{
		if ("stone name : " + fromUser == stoneVec[i].stoneName)
		{
			std::cout << "Found Entry!" << std::endl;
			std::cout << "What would you like to change?" << std::endl;
			std::cout << "1.Name 2. Keywords 3.Color " << endl;
		enterCase:
			std::cin >> charFromUser;
			switch (charFromUser)
			{
			case'1':
				cout << "Change Name to?" << std::endl;
				cin.ignore();
				getline(cin, fromUser);
				stoneVec[i].stoneName = "stone name: " + toLowerCaseString(fromUser);
				system("pause");
				break;
			case'2':
				cout << " Change Keywords to?" << std::endl;
				cin.ignore();
				getline(cin, fromUser);
				stoneVec[i].keyWord = "keywords: " + toLowerCaseString(fromUser);
				system("pause");
				break;
			case '3':
				cout << "Change Color(s) to?" << std::endl;
				cin.ignore();
				getline(cin, fromUser);
				stoneVec[i].color = "color: " + toLowerCaseString(fromUser);
				system("pause");
				break;
			default:
				cout << "Invalid Entry please enter 1 - 3." << endl;
				goto enterCase;
				break;
			}
			std::cout << border << endl;
			std::cout << stoneVec[i].stoneName << std::endl;
			std::cout << stoneVec[i].keyWord << std::endl;
			std::cout << stoneVec[i].color << std::endl;
		writeConfirm:
			std::cout << "Write modified entry to file(Y/N)?" << endl;
			cin >> charFromUser;
			if (tolower(charFromUser == 'y'))
			{
				system("pause");
				outFile.open("Stone_Archive.txt");
				if (outFile.is_open())
				{
					for (unsigned int j = 0; j < stoneVec.size(); j++)
					{
						outFile << stoneVec[j].stoneName << std::endl;
						outFile << stoneVec[j].keyWord << std::endl;
						outFile << stoneVec[j].color << std::endl;
						outFile << "----------------------------" << std::endl;

					}
				}
			}
			else if (tolower(charFromUser) == 'n')
			{
				cout << "Cancel writing to file. Exiting program.";
				exit(1);
			}
			else
			{
				cout << "Sorry invalid input" << endl;
				goto writeConfirm;
			}
			std::cout << "Writing to file complete!" << std::endl;

		}
	}


}
//attempts to modify an already existing entry
void endUserInit()
{
	string userInput;
	char userDecision;
	ofstream outFile;
	ifstream inFile;
	inFile.open("Stone_Archive.txt");
	

	Stone* newStone = new Stone;
newEntry:
	cout << "Would you like to create a new stone entry?" << endl;
	cin >> userDecision;

	if (tolower(userDecision) == 'y') 
	{
		outFile.open("Stone_Archive.txt", fstream::app);
	}
	else if (tolower(userDecision) == 'n')
	{
		cout << "Exiting program." << endl;
		exit(1);
	}
	else
	{
		cout << "Invalid entry expected a Y or N." << endl;
		goto newEntry;
	}
	if (!outFile.is_open()) 
	{
		cerr << "Failed to open write file. Exiting program." << endl;
		exit(2);
	}
	cout << "Please enter the name of the new stone" << endl;
	cin.ignore();
	getline(cin, newStone->stoneName);
	newStone->stoneName = "stone name :" + toLowerCaseString(newStone->stoneName);
	cout << "Now which keywords would you like associated with " 
		<< newStone->stoneName << " ?"<< endl;

	getline(cin, newStone->keyWord);
	newStone->keyWord ="keywords :" + toLowerCaseString(newStone->keyWord);


	cout << "What color or colors are present in this stone?" << endl;
	getline(cin, newStone->color);
	newStone->color = "color :"+ toLowerCaseString(newStone->color);

	cout << "Would you like to add this new entry to the Archive?" << endl;
	
	cin >> userDecision;

	if (tolower(userDecision) == 'y')
	{
		outFile << endl;
		outFile << newStone->stoneName << endl;
		outFile << newStone->keyWord << endl;
		outFile << newStone->color << endl;
		outFile << "----------------------------";
		cout << "File Write Complete!" << endl;
		outFile.close();
		system("pause");
		exit(0);
	}
	else if (tolower(userDecision) == 'n')
	{
		cout << "Cancel file writing. Exiting program." << endl;
		outFile.close();
			exit(3);
			
	}

	

}
//adds a Stone object to the database for entry into the Stone Archive text file
