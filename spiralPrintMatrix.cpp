#include <iostream>
using namespace std;

int main()
{
	int matrix[4][4] = {{1,12,11,10},{2,13,16,9},{3,14,15,8},{4,5,6,7}};
	// int matrix[4][3] = {{1,10,9},{2,11,8},{3,12,7},{4,5,6}};
	// int matrix[3][4] = {{1,10,9,8},{2,11,12,7},{3,4,5,6}};
	int height = 4;
	int width = 4;

	// j is distance to centre from edge 
	// used to move towards matrix centre one ring at a time
	for (int j = 0; j < max(height, width) / 2; j++)
	{
		// print left side
		for (int i = j; i < height - j; i++)
		{
			cout << matrix[i][j] << endl;
		}

		// print bottom side
		for (int i = 1 + j; i < width - j; i++)
		{
			cout << matrix[height - 1 - j][i] << endl;
		}

		// print right side
		// don't print if in last ring and width is odd
		if (j != max(height, width) / 2 - 1)
		{
			for (int i = height - 2 - j; i >= j; i--)
			{
				cout << matrix[i][width - 1 - j] << endl;
			}
		}
		else if (width % 2 == 0)
		{
			for (int i = height - 2 - j; i >= j; i--)
			{
				cout << matrix[i][width - 1 - j] << endl;
			}
		}

		// print top side
		for (int i = width - 2 - j; i > j; i--)
		{
			cout << matrix[j][i] << endl;
		}
	}

	return 0;
}