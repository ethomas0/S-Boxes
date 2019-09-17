#include <iostream>
#include <bitset>
#include <vector>
#include "Cypher2.0.h"

using namespace std;

int main()
{
	//creating all variables needed for test
	Cypher2 p1k1, p1k2, p2k1, p2k2, p3k1, p3k2, p4k1, p4k2, p5k1, p5k2;

	string name = "key1";
	string name2 = "key2";

	vector<bitset<4>> p1 = { (int)15, (int)5, (int)6, (int)6 };
	vector<bitset<4>> p2 = { (int)2, (int)9, (int)12, (int)2 };
	vector<bitset<4>> p3 = { (int)5, (int)12, (int)14, (int)2 };
	vector<bitset<4>> p4 = { (int)14, (int)7, (int)12, (int)3 };
	vector<bitset<4>> p5 = { (int)3, (int)14, (int)15, (int)2 };

	//encrypting plaint text messages
	p1k1.createCypher(p1, name);
	p1k2.createCypher(p1, name2);


	p2k1.createCypher(p2, name);
	p2k2.createCypher(p2, name2);


	p3k1.createCypher(p3, name);
	p3k2.createCypher(p3, name2);


	p4k1.createCypher(p4, name);
	p4k2.createCypher(p4, name2);


	p5k1.createCypher(p5, name);
	p5k2.createCypher(p5, name2);




	//showing results
	cout << "1st Plain Text Message:" << endl;
	cout << p1k1 << endl;
	cout << p1k2 << endl;
	p1k1.calcAvalanch(name);
	p1k2.calcAvalanch(name2);
	cout << endl;

	cout << "2nd Plain Text Message:" << endl;
	cout << p2k1 << endl;
	cout << p2k2 << endl;
	p2k1.calcAvalanch(name);
	p2k2.calcAvalanch(name2);
	cout << endl;

	cout << "3rd Plain Text Message:" << endl;
	cout << p3k1 << endl;
	cout << p3k2 << endl;
	p3k1.calcAvalanch(name);
	p3k2.calcAvalanch(name2);
	cout << endl;


	cout << "4th Plain Text Message:" << endl;
	cout << p4k1 << endl;
	cout << p4k2 << endl;
	p4k1.calcAvalanch(name);
	p4k2.calcAvalanch(name2);
	cout << endl;

	cout << "5th Plain Text Message:" << endl;
	cout << p5k1 << endl;
	cout << p5k2 << endl;
	p5k1.calcAvalanch(name);
	p5k2.calcAvalanch(name2);
	cout << endl;

	cout << "Average Avalanche effect: " << p5k1.getAvgAvalanche() * 100 << "%" << endl;




	system("pause");

	return 0;
}

//Output:
//1st Plain Text Message :
//Plain Text : [1111 0101 0110 0110]
//Key Used : Key 1
//Cipher Text : [0000 0001 1010 1011]
//
//Plain Text : [1111 0101 0110 0110]
//Key Used : Key 2
//Cipher Text : [0110 1100 0100 1101]
//
//Total Number of Changed Bits : 145
//Number of Rounds : 18
//
//Total Number of Changed Bits : 295
//Number of Rounds : 18
//
//
//2nd Plain Text Message :
//Plain Text : [0010 1001 1100 0010]
//Key Used : Key 1
//Cipher Text : [0101 0001 0101 0000]
//
//Plain Text : [0010 1001 1100 0010]
//Key Used : Key 2
//Cipher Text : [0100 1101 0011 0011]
//
//Total Number of Changed Bits : 392
//Number of Rounds : 18
//
//Total Number of Changed Bits : 540
//Number of Rounds : 18
//
//
//3rd Plain Text Message :
//Plain Text : [0101 1100 1110 0010]
//Key Used : Key 1
//Cipher Text : [1010 0001 0000 0000]
//
//Plain Text : [0101 1100 1110 0010]
//Key Used : Key 2
//Cipher Text : [0110 1101 0110 0011]
//
//Total Number of Changed Bits : 670
//Number of Rounds : 18
//
//Total Number of Changed Bits : 791
//Number of Rounds : 18
//
//
//4th Plain Text Message :
//Plain Text : [1110 0111 1100 0011]
//Key Used : Key 1
//Cipher Text : [0111 0000 0111 0000]
//
//Plain Text : [1110 0111 1100 0011]
//Key Used : Key 2
//Cipher Text : [0100 1100 0011 0011]
//
//Total Number of Changed Bits : 898
//Number of Rounds : 18
//
//Total Number of Changed Bits : 1030
//Number of Rounds : 18
//
//
//5th Plain Text Message :
//Plain Text : [0011 1110 1111 0010]
//Key Used : Key 1
//Cipher Text : [1101 0011 1101 1101]
//
//Plain Text : [0011 1110 1111 0010]
//Key Used : Key 2
//Cipher Text : [1010 1111 0101 1011]
//
//Total Number of Changed Bits : 1186
//Number of Rounds : 18
//
//Total Number of Changed Bits : 1330
//Number of Rounds : 18
//
//
//Average Avalanche effect : 51.9531%