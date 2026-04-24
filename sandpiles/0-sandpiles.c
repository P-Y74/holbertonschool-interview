#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Prints a 3x3 grid of integers
 * @grid: The 3x3 grid to be printed
 *
 * This function displays the grid in a formatted way,
 * with values separated by spaces and each row on a new line.
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Checks if a sandpile grid is stable
 * @grid: The 3x3 grid to check
 *
 * A grid is considered stable if no cell contains more than 3 grains.
 *
 * Return: 1 if the grid is stable, 0 otherwise
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: The first 3x3 grid (result is stored here)
 * @grid2: The second 3x3 grid
 *
 * This function adds grid2 to grid1 and stabilizes the result.
 * If the resulting grid is unstable (cells > 3), it performs
 * toppling operations until the grid becomes stable.
 *
 * During each toppling round, the current state of the grid
 * is printed before applying the transformation.
 *
 * No dynamic memory allocation is used.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int unstable[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	}
	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				unstable[i][j] = (grid1[i][j] > 3);
			}
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (unstable[i][j])
				{
					grid1[i][j] -= 4;

					if (i > 0)
						grid1[i - 1][j] += 1;
					if (i < 2)
						grid1[i + 1][j] += 1;
					if (j > 0)
						grid1[i][j - 1] += 1;
					if (j < 2)
						grid1[i][j + 1] += 1;
				}
			}
		}
	}
}
