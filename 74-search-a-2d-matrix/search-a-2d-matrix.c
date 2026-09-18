bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int rows = matrixSize;
    int cols = matrixColSize[0];

    int low = 0;
    int high = rows * cols - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int row = mid / cols;
        int col = mid % cols;

        if (matrix[row][col] == target)
        {
            return true;
        }
        else if (matrix[row][col] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return false;
}