/** 
    Name:  Bryan Altman
    HW: 02
    desc: Implementation of a hash table.
            The table itself is a template capable of hashing any kind of data.
            Str_Table is the specific implementation of a hash table for string data.
 **/

#include "str_table.h"
#include <iostream>
using namespace std;

int main()
{
	char c;
	int N, pos;
	Str_Table hs(1000);
	string topic, disc;

	cout << "Hash Table\n";
	cout << "\nChoose one of the following" << endl;
	cout << "n: New hash table" << endl;
	cout << "a: Add a subject and a title" << endl;
	cout << "d: Del a subject " << endl;
	cout << "t: print all titles of the subject " << endl;
    cout << "s: print N first appearances of a subect " << endl;
	cout << "p: print all non-empty entries " << endl;
	cout << "e: Exit" << endl;
	do
	{
		cin >> c;
		switch (c)
		{
		
		case 'n':
            hs.resetTable();
            break;
		case 'a':
            cout << "Enter a subject and a title\n";
			cin >> topic >> disc;
			hs.addNewTopic(topic, disc);
			break;
		case 'd':
            cout << "Enter a subject to remove\n";
			cin >> topic;
			hs.deleteItem(topic);
            break;
		case 't':
            cout << "enter subject to print\n";
			cin >> topic;
            pos = hs.search(topic);
            if (pos != -1)
			    hs.printTopic(topic, pos);
            else
                cout << "ERROR" << endl;
            break;
		case 's':
            cout << "enter a subject and N\n";
            cin >> topic >> N; 
            pos = hs.search(topic);
            if (pos != -1)
			    hs.printFirstNDisc(topic, pos, N);
            else
                cout << "ERROR" << endl;
            break;
		case 'p':
            hs.printAllTopics();
            break;
        case 'e':
            cout << "bye\n";
            break;
		default:
            cout << "ERROR\n";
            break;
		}
	} while (c != 'e');
}