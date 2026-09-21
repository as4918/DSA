typedef struct {
    long long key;
    int value;
    int used;
} HashEntry;

int hashFunction(long long key, int size)
{
    long long h = key % size;

    if (h < 0)
        h += size;

    return (int)h;
}

int subarraySum(int* nums, int numsSize, int k)
{
    int tableSize = 50021;

    HashEntry *table = calloc(tableSize, sizeof(HashEntry));

    int count = 0;
    long long prefixSum = 0;

    // Prefix sum 0 occurs once
    int index = hashFunction(0, tableSize);

    while (table[index].used)
        index = (index + 1) % tableSize;

    table[index].used = 1;
    table[index].key = 0;
    table[index].value = 1;

    for (int i = 0; i < numsSize; i++)
    {
        prefixSum += nums[i];

        // We need an earlier prefixSum = currentSum - k
        long long needed = prefixSum - k;

        index = hashFunction(needed, tableSize);

        while (table[index].used)
        {
            if (table[index].key == needed)
            {
                count += table[index].value;
                break;
            }

            index = (index + 1) % tableSize;
        }

        // Store current prefix sum
        index = hashFunction(prefixSum, tableSize);

        while (table[index].used &&
               table[index].key != prefixSum)
        {
            index = (index + 1) % tableSize;
        }

        if (!table[index].used)
        {
            table[index].used = 1;
            table[index].key = prefixSum;
            table[index].value = 1;
        }
        else
        {
            table[index].value++;
        }
    }

    free(table);

    return count;
}