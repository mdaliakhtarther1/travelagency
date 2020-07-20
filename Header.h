#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;


class record
{
public:
	std::string pass_id, name, source, dest, d_o_t;
}rec[20], found[20];

int m = 0, n;

void Insert(std::string values[])
{
	//cout << "Enter number of passengers: ";
	//cin >> n;
	//cout << "Enter passenger id,Name, source, destination, date of travel\n";
	
	
		//cout << "Passenger " << i + 1 << " :\n";
		    rec[n].pass_id = values[0];
			rec[n].name = values[1];
			rec[n].source = values[2];
			rec[n].dest = values[3];
			rec[n].d_o_t = values[4];
			n++;
	
}


void sort_records()
{
	int i, j;
	record temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (rec[j].name.compare(rec[j + 1].name) >  0)
			{
				temp = rec[j];
				rec[j] = rec[j + 1];
				rec[j + 1] = temp;
			}
			else if (rec[j].name.compare(rec[j + 1].name) == 0)
			{
				if (rec[j].pass_id.compare(rec[j + 1].pass_id) > 0)
				{
					temp = rec[j];
					rec[j] = rec[j + 1];
					rec[j + 1] = temp;
				}
			}
		}
	}
}


void create_file()
{
	ofstream index("secindex.txt");
	ofstream file("record.txt");
	ofstream track("track");
	track.seekp(0, ios::beg);
	track << n;
	track.close();
	for (int i = 0; i < n; i++)
	{
		index << rec[i].name.c_str() << "|" << rec[i].pass_id.c_str() << "|" << i << "\n";
		file << i << "|" << rec[i].pass_id.c_str() << "|" << rec[i].name.c_str() << "|" << rec[i].source.c_str() << "|" << rec[i].dest.c_str() <<"|"<< rec[i].d_o_t.c_str() << "\n";
	}
	index.close();
	file.close();
}



char* retrieve_record(const char* index)
{
	fstream f1("record.txt", ios::in);
	int i;
	char* result = new char[1000];
	strcpy_s(result, 1, "");
	std::string pass_id, name, source, dest, d_o_t, indx;
	char* str = new char[20];
	for (i = 0; i < n; i++)
	{
		f1.getline(str, 10, '|');
		 indx = str;
		f1.getline(str, 10, '|');
		pass_id = str;
		f1.getline(str, 20, '|');
		name = str;
		f1.getline(str, 20, '|');
		source = str;
		f1.getline(str, 20, '|');
		dest = str;
		f1.getline(str, 10, '\n');
		d_o_t = str;
		if (string(index).compare(indx) == 0)
		{
			strcat_s(result, 100, pass_id.c_str());
			strcat_s(result, 100, "|");
			strcat_s(result, 100, name.c_str());
			strcat_s(result, 100, "|");
			strcat_s(result, 100, source.c_str());
			strcat_s(result, 100, "|");
			strcat_s(result, 100, dest.c_str());
			strcat_s(result, 100, "|");
			strcat_s(result, 100, d_o_t.c_str());
			strcat_s(result, 100, "\n");
		}
			//cout << "passenger_id: " << pass_id.c_str() << " Name: " << name.c_str() << " source: " << source.c_str() << " destination: " << dest.c_str() << "date of journey:" << d_o_t.c_str() << endl;
		//f1.seekg(2, ios::cur);
	}
	f1.close();
	return result;
}

 
char*  Search(std::string key_name)
{
	int k = 0, i, flag;
	fstream f1("secindex.txt",ios::in);
	if (!f1)
		return NULL;
	string name, pass_id, ind, key_pass_id;
	std::string index[20];
	char* result = new char[1000];
	strcpy_s(result, 10, "");
	char* str = new char[100];
	//cout << "Enter the name for search: ";
	//cin >> key_name;
	for (i = 0; i < n; i++)
	{
		f1.getline(str, 20, '|');
		name = str;
		f1.getline(str, 10, '|');
		pass_id = str;
		f1.getline(str, 10, '\n');
		ind = str;
		if (key_name.compare(name) == 0)
		{
			found[k].name = name;
			found[k].pass_id = pass_id;
			index[k] = ind;
			k++;
		}
	}
	f1.close();
	if (k == 0)
		return NULL;
	else if (k == 1)
		result = retrieve_record(index[0].c_str());
	else
	{
		/*cout << "Choose USN from the list:\n";
		for (i = 0; i < k; i++)
			cout << found[i].pass_id << endl;
		cin >> key_pass_id;*/
		flag = 0;
		for (i = 0; i < k; i++)
		{
			/*if (strcmp(key_pass_id, found[i].pass_id) == 0)
			{*/
			strcat_s( result , 500 , retrieve_record(index[i].c_str()));
				//result = retrieve_record(index[i].c_str());
				flag = 1;
			//}
		}
		if (!flag)
			//cout << "Invalid entry!!\n";
			return NULL;
	}
	return result;
}



