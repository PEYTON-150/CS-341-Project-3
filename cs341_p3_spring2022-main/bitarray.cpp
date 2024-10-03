#include<cmath>

#include "bitarray.h"

//constructor
BitArray :: BitArray(int n)//takes in number of bits
{
	LENGTH = n; //sets length = to number of bits
	BYTES = ((LENGTH/8)); //set bytes = to number of bits/8 since 8 bits in byte
	data = new char[BYTES]; // access by data + i
}

void BitArray :: clear()
{
	for(int i = 0; i < BYTES; i++)
	{
		data[i] &= ~data[i]; // takes the AND of data at index i and the complement of data at index i
	}
}


void BitArray :: initialize(char * n)
{
	for(int i = 0; i < BYTES; i++)
	{
		data[i] = n[i];
	}
}

//deconstructor
BitArray :: ~BitArray()
{
	delete [] data;
}

char BitArray :: get(int p) const
{
	int pos;
	char cell;//creates holders for the cell and position being targeted
	cell = data[p/8]; //targets the cell at which bit p is located
	pos = p%8; //targets the corresponding bit to p of the char in the cell being targeted
	if((cell >> pos ) & 1)//if the bit at pos in char cell is "on" return the char cell if not return zero
	{
		return cell;
	}
	else
		return '0';



}

bool BitArray :: set(int p, int b)
{
	//to find cell and correspondng bit
	int pos;
	char cell;
	cell = data[p/8]; // cell in array
	pos = p%8; //position in cell
	if((cell |= b << pos))
	{
		return true;
	}
	else
		return false;
}

bool BitArray :: flip(int p)
{
	//to find cell and correspondng bit
	int pos;
	char cell;
	cell = data[p/8];
	pos = p%8;

	if ((cell >> pos) & 1)
	{
		cell &= ~(1 << pos);//if bit at p is "on" unset bit
	}
	else
		cell |= 1 << pos;// if bit at p is "off" set bit

	return true;
}

void BitArray :: complement()//this will flip every bit in data
{
	//these variables are used to make it easier to read
	char cell;
	int pos;
	for(int i = 0; i < BYTES; i++)//used to itterate through the char array
	{
		for(int b = 0; b < 8; b++)//used to itterate through each of 8 bits in a char
		{
			cell = data[i];
			pos = b;
			if ((cell >> pos) & 1)
			{
				cell &= ~(1 << pos);//if bit at p is "on" unset bit
			}
			else
				cell |= 1 << pos;// if bit at p is "off" set bit

		}
	}
}

char BitArray :: get8(int p)
{
	char cell = data[p/8];
	int pos = p%8;
	int bitsOfNextCell = 8 - pos;// value to hold how many bits to go into in the next cell
	int charintval = 0;
	for(int i = pos; i <= 8; pos ++)//used to itterate through bits of cell, then make sure to stop before leaving cell
	{
		if((cell >> i ) & 1)//if the bit at i is on
		{
			charintval += 2^i;//add 2 to the power of i to the in val of char
		}
	}
	cell = data[(p/8)+1];//to go into the next cell after we hit the end of bits in the first one
	for(int i = 0; i < bitsOfNextCell; i ++)
	{
		if((cell >> i ) & 1)//if the bit at i is on
		{
			charintval += 2^i;//add 2 to the power of i to the in val of char
		}
	}
	//basically as i grows charintval grows by a factor of 2^i
	//if p starts at the 7th bit of a cell p+8 will be in the next cell
	//as you enter the next cell the value that needs to be added to charintval changes
	//finally you return a char that holds the value of charintval

	char answer;
	answer = '0'+ charintval;
	return answer;
}
