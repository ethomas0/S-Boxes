#include <iostream>
#include <bitset>
#include <vector>
#include "Cypher.h"

using namespace std;

int main()
{
	//creating all variables needed for test
	Cypher p1k1, p1k2, p2k1, p2k2, p3k1, p3k2, p4k1, p4k2, p5k1, p5k2;
	
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

//Output
//1st Plain Text Message :
//Plain Text : [1111 0101 0110 0110]
//Key Used : Key 1
//Cipher Text : [1100 1000 0100 1011]
//
//Plain Text : [1111 0101 0110 0110]
//Key Used : Key 2
//Cipher Text : [0111 1011 0001 0011]
//
//0110 1010 0011 1000 //this was to ensure that bits were flipping properly during calculation of avalanche effect for Key 1
//1010 1010 0011 1000
//1100 1010 0011 1000
//1111 1010 0011 1000
//1110 0010 0011 1000
//1110 1110 0011 1000
//1110 1000 0011 1000
//1110 1011 0011 1000
//1110 1010 1011 1000
//1110 1010 0111 1000
//1110 1010 0001 1000
//1110 1010 0010 1000
//1110 1010 0011 0000
//1110 1010 0011 1100
//1110 1010 0011 1010
//1110 1010 0011 1001
//Total Number of Changed Bits : 80
//Number of Rounds : 16
//
//0011 1101 1000 0001 //this was to ensure that bits were flipping properly during calculation of avalanche effect for Key 2
//1111 1101 1000 0001
//1001 1101 1000 0001
//1010 1101 1000 0001
//1011 0101 1000 0001
//1011 1001 1000 0001
//1011 1111 1000 0001
//1011 1100 1000 0001
//1011 1101 0000 0001
//1011 1101 1100 0001
//1011 1101 1010 0001
//1011 1101 1001 0001
//1011 1101 1000 1001
//1011 1101 1000 0101
//1011 1101 1000 0011
//1011 1101 1000 0000
//Total Number of Changed Bits : 192
//Number of Rounds : 32
//
//
//2nd Plain Text Message :
//Plain Text : [0010 1001 1100 0010]
//Key Used : Key 1
//Cipher Text : [0011 1001 0010 0000]
//
//Plain Text : [0010 1001 1100 0010]
//Key Used : Key 2
//Cipher Text : [0001 0110 1101 1101]
//
//Total Number of Changed Bits : 336
//Number of Rounds : 48
//
//Total Number of Changed Bits : 432
//Number of Rounds : 64
//
//
//3rd Plain Text Message :
//Plain Text : [0101 1100 1110 0010]
//Key Used : Key 1
//Cipher Text : [0001 1001 1101 0001]
//
//Plain Text : [0101 1100 1110 0010]
//Key Used : Key 2
//Cipher Text : [0011 0110 0010 1100]
//
//Total Number of Changed Bits : 560
//Number of Rounds : 80
//
//Total Number of Changed Bits : 688
//Number of Rounds : 96
//
//
//4th Plain Text Message :
//Plain Text : [1110 0111 1100 0011]
//Key Used : Key 1
//Cipher Text : [1011 0100 1010 0000]
//
//Plain Text : [1110 0111 1100 0011]
//Key Used : Key 2
//Cipher Text : [0101 1110 1001 1101]
//
//Total Number of Changed Bits : 816
//Number of Rounds : 112
//
//Total Number of Changed Bits : 976
//Number of Rounds : 128
//
//
//5th Plain Text Message :
//Plain Text : [0011 1110 1111 0010]
//Key Used : Key 1
//Cipher Text : [1111 1001 1011 0011]
//
//Plain Text : [0011 1110 1111 0010]
//Key Used : Key 2
//Cipher Text : [0100 0110 0111 1011]
//
//Total Number of Changed Bits : 1104
//Number of Rounds : 144
//
//
//Total Number of Changed Bits : 1232
//Number of Rounds : 160
//
//
//Average Avalanche effect : 48.125%