void delete_record(const char* indx)
{
	int i, flag;
	char ch;
	fstream f1("record.txt", ios::in);
	std::string index[20];
	char* str = new char[100];
	for (i = 0; i < n; i++)
	{
		f1.getline(str, 10, '|');
		index[i] = str;
		f1.getline(str, 10, '|');
		rec[i].pass_id = str;
		f1.getline(str, 20, '|');
		rec[i].name = str;
		f1.getline(str, 20, '|');
		rec[i].source = str;
		f1.getline(str, 20, '|');
		rec[i].dest = str;
		f1.getline(str, 10, '\n');
		rec[i].d_o_t = str;
		f1.seekg(2, ios::cur);
		//cout << f1.tellg() << endl;
	}
	flag = -1;
	for (i = 0; i < n; i++)
	{
		if (index[i].compare(indx) == 0)
			flag = i;
	}
	if (flag != n - 1)
	{
		for (i = flag; i < n; i++)
			rec[i] = rec[i + 1];
	}
	n--;
	ofstream o("track", ios::trunc);
	o << n;
	o.close();
	//cout << "Record deleted!!\n";
	f1.close();
	f1.open("secindex.txt", ios::out|ios::trunc);
	fstream f2("record.txt", ios::out|ios::trunc);
	for (i = 0; i < n; i++)
	{
		f1 << rec[i].name.c_str() << "|" << rec[i].pass_id.c_str() << "|" << i << "\n";
		f2 << i << "|" << rec[i].pass_id.c_str() << "|" << rec[i].name.c_str() << "|" << rec[i].source.c_str() << "|" << rec[i].dest.c_str() << "|" << rec[i].d_o_t.c_str() << "\n";
	}
	f1.close();
	f2.close();
}




int del(std::string key_name, std::string key_pass_id)
{
	int k = 0, i, flag;
	fstream f1("secindex.txt");
	if (!f1)
		return NULL;
	string name, ind, pass_id;
	std::string index[20];
	char* result = new char[1000];
	strcpy_s(result, 10, "");
	char* str = new char[100];
	//cout << "Enter the name to delete: ";
	//cin >> key_name;
	for (i = 0; i < n; i++)
	{
		f1.getline(str, 20, '|');
		name = str;
		f1.getline(str, 10, '|');
		pass_id = str;
		f1.getline(str, 10, '\n');
		ind = str;
		if (key_name.compare(name) == 0)
		{
			found[k].name = name;
			found[k].pass_id = pass_id;
			index[k] = ind;
			k++;
		}
	}
	f1.close();
	if (k == 0)
		return 0;//cout << "Deletion failed!!\n";
	else if (k == 1)
		delete_record(index[0].c_str());
	else
	{
		flag = 0;
		//cout << "Choose USN from the list:\n";
		//for (i = 0; i < k; i++)
		//	cout << found[i].pass_id << endl;
		//cin >> key_pass_id;
		for (i = 0; i < k; i++)
		{
			if (key_pass_id.compare(found[i].pass_id) == 0)
			{
				delete_record(index[i].c_str());
				flag = 1;
			}
		}
		if (!flag)
			return 0;
	}
	return 1;
	
}






/*void main()
{
	int ch;
	cout << "1:Insert\n2:Search\n3:Delete\n4:Exit\n";
	do
	{
		cout << "\nEnter your choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			insert();
			sort_records();
			create_file();
			break;
		case 2:
			search();
			break;
		case 3:
			del();
			break;
		case 4:
			remove("secindex.txt");
			remove("record.txt");
			break;
		}
	} while (ch != 4);
}*/