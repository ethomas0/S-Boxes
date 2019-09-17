#include "Cypher2.0.h"


double Cypher2::totalAvalanche(0);
int Cypher2::numAvalRounds(0);
Cypher2::Cypher2()
{
	vector<bitset<4>> tempkey1(4);
	vector<bitset<4>> tempkey2(4);
	for (int i = 0; i < 4; i++) // stores in reverse so I reverse again. *just easier for me to troubleshoot, plus first time using bitset
	{
		for (int j = 0, k = 3; j < 4, k > -1; j++, k--)
		{
			tempkey1[i][j] = key1[i][k];
			tempkey2[i][j] = key2[i][k];
		}
	}
	key1 = tempkey1;
	key2 = tempkey2;

	vector<bitset<2>> tempIndexValue(4);
	for (int i = 0; i < 4; i++) //same as above
	{
		for (int j = 0, k = 1; j < 2, k > -1; j++, k--)
		{
			tempIndexValue[i][j] = indexVal[i][k];
		}
	}
	indexVal = tempIndexValue;
	numRounds = 0;
}

void Cypher2::createCypher(vector<bitset<4>> pText, string keyName)
{
	vector<bitset<4>> tempText(4);
	for (int i = 0; i < 4; i++) // reverse numbers again
	{
		for (int j = 0, k = 3; j < 4, k > -1; j++, k--)
		{
			tempText[i][j] = pText[i][k];
		}
	}
	plainText = tempText;
	if (keyName == "key1")
	{
		whichKey = "Key 1";
		cypherSol.push_back(plainText[1] ^ key1[0]);
		cypherSol.push_back(plainText[3] ^ key1[2]);
		cypherSol.push_back(plainText[0] ^ key1[1]);
		cypherSol.push_back(plainText[2] ^ key1[3]);
		encrypt();

	}
	else
	{
		whichKey = "Key 2";
		cypherSol.push_back(plainText[1] ^ key2[0]);
		cypherSol.push_back(plainText[3] ^ key2[2]);
		cypherSol.push_back(plainText[0] ^ key2[1]);
		cypherSol.push_back(plainText[2] ^ key2[3]);
		encrypt();
	}
}

void Cypher2::calcAvalanch(string keyName)
{
	Cypher2 changedSol;
	changedSol.createCypher(this->plainText, keyName);



	for (int j = 0; j < 4; j++)
	{
		for (int k = 0; k < 4; k++)
		{
			if (keyName == "key1")
			{
				changedSol.key1[j].flip(k);
				changedSol.createCypher(this->plainText, keyName);
				compare(*this, changedSol);
				++numRounds;
				changedSol.key1 = this->key1;


			}
			else
			{ 
				changedSol.key2[j].flip(k);
				changedSol.createCypher(this->plainText, keyName);
				compare(*this, changedSol);
				++numRounds;
				changedSol.key2 = this->key2;

			}


		}

	}


	cout << "Total Number of Changed Bits: " << totalAvalanche << endl;
	cout << "Number of Rounds: " << numRounds << endl << endl;
}


double Cypher2::getAvgAvalanche()
{
	return (totalAvalanche / (5 * 2 * 16 * 16));
}

void Cypher2::encrypt()
{
	int i, j, k(0), intRow, intCol;
	bitset<2> row, col;

	do
	{
		for (i = 0, j = 0; i < 4; i++)//indexing the vector
		{
			for (j = 0; j < 4; j++)//indexing bit by bit
			{
				if (k >= 2)
				{
					k = 0;
				}
				if (j < 2)
				{
					if (numRounds == 0)
					{
						col[k] = cypherSol[i][j];
						++k;
					}
					else
					{
						col[k] = encryption[i][j];
					}
					
				}
				else
				{
					if (numRounds == 0)
					{
						row[k] = cypherSol[i][j];
						++k;
					}
					else
					{
						row[k] = encryption[i][j];
					}
					
				}


			}
			for (int z = 0; z < 4; z++)
			{
				if (row == indexVal[z])
				{

					intRow = z;
				}
				if (col == indexVal[z])
				{
					intCol = z;
				}
			}

			if (i % 2 == 0)
			{
				if (numRounds == 0)
				{
					encryption.push_back(S1[intRow][intCol]);
				}
				else
				{
					encryption[i] = S1[intRow][intCol];
				}

				
			}
			else
			{
				if (numRounds == 0)
				{
					encryption.push_back(S2[intRow][intCol]);
				}
				else
				{
					encryption[i] = S2[intRow][intCol];
				}
			}
		}
		++numRounds;
	} while (numRounds < 2);

	

	vector<bitset<4>> tempEncryp(4);
	for (int i = 0; i < 4; i++) // reversing numbers again
	{
		for (int j = 0, k = 3; j < 4, k > -1; j++, k--)
		{
			tempEncryp[i][j] = encryption[i][k];
		}
	}
	encryption = tempEncryp;
}

void Cypher2::compare(Cypher2 e1, Cypher2 e2)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (e1.encryption[i][j] != e2.encryption[i][j])
			{
				++totalAvalanche;
			}
		}
	}
}

ostream & operator<<(ostream & output, const Cypher2 var)
{
	output << "Plain Text: [";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			output << var.plainText[i][j];
		}
		if (i != 3)
		{
			output << " ";
		}

	}

	output << "]" << endl;
	output << "Key Used: " << var.whichKey << endl;
	output << "Cipher Text: [";

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			output << var.encryption[i][j];
		}
		if (i != 3)
		{
			output << " ";
		}

	}
	output << "]" << endl;
	return output;
}
