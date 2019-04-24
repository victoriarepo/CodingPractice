// compute the number of connected components in a binary matrix
// cells with "1" are nodes 
// adjacent nodes (including diagonal) are considered connected

#include <iostream>
using namespace std;

int xDim = 4, yDim = 5;
int explored[4][5] = {{0,0,0,0,0},
					  {0,0,0,0,0},
					  {0,0,0,0,0},
					  {0,0,0,0,0}};

// recursive function to expand on each connection
int expand(int array[4][5], int x, int y, int sofar)
{
	bool expandable = false;

	// if not on bottom row
	if (x < xDim - 1)
	{
		if (array[x + 1][y] == 1 && explored[x + 1][y] == 0)
		{
			expandable = true;
			explored[x + 1][y] = 1;
			sofar += expand(array, x + 1, y, sofar);
		}

		// if not on rightmost edge
		if (y < yDim - 1)
		{
			if (array[x + 1][y + 1] == 1 && explored[x + 1][y + 1] == 0)
			{
				expandable = true;
				explored[x + 1][y + 1] = 1;
				sofar += expand(array, x + 1, y + 1, sofar);
			}
		}

		// if not on leftmost edge
		if (y > 0)
		{
			if (array[x + 1][y - 1] == 1 && explored[x + 1][y - 1] == 0)
			{
				expandable = true;
				explored[x + 1][y - 1] = 1;
				sofar += expand(array, x + 1, y - 1, sofar);
			}
		}
	}

	// if not on rightmost edge
	if (y < yDim - 1)
	{
		if (array[x][y + 1] == 1  && explored[x][y + 1] == 0)
		{
			expandable = true;
			explored[x][y + 1] = 1;
			sofar += expand(array, x, y + 1, sofar);
		}
	}

	// if not on leftmost edge
	if (y > 0)
	{
		if (array[x][y - 1] == 1  && explored[x][y - 1] == 0)
		{
			expandable = true;
			explored[x][y - 1] = 1;
			sofar += expand(array, x, y - 1, sofar);
		}
	}

	// if not on top row
	if (x > 0)
	{
		if (array[x - 1][y] == 1 && explored[x - 1][y] == 0)
		{
			expandable = true;
			explored[x - 1][y] = 1;
			sofar += expand(array, x - 1, y, sofar);
		}

		// if not on rightmost edge
		if (y < yDim - 1)
		{
			if (array[x - 1][y + 1] == 1 && explored[x - 1][y + 1] == 0)
			{
				expandable = true;
				explored[x - 1][y + 1] = 1;
				sofar += expand(array, x - 1, y + 1, sofar);
			}
		}

		// if not on leftmost edge
		if (y > 0)
		{
			if (array[x - 1][y - 1] == 1  && explored[x - 1][y - 1] == 0)
			{
				expandable = true;
				explored[x - 1][y - 1] = 1;
				sofar += expand(array, x - 1, y - 1, sofar);
			}
		}
	}

	if (!expandable)
	{
		return 0;
	}
	else
	{
		return sofar + 1;
	}
}

int main(int argc, char **argv)
{
	int array[4][5] = {{1,0,0,1,0},
					   {0,1,1,0,0},
					   {0,0,1,0,1},
					   {0,1,1,1,1}};

  	int x = 0, y = 0;
  	bool end = false;

	// first find a '1' node
	for (int i = 0; i < xDim; i++)
	{
		for (int j = 0; j < yDim; j++)
		{
			if (array[i][j] == 1)
			{
				x = i;
				y = j;
				end = true;
				break;
			}
		}

		if (end)
			break;
	}

	explored[x][y] = 1;

	for (int i = 0; i < xDim; i++)
	{
		for (int j = 0; j < yDim; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << expand(array, x, y, 0) + 1 << " connected nodes in the array." << endl;

	return 0;
}