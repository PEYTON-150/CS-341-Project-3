#include <cmath>
#include "set.h"



Set :: Set (int n)
{
	LENGTH = n; //sets length = to number of bits
	BYTES = ((LENGTH/8)); //set bytes = to number of bits/8 since 8 bits in byte
	data = new char[BYTES]; // access by data + i
}

Set :: ~Set()
{
 delete [] data;
}

void Set :: initialize(char * n)
{
	for(int i = 0; i < BYTES; i++)
	{
		data[i] = n[i];
	}
}


int Set :: cardinality() const // needs work
{
return BYTES;
}

bool Set :: setIntersection(Set & n)//this is the logic for intersection just need to change it to fit bitarray
{ bool dupe;
  for(int j = 0; j<BYTES; j++)
  {
    for(int i = 0; i<BYTES; i++)//fills the temp array
      { dupe = false;
        temp[j] = data[j];

        if(temp[j] == n[i])//if they are dupelicates then we dont add it to the array
        {
          dupe = true;
        }
        if(dupe == true)//not a duplicate so we add it to the end
        {
          data[i] = n[i];

        }
      }
    }
}

bool Set :: setDifference(Set & n)
{
return false;
}

bool Set :: setUnion(Set & n)
{//compare all of one array to one spot of the other and then ++ the spot when all is done
  int last = 1;//use this to add to the end
  bool dupe;//duplicate check
temp = new char[BYTES];
  for(int j = 0; j<BYTES; j++)
  {
    for(int i = 0; i<BYTES; i++)//fills the temp array
      { dupe = false;
        temp[j] = data[j];

        if(temp[j] == n[i])//if they are dupelicates then we dont add it to the array
        {
          dupe = true;
        }
        if(dupe == false)//not a duplicate so we add it to the end
        {
          data[BYTES+last] = n[i];
          last++;
        }
      }
    }
    return true;

}
BitArray  :: getData()
{
  for(int i = 0; i<BYTES; i++)
  {
    return data[i];
  }
}